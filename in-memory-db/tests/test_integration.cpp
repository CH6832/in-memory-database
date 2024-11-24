#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <optional>
#include <chrono>
#include <unordered_map>
#include "../../in-memory-db/src/Db.hpp"
#include "../../in-memory-db/src/Storage.hpp"

// Integration test: CRUD Workflow
TEST(IntegrationTest, CRUDWorkflow) {
    Database db;
    ASSERT_TRUE(db.insert("user1", "{\"name\": \"Alice\", \"age\": 30}"));
    ASSERT_EQ(db.find("user1"), "{\"name\": \"Alice\", \"age\": 30}");
    ASSERT_TRUE(db.update("user1", "{\"name\": \"Alice\", \"age\": 31}"));
    ASSERT_EQ(db.find("user1"), "{\"name\": \"Alice\", \"age\": 31}");
    ASSERT_TRUE(db.deleteRecord("user1"));
    ASSERT_EQ(db.find("user1"), "");
}

// Integration test: Bulk Insert and Query
TEST(IntegrationTest, BulkInsertAndQuery) {
    Database db;
    for (int i = 0; i < 1000; ++i) {
        ASSERT_TRUE(db.insert("key" + std::to_string(i), "{\"value\": " + std::to_string(i) + "}"));
    }
    for (int i = 0; i < 1000; ++i) {
        ASSERT_EQ(db.find("key" + std::to_string(i)), "{\"value\": " + std::to_string(i) + "}");
    }
}
