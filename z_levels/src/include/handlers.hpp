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


class HandlerAddArguments : public HandlerCommandArguments {
public:
    HandlerAddArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerListArguments : public HandlerCommandArguments {
public:
    HandlerListArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerMoveArguments : public HandlerCommandArguments {
public:
    HandlerMoveArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerClickArguments : public HandlerCommandArguments {
public:
    HandlerClickArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};
