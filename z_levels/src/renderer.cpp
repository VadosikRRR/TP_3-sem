#include "include/renderer.hpp"
#include "include/constants.hpp"
#include <iostream>

void hash_line(int hash_symbols_number);
void clear_console();


std::shared_ptr<Renderer> Renderer::_instance = 0;

Renderer & Renderer::Instance() {
    if (!_instance) {
        _instance = std::make_shared<Renderer>(Renderer());
    }
    
    return *_instance;
}

Renderer::Renderer() : _main_width(-1), _main_height(-1) {}

void Renderer::Drow(std::list<Window> &windows, std::string message) {
    if (_main_width == -1 || _main_height == -1) {
        std::cout << "Params are not set" << std::endl;
        return;
    }
    hash_line(_main_width + 2);

    for (int y = 0; y != _main_height; y++) {
        std::cout << BLACK_BACKGROUND << BOUNDARY_SYMBOL;
        for (int x = 0; x != _main_width; x++) {
            std::cout << BLACK_BACKGROUND;
            for (Window &window : windows) {
                if (!window.GetIsOpen() || !window.BelongWindowPoint(Point(x, y))) {
                    continue;
                }
                
                if (x == window.GetCoordinate()._x ||
                    x == window.GetCoordinate()._x + window.GetWidth() - 1 ||
                    y == window.GetCoordinate()._y ||
                    y == window.GetCoordinate()._y + window.GetHeight() - 1) {
                    std::cout << window.GetBorderColor();
                    break;
                }
                
                std::cout << window.GetColor();
                break;
            }
            
            std::cout << ' ';
        }
        
        std::cout << BLACK_BACKGROUND << BOUNDARY_SYMBOL << std::endl;
    }

    hash_line(_main_width + 2);
    std::cout << message << std::endl;
}

void Renderer::SetMainWidth(int main_width) {
    if (main_width > 0) {
        _main_width = main_width;
    }
}

void Renderer::SetMainHeight(int main_height) {
    if (main_height > 0) {
        _main_height = main_height;
    }
}

void hash_line(int hash_symbols_number) {
    std::cout << BLACK_BACKGROUND;
    for (int i = 0; i < hash_symbols_number; i++) {
        std::cout << BOUNDARY_SYMBOL;
    }
    
    std::cout << std::endl;
}
