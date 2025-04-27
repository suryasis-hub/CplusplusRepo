#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    const int stride = 64;
    const int size = 1024 * 1024 * 64; // same big size
    vector<int> arr(size, 1);
    
    volatile int sum = 0;
    
    // Sequential Access
    auto start = high_resolution_clock::now();
    for (int i = 0; i < (size/64); i++)
        sum += arr[i];
    auto end = high_resolution_clock::now();
    cout << "Sequential: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    
    // Strided Access with same total work
    sum = 0;
    start = high_resolution_clock::now();
    for (int i = 0; i < size; i+=stride) {
        sum += arr[i]; // access scattered elements
    }
    end = high_resolution_clock::now();
    cout << "Strided but same work: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
}
