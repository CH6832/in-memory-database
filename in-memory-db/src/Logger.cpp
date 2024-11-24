/**
 * @file Logger.cpp
 * @brief Simple logging utility.
 */

#include "Logger.hpp"
#include <iostream>
#include <fstream>

 /**
  * @brief Logs a message to the console and a file.
  */
void Logger::log(const std::string& message) {
    std::ofstream logFile("logs.txt", std::ios::app);
    logFile << message << "\n";
    std::cout << "[LOG]: " << message << "\n";
}
