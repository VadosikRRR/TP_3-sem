#include "include/manager.hpp"
#include "include/constans.hpp"
#include <sstream>


Manager * Manager::_instance = 0;

Manager::Manager() {
    _commands[ADD] = new HandlerAddArguments();
    _commands[MOVE] = new HandlerMoveArguments();
    _commands[PUT] = new HandlerPutArguments();
    _commands[INSERT] = new HandlerInsertArguments();
    _commands[DEL] = new HandlerDeleteSymbolArguments();
    _commands[REMOVE] = new HandlerRemoveArguments();
    _commands[MOVELW] = new HandlerMoveLeftSomeWordsArguments();
    _commands[MOVERW] = new HandlerMoveRightSomeWordsArguments();
    _commands[UPCASE] = new HandlerUpCaseArguments();
    _commands[LOWCASE] = new HandlerLowCaseArguments();
    _commands[FIND] = new HandlerFindArguments();
    _commands[REPLACE] = new HandlerReplaceArguments();
    _commands[SAVE] = new HandlerSaveArguments();
    _commands[LOAD] = new HandlerLoadArguments();
}

Manager::~Manager() {
    for (auto & pair : _commands) {
        delete pair.second;
    }
}

Manager * Manager::Instance() {
    if (!_instance) {
        _instance = new Manager();
    }
    
    return _instance;
}

void Manager::StringProcessing(Document &document, std::string command_text) {
    std::istringstream iss(command_text);
    std::string command;
    iss >> command;
    auto it = _commands.find(command);
    if (it != _commands.end()) {
        Command * p_command = it->second->Execute(document, command_text.substr(command.length()));
        if (!p_command) {
            document.GetErrorMessage() = ARGUMENT_ERROR;
            return;
        }
        
        p_command->Execute();
        delete p_command;
    } 
    else {
        document.GetErrorMessage() = COMMAND_ERROR;
    }
}
