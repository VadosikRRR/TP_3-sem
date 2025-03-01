#include "include/handlers.hpp"
#include "include/constants.hpp"
#include <iostream>
#include <sstream>


HandlerCommandArguments::~HandlerCommandArguments() {}

HandlerCommandArguments::HandlerCommandArguments() : _message("") {}

std::string HandlerCommandArguments::GetMessage() {
    return _message;
}

void HandlerCommandArguments::SetMessage(std::string new_message) {
    _message = new_message;
}

HandlerAddArguments::HandlerAddArguments() : HandlerCommandArguments() {}

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
            _message = "BAD";
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
        _message = "BAD ARGUMENT";
    }
}

HandlerListArguments::HandlerListArguments() {}

void HandlerListArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (string_args != "") {
        _message = "BAD ARGUMENT";
        return;
    }

    if (windows.empty()) {
        _message = "Window manager does not have a window";
        return;
    }
    
    _message = "";
    for (Window &window : windows) {
        _message += window.GetInfo();
    }
}

HandlerMoveArguments::HandlerMoveArguments() {}

void HandlerMoveArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = "Window manager does not have a window";
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
            _message = "BAD";
            return;
        }

        if (x_coordinate < 0 ||
            y_coordinate < 0) {
            return;
        }
        
        windows.front().MoveWindow(Point(x_coordinate, y_coordinate));
    }
    catch(const std::exception& e) {
        _message = "BAD ARGUMENT";
    }
}

HandlerClickArguments::HandlerClickArguments() {}

void HandlerClickArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = "Window manager does not have a window";
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
            _message = "BAD";
            return;
        }

        if (x_coordinate < 0 ||
            y_coordinate < 0) {
            return;
        }
        
        Point point = Point(x_coordinate, y_coordinate);
        for (auto iter = windows.begin(); iter != windows.end(); iter++) {
            if (!iter->BelongWindowPoint(point)) {
                continue;
            }
            
            Window window = *iter;
            windows.erase(iter);
            windows.push_front(window);
            return;
        }
    }
    catch(const std::exception& e) {
        _message = "BAD ARGUMENT";
    }
}

HandlerDelArguments::HandlerDelArguments() {}

void HandlerDelArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (string_args != "") {
        _message = "BAD ARGUMENT";
        return;
    }

    if (windows.empty()) {
        _message = "Window manager does not have a window";
        return;
    }
    
    windows.pop_front();
}

HandlerChangeColorArguments::HandlerChangeColorArguments() {}

void HandlerChangeColorArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = "Window manager does not have a window";
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    if (arg2 != ARGUMENT_START_VALUE) {
        _message = "BAD ARGUMENT";
        return;
    }
    
    if (arg1 == BLACK) {
        windows.front().ChangeColor(BLACK_BACKGROUND);
    }
    else if (arg1 == RED){
        windows.front().ChangeColor(RED_BACKGROUND);
    }
    else if (arg1 == GREEN){
        windows.front().ChangeColor(GREEN_BACKGROUND);
    }
    else if (arg1 == YELLOW){
        windows.front().ChangeColor(YELLOW_BACKGROUND);
    }
    else if (arg1 == BLUE){
        windows.front().ChangeColor(BLUE_BACKGROUND);
    }
    else if (arg1 ==  PURPLE){
        windows.front().ChangeColor(BLUE_BACKGROUND);
    }
    else if (arg1 == CYAN){
        windows.front().ChangeColor(BLUE_BACKGROUND);
    }
    else if (arg1 == WHITE){
        windows.front().ChangeColor(BLUE_BACKGROUND);
    }
    else {
        _message = "BAD ARGUMENT";
    }
}

HandlerChangeBorderColorArguments::HandlerChangeBorderColorArguments() {}

void HandlerChangeBorderColorArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = "Window manager does not have a window";
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    if (arg2 != ARGUMENT_START_VALUE) {
        _message = "BAD ARGUMENT";
        return;
    }
    
    if (arg1 == BLACK) {
        windows.front().ChangeBorderColor(BLACK_BACKGROUND);
    }
    else if (arg1 == RED){
        windows.front().ChangeBorderColor(RED_BACKGROUND);
    }
    else if (arg1 == GREEN){
        windows.front().ChangeBorderColor(GREEN_BACKGROUND);
    }
    else if (arg1 == YELLOW){
        windows.front().ChangeBorderColor(YELLOW_BACKGROUND);
    }
    else if (arg1 == BLUE){
        windows.front().ChangeBorderColor(BLUE_BACKGROUND);
    }
    else if (arg1 ==  PURPLE){
        windows.front().ChangeBorderColor(BLUE_BACKGROUND);
    }
    else if (arg1 == CYAN){
        windows.front().ChangeBorderColor(BLUE_BACKGROUND);
    }
    else if (arg1 == WHITE){
        windows.front().ChangeBorderColor(BLUE_BACKGROUND);
    }
    else {
        _message = "BAD ARGUMENT";
    }
}

HandlerOpenArguments::HandlerOpenArguments() {}

void HandlerOpenArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = "Window manager does not have a window";
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    try {
        int id = std::stoi(arg1);

        if (arg2 != ARGUMENT_START_VALUE) {
            _message = "BAD ARGUMENT";
            return;
        }

        if (id < 0) {
            _message = "BAD ARGUMENT";
            return;
        }

        for (auto iter = windows.begin(); iter != windows.end(); iter++) {
            if (iter->GetId() != id) {
                continue;
            }
            
            Window window = *iter;
            windows.erase(iter);
            window.Open();
            windows.push_front(window);
            return;
        }

        _message = "BAD ARGUMENT";
    }
    catch(const std::exception& e) {
        _message = "BAD ARGUMENT";
    }
}

HandlerCloseArguments::HandlerCloseArguments() {}

void HandlerCloseArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = "Window manager does not have a window";
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    try {
        int id = std::stoi(arg1);

        if (arg2 != ARGUMENT_START_VALUE) {
            _message = "BAD ARGUMENT";
            return;
        }

        if (id < 0) {
            _message = "BAD ARGUMENT";
            return;
        }

        for (Window &window: windows) {
            if (window.GetId() != id) {
                continue;
            }

            window.Close();
            return;
        }

        _message = "BAD ARGUMENT";
    }
    catch(const std::exception& e) {
        _message = "BAD ARGUMENT";
    }
}