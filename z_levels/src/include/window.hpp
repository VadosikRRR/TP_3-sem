#pragma once
#include "point.hpp"
#include <iostream>


class Window {
private:
    int _id;
    bool _is_open;
    int _width;
    int _height;
    Point _coordinate;

    std::string _color;
    std::string _border_color;
public:
    Window();
    ~Window();
    Window(Point coordinate, int width, int height);
    int GetId();
    bool GetIsOpen();
    int GetWidth();
    int GetHeight();
    Point GetCoordinate();
    std::string GetColor();
    std::string GetBorderColor();

    std::string GetInfo();
    void MoveWindow(Point new_coordinate);
    
    bool BelongWindowPoint(Point point);
};
