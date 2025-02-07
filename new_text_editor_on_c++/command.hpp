#include <iostream>
#include "application.hpp"

class Command {
protected:
    Command();
public:
    virtual ~Command();
    virtual void Execute() = 0;
};


class AddCommand : public Command {
private:
    std::string _new_text;
    std::string &_text;
public:
    AddCommand(std::string &text, std::string new_text);
    virtual void Execute();
};


class MoveCommand : public Command {
private:
    int _old_index;
    int _new_index;
    std::string &_text;
public:
    MoveCommand(std::string &text, int old_index, int new_text);
    virtual void Execute();
};


class InsertCommand : public Command {
private:
    int _old_index;
    int _new_index;
    std::string _new_text;
    std::string &_text;
public:
    InsertCommand(std::string &text, std::string new_text, int old_index, int new_index);
    virtual void Execute();
};


class PutCommand : public Command {
private:
    int _index;
    std::string _new_text;
    std::string &_text;
public:
    PutCommand(std::string &text, std::string new_text, int index);
    virtual void Execute();
};


class RemoveCommand : Command {};


class DeleteSymbolCommand : Command {
private:
    int _index;
    std::string &_text;
public:
    DeleteSymbolCommand(std::string &text, int index);
    virtual void Execute();
};

class DeleteFewSymbolsCommand : Command {
private:
    int _index;
    int _symbols_number;
    std::string &_text;
public:
    DeleteFewSymbolsCommand(std::string &text, int index, int symbols_number);
    virtual void Execute();
};
