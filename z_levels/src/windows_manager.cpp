#include "include/windows_manager.hpp"
#include "include/parser.hpp"


std::unique_ptr<WindowsManager> WindowsManager::_instance = nullptr;

WindowsManager & WindowsManager::Instance() {
    if (!_instance) {
        _instance = std::make_unique<WindowsManager>(WindowsManager());
    }
    
    return *_instance;
}

WindowsManager::WindowsManager() {}

void WindowsManager::Launch() {
    Parser & parser = Parser::Instance();
    std::string input_text;
    while (true) {
        input_text = parser.Parse();
        if (input_text == "Exit") {
            break;
        }
        
        // StringProcessing(input_text);
    }
}


// void WindowsManager::StringProcessing(std::string command_text) {

// }