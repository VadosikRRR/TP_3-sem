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


class RemoveCommand : public Command {
private:
    int _old_index;
    int _start_index;
    int _end_index;
    std::string &_text;
public:
    RemoveCommand(std::string &text, int old_index, int start_index, int end_index);
    virtual void Execute();
};


class DeleteSymbolCommand : public Command {
private:
    int _index;
    std::string &_text;
public:
    DeleteSymbolCommand(std::string &text, int index);
    virtual void Execute();
};


class DeleteFewSymbolsCommand : public Command {
private:
    int _index;
    int _symbols_number;
    std::string &_text;
public:
    DeleteFewSymbolsCommand(std::string &text, int index, int symbols_number);
    virtual void Execute();
};


class MoveLeftOnSomeWordsCommand : public Command {
private:
    int _index;
    int _words_number;
    std::string &_text;
public:
    MoveLeftOnSomeWordsCommand(std::string &text, int index, int words_number);
    virtual void Execute();
};


class MoveRightOnSomeWordsCommand : public Command {
private:
    int _index;
    int _words_number;
    std::string &_text;
public:
    MoveRightOnSomeWordsCommand(std::string &text, int index, int words_number);
    virtual void Execute();
};


class UpCaseCommand : public Command {
private:
    int _index;
    std::string &_text;
public:
    UpCaseCommand(std::string &text, int index);
    virtual void Execute();
};


class LowCaseCommand : public Command { 
private:
    int _index;
    std::string &_text;
public:
    LowCaseCommand(std::string &text, int index);
    virtual void Execute();
};


class FindCommand : public Command {
private:
    std::string _needed_text;
    std::string &_text;
public:
    FindCommand(std::string &text, std::string needed_text);
    virtual void Execute();
};


class ReplaceCommand : public Command {
private:
    std::string _old_text;
    std::string _new_text;
    std::string &_text;
public:
    ReplaceCommand(std::string &text, std::string old_text, std::string new_text);
    virtual void Execute();
};
