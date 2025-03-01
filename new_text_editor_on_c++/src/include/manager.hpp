#pragma once
#include "handler_coomand_arguments.hpp"
#include "document.hpp"
#include <map>


class Manager {
private:
    static Manager *_instance;
    std::map<std::string, HandlerCommandArguments *> _commands; //Unordered
protected:
    Manager();
public:
    ~Manager();
    static Manager * Instance();
    void StringProcessing(Document &document, std::string command_text);
};
