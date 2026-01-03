/*
===============================================================================
Benchmark: Contiguous Objects vs Pointer-Based Objects (Memory Locality Study)
===============================================================================

Purpose
-------
This benchmark compares the *runtime cost of memory access* for two common
data layouts in C++:

  1) std::vector<Obj>     — contiguous, value-based storage
  2) std::vector<Obj*>    — pointer-based storage with heap allocation

The goal is NOT to measure raw allocation time, but to understand how
*memory locality* and *pointer chasing* affect performance at scale.

Why this benchmark exists
-------------------------
Dynamic memory allocation often appears cheap in microbenchmarks.
However, its real cost shows up during *repeated access* due to:

  - Cache misses
  - TLB pressure
  - Loss of spatial locality
  - Pointer indirection

This benchmark demonstrates that effect by isolating and amplifying
memory access cost.

Benchmark structure
-------------------
1) Allocation phase (NOT timed for output)
   - Allocate 5,000,000 objects contiguously (vector<Obj>)
   - Allocate 5,000,000 objects individually on the heap (vector<Obj*>)

2) Access phase (timed)
   - Repeatedly iterate over the data 400 times
   - Read a single integer field (Obj::a) from each element
   - Accumulate into a volatile variable to prevent dead-code elimination

Why these design choices
------------------------
- Large working set ensures data exceeds CPU caches
- Repetition amortizes timer overhead and noise
- volatile 'sum' forces real memory loads
- Allocation and access are separated to avoid mixed signals
- steady_clock is used for monotonic timing

What this benchmark shows
-------------------------
- Contiguous storage (vector<Obj>) benefits from:
    * Sequential access
    * Hardware prefetching
    * Fewer cache/TLB misses

- Pointer-based storage (vector<Obj*>) suffers from:
    * Pointer chasing
    * Scattered memory access
    * Reduced cache efficiency

Expected outcome
----------------
vector<Obj> should consistently outperform vector<Obj*> during iteration,
even if allocation time initially appears similar.

This demonstrates why dynamic allocation and pointer-heavy designs scale
poorly in performance-critical systems.

Notes
-----
- This benchmark is single-threaded
- Results are architecture and allocator dependent
- Absolute times matter less than relative trends

References
----------
- "The Price of Dynamic Memory Allocation" — Johnny's Software Lab
- Data-Oriented Design principles
- CPU cache hierarchy behavior

===============================================================================
*/
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

struct Obj
{
        int a, b, c ,d;
        Obj():a(1), b(2), c(3), d(4)
        {
                //std::cout<<"Object constructor called"<<std::endl;
        }
};

int main()
{
        volatile int sum = 0;
        auto start = std::chrono::steady_clock::now();
        vector<Obj> vec(5000000);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_nano_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        //std::cout<<elapsed_nano_seconds.count()<<std::endl;

        start =  std::chrono::steady_clock::now();
        vector<Obj*> vec1(5000000);
        for (int i = 0 ; i < 5000000 ; i++)
        {
                vec1[i] = new Obj();
        }
        end = std::chrono::steady_clock::now();
        auto elapsed_nano_seconds_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        //std::cout<<elapsed_nano_seconds_2.count()<<std::endl;

        start = std::chrono::steady_clock::now();
        for(int j = 0 ; j < 400 ; j++)
        {
                for (int i = 0 ; i < 5000000; ++i)
                {
                        sum += vec[i].a;
                }
        }
        end = std::chrono::steady_clock::now();
        elapsed_nano_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout<<elapsed_nano_seconds.count()<<std::endl;

        start = std::chrono::steady_clock::now();
        for(int j = 0 ; j < 400 ; j++)
        {
                for (int i = 0 ; i < 5000000; ++i)
                {
                         sum += vec1[i]->a;

                }
        }
        end = std::chrono::steady_clock::now();
        elapsed_nano_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout<<elapsed_nano_seconds.count()<<std::endl;
        return 0;
}
