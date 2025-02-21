#include "include/handler_coomand_arguments.hpp"
#include <sstream>


HandlerCommandArguments::~HandlerCommandArguments() {}

HandlerCommandArguments::HandlerCommandArguments() {}

HandlerAddArguments::HandlerAddArguments() {}

Command * HandlerAddArguments::Execute(Document &document, std::string string_args) {
    if (string_args != "" && string_args.substr(1) != "") {
        return new AddCommand(document, string_args.substr(1));
    }
    
    return NULL;
}
                         
HandlerMoveArguments::HandlerMoveArguments() {}

Command * HandlerMoveArguments::Execute(Document &document, std::string string_args) {
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

HandlerPutArguments::HandlerPutArguments() {}

Command * HandlerPutArguments::Execute(Document &document, std::string string_args) {
    if (string_args != "" && string_args.substr(1) != "") {
        return new PutCommand(document, string_args.substr(1));
    }
    
    return NULL;
}

HandlerInsertArguments::HandlerInsertArguments() {}

Command * HandlerInsertArguments::Execute(Document &document, std::string string_args) {
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

HandlerDeleteSymbolArguments::HandlerDeleteSymbolArguments() {}

Command * HandlerDeleteSymbolArguments::Execute(Document &document, std::string string_args) {
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

HandlerRemoveArguments::HandlerRemoveArguments() {}

Command * HandlerRemoveArguments::Execute(Document &document, std::string string_args) {
    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::string arg3 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2 >> arg3;

    if (arg1 == "BAN" || arg2 == "BAN" || arg3 != "BAN") {
        return NULL;
    }
    
    HandlerMoveArguments move_handler = HandlerMoveArguments();
    Command * move_command = move_handler.Execute(document, arg2);
    if (!move_command) {
        return NULL;
    }
    delete move_command;

    try {
        int start_index = std::stoi(arg1);
        int end_index = std::stoi(arg2);
        HandlerDeleteSymbolArguments del_handler = HandlerDeleteSymbolArguments();
        Command * del_command = del_handler.Execute(document, std::to_string(end_index - start_index + 1));
        if (!del_command) {
            return NULL;
        }
        delete del_command;

        return new RemoveCommand(document, start_index, end_index);
    }
    catch(const std::exception& e) {
        return NULL;
    }
}


HandlerMoveLeftSomeWordsArguments::HandlerMoveLeftSomeWordsArguments() {}

Command * HandlerMoveLeftSomeWordsArguments::Execute(Document &document, std::string string_args) {
    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;

    if (arg2 != "BAN") {
        return NULL;
    }

    try {
        int words_number = std::stoi(arg1);
        
        if (words_number <= 0) {
            return NULL;
        }
        
        return new MoveLeftOnSomeWordsCommand(document, words_number);
    }
    catch(const std::exception& e) {
        return NULL;
    }
}


HandlerMoveRightSomeWordsArguments::HandlerMoveRightSomeWordsArguments() {}

Command * HandlerMoveRightSomeWordsArguments::Execute(Document &document, std::string string_args) {
    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2;

    if (arg2 != "BAN") {
        return NULL;
    }

    try {
        int words_number = std::stoi(arg1);
        
        if (words_number <= 0) {
            return NULL;
        }
        
        return new MoveRightOnSomeWordsCommand(document, words_number);
    }
    catch(const std::exception& e)
    {
        return NULL;
    }
}

HandlerUpCaseArguments::HandlerUpCaseArguments() {}

Command * HandlerUpCaseArguments::Execute(Document &document, std::string string_args) {
    if (string_args != "" || document.GetDocumentText()[document.GetCursorPosition()] == ' ') {
        return NULL;
    }

    return new UpCaseCommand(document);
}

HandlerLowCaseArguments::HandlerLowCaseArguments() {}

Command * HandlerLowCaseArguments::Execute(Document &document, std::string string_args) {
    if (string_args != "" || document.GetDocumentText()[document.GetCursorPosition()] == ' ') {
        return NULL;
    }

    return new LowCaseCommand(document);
}

HandlerFindArguments::HandlerFindArguments() {}

Command * HandlerFindArguments::Execute(Document &document, std::string string_args) {
    if (string_args == "" || string_args.substr(1) == "") {
        return NULL;
    }

    return new FindCommand(document, string_args.substr(1));
}

HandlerReplaceArguments::HandlerReplaceArguments() {}

Command * HandlerReplaceArguments::Execute(Document &document, std::string string_args) {
    std::string arg1 = "BAN";
    std::string arg2 = "BAN";
    std::string arg3 = "BAN";
    std::istringstream iss(string_args);
    iss >> arg1 >> arg2 >> arg3;

    if (arg1 == "BAN" || arg2 == "BAN" || arg3 != "BAN") {
        return NULL;
    }

    return new ReplaceCommand(document, arg1, arg2);
}