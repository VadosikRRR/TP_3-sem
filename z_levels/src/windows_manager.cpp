#include "include/windows_manager.hpp"
#include "include/parser.hpp"
#include "include/constants.hpp"
#include <sstream>


std::shared_ptr<WindowsManager> WindowsManager::_instance = nullptr;

WindowsManager & WindowsManager::Instance() {
    if (!_instance) {
        _instance = std::make_shared<WindowsManager>(WindowsManager());
    }
    
    return *_instance;
}

WindowsManager::WindowsManager() {
    _commands[ADD] = std::make_shared<HandlerAddArguments>(HandlerAddArguments());
    _commands[LIST] = std::make_shared<HandlerListArguments>(HandlerListArguments());
    _commands[MOVE] = std::make_shared<HandlerMoveArguments>(HandlerMoveArguments());
}

void WindowsManager::Launch() {
    Parser & parser = Parser::Instance();
    std::string input_text;
    while (true) {
        input_text = parser.Parse();
        if (input_text == "Exit") {
            break;
        }
        
        StringProcessing(input_text);
    }
}


void WindowsManager::StringProcessing(std::string command_text) {
    std::istringstream iss(command_text);
    std::string command;
    iss >> command;
    auto it = _commands.find(command);
    if (it != _commands.end()) {
        it->second->Execute(_windows, command_text.substr(command.length()));
    } 
    else {
        std::cout << "Command is not found" << std::endl;
    }
}