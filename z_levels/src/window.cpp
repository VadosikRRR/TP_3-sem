#include "include/window.hpp"
#include "include/constants.hpp"
#include <iostream>


int WINDOW_CNT = 0;

Window::Window() : _id(WINDOW_CNT++), _is_open(true), 
    _coordinate(Point()), _width(1), _height(1),
    _color(BLUE_BACKGROUND), _border_color(RED_BACKGROUND) {}

Window::Window(Point coordinate, int width, int height) : 
    _id(WINDOW_CNT++), _is_open(true), 
    _color(BLUE_BACKGROUND), _border_color(RED_BACKGROUND) {

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

std::string Window::GetColor() {
    return _color;
}

std::string Window::GetBorderColor() {
    return _border_color;
}

std::string Window::GetInfo() {
    std::string text = "";
    text += "ID: " + std::string(_id + "; ");
    text += "x: " + std::string(_coordinate._x + ", ");
    text += "y: " + std::string(_coordinate._y + "; ");
    text += "width: " + std::string(_width + ", ");
    text += "height: " + std::string(_height + ";\n");
    return text;
}

void Window::MoveWindow(Point new_coordinate) {
    if (new_coordinate._x < 0 || new_coordinate._y < 0) {
        return;
    }
    
    _coordinate = new_coordinate;
}

bool Window::BelongWindowPoint(Point point) {
    bool belong_x = point._x >=_coordinate._x && 
                    point._x <= _coordinate._x + _width - 1;
    bool belong_y = point._y >=_coordinate._y && 
                    point._y <= _coordinate._y + _height - 1;
    return belong_x && belong_y;
}

void Window::ChangeColor(std::string new_color) {
    _color = new_color;
}

void Window::ChangeBorderColor(std::string new_border_color) {
    _border_color = new_border_color;
}
