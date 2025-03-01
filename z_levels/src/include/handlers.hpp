#pragma once
#include "window.hpp"
#include <list>
#include <iostream>


class HandlerCommandArguments {
protected:
    std::string _message;
    HandlerCommandArguments();
public:
    std::string GetMessage();
    void SetMessage(std::string new_message);
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


class HandlerDelArguments : public HandlerCommandArguments {
public:
    HandlerDelArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerChangeColorArguments : public HandlerCommandArguments {
public:
    HandlerChangeColorArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerChangeBorderColorArguments : public HandlerCommandArguments {
public:
    HandlerChangeBorderColorArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerOpenArguments : public HandlerCommandArguments {
public:
    HandlerOpenArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerCloseArguments : public HandlerCommandArguments {
public:
    HandlerCloseArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};
