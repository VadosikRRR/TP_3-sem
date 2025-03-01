#pragma once
#include "window.hpp"
#include <list>
#include <iostream>


class HandlerCommandArguments {
protected:
    int _main_width;
    int _main_height;
    std::string _message;
    HandlerCommandArguments(int new_width, int new_height);
public:
    std::string GetMessage();
    void SetWidth(int main_width);
    void SetHeight(int main_width);
    void SetMessage(std::string new_message);
    virtual ~HandlerCommandArguments();
    virtual void Execute(std::list<Window> &windows, std::string string_args) = 0;
};


class HandlerAddArguments : public HandlerCommandArguments {
public:
    HandlerAddArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerListArguments : public HandlerCommandArguments {
public:
    HandlerListArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerMoveArguments : public HandlerCommandArguments {
public:
    HandlerMoveArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerClickArguments : public HandlerCommandArguments {
public:
    HandlerClickArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerDelArguments : public HandlerCommandArguments {
public:
    HandlerDelArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerChangeColorArguments : public HandlerCommandArguments {
public:
    HandlerChangeColorArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerChangeBorderColorArguments : public HandlerCommandArguments {
public:
    HandlerChangeBorderColorArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerOpenArguments : public HandlerCommandArguments {
public:
    HandlerOpenArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};


class HandlerCloseArguments : public HandlerCommandArguments {
public:
    HandlerCloseArguments(int new_width, int new_height);
    virtual void Execute(std::list<Window> &windows, std::string string_args);
};
