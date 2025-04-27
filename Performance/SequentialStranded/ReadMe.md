***Overview***
This C++ program demonstrates the impact of memory access patterns on cache performance.

Specifically, it compares:

**Sequential Access**: Reading consecutive elements of an array.

**Strided Access**: Reading elements at regular strides (every 64th element).
Even though both access a similar number of elements, the memory access pattern dramatically affects execution time due to how CPU caches work.
Concepts Demonstrated

**Cache Lines**: Modern CPUs load 64-byte blocks from memory into cache. Sequential access fully utilizes each cache line; strided access wastes much of it.

**Spatial Locality**: Sequential memory access benefits from preloading nearby data, improving performance.

**Cache Misses**: Strided access increases cache misses, causing more expensive memory fetches from RAM.

**Expected Results**
Sequential access should be faster than strided access.
Strided access causes more cache misses, leading to higher traversal time.

✅ Sequential access utilizes each loaded cache line efficiently.

❌ Strided access causes partial cache line usage and frequent misses.
