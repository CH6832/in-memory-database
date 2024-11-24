#include <iostream>
#include "src/Db.hpp"

int main() {
    Database db;

    std::cout << "Welcome to the In-Memory Database. Type commands (INSERT, UPDATE, DELETE, FIND, CLEAR):\n";

    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "EXIT") {
            break;
        }

        auto result = db.execute(command);
        if (result.has_value()) {
            std::cout << result.value() << std::endl;
        }
        else {
            std::cout << "Error: Invalid command" << std::endl;
        }
    }

    return 0;
}
