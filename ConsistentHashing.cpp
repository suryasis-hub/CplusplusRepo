#include <iostream>
#include <map>
#include <string>

class ConsistentHashRing {
    private:
        std::map<std::size_t, std::string> m_u_map;
        std::size_t m_ring_size;
        int m_number_of_virtuals;

    
    public: 
        ConsistentHashRing(int ring_size, int m_number_of_virtuals) : m_ring_size(ring_size), m_number_of_virtuals(m_number_of_virtuals)
        {

        }

        void addServer(const std::string &server)
        {
            for (int i = 0 ; i < m_number_of_virtuals; i++) 
            {
                std::string new_server = server + std::to_string(i);
                std::size_t hash_result = std::hash<std::string>{}(new_server)%m_ring_size;
                m_u_map[hash_result] = server;
            }
        }

        void removeServer(const std::string& server)
        {
            for (int i = 0 ; i < m_number_of_virtuals; i++)
            {
                std::string new_server = server + std::to_string(i);
                std::size_t hash_result = std::hash<std::string>{}(new_server)%m_ring_size;
                m_u_map.erase(hash_result);
            }
        }
        
        std::string getAssignedServer(const std::string &user) 
        {
            
            if (m_u_map.size() == 0)
            {
                return "NOTHING";
            }
            std::size_t hash_result = std::hash<std::string>{}(user)%m_ring_size;
            auto last_node = m_u_map.end();
            last_node--;
            if (last_node->first < hash_result)
            {
                return  m_u_map.begin()->second;
            }
            /*
            std::string answer = "";
            for (auto key_value : m_u_map)
            {
                if (key_value.first > hash_result)
                {
                    answer = key_value.second;
                    break;
                }
            }
            */
           //std::cout<<m_u_map.lower_bound(hash_result)->second<<std::endl;
            return m_u_map.lower_bound(hash_result)->second;
        }
};


int main()
{
    ConsistentHashRing consistent_hashing(256,3);
    for (char ch = 'A'; ch <= 'C'; ++ch)
    {
        std::string server_name = "Server_";
        server_name += ch;
        consistent_hashing.addServer(server_name); 
    }
    std::unordered_map<std::string, std::string> original_map;
    for (char ch = 'a' ; ch <= 'z'; ++ch)
    {
        std::string user_name = "User_";
        user_name += ch;
        //std::cout<<"User name :"<<user_name<<" "<<"assigned to ";
        std::string assigned_server = consistent_hashing.getAssignedServer(user_name);
        std::cout<<assigned_server<<std::endl;
        original_map[user_name] = assigned_server;
    }
    consistent_hashing.addServer("Server_D");
    std::unordered_map<std::string, std::string> new_map; 
    for (char ch = 'a' ; ch <= 'z'; ++ch)
    {
        std::string user_name = "User_";
        user_name += ch;
       // std::cout<<"User name :"<<user_name<<" "<<"assigned to ";
        std::string assigned_server = consistent_hashing.getAssignedServer(user_name);
        std::cout<<assigned_server<<std::endl;
        new_map[user_name] = assigned_server;
    }
    for (auto keyvalue : original_map)
    {
        std::cout<<keyvalue.first<<" "<<keyvalue.second<<" "<<new_map[keyvalue.first]<<std::endl;
    }

    return 0;
}
