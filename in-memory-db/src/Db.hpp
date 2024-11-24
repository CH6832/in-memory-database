#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <unordered_map>
#include <string>
#include <mutex>
#include <optional>
#include <iostream> // For logging (if needed)

class Database {
public:
    // Inserts a key-value pair, returns true if successful, false if key already exists
    bool insert(const std::string& key, const std::string& value);

    // Updates an existing key with a new value
    bool update(const std::string& key, const std::string& value);

    // Deletes a key-value pair by key
    bool deleteRecord(const std::string& key);

    // Finds a value by its key
    std::string find(const std::string& key) const;

    // Clears all data from the database
    void clear();

    // Executes a database command (e.g., "INSERT key value")
    std::optional<std::string> execute(const std::string& command);

private:
    std::unordered_map<std::string, std::string> data_;  // Stores the key-value pairs
    mutable std::mutex mutex_;  // Mutex for thread-safe access

    // Helper method for parsing the key and value from the input command
    std::pair<std::string, std::string> parseKeyValue(const std::string& input) const;
};

#endif // DATABASE_HPP
