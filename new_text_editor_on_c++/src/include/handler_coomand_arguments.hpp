#pragma once
#include "editor_commands.hpp"
#include "document.hpp"
#include <vector>


class HandlerCommandArguments {
protected:
    HandlerCommandArguments();
public:
    virtual ~HandlerCommandArguments();
    virtual Command * Execute(Document &document, std::string string_args) = 0;
};


class HandlerAddArguments : public HandlerCommandArguments {
public:
    HandlerAddArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerMoveArguments : public HandlerCommandArguments {
public:
    HandlerMoveArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerPutArguments : public HandlerCommandArguments {
public:
    HandlerPutArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerInsertArguments : public HandlerCommandArguments {
public:
    HandlerInsertArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerDeleteSymbolArguments : public HandlerCommandArguments {
public:
    HandlerDeleteSymbolArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerRemoveArguments : public HandlerCommandArguments {
public:
    HandlerRemoveArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerMoveLeftSomeWordsArguments : public HandlerCommandArguments {
public:
    HandlerMoveLeftSomeWordsArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerMoveRightSomeWordsArguments : public HandlerCommandArguments {
public:
    HandlerMoveRightSomeWordsArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerUpCaseArguments : public HandlerCommandArguments {
public:
    HandlerUpCaseArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerLowCaseArguments : public HandlerCommandArguments {
public:
    HandlerLowCaseArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerFindArguments : public HandlerCommandArguments {
public:
    HandlerFindArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};


class HandlerReplaceArguments : public HandlerCommandArguments {
public:
    HandlerReplaceArguments();
    virtual Command * Execute(Document &document, std::string string_args);
};
