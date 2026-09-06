#include <cstddef>
#include <chrono>
#include <mutex>
#include <iostream>
#include <thread>

class TokenBucket
{
    public: 
        TokenBucket(std::size_t capacity, std::size_t refill_per_seconds): m_capacity(capacity), m_refill_per_seconds(refill_per_seconds), m_current_tokens(capacity) 
        {
            m_last_refill_time =  std::chrono::steady_clock::now();
        }
    

        bool allow(std::string request, int n)
        {
            std::lock_guard<std::mutex>> lg(m);
            auto elapsed = std::chrono::steady_clock::now() - m_last_refill_time;
            auto refill_amount = size_t(std::chrono::duration<double>(elapsed).count()*m_refill_per_seconds);
            if (refill_amount > 0)
            {
                m_last_refill_time = std::chrono::steady_clock::now();
                m_current_tokens = std::min(m_capacity, m_current_tokens + refill_amount);
            }
            std::cout<<"Current refill : "<<refill_amount<<" token count: "<<m_current_tokens<<std::endl;
            if (m_current_tokens >= n)
            {
              m_current_tokens-=n;
              std::cout<<"Request accepted: "<<request<<std::endl;
              return true;  
            }
            else
            {   
                std::cout<<"Request denied:  "<<request<<std::endl;
                return false;
            }
              
        }

         bool allow(std::string request)
         {
            return allow(request, 1);
         }

    private:
        std::size_t m_capacity;
        std::size_t m_current_tokens;
        double m_refill_per_seconds;
        std::chrono::steady_clock::time_point m_last_refill_time;
        std::mutex m;
        
};

int main()
{
    TokenBucket tokenBucket(2, 1);
    int count_of_accepted = 0;
    for (int i = 0 ; i < 100 ; i++)
    {
        if (tokenBucket.allow("Request: "+std::to_string(i)))
        {
            count_of_accepted++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout<<"Accepted count: "<<count_of_accepted<<std::endl;
    return 0;
}
