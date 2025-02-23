#pragma once
#include "point.hpp"


class Window {
private:
    int _width;
    int _height;
    bool _is_open;
    Point _coordinate;
public:
    Window(Point coordinate, int width, int height);
};