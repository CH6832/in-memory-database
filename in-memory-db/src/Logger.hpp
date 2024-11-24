/**
 * @file Logger.hpp
 * @brief Header for the Logger utility.
 */

#pragma once
#include <string>

class Logger {
public:
    /**
     * @brief Logs a message.
     * @param message The message to log.
     */
    static void log(const std::string& message);
};
