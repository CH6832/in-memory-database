### **System Documentation** (SystemDocumentation.md)

# In-Memory Database System Documentation

## Table of Contents
- [In-Memory Database System Documentation](#in-memory-database-system-documentation)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [System Architecture](#system-architecture)
    - [Key Modules](#key-modules)
  - [Design Details](#design-details)
    - [Core Components](#core-components)
      - [Command-Line Interface (CLI)](#command-line-interface-cli)
      - [Query Processor](#query-processor)
      - [Data Storage Model](#data-storage-model)
    - [Query Execution](#query-execution)
      - [CRUD Operations Workflow](#crud-operations-workflow)
  - [Concurrency and Performance](#concurrency-and-performance)
  - [Error Handling and Logging](#error-handling-and-logging)
  - [Build and Deployment](#build-and-deployment)
    - [Build Instructions](#build-instructions)
    - [Deployment](#deployment)
  - [Testing and Benchmarking](#testing-and-benchmarking)
    - [Unit Tests](#unit-tests)
    - [Integration Tests](#integration-tests)
    - [Performance Benchmarks](#performance-benchmarks)

---

## Introduction

The In-Memory Database (IMDB) is a high-performance, command-line tool designed to handle CRUD (Create, Read, Update, Delete) operations with low latency. The database operates entirely in RAM, making it suitable for real-time applications like caching, analytics, and gaming.

This document outlines the architecture, design, and technical details for developers and contributors.

---

## System Architecture

The IMDB follows a modular architecture with three main layers:

```
+--------------------+
|  User Interface    | <- CLI Input Parser
+--------------------+
| Query Processing   | <- Validation, Parsing, Execution
+--------------------+
| Data Storage Layer | <- In-Memory Storage
+--------------------+
```

### Key Modules
1. **Command-Line Interface (CLI)**:
   - Accepts user commands in a MongoDB-like syntax.
   - Provides feedback and error messages.

2. **Query Processor**:
   - Parses and validates commands.
   - Executes operations (e.g., CRUD).

3. **Data Storage Layer**:
   - Manages in-memory storage using hashmaps and vectors for efficiency.

---

## Design Details

### Core Components

#### Command-Line Interface (CLI)
- **Input**: User commands (`insert`, `find`, `update`, `delete`) are processed in a syntax similar to MongoDB JSON queries.
- **Output**: Feedback or query results in JSON-like format.

#### Query Processor
- **Validation**: Ensures the query follows supported syntax.
- **Parsing**: Breaks down commands into operations for the storage layer.
- **Execution**: Invokes appropriate methods for CRUD operations.

#### Data Storage Model
- Uses a `std::unordered_map` for collections.
- Each collection contains records stored as key-value pairs (`std::unordered_map<string, json>`).
- Data is structured in a document-like model similar to MongoDB.

---

### Query Execution

#### CRUD Operations Workflow
1. **Insert**:
    - Validates schema.
    - Adds a document to the collection.

2. **Find**:
    - Accepts filter criteria.
    - Scans and retrieves matching records.

3. **Update**:
    - Updates specific fields in matching documents.

4. **Delete**:
    - Removes matching records.

---

## Concurrency and Performance

The system leverages **modern C++ features** for concurrency:
- **Multithreading**: Operations like `find` are parallelized using worker threads.
- **Read-Write Locking**: Uses `std::shared_mutex` to allow simultaneous reads while protecting writes.
- **Lock-Free Data Structures**: The design aims to minimize locks using libraries like Boost Lockfree.

Performance optimization includes:
- Compiler flags (`/O2` for MSVC, `-O3` for GCC/Clang).
- Memory pools for efficient allocations.
- Profiling and benchmarking with tools like Google Benchmark.

---

## Error Handling and Logging

- **Exception Handling**: All critical operations are wrapped in try-catch blocks.
- **Logging**:
    - Uses a basic logging mechanism with levels (INFO, WARN, ERROR).
    - Errors are written to a log file (`errors.log`).

---

## Build and Deployment

### Build Instructions
1. **Install Dependencies**: C++17 or higher, CMake 3.20+, Visual Studio 2022.
2. **Build**:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```
3. **Run**:
   ```bash
   ./build/inmemorydb
   ```

### Deployment
- Ensure the system has sufficient RAM for the expected dataset size.
- Optionally configure logging paths.

---

## Testing and Benchmarking

### Unit Tests
- Cover CRUD operations, input validation, and edge cases.
- Framework: Google Test.

### Integration Tests
- Test the interaction between CLI, Query Processor, and Storage Layer.

### Performance Benchmarks
- Measure CRUD operation latency and throughput.
- Benchmark Tools: Google Benchmark, Visual Studio Profiler.

---
