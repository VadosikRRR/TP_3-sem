#include "include/handlers.hpp"
#include "include/constants.hpp"
#include <iostream>
#include <sstream>


HandlerCommandArguments::~HandlerCommandArguments() {}

HandlerCommandArguments::HandlerCommandArguments(int new_width, int new_height) : _main_width(new_width), _main_height(new_height), _message("") {}

std::string HandlerCommandArguments::GetMessage() {
    return _message;
}

void HandlerCommandArguments::SetWidth(int new_width) {
    if (new_width > 0) {
        _main_width = new_width;
    }
}

void HandlerCommandArguments::SetHeight(int new_height) {
    if (new_height > 0) {
        _main_height = new_height;
    }
}


void HandlerCommandArguments::SetMessage(std::string new_message) {
    _message = new_message;
}

HandlerAddArguments::HandlerAddArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

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
            _message = ARGUMENT_ERROR;
            return;
        }

        if (x_coordinate < 0 || y_coordinate < 0 ||
            width < 0 || height < 0 ||
            x_coordinate + width > _main_width ||
            y_coordinate + height > _main_height) { 
            _message = ARGUMENT_ERROR;
            return;
        }
        
        windows.push_front(Window(Point(x_coordinate, y_coordinate), width, height));
    }
    catch(const std::exception& e) {
        _message = ARGUMENT_ERROR;
    }
}

HandlerListArguments::HandlerListArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerListArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (string_args != "") {
        _message = ARGUMENT_ERROR;
        return;
    }

    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
        return;
    }
    
    _message = "";
    for (Window &window : windows) {
        _message += window.GetInfo();
    }
}

HandlerMoveArguments::HandlerMoveArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerMoveArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
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
            _message = ARGUMENT_ERROR;
            return;
        }

        Window &window = windows.front();

        if (x_coordinate < 0 || y_coordinate < 0 ||
            x_coordinate + window.GetWidth() > _main_width ||
            y_coordinate + window.GetHeight() > _main_height) {
            _message = ARGUMENT_ERROR;
            return;
        }
        
        windows.front().MoveWindow(Point(x_coordinate, y_coordinate));
    }
    catch(const std::exception& e) {
        _message = ARGUMENT_ERROR;
    }
}

HandlerClickArguments::HandlerClickArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerClickArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
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
            _message = ARGUMENT_ERROR;
            return;
        }

        if (x_coordinate < 0 || y_coordinate < 0 ||
            x_coordinate > _main_width - 1 || y_coordinate > _main_height - 1) {
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
        _message = ARGUMENT_ERROR;
    }
}

HandlerDelArguments::HandlerDelArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerDelArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (string_args != "") {
        _message = ARGUMENT_ERROR;
        return;
    }

    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
        return;
    }
    
    windows.pop_front();
}

HandlerChangeColorArguments::HandlerChangeColorArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerChangeColorArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    if (arg2 != ARGUMENT_START_VALUE) {
        _message = ARGUMENT_ERROR;
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
        _message = ARGUMENT_ERROR;
    }
}

HandlerChangeBorderColorArguments::HandlerChangeBorderColorArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerChangeBorderColorArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    if (arg2 != ARGUMENT_START_VALUE) {
        _message = ARGUMENT_ERROR;
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
        _message = ARGUMENT_ERROR;
    }
}

HandlerOpenArguments::HandlerOpenArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerOpenArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    try {
        int id = std::stoi(arg1);

        if (arg2 != ARGUMENT_START_VALUE) {
            _message = ARGUMENT_ERROR;
            return;
        }

        if (id < 0) {
            _message = ARGUMENT_ERROR;
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

        _message = ARGUMENT_ERROR;
    }
    catch(const std::exception& e) {
        _message = ARGUMENT_ERROR;
    }
}

HandlerCloseArguments::HandlerCloseArguments(int new_width, int new_height) : HandlerCommandArguments(new_width, new_height) {}

void HandlerCloseArguments::Execute(std::list<Window> &windows, std::string string_args) {
    if (windows.empty()) {
        _message = EMPTY_WINDOWS_ERROR;
        return;
    }

    std::string arg1 = ARGUMENT_START_VALUE;
    std::string arg2 = ARGUMENT_START_VALUE;
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    try {
        int id = std::stoi(arg1);

        if (arg2 != ARGUMENT_START_VALUE) {
            _message = ARGUMENT_ERROR;
            return;
        }

        if (id < 0) {
            _message = ARGUMENT_ERROR;
            return;
        }

        for (Window &window: windows) {
            if (window.GetId() != id) {
                continue;
            }

            window.Close();
            return;
        }

        _message = ARGUMENT_ERROR;
    }
    catch(const std::exception& e) {
        _message = ARGUMENT_ERROR;
    }
}
