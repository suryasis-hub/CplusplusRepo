#include <algorithm>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <locale>
#include <mutex>
#include <optional>
#include <ostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>

enum class OperationType
{
    PUT,
    ERASE
};

std::string to_string(OperationType operatorType)
{
    if (operatorType == OperationType::PUT)
    {
        return "PUT";
    }
    else
    {
        return "ERASE";
    }
}

std::ostream& operator<<(std::ostream& os, OperationType operatorType)
{
    os << to_string(operatorType);
    return os;
}

class PersistentKV
{
    public:
        PersistentKV(std::string file_path) : m_file_path(file_path)
        {
            load_on_start();
        }

        bool insert(std::string key, std::string value)
        {
            std::lock_guard<std::mutex> lock_guard(m);

            if (!write_single_record(OperationType::PUT, key, value))
            {
                return false;
            }

            m_in_memory_store[key] = value;
            return true;
        }

        bool erase(std::string key)
        {
            std::lock_guard<std::mutex> lock_guard(m);

            if (!write_single_record(OperationType::ERASE, key, ""))
            {
                return false;
            }

            m_in_memory_store.erase(key);
            return true;
        }

        std::optional<std::string> get(std::string key)
        {
            std::lock_guard<std::mutex> lock_guard(m);

            if (m_in_memory_store.find(key) == m_in_memory_store.end())
            {
                return std::nullopt;
            }

            return m_in_memory_store[key];
        }

    private:

        void load_on_start()
        {
            std::ifstream input_file(m_file_path);

            if (!input_file.is_open())
            {
                return;
            }

            std::string line;

            while (std::getline(input_file, line))
            {
                auto result = read_record(line);

                if (!result.has_value())
                {
                    continue;
                }

                load_single_record(
                    std::get<0>(result.value()),
                    std::get<1>(result.value()),
                    std::get<2>(result.value())
                );
            }
        }

        std::optional<std::tuple<OperationType, std::string, std::string>>
        read_record(std::string record)
        {
            std::size_t first_comma = record.find(',');
            std::size_t second_comma = record.find(',', first_comma + 1);
            std::size_t last_comma = record.rfind(',');

            if (first_comma == std::string::npos ||
                second_comma == std::string::npos ||
                last_comma == std::string::npos)
            {
                return std::nullopt;
            }

            std::string operation =
                record.substr(0, first_comma);

            std::string key =
                record.substr(
                    first_comma + 1,
                    second_comma - first_comma - 1
                );

            std::string value =
                record.substr(
                    second_comma + 1,
                    last_comma - second_comma - 1
                );

            std::string checksum =
                record.substr(last_comma + 1);

            std::string string_without_checksum =
                record.substr(0, last_comma);

            std::size_t calculated_hash =
                std::hash<std::string>{}(string_without_checksum);

            std::size_t stored_hash;

            try
            {
                stored_hash = std::stoull(checksum);
            }
            catch (...)
            {
                return std::nullopt;
            }

            if (calculated_hash != stored_hash)
            {
                return std::nullopt;
            }

            if (operation == "PUT")
            {
                return std::make_tuple(
                    OperationType::PUT,
                    key,
                    value
                );
            }
            else if (operation == "ERASE")
            {
                return std::make_tuple(
                    OperationType::ERASE,
                    key,
                    value
                );
            }

            return std::nullopt;
        }

        bool write_single_record(
            OperationType operation_type,
            std::string key,
            std::string value)
        {
            std::ofstream output_file(
                m_file_path,
                std::ios::app
            );

            if (!output_file.is_open())
            {
                return false;
            }

            std::string value_to_write =
                to_string(operation_type)
                + ","
                + key
                + ","
                + value;

            std::size_t hash_value =
                std::hash<std::string>{}(value_to_write);

            output_file
                << value_to_write
                << ","
                << hash_value
                << std::endl;

            output_file.flush();

            return output_file.good();
        }

        void load_single_record(
            OperationType operation_type,
            std::string key,
            std::string value)
        {
            if (operation_type == OperationType::PUT)
            {
                m_in_memory_store[key] = value;
            }
            else
            {
                m_in_memory_store.erase(key);
            }
        }

        std::unordered_map<std::string, std::string> m_in_memory_store;
        std::string m_file_path;
        std::mutex m;
};

int main()
{
    PersistentKV persistentKV("wal.txt");

    persistentKV.insert("one", "1");
    persistentKV.insert("two", "2");
    persistentKV.insert("three", "3");

    persistentKV.erase("two");

    auto value = persistentKV.get("one");

    if (value.has_value())
    {
        std::cout << value.value() << std::endl;
    }

    return 0;
}
