#pragma once
#include "editor_commands.hpp"
#include "document.hpp"
#include <vector>


extern int AGRUMENT_NUMBER_ADD;
extern int AGRUMENT_NUMBER_MOVE;
extern int AGRUMENT_NUMBER_PUT;
extern int AGRUMENT_NUMBER_INSERT;


class HandlerCommandArguments {
private:
    int _arg_number;
protected:
    HandlerCommandArguments(int arg_number);
public:
    int GetArgNumber();
    virtual ~HandlerCommandArguments();
    virtual Command * Execute(Document &document, std::string string_args) = 0;
};


class HandlerAddArguments : public HandlerCommandArguments {
public:
    HandlerAddArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerMoveArgument : public HandlerCommandArguments {
public:
    HandlerMoveArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerPutArgument : public HandlerCommandArguments {
public:
    HandlerPutArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerInsertArgument : public HandlerCommandArguments {
public:
    HandlerInsertArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerDeleteSymbolArgument : public HandlerCommandArguments {
public:
    HandlerDeleteSymbolArgument();
    virtual Command * Execute(Document &document, std::string string_args);
};


// class HandlerDeleteFewSymbolsArgument : public HandlerCommandArguments {
// public:
//     HandlerDeleteFewSymbolsArgument();
//     virtual Command * Execute(Document &document, std::string string_args);
// };
