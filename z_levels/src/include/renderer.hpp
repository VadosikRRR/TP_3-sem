#pragma once
#include "window.hpp"
#include <list>
#include <memory>


class Renderer {
private:
    static std::shared_ptr<Renderer> _instance;
    int _main_width;
    int _main_height;
protected:
    Renderer();
public:
    static Renderer & Instance();
    void Drow(std::list<Window> &windows, std::string message);
    void SetMainWidth(int main_width);
    void SetMainHeight(int main_height);
};
