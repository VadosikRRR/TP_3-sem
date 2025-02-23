#include "include/window.hpp"
#include "include/constants.hpp"


Window::Window(Point coordinate, int width, int height) : _is_open(true) {
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
