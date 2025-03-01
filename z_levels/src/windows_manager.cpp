#include "include/windows_manager.hpp"
#include "include/parser.hpp"
#include "include/constants.hpp"
#include "include/renderer.hpp"
#include <sstream>
#include <cstdlib>


std::shared_ptr<WindowsManager> WindowsManager::_instance = nullptr;

WindowsManager & WindowsManager::Instance() {
    if (!_instance) {
        _instance = std::make_shared<WindowsManager>(WindowsManager());
    }
    
    return *_instance;
}

WindowsManager::WindowsManager() : _message("") {
    _commands[ADD] = std::make_shared<HandlerAddArguments>(HandlerAddArguments());
    _commands[LIST] = std::make_shared<HandlerListArguments>(HandlerListArguments());
    _commands[MOVE] = std::make_shared<HandlerMoveArguments>(HandlerMoveArguments());
    _commands[CLICK] = std::make_shared<HandlerClickArguments>(HandlerClickArguments());
    _commands[DEL] = std::make_shared<HandlerDelArguments>(HandlerDelArguments());
    _commands[CHANGE_BORDER_COL] = std::make_shared<HandlerChangeBorderColorArguments>(HandlerChangeBorderColorArguments());
    _commands[CHANGE_COL] = std::make_shared<HandlerChangeColorArguments>(HandlerChangeColorArguments());
}

void WindowsManager::Launch() {
    // std::cout << EMPTY_CONSOLE;
    // std::cout << BLACK_BACKGROUND;
    Parser & parser = Parser::Instance();
    Renderer & renderer = Renderer::Instance();
    renderer.SetMainWidth(60);
    renderer.SetMainHeight(60);
    std::string input_text;
    system("clear");
    while (true) {
        std::cout << BLACK_BACKGROUND;
        input_text = parser.Parse();
        if (input_text == "Exit") {
            break;
        }
        
        system("clear");
        StringProcessing(input_text);
        renderer.Drow(_windows, _message);
    }
}


void WindowsManager::StringProcessing(std::string command_text) {
    std::istringstream iss(command_text);
    std::string command;
    iss >> command;
    auto it = _commands.find(command);
    if (it != _commands.end()) {
        it->second->Execute(_windows, command_text.substr(command.length()));
        _message = it->second->GetMessage();
        it->second->SetMessage("");
    } 
    else {
        _message = "Command is not found";
    }
}