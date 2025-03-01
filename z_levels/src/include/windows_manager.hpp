#pragma once
#include "window.hpp"
#include "handlers.hpp"
#include <list>
#include <memory>
#include <unordered_map>

class WindowsManager {
private:
    int _main_width;
    int _main_height;
    std::string _message;
    static std::shared_ptr<WindowsManager> _instance;
    std::list<Window> _windows;
    std::unordered_map<std::string, std::shared_ptr<HandlerCommandArguments>> _commands;
    void StringProcessing(std::string command_text);
protected:
    WindowsManager();
public:
    void SetWidth(int new_width);
    void Setheight(int new_height);
    static WindowsManager & Instance();
    void Launch();
};
