# In-Memory Database

This is a high-performance, in-memory database written in **C++20**. It supports basic CRUD operations (Create, Read, Update, Delete) and can be controlled via a simple **command-line interface (CLI)**. This database is optimized for low-latency, high-frequency operations, making it ideal for high-performance applications that need fast, in-memory data processing.

---

## Features

- **CRUD Operations**: Insert, Update, Delete, Find
- **Command-Line Interface**: Interact with the database using simple commands
- **Thread Safety**: Mutex-based locking for thread safety during concurrent access
- **Performance Optimized**: Low-latency operations suitable for high-frequency environments

---

## Requirements

- **C++20** or higher
- **CMake** 3.10 or higher
- **Google Test** for unit and integration testing
- **vcpkg** or similar package manager for dependency management

---

## Building the Project

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/in-memory-db.git
cd in-memory-db
```

### 2. Install Dependencies

Install dependencies using **vcpkg** or your preferred package manager. For example, with **vcpkg**:

```bash
./vcpkg install fmt gtest
```

### 3. Build the Project

Generate the build files using **CMake** and build the project:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This will compile both the database application and the test suite.

---

## Running the Database

### 1. Launch the Database CLI

To start the in-memory database application, run:

```bash
./in-memory-db
```

### 2. Example Commands

Once the application is running, you can interact with it using the following commands:

#### Insert a Key-Value Pair

```bash
INSERT key1 value1
```

- This will insert a new key-value pair into the database.
- **Response**: `Inserted: key1 -> value1`

#### Update an Existing Key-Value Pair

```bash
UPDATE key1 new_value
```

- This will update the value associated with the key `key1`.
- **Response**: `Updated: key1 -> new_value`

#### Delete a Key-Value Pair

```bash
DELETE key1
```

- This will delete the key-value pair associated with `key1`.
- **Response**: `Deleted: key1`

#### Find a Key-Value Pair

```bash
FIND key1
```

- This will return the value associated with `key1`, or an empty response if not found.
- **Response**: `Found: key1 -> value1` or `Key not found`

#### Clear All Records

```bash
CLEAR
```

- This will remove all key-value pairs from the database.
- **Response**: `Database cleared`

---

## Example Usage

Here is a simple example of interacting with the database:

```bash
Welcome to the In-Memory Database. Type commands (INSERT, UPDATE, DELETE, FIND, CLEAR):
> INSERT user1 Alice
Inserted: user1 -> Alice

> FIND user1
Found: user1 -> Alice

> UPDATE user1 Bob
Updated: user1 -> Bob

> DELETE user1
Deleted: user1

> FIND user1
Key not found

> CLEAR
Database cleared
```

---

## Testing

### Unit Tests

The project includes unit tests to ensure the functionality of the database operations. You can run the tests with:

```bash
cmake --build . --target tests
./tests
```

### Integration Tests

Integration tests are also provided to verify the behavior of the system as a whole. These tests ensure that the database interacts correctly with its components under real-world conditions.

---

## Contributions

Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository, create a feature branch, and submit a pull request.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

## Acknowledgements

- **C++ Standard Library**: For providing the core data structures and utilities.
- **Google Test**: For providing a framework for testing.
- **vcpkg**: For simplifying the management of third-party libraries.
