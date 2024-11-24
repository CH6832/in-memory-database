/**
 * @file QueryProcessor.cpp
 * @brief Implementation of query parsing and execution.
 */

#include "QueryProcessor.hpp"
#include "Logger.hpp"
#include <sstream>
#include <stdexcept>

 /**
  * @brief Processes a user command and interacts with the storage layer.
  */
std::string QueryProcessor::process(const std::string& command, Storage& storage) {
    // Example: Parsing and processing an 'insert' command
    if (command.find("insert") == 0) {
        Logger::log("Parsing 'insert' command.");

        // Parse logic (mocked for simplicity)
        std::string collection = "default";
        std::string data = "{}";

        // Perform the insert operation
        storage.insert(collection, data);
        return "Insert successful.";
    }

    throw std::runtime_error("Unsupported command.");
}
