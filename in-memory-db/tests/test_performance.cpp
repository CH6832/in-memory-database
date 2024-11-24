#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <optional>
#include <chrono>
#include <unordered_map>
#include "../src/Db.hpp"
#include "../src/Storage.hpp"

// Benchmark: Insert Performance
TEST(PerformanceTest, InsertPerformance) {
    Database db;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 10000; i < 20000; ++i) {
        db.insert("key" + std::to_string(i), "{\"value\": " + std::to_string(i) + "}");
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Insert Performance: " << duration.count() << "ms" << std::endl;
}

// Benchmark: Read Performance
TEST(PerformanceTest, ReadPerformance) {
    Database db;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        db.find("key" + std::to_string(i));
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Read Performance: " << duration.count() << "ms" << std::endl;
}

// Benchmark: Update Performance
TEST(PerformanceTest, UpdatePerformance) {
    Database db;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        db.update("key" + std::to_string(i), "{\"value\": " + std::to_string(i * 2) + "}");
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Update Performance: " << duration.count() << "ms" << std::endl;
}
