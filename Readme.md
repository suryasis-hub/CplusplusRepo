# 🚀 C++ Systems & AI Inference Engineering

A hands-on C++ repository for learning **systems programming, distributed systems, databases, concurrency, and AI inference infrastructure by implementing them from scratch**.

The objective is not simply to solve coding problems. It is to understand the engineering ideas that appear inside production systems by actually building simplified versions of them.

## 📊 Progress

**100 implementation projects**

* ✅ **Done** — implemented and understood
* 🟡 **Partial** — started / core implementation exists, but needs more work
* ⬜ **Todo** — not implemented yet

Current status:

**✅ 7 Done · 🟡 3 In Progress · ⬜ 90 Todo**

---

# 🧠 Part I — C++ & Systems Engineering

## 1. Core Data Structures & Infrastructure

| #  | Status | Implementation                        |
| -- | :----: | ------------------------------------- |
| 1  |    ✅   | Bloom Filter                          |
| 2  |    ✅   | Token Bucket Rate Limiter             |
| 3  |    ✅   | Sliding Window Rate Limiter           |
| 4  |    ✅   | Consistent Hash Ring                  |
| 5  |    ✅   | Consistent Hashing with Virtual Nodes |
| 6  |    ✅   | LRU Cache                             |
| 7  |    ⬜   | LFU Cache                             |
| 8  |    ⬜   | TTL Cache                             |
| 9  |   🟡   | Producer / Consumer Bounded Queue     |
| 10 |   🟡   | Bounded Thread Pool with Backpressure |
| 11 |    ⬜   | Sharded Concurrent Hash Map           |
| 12 |    ⬜   | Object Pool                           |
| 13 |    ⬜   | Memory Pool / Arena Allocator         |
| 14 |    ⬜   | Lock-Free SPSC Queue                  |
| 15 |    ⬜   | MPMC Concurrent Queue                 |

---

## 2. Distributed Systems Building Blocks

| #  | Status | Implementation                          |
| -- | :----: | --------------------------------------- |
| 16 |   🟡   | Snowflake Distributed ID Generator      |
| 17 |    ⬜   | Circuit Breaker                         |
| 18 |    ⬜   | Retry with Exponential Backoff + Jitter |
| 19 |    ⬜   | Heartbeat-Based Failure Detector        |
| 20 |    ⬜   | Gossip Membership Protocol              |
| 21 |    ⬜   | Lamport Logical Clock                   |
| 22 |    ⬜   | Vector Clock                            |
| 23 |    ⬜   | Leader Election Simulation              |
| 24 |    ⬜   | Distributed Lease                       |
| 25 |    ⬜   | Distributed Lock                        |
| 26 |    ⬜   | Replicated Log                          |
| 27 |    ⬜   | Primary–Replica KV Store                |
| 28 |    ⬜   | Quorum Read / Write KV Store            |
| 29 |    ⬜   | Read Repair                             |
| 30 |    ⬜   | Anti-Entropy Synchronization            |
| 31 |    ⬜   | Raft Leader Election                    |
| 32 |    ⬜   | Raft Log Replication                    |

---

## 3. Storage & Database Internals

| #  | Status | Implementation                       |
| -- | :----: | ------------------------------------ |
| 33 |    ✅   | WAL-backed Persistent KV Store       |
| 34 |    ⬜   | WAL Snapshotting                     |
| 35 |    ⬜   | WAL Compaction / Checkpointing       |
| 36 |    ⬜   | Crash-Safe WAL with Record Checksums |
| 37 |    ⬜   | Fixed-Size Database Pages            |
| 38 |    ⬜   | Slotted Page Layout                  |
| 39 |    ⬜   | Buffer Pool Manager                  |
| 40 |    ⬜   | B+ Tree                              |
| 41 |    ⬜   | Disk-Backed B+ Tree                  |
| 42 |    ⬜   | Mini SQL Parser                      |
| 43 |    ⬜   | SQL Execution Engine                 |
| 44 |    ⬜   | Table Scan + Index Scan              |
| 45 |    ⬜   | MemTable                             |
| 46 |    ⬜   | SSTable                              |
| 47 |    ⬜   | LSM Tree                             |
| 48 |    ⬜   | LSM Compaction                       |
| 49 |    ⬜   | MVCC / Versioned Records             |
| 50 |    ⬜   | Mini Transactional Database          |

---

# 🤖 Part II — AI Inference Systems

The second half focuses specifically on the infrastructure behind **production AI inference engines and model-serving systems**.

---

## 4. Tensors, Models & Execution

| #  | Status | Implementation                          |
| -- | :----: | --------------------------------------- |
| 51 |    ⬜   | Tensor Class — Shape, Stride & Storage  |
| 52 |    ⬜   | Tensor Views without Copying            |
| 53 |    ⬜   | Tensor Memory Arena                     |
| 54 |    ⬜   | Computational Graph Representation      |
| 55 |    ⬜   | Operator Interface / Kernel Abstraction |
| 56 |    ⬜   | Graph Topological Executor              |
| 57 |    ⬜   | Model Serialization / Deserialization   |
| 58 |    ⬜   | Constant Folding                        |
| 59 |    ⬜   | Dead Node Elimination                   |
| 60 |    ⬜   | Operator Fusion                         |

