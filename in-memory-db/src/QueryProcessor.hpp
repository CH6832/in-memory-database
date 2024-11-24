/**
 * @file QueryProcessor.hpp
 * @brief Header for the QueryProcessor class.
 */

#pragma once
#include "Storage.hpp"
#include <string>

class QueryProcessor {
public:
    /**
     * @brief Processes a command string.
     * @param command The command to process.
     * @param storage The storage layer to interact with.
     * @return The result of the operation.
     */
    std::string process(const std::string& command, Storage& storage);
};
