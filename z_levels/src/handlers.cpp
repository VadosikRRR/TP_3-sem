#include "include/handlers.hpp"
#include "include/constants.hpp"
#include <iostream>
#include <sstream>


HandlerCommandArguments::~HandlerCommandArguments() {}

HandlerCommandArguments::HandlerCommandArguments() {}

HandlerAddArguments::HandlerAddArguments() {}

void HandlerAddArguments::Execute(std::list<Window> &windows, std::string string_args) {
    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::string arg3 = ARGUMENT_START_VALUE;
    std::string arg4 = ARGUMENT_START_VALUE;
    std::string arg5 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;
    try {
        int x_coordinate = std::stoi(arg1);
        int y_coordinate = std::stoi(arg2);
        int width = std::stoi(arg3);
        int height = std::stoi(arg4);
        if (arg5 != ARGUMENT_START_VALUE) {
            std::cout << "BAD" << std::endl;
            return;
        }

        if (x_coordinate < 0 ||
            y_coordinate < 0 ||
            width < 0 ||
            height < 0) {
            return;
        }
        
        windows.push_front(Window(Point(x_coordinate, y_coordinate), width, height));
    }
    catch(const std::exception& e) {
        std::cout << "BAD ARGUMENT" << std::endl;
    }
}

HandlerListArguments::HandlerListArguments() {}

void HandlerListArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (string_args != "") {
        std::cout << "BAD ARGUMENT" << std::endl;
        return;
    }

    for (Window &window : windows) {
        window.PrintInfo();
    }
}

HandlerMoveArguments::HandlerMoveArguments() {}

void HandlerMoveArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        std::cout << "Window manager does not have a window";
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::string arg3 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2 >> arg3;
    try {
        int x_coordinate = std::stoi(arg1);
        int y_coordinate = std::stoi(arg2);
        if (arg3 != ARGUMENT_START_VALUE) {
            std::cout << "BAD" << std::endl;
            return;
        }

        if (x_coordinate < 0 ||
            y_coordinate < 0) {
            return;
        }
        
        windows.front().MoveWindow(Point(x_coordinate, y_coordinate));
    }
    catch(const std::exception& e) {
        std::cout << "BAD ARGUMENT" << std::endl;
    }
}