---

## 5. AI Operator Implementations

| #  | Status | Implementation                      |
| -- | :----: | ----------------------------------- |
| 61 |    ⬜   | Naive Matrix Multiplication         |
| 62 |    ⬜   | Cache-Aware Matrix Multiplication   |
| 63 |    ⬜   | Multithreaded Matrix Multiplication |
| 64 |    ⬜   | SIMD Matrix Operations              |
| 65 |    ⬜   | Convolution Operator                |
| 66 |    ⬜   | ReLU / Activation Operators         |
| 67 |    ⬜   | Softmax                             |
| 68 |    ⬜   | Layer Normalization                 |
| 69 |    ⬜   | Embedding Lookup                    |
| 70 |    ⬜   | Quantization — FP32 → INT8          |

---

## 6. Model Runtime & Memory Planning

| #  | Status | Implementation                     |
| -- | :----: | ---------------------------------- |
| 71 |    ⬜   | INT8 Dequantization                |
| 72 |    ⬜   | Static Tensor Memory Planner       |
| 73 |    ⬜   | Tensor Lifetime Analysis           |
| 74 |    ⬜   | Reuse Intermediate Tensor Buffers  |
| 75 |    ⬜   | CPU Backend Interface              |
| 76 |    ⬜   | Accelerator Backend Abstraction    |
| 77 |    ⬜   | Model Partitioning Across Backends |
| 78 |    ⬜   | Asynchronous Inference Request     |
| 79 |    ⬜   | Multi-Model Runtime                |
| 80 |    ⬜   | Model Hot Reloading                |

---

## 7. AI Serving & Scheduling

| #  | Status | Implementation                      |
| -- | :----: | ----------------------------------- |
| 81 |    ⬜   | Dynamic Batching                    |
| 82 |    ⬜   | Batch Timeout Scheduler             |
| 83 |    ⬜   | Priority-Based Inference Scheduler  |
| 84 |    ⬜   | Multi-Model Scheduler               |
| 85 |    ⬜   | Admission Control                   |
| 86 |    ⬜   | Request Cancellation / Deadlines    |
| 87 |    ⬜   | Inference Load Shedding             |
| 88 |    ⬜   | Model Worker Pool                   |
| 89 |    ⬜   | Inference Request Queue             |
| 90 |    ⬜   | End-to-End Model Serving Simulation |

---

## 8. LLM & Production Inference

| #   | Status | Implementation                            |
| --- | :----: | ----------------------------------------- |
| 91  |    ⬜   | Transformer KV Cache                      |
| 92  |    ⬜   | KV Cache Memory Manager                   |
| 93  |    ⬜   | Paged KV Cache                            |
| 94  |    ⬜   | Continuous Batching                       |
| 95  |    ⬜   | Prefix / Prompt Cache                     |
| 96  |    ⬜   | Speculative Decoding Simulation           |
| 97  |    ⬜   | Tensor Parallelism Simulation             |
| 98  |    ⬜   | Pipeline Parallelism Simulation           |
| 99  |    ⬜   | Inference Latency + Memory Profiler       |
| 100 |    ⬜   | Production-Style Mini AI Inference Server |

---

# 🏗️ Larger Systems to Eventually Build

Individual implementations should eventually compose into larger systems.

### Distributed Service

```text
Client
   ↓
Rate Limiter
   ↓
Request Queue
   ↓
Thread Pool
   ↓
Cache
   ↓
Replicated KV Store
   ↓
Persistent WAL
```

### AI Inference Service

```text
Request
   ↓
Tokenizer
   ↓
Dynamic Batcher
   ↓
Scheduler
   ↓
Model Runtime
   ↓
Tensor Memory Planner
   ↓
CPU / GPU / NPU Backend
   ↓
KV Cache
   ↓
Response
```

---

# 🎯 Why This Repository Exists

Reading about systems such as rate limiters, databases, distributed caches, schedulers, or inference runtimes gives a useful overview.

Implementing them forces deeper questions:

* What state actually needs to be stored?
* What happens when multiple threads modify it?
* What happens when the process crashes?
* What happens when a machine disappears?
* Where does contention occur?
* What data structure makes the operation efficient?
* What assumptions stop working at scale?
* What trade-offs would a production implementation make differently?

The repository is therefore intended as an evolving **engineering laboratory**, rather than a collection of polished production libraries.

---

# 📈 Current Focus

The progression so far:

```text
Bloom Filter
     ↓
Rate Limiting
     ↓
Consistent Hashing
     ↓
Caching
     ↓
Concurrency / Queues
     ↓
Persistence + WAL
     ↓
Distributed IDs
     ↓
Database Internals
     ↓
Distributed Systems
     ↓
AI Inference Runtime
```

The long-term objective is to develop strong intuition for the systems that sit underneath modern distributed applications and production AI infrastructure.
