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

WindowsManager::WindowsManager() : _main_width(-1), _main_height(-1), _message("") {
    _commands[ADD] = std::make_shared<HandlerAddArguments>(HandlerAddArguments(_main_width, _main_height));
    _commands[LIST] = std::make_shared<HandlerListArguments>(HandlerListArguments(_main_width, _main_height));
    _commands[MOVE] = std::make_shared<HandlerMoveArguments>(HandlerMoveArguments(_main_width, _main_height));
    _commands[CLICK] = std::make_shared<HandlerClickArguments>(HandlerClickArguments(_main_width, _main_height));
    _commands[DEL] = std::make_shared<HandlerDelArguments>(HandlerDelArguments(_main_width, _main_height));
    _commands[CHANGE_BORDER_COL] = std::make_shared<HandlerChangeBorderColorArguments>(HandlerChangeBorderColorArguments(_main_width, _main_height));
    _commands[CHANGE_COL] = std::make_shared<HandlerChangeColorArguments>(HandlerChangeColorArguments(_main_width, _main_height));
    _commands[OPEN] = std::make_shared<HandlerOpenArguments>(HandlerOpenArguments(_main_width, _main_height));
    _commands[CLOSE] = std::make_shared<HandlerCloseArguments>(HandlerCloseArguments(_main_width, _main_height));
}

void WindowsManager::Launch() { 
    if (_main_height == -1 || _main_width == -1) {
        std::cout << SIZE_ERROR << std::endl;
        return;
    }
    
    fill_colors();

    for (auto &command: _commands) {
        command.second.get()->SetWidth(_main_width);
        command.second.get()->SetHeight(_main_height);
    }
    
    Parser & parser = Parser::Instance();
    Renderer & renderer = Renderer::Instance();
    renderer.SetMainWidth(_main_width);
    renderer.SetMainHeight(_main_height);
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

void WindowsManager::SetWidth(int new_width) {
    if (new_width > 0) {
        _main_width = new_width;
    }
}

void WindowsManager::Setheight(int new_height) {
    if (new_height > 0) {
        _main_height = new_height;
    }
}
