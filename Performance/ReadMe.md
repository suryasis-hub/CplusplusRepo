###Overview###
This C++ program demonstrates the impact of memory access patterns on cache performance.

Specifically, it compares:

Sequential Access: Reading consecutive elements of an array.

Strided Access: Reading elements at regular strides (every 64th element).

Even though both access a similar number of elements, the memory access pattern dramatically affects execution time due to how CPU caches work.

Concepts Demonstrated
Cache Lines: Modern CPUs load 64-byte blocks from memory into cache. Sequential access fully utilizes each cache line; strided access wastes much of it.

Spatial Locality: Sequential memory access benefits from preloading nearby data, improving performance.

Cache Misses: Strided access increases cache misses, causing more expensive memory fetches from RAM.

Code Details
Array Setup:

A large array arr of size 64 million integers (roughly 256MB) is created and initialized to 1.

Sequential Access:

The program reads 1 out of every 64 elements sequentially (i++ from 0 to size/64).

Simulates tight spatial locality.

Strided Access:

The program reads elements with a stride of 64 (i += stride).

Simulates strided memory access that skips through the array.

Timing Measurement:

The chrono library measures elapsed time for both access patterns.

Results printed in milliseconds.

Expected Results
Sequential access should be faster than strided access.

Strided access causes more cache misses, leading to higher traversal time.

✅ Sequential access utilizes each loaded cache line efficiently.
❌ Strided access causes partial cache line usage and frequent misses.
