#include "handler_coomand_arguments.hpp"
#include <sstream>

int AGRUMENT_NUMBER_ADD = 1;
int AGRUMENT_NUMBER_MOVE = 1;
int AGRUMENT_NUMBER_PUT = 1;
int AGRUMENT_NUMBER_INSERT = 2;
int AGRUMENT_NUMBER_DELETE_SYMBOL = 0;
int AGRUMENT_NUMBER_DELETE_FEW_SYMBOLS = 1;

HandlerCommandArguments::~HandlerCommandArguments() {}

HandlerCommandArguments::HandlerCommandArguments(int arg_number) : _arg_number(arg_number) {}

int HandlerCommandArguments::GetArgNumber() {
    return _arg_number;
}

HandlerAddArguments::HandlerAddArguments() : HandlerCommandArguments(AGRUMENT_NUMBER_ADD) {}

Command * HandlerAddArguments::Execute(Document &document, std::string string_args) {
    if (string_args != "" && string_args.substr(1) != "") {
        return new AddCommand(document, string_args.substr(1));
    }
    
    return NULL;
}
                         
HandlerMoveArgument::HandlerMoveArgument() : HandlerCommandArguments(AGRUMENT_NUMBER_MOVE) {}

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
        
        if (new_cursor_position < 0 || document.GetDocumentText().length() <= new_cursor_position) {
            std::cout << "ARGUMENT ERROR" << std::endl;
            return NULL;
        }

        return new MoveCommand(document, new_cursor_position);
    }
    catch(const std::invalid_argument& e) {
        std::cout << "Ты что, ЕБАНУЛСЯ? А НИЧЁ ТОТ ФАКТ, ЧТО ЭТО НЕ МОЖЕТ БЫТЬ ПОЗИЦИЕЙ КУРСОРА";
        return NULL;
    }
}

HandlerPutArgument::HandlerPutArgument() : HandlerCommandArguments(AGRUMENT_NUMBER_PUT) {}

Command * HandlerPutArgument::Execute(Document &document, std::string string_args) {
    if (string_args != "" && string_args.substr(1) != "") {
        return new PutCommand(document, string_args.substr(1));
    }
    
    return NULL;
}

HandlerInsertArgument::HandlerInsertArgument() : HandlerCommandArguments(AGRUMENT_NUMBER_INSERT) {}

Command * HandlerInsertArgument::Execute(Document &document, std::string string_args) {
    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1;
    try {
        int new_cursor_position = std::stoi(arg1);
        if (string_args.substr(arg1.length()) != "" && string_args.substr(arg1.length() + 1) != "") {
            if (new_cursor_position < 0 || document.GetDocumentText().length() <= new_cursor_position) {
                std::cout << "ARGUMENT ERROR" << std::endl;
                return NULL;
            }

            return new InsertCommand(document, string_args.substr(arg1.length() + 2), new_cursor_position);
        }

        return NULL;
    }
    catch(const std::invalid_argument& e) {
            std::cout << "Ты что, ЕБАНУЛСЯ? А НИЧЁ ТОТ ФАКТ, ЧТО ЭТО НЕ МОЖЕТ БЫТЬ ПОЗИЦИЕЙ КУРСОРА";
            return NULL;
    }
}

HandlerDeleteSymbolArgument::HandlerDeleteSymbolArgument() : HandlerCommandArguments(AGRUMENT_NUMBER_DELETE_SYMBOL) {}

Command * HandlerDeleteSymbolArgument::Execute(Document &document, std::string string_args) {
    if (string_args == "") {
        if (document.GetDocumentText() == "") {
            std::cout << "INCORRECT CASE" << std::endl;
            return NULL;
        }
    
        return new DeleteSymbolCommand(document);
    }

    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;
    try {
        int number_delete_symbols = std::stoi(arg1);
        if (arg2 != "BAN") {
            return NULL;
        }
        
        if (number_delete_symbols <= 0 ||
            document.GetCursorPosition() < number_delete_symbols) {
            return NULL;
        }

        return new DeleteFewSymbolsCommand(document, number_delete_symbols);
    }
    catch(const std::invalid_argument& e) {
        std::cout << "Ты что, ЕБАНУЛСЯ? А НИЧЁ ТОТ ФАКТ, ЧТО ЭТО НЕ МОЖЕТ БЫТЬ ПОЗИЦИЕЙ КУРСОРА";
        return NULL;
    }
}

// HandlerDeleteFewSymbolsArgument::HandlerDeleteFewSymbolsArgument() : HandlerCommandArguments(AGRUMENT_NUMBER_DELETE_FEW_SYMBOLS) {}

// Command * HandlerDeleteFewSymbolsArgument::Execute(Document &document, std::string string_args) {
    
// }
