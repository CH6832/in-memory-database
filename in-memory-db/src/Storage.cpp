/**
 * @file Storage.cpp
 * @brief Implementation of the in-memory data storage.
 */

#include "Storage.hpp"
#include <stdexcept>

 /**
  * @brief Inserts a record into a collection.
  */
void Storage::insert(const std::string& collection, const std::string& data) {
    collections[collection].push_back(data);
}
