/**
 * @file Storage.hpp
 * @brief Header for the in-memory storage system.
 */

#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class Storage {
private:
    std::unordered_map<std::string, std::vector<std::string>> collections;

public:
    /**
     * @brief Inserts a document into a collection.
     * @param collection The name of the collection.
     * @param data The document data (JSON string).
     */
    void insert(const std::string& collection, const std::string& data);
};
