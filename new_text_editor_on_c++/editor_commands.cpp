#include "editor_commands.hpp"

Command::Command(Document &document) : _document(document) {}

Command::~Command() {}

AddCommand::AddCommand(Document &document, std::string new_text) : _new_text(new_text), Command(document) {}

std::string ADD = "add";
std::string MOVE = "move";
std::string INSERT = "insert";
std::string PUT = "put";
std::string REMOVE = "remove";
std::string DEL = "del";
std::string MOVELW = "movelw";
std::string MOVERW = "moverw";
std::string UPCASE = "upcase";
std::string LOWCASE = "lowcase";
std::string REPLACE = "replace";
std::string FIND = "find";
std::string SAVE = "save";
std::string LOAD = "load";

void AddCommand::Execute() {
    _document.GetDocumentText().append(_new_text);
    _document.GetCursorPosition() = _document.GetDocumentText().length() - 1;
}

MoveCommand::MoveCommand(Document &document, int new_index) : _new_index(new_index), Command(document) {}

void MoveCommand::Execute() {
    if (_new_index < 0 || _document.GetDocumentText().length() <= _new_index) {
        std::cout << "EBAT TI CHEL" << std::endl;;
        return;
    }
    
    _document.GetCursorPosition() = _new_index;
}

InsertCommand::InsertCommand(Document &document, std::string new_text, int position) : _new_text(new_text), _position(position), Command(document) {}

void InsertCommand::Execute() { //////////////////
    // Command *move = new MoveCommand(_document, _position);
    // move->Execute();
    // delete move;

    // Command *put = new PutCommand(_document, _new_text);
    // put->Execute();
    // delete put;

    if (_position < 0 || _document.GetDocumentText().length() <= _position) {
        std::cout << "EBAT TI CHEL" << std::endl;;
        return;
    }

    _document.GetCursorPosition() = _position;

    Command *put = new PutCommand(_document, _new_text);
    put->Execute();
    delete put;
}

PutCommand::PutCommand(Document &document, std::string new_text) : _new_text(new_text), Command(document) {}

void PutCommand::Execute() {
    _document.GetDocumentText().insert(_document.GetCursorPosition(), _new_text);
    _document.GetCursorPosition() += _new_text.length() - 1;
}

// DeleteSymbolCommand::DeleteSymbolCommand(std::string &text, int index) : _text(text), _index(index) {}

// void DeleteSymbolCommand::Execute() {
//     _text.erase(_index - 1, 1);
// }

// DeleteFewSymbolsCommand::DeleteFewSymbolsCommand(std::string &text, int index, int symbols_number) : _text(text), _index(index), _symbols_number(symbols_number) {}

// void DeleteFewSymbolsCommand::Execute() {
//     _text.erase(_index - _symbols_number, _symbols_number);
// }

// RemoveCommand::RemoveCommand(std::string &text, int old_index, int start_index, int end_index) : _text(text), _old_index(old_index), _start_index(start_index), _end_index(end_index) {}

// void RemoveCommand::Execute() {
//     Command *move = new MoveCommand(_text, _old_index, _start_index);
//     move->Execute();
//     delete move;

//     _text.erase(_start_index, _end_index);
// }

// MoveLeftOnSomeWordsCommand::MoveLeftOnSomeWordsCommand(std::string &text, int index, int words_number) : _text(text), _index(index), _words_number(words_number) {}

// void MoveLeftOnSomeWordsCommand::Execute() {
//     int new_index = find_index_after_some_words(_text, _index, _words_number, true);
//     Command *move = new MoveCommand(_text, _index, new_index);
//     move->Execute();
//     delete move;
// }//////////////////

// int find_index_after_some_words(std::string &text, int index, int words_number, bool is_reverse) {
//     return 0; ///////////////////////////////////////////////////////////////////
// }

// MoveRightOnSomeWordsCommand::MoveRightOnSomeWordsCommand(std::string &text, int index, int words_number) : _text(text), _index(index), _words_number(words_number) {}

// void MoveRightOnSomeWordsCommand::Execute() {
//     int new_index = find_index_after_some_words(_text, _index, _words_number, false);
//     Command *move = new MoveCommand(_text, _index, new_index);
//     move->Execute();
//     delete move;
// }/////////////////

// UpCaseCommand::UpCaseCommand(std::string &text, int index) : _text(text), _index(index) {}

// void UpCaseCommand::Execute() {
//     int start_index = find_index_after_some_words(_text, _index, 1, true);
//     int end_index = find_index_after_some_words(_text, _index, 1, false);
//     to_upper_str(_text, start_index, end_index);
// }

// void to_upper_str(std::string &text, int start_index, int end_index) {} ////////////////////////////////////////////////

// LowCaseCommand::LowCaseCommand(std::string &text, int index) : _text(text), _index(index) {}

// void LowCaseCommand::Execute() {
//     int start_index = find_index_after_some_words(_text, _index, 1, true);
//     int end_index = find_index_after_some_words(_text, _index, 1, false);
//     to_upper_str(_text, start_index, end_index);
// }

// void to_low_str(std::string &text, int start_index, int end_index) {} //////////////////////////////////////////////////

// FindCommand::FindCommand(std::string &text, std::string needed_text) : _text(text), _needed_text(needed_text) {}

// void FindCommand::Execute() {
//     /////////////////////
// }

// ReplaceCommand::ReplaceCommand(std::string &text, std::string old_text, std::string new_text) : _text(text), _old_text(old_text), _new_text(new_text) {}

// void ReplaceCommand::Execute() {
//     /////////////////////
// }

// SaveCommand::SaveCommand(std::string &text, std::string name, std::string path) : _text(text), _name(name), _path(path) {}

// void SaveCommand::Execute() {
//     ///////////////////////////////////
// }

// LoadCommand::LoadCommand(std::string &text, std::string name, std::string path) : _text(text), _name(name), _path(path) {}

// void LoadCommand::Execute() {
//     /////////////////////////////////////
// }
