#include <iostream>
#include <sstream>


int main() {
    while (true) {
        std::string input;
        std::cout << "> ";
        if (std::getline(std::cin, input)) {
            std::istringstream iss(input);
            std::string command;
            std::string argv1 = "BAN";
            std::string argv2 = "BAN";
            iss >> command >> argv1 >> argv2;
            std::cout << argv1 << std::endl;
            std::cout << argv2 << std::endl;
        }
    }
}
