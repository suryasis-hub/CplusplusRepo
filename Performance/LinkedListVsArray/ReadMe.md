# Linked List vs Array Traversal Benchmark

This project demonstrates the performance difference between traversing a **linked list** and an **array** in C++.

Even though both data structures contain the same number of integers and perform the same logical work (summing elements), **memory access patterns** significantly affect performance because of **CPU caching behavior**.

---

## 📚 Concepts Demonstrated

- **Cache Lines**: CPUs fetch memory in 64-byte chunks, not byte-by-byte.
- **Spatial Locality**: Accessing nearby memory addresses is much faster.
- **Prefetching**: Arrays allow the CPU to preload data efficiently; linked lists break prefetching.
- **Cache Misses**: Random memory accesses cause expensive stalls.

---

## 🛠 How It Works

1. **Array Setup**:
   - A `vector<int>` with 20 million elements initialized to `1`.

2. **Linked List Setup**:
   - A singly linked list with 20 million nodes, each storing `1`.

3. **Benchmarking**:
   - Measure time to traverse and sum all elements in the array.
   - Measure time to traverse and sum all elements in the linked list.

4. **Memory Cleanup**:
   - Properly deallocate the linked list to avoid memory leaks.

---

## 📈 Expected Behavior

- **Array traversal** should be significantly **faster**.
- **Linked list traversal** will be **slower** due to cache misses and pointer chasing.

✅ **Sequential access** (arrays) = cache-friendly = fast.  
❌ **Random pointer chasing** (linked list) = cache-miss-prone = slow.

---

## 🧪 Sample Output

```plaintext
Array Traversal: 50 ms
Linked List Traversal: 90 ms
