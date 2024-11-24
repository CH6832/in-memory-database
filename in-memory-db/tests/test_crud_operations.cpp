#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <optional>
#include <chrono>
#include <unordered_map>
#include "../../in-memory-db/src/Db.hpp"
#include "../../in-memory-db/src/Storage.hpp"

// Unit test: Insert
TEST(CRUDOperationsTest, InsertRecord) {
    Database db;
    ASSERT_TRUE(db.insert("user2", "{\"name\": \"Bob\", \"age\": 25}"));
    ASSERT_EQ(db.find("user2"), "{\"name\": \"Bob\", \"age\": 25}");
}

// Unit test: Update
TEST(CRUDOperationsTest, UpdateRecord) {
    Database db;
    db.insert("user2", "{\"name\": \"Bob\", \"age\": 25}");
    ASSERT_TRUE(db.update("user2", "{\"name\": \"Bob\", \"age\": 26}"));
    ASSERT_EQ(db.find("user2"), "{\"name\": \"Bob\", \"age\": 26}");
}

// Unit test: Delete
TEST(CRUDOperationsTest, DeleteRecord) {
    Database db;
    ASSERT_TRUE(db.deleteRecord("user1"));
    ASSERT_EQ(db.find("user1"), "");
}

// Unit test: Find
TEST(CRUDOperationsTest, FindRecord) {
    Database db;
    ASSERT_EQ(db.find("user1"), "{\"name\": \"Alice\", \"age\": 30}");
    ASSERT_EQ(db.find("nonexistent"), "");
}

// Unit test: Duplicate Key Insertion
TEST(CRUDOperationsTest, DuplicateKeyInsert) {
    Database db;
    ASSERT_FALSE(db.insert("user1", "{\"name\": \"Charlie\"}"));
}
