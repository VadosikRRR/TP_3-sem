#pragma once
#include "editor_commands.hpp"
#include "document.hpp"
#include <vector>


extern int AGRUMENT_NUMBER_ADD;
extern int AGRUMENT_NUMBER_MOVE;
extern int AGRUMENT_NUMBER_PUT;
extern int AGRUMENT_NUMBER_INSERT;


class HandlerCoomandArguments {
private:
    int _arg_number;
protected:
    HandlerCoomandArguments(int arg_number);
public:
    int GetArgNumber();
    virtual ~HandlerCoomandArguments();
    virtual Command * Execute(Document &document, std::string string_args) = 0;
};


class HandlerAddArguments : public HandlerCoomandArguments {
public:
    HandlerAddArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerMoveArgument : public HandlerCoomandArguments {
public:
    HandlerMoveArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerPutArgument : public HandlerCoomandArguments {
public:
    HandlerPutArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerInsertArgument : public HandlerCoomandArguments {
public:
    HandlerInsertArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerDeleteSymbolArgument : public HandlerCoomandArguments {
public:
    HandlerDeleteSymbolArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};
