#pragma once
#include "handler_coomand_arguments.hpp"
#include "document.hpp"
#include <map>


class Manager {
private:
    static Manager *_instance;
    std::map<std::string, HandlerCoomandArguments *> _commands;
    // void RegisterCommand(std::string command_name, HandlerCoomandArguments * p_handler);
protected:
    Manager();
public:
    static Manager * Instance();
    void StringProcessing(Document &document, std::string command_text);
};
