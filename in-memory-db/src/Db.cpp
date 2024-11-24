#include "Db.hpp"
#include <sstream>
#include <stdexcept>

bool Database::insert(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto result = data_.emplace(key, value);  // Insert a new key-value pair
    return result.second;  // Returns true if insertion was successful
}

bool Database::update(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = data_.find(key);  // Find the key
    if (it != data_.end()) {
        it->second = value;  // Update the value if key exists
        return true;
    }
    return false;  // Return false if key does not exist
}

bool Database::deleteRecord(const std::string& key) {
    std::lock_guard<std::mutex> lock(mutex_);
    return data_.erase(key) > 0;  // Erase and return whether a record was deleted
}

std::string Database::find(const std::string& key) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = data_.find(key);  // Find the key
    if (it != data_.end()) {
        return it->second;  // Return the value if found
    }
    return "";  // Return empty string if not found
}

void Database::clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    data_.clear();  // Clear all entries in the database
}

std::optional<std::string> Database::execute(const std::string& command) {
    std::istringstream ss(command);
    std::string action, key, value;
    ss >> action;  // Read the action (INSERT, UPDATE, etc.)

    if (action == "INSERT") {
        ss >> key;
        std::getline(ss, value);  // Get the value after the key
        value.erase(0, value.find_first_not_of(" "));  // Remove leading spaces
        if (insert(key, value)) {
            return "Inserted successfully";  // Return success message
        }
        else {
            return "Error: Key already exists";  // Error if the key already exists
        }
    }
    else if (action == "UPDATE") {
        ss >> key;
        std::getline(ss, value);  // Get the value after the key
        value.erase(0, value.find_first_not_of(" "));  // Remove leading spaces
        if (update(key, value)) {
            return "Updated successfully";  // Return success message
        }
        else {
            return "Error: Key not found";  // Error if the key does not exist
        }
    }
    else if (action == "DELETE") {
        ss >> key;
        if (deleteRecord(key)) {
            return "Deleted successfully";  // Return success message
        }
        else {
            return "Error: Key not found";  // Error if the key does not exist
        }
    }
    else if (action == "FIND") {
        ss >> key;
        std::string result = find(key);  // Get the value associated with the key
        if (!result.empty()) {
            return result;  // Return the value if found
        }
        else {
            return "Error: Key not found";  // Error if the key does not exist
        }
    }
    else if (action == "CLEAR") {
        clear();
        return "Database cleared";  // Clear all data and return success message
    }
    else {
        return "Error: Invalid command";  // Return error for unknown commands
    }
}
