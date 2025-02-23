#pragma once
#include "window.hpp"
#include <list>
#include <iostream>


class HandlerCommandArguments {
protected:
    HandlerCommandArguments();
public:
    virtual ~HandlerCommandArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args) = 0;
};
