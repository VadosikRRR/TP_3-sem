#pragma once
#include "point.hpp"


class Window {
private:
    int _id;
    bool _is_open;
    int _width;
    int _height;
    Point _coordinate;
public:
    Window();
    ~Window();
    Window(Point coordinate, int width, int height);
    int GetId();
    bool GetIsOpen();
    int GetWidth();
    int GetHeight();
    Point GetCoordinate();

    void PrintInfo();
    void MoveWindow(Point new_coordinate);
};
