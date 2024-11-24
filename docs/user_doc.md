
### **User Documentation** (UserGuide.md)

```markdown
# In-Memory Database User Guide

## Table of Contents
1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Commands and Syntax](#commands-and-syntax)
    - [Insert](#insert)
    - [Find](#find)
    - [Update](#update)
    - [Delete](#delete)
4. [Advanced Features](#advanced-features)
5. [FAQs and Troubleshooting](#faqs-and-troubleshooting)

---

## Introduction

The In-Memory Database (IMDB) is a command-line tool for storing and managing data in RAM. It supports CRUD operations and is designed for applications requiring low-latency data access.

---

## Getting Started

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/example/inmemorydb.git
   ```
2. Build the project (C++17 and CMake required):
   ```bash
   cmake -S . -B build
   cmake --build build
   ```
3. Run the tool:
   ```bash
   ./build/inmemorydb
   ```

---

## Commands and Syntax

### **Insert**
Add a new record to a collection.
```bash
insert {"collection": "users", "data": {"id": 1, "name": "Alice", "age": 30}}
```
- **collection**: Name of the collection.
- **data**: JSON document.

### **Find**
Retrieve records matching a filter.
```bash
find {"collection": "users", "filter": {"age": {"$gt": 25}}}
```
- **filter**: JSON-like query criteria.

### **Update**
Update records matching a filter.
```bash
update {"collection": "users", "filter": {"id": 1}, "update": {"$set": {"age": 31}}}
```
- **update**: Specifies modifications (e.g., `$set`, `$inc`).

### **Delete**
Remove records matching a filter.
```bash
delete {"collection": "users", "filter": {"id": 1}}
```

---

## Advanced Features

1. **Concurrency**: Supports simultaneous reads and writes.
2. **Schema-Less Storage**: Flexible document model.
3. **Logging**: Errors are logged to `errors.log`.

---

## FAQs and Troubleshooting

1. **How do I handle memory limits?**
   - Ensure your system has sufficient RAM or reduce dataset size.

2. **How do I view logs?**
   - Check the `errors.log` file in the working directory.

3. **Why is my query slow?**
   - Optimize your filter criteria and reduce collection size.

---
