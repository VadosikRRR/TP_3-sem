#include "handler_coomand_arguments.hpp"
#include <sstream>

int AGRUMENT_NUMBER_ADD = 1;
int AGRUMENT_NUMBER_MOVE = 1;
int AGRUMENT_NUMBER_PUT = 1;
int AGRUMENT_NUMBER_INSERT = 2;

HandlerCoomandArguments::~HandlerCoomandArguments() {}

HandlerCoomandArguments::HandlerCoomandArguments(int arg_number) : _arg_number(arg_number) {}

int HandlerCoomandArguments::GetArgNumber() {
    return _arg_number;
}

HandlerAddArguments::HandlerAddArguments() : HandlerCoomandArguments(AGRUMENT_NUMBER_ADD) {}

Command * HandlerAddArguments::Execute(Document &document, std::string string_args) {
    if (string_args != "" && string_args.substr(1) != "") {
        return new AddCommand(document, string_args.substr(1));
    }
    
    return NULL;
}
                         
HandlerMoveArgument::HandlerMoveArgument() : HandlerCoomandArguments(AGRUMENT_NUMBER_MOVE) {}
    // std::istringstream iss(command_text);
    // std::string command;
    // iss >> command;

Command * HandlerMoveArgument::Execute(Document &document, std::string string_args) {
    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    try {
        int new_cursor_position = std::stoi(arg1);
        if (arg2 != "BAN") {
            return NULL;
        }
        
        return new MoveCommand(document, new_cursor_position);
    }
    catch(const std::invalid_argument& e) {
        std::cout << "Ты что, ЕБАНУЛСЯ? А НИЧЁ ТОТ ФАКТ, ЧТО ЭТО НЕ МОЖЕТ БЫТЬ ПОЗИЦИЕЙ КУРСОРА";
        return NULL;
    }
}

HandlerPutArgument::HandlerPutArgument() : HandlerCoomandArguments(AGRUMENT_NUMBER_PUT) {}

Command * HandlerPutArgument::Execute(Document &document, std::string string_args) {
    if (string_args != "" && string_args.substr(1) != "") {
        return new PutCommand(document, string_args.substr(1));
    }
    
    return NULL;
}

HandlerInsertArgument::HandlerInsertArgument() : HandlerCoomandArguments(AGRUMENT_NUMBER_INSERT) {}

Command * HandlerInsertArgument::Execute(Document &document, std::string string_args) {
    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1;
    try {
        int new_cursor_position = std::stoi(arg1);
        if (string_args.substr(arg1.length()) != "" && string_args.substr(arg1.length() + 1) != "") {
            return new InsertCommand(document, string_args.substr(arg1.length() + 1), new_cursor_position);
        }

        return NULL;
    }
    catch(const std::invalid_argument& e) {
            std::cout << "Ты что, ЕБАНУЛСЯ? А НИЧЁ ТОТ ФАКТ, ЧТО ЭТО НЕ МОЖЕТ БЫТЬ ПОЗИЦИЕЙ КУРСОРА";
            return NULL;
    }
}
