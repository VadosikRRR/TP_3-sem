#include "command.hpp"

AddCommand::AddCommand(std::string &text, std::string new_text) : _text(text), _new_text(new_text) {}

void AddCommand::Execute() {
    _text.append(_new_text);
}

MoveCommand::MoveCommand(std::string &text, int old_index, int new_index) : _text(text), _old_index(old_index), _new_index(new_index) {}

void MoveCommand::Execute() {
    _old_index = _new_index;
}

InsertCommand::InsertCommand(std::string &text, std::string new_text, int index) : _text(text), _new_text(new_text), _index(index) {}

void InsertCommand::Execute() {
    _text.insert(_index, _new_text);
}

