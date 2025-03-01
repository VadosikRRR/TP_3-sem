#include "include/window.hpp"
#include "include/constants.hpp"
#include <iostream>


int WINDOW_CNT = 0;

Window::Window() : _id(WINDOW_CNT++), _is_open(true), _coordinate(Point()), _width(1), _height(1) {}

Window::Window(Point coordinate, int width, int height) : _id(WINDOW_CNT++), _is_open(true){
    if (coordinate._x >= 0 && coordinate._y >= 0) {
        _coordinate = coordinate;
    }
    else {
        _coordinate = Point(0, 0);
    }

    if (width > 0) {
        _width = width;
    }
    else {
        _width = START_BASIC_WIDTH_WINDOW;
    }
    
    if (height > 0) {
        _height = height;
    }
    else {
        _height = START_BASIC_HEIGHT_WINDOW;
    }
}

Window::~Window() {}

int Window::GetId() {
    return _id;
}

bool Window::GetIsOpen() {
    return _is_open;
}

int Window::GetWidth() {
    return _width;
}

int Window::GetHeight() {
    return _height;
}

Point Window::GetCoordinate() {
    return _coordinate;
}

void Window::PrintInfo() {
    std::cout << "ID: " << _id << "; ";
    std::cout << "x: " << _coordinate._x << ", " << "y: " << _coordinate._y << "; ";
    std::cout << "width: " << _width << ", " << "height: " << _height << ";" << std::endl;
}

void Window::MoveWindow(Point new_coordinate) {
    if (new_coordinate._x < 0 || new_coordinate._y < 0) {
        return;
    }
    
    _coordinate = new_coordinate;
}
