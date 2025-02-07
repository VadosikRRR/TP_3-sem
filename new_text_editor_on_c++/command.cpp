#include "command.hpp"

AddCommand::AddCommand(std::string &text, std::string new_text) : _text(text), _new_text(new_text) {}

void AddCommand::Execute() {
    _text.append(_new_text);
}

MoveCommand::MoveCommand(std::string &text, int old_index, int new_index) : _text(text), _old_index(old_index), _new_index(new_index) {}

void MoveCommand::Execute() {
    _old_index = _new_index;
}

InsertCommand::InsertCommand(std::string &text, std::string new_text, int old_index, int new_index) : _text(text), _new_text(new_text), _old_index(old_index), _new_index(new_index) {}

void InsertCommand::Execute() {
    Command *move = new MoveCommand(_text, _old_index, _new_index);
    move->Execute();
    delete move;

    Command *put = new PutCommand(_text, _new_text, _new_index);
    put->Execute();
    delete put;
}

PutCommand::PutCommand(std::string &text, std::string new_text, int index) : _text(text), _new_text(new_text), _index(index) {}

void PutCommand::Execute() {
    _text.insert(_index, _new_text);
}

DeleteSymbolCommand::DeleteSymbolCommand(std::string &text, int index) : _text(text), _index(index) {}

void DeleteSymbolCommand::Execute() {
    _text.erase(_index - 1, 1);
}

DeleteFewSymbolsCommand::DeleteFewSymbolsCommand(std::string &text, int index, int symbols_number) : _text(text), _index(index), _symbols_number(symbols_number) {}

void DeleteFewSymbolsCommand::Execute() {
    _text.erase(_index - _symbols_number, _symbols_number);
}

RemoveCommand::RemoveCommand(std::string &text, int old_index, int start_index, int end_index) : _text(text), _old_index(old_index), _start_index(start_index), _end_index(end_index) {}

void RemoveCommand::Execute() {
    Command *move = new MoveCommand(_text, _old_index, _start_index);
    move->Execute();
    delete move;

    _text.erase(_start_index, _end_index);
}