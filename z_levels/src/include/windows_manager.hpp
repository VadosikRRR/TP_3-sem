#pragma once
#include "window.hpp"
#include "handlers.hpp"
#include <list>
#include <memory>
#include <unordered_map>

class WindowsManager {
private:
    static std::unique_ptr<WindowsManager> _instance;
    std::list<Window> _windows;
    std::unordered_map<std::string, std::unique_ptr<HandlerCommandArguments>> _commands;
    void StringProcessing(std::string command_text);
protected:
    WindowsManager();
public:
    static WindowsManager & Instance();
    void Launch();
};
