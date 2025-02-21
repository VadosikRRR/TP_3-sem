#pragma once
#include "document.hpp"
#include <iostream>
#include <bits/stdc++.h>


extern std::string ADD;
extern std::string MOVE;
extern std::string INSERT;
extern std::string PUT;
extern std::string REMOVE;
extern std::string DEL;
extern std::string MOVELW;
extern std::string MOVERW;
extern std::string UPCASE;
extern std::string LOWCASE;
extern std::string PEPLACE;
extern std::string FIND;
extern std::string SAVE;
extern std::string LOAD;

class Command {
protected:
    Document &_document;
    Command(Document &document);
public:
    virtual ~Command();
    virtual void Execute() = 0;
};


class AddCommand : public Command {
private:
    std::string _new_text;
public:
    AddCommand(Document &document, std::string new_text);
    virtual void Execute();
};


class MoveCommand : public Command {
private:
    int _new_index;
public:
    MoveCommand(Document &document, int new_index);
    virtual void Execute();
};


class InsertCommand : public Command {
private:
    int _position;
    std::string _new_text;
public:
    InsertCommand(Document &document, std::string new_text, int position);
    virtual void Execute();
};


class PutCommand : public Command {
private:
    std::string _new_text;
public:
    PutCommand(Document &document, std::string new_text);
    virtual void Execute();
};


class RemoveCommand : public Command {
private:
    int _start_index;
    int _end_index;
public:
    RemoveCommand(Document &document, int start_index, int end_index);
    virtual void Execute();
};


class DeleteSymbolCommand : public Command {
public:
    DeleteSymbolCommand(Document &document);
    virtual void Execute();
};


class DeleteFewSymbolsCommand : public Command {
private:
    int _symbols_number;
public:
    DeleteFewSymbolsCommand(Document &document, int symbols_number);
    virtual void Execute();
};


class MoveLeftOnSomeWordsCommand : public Command {
private:
    int _words_number;
public:
    MoveLeftOnSomeWordsCommand(Document &document, int words_number);
    virtual void Execute();
};


class MoveRightOnSomeWordsCommand : public Command {
private:
    int _words_number;
public:
    MoveRightOnSomeWordsCommand(Document &document, int words_number);
    virtual void Execute();
};


class UpCaseCommand : public Command {
public:
    UpCaseCommand(Document &document);
    virtual void Execute();
};


class LowCaseCommand : public Command { 
public:
    LowCaseCommand(Document &document);
    virtual void Execute();
};


class FindCommand : public Command {
private:
    std::string _needed_text;
public:
    FindCommand(Document &document, std::string needed_text);
    virtual void Execute();
};


class ReplaceCommand : public Command {
private:
    std::string _old_text;
    std::string _new_text;
public:
    ReplaceCommand(Document &document, std::string old_text, std::string new_text);
    virtual void Execute();
};


class SaveCommand : public Command {
private:
    std::string _name;
public:
    SaveCommand(Document &document, std::string name);
    virtual void Execute();
};


class LoadCommand : public Command {
private:
    std::string _name;
public:
    LoadCommand(Document &document, std::string name);
    virtual void Execute();
};
