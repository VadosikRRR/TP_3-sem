#include "manager.hpp"
#include <sstream>


std::string STANDART_ERROR = "BAN";
std::string ARGUMENT_NUMBER_ERROR = "number of arguments is less than this command is needed";

Manager * Manager::_instance = 0;

Manager::Manager() {
    _commands[ADD] = new HandlerAddArguments();
    _commands[MOVE] = new HandlerMoveArgument();
    _commands[PUT] = new HandlerPutArgument();
    _commands[INSERT] = new HandlerInsertArgument();
    _commands[DEL] = new HandlerDeleteSymbolArgument();
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
            std::cout << "Чел, ебать, аргументы проверяй" << std::endl;
            return;
        }
        
        p_command->Execute();
        delete p_command;
    } 
    else {
        std::cout << "Чел, ебать, команды выучи" << std::endl;
    }
}

// void Manager::RegisterCommand(std::string command_name, HandlerCommandArguments * p_handler) {

// }

// std::string * string_split(std::string text) {
//     int cnt = 0;
//     for (int i = 0; text[i] != '\0'; i++) {
//         if (text[i] == ' ' && text[i + 1] != '\0' && text[i + 1] != ' ') {
//             cnt++;
//         }
//     }
    
//     std::string * splitted_text = new std::string[cnt + 1];

//     cnt = 0;
//     int start_index = 0;
//     for (int i = 0; text[i] != '\0'; i++) {
//         if (text[i] == ' ' && text[i + 1] != '\0' && text[i + 1] != ' ') {
//             splitted_text[cnt] = text.substr(start_index, i - start_index - 1);
//             cnt++;

//         while (text[i + 1] == ' ') {
//             i++;
//         }
        
//         start_index = i + 1;
//         }
//     }
// }

////////////////////////////////////////////////////////////////////////////////////

// std::string * string_split(std::string text, char separator) {
//     int cnt = 0;
//     for (int i = 0; text[i] != '\0'; i++) {
//         if (text[i] != separator) {
//             continue;
//         }

//         cnt++;
//         while (text[i + 1] == separator) {
//             i++;
//         }
        
//         if (text[i + 1] == '\0') {
//             cnt--;
//         }
//     }

//     std::string * splitted_text = new std::string[cnt + 1];

//     int cnt_cnt = 0;
//     int start_index = 0;

//     for (int i = 0; cnt_cnt != cnt; i++) {
//         if (text[i] != separator) {
//             continue;
//         }
        
//         splitted_text[cnt_cnt] = text.substr(start_index, i - start_index - 1);
//         cnt_cnt++;

//     }
    
    
// }
