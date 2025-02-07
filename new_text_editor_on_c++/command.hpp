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
    int _index;
    std::string _new_text;
    std::string &_text;
public:
    AddCommand(std::string &text, std::string new_text, int index);
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
