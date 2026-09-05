#include <cstddef>
#include <string>
#include <vector>
#include <functional>

class BloomFilter {
public:
    BloomFilter(std::size_t numBits, std::size_t numHashes)
        : m_num_bits(numBits), m_num_hashes(numHashes) {
        binary_array = std::vector<bool>(m_num_bits, false);
    }

    void insert(const std::string& value) {
        std::size_t h1 = std::hash<std::string>{}(value);
        std::size_t h2 = std::hash<std::string>{}(salt_value + value);

        for (std::size_t i = 0; i < m_num_hashes; ++i) {
            std::size_t index =
                (h1 + i * h2) % m_num_bits;

            binary_array[index] = true;
        }
    }

    bool contains(const std::string& value) {
        std::size_t h1 = std::hash<std::string>{}(value);
        std::size_t h2 = std::hash<std::string>{}(salt_value + value);

        for (std::size_t i = 0; i < m_num_hashes; ++i) {
            std::size_t index =
                (h1 + i * h2) % m_num_bits;

            if (!binary_array[index]) {
                return false;
            }
        }

        return true;
    }

private:
    std::size_t m_num_bits;
    std::size_t m_num_hashes;

    std::vector<bool> binary_array;

    const std::string salt_value = "bloom_filter_salt";
};
