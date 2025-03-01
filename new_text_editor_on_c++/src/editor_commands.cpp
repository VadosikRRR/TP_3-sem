#include "include/editor_commands.hpp"
#include "include/constant.hpp"
#include <string>
#include <fstream>


Command::Command(Document &document) : _document(document) {}

Command::~Command() {}

AddCommand::AddCommand(Document &document, std::string new_text) : _new_text(new_text), Command(document) {}
`
void AddCommand::Execute() {
    _document.GetDocumentText().append(_new_text);
    _document.GetCursorPosition() = _document.GetDocumentText().length() - 1;
}

MoveCommand::MoveCommand(Document &document, int new_index) : _new_index(new_index), Command(document) {}

void MoveCommand::Execute() {
    _document.GetCursorPosition() = _new_index;
}

InsertCommand::InsertCommand(Document &document, std::string new_text, int position) : _new_text(new_text), _position(position), Command(document) {}

void InsertCommand::Execute() { 
    MoveCommand move = MoveCommand(_document, _position);
    move.Execute();
    
    PutCommand put = PutCommand(_document, _new_text);
    put.Execute();
}

PutCommand::PutCommand(Document &document, std::string new_text) : _new_text(new_text), Command(document) {}

void PutCommand::Execute() {
    _document.GetDocumentText().insert(_document.GetCursorPosition(), _new_text);
    _document.GetCursorPosition() += _new_text.length() - 1;
}

DeleteSymbolCommand::DeleteSymbolCommand(Document &document) : Command(document) {}

void DeleteSymbolCommand::Execute() {
    _document.GetDocumentText().erase(_document.GetCursorPosition(), 1);
    if (_document.GetCursorPosition() == 0) {
        return;
    }
    
    _document.GetCursorPosition()--;
}

DeleteFewSymbolsCommand::DeleteFewSymbolsCommand(Document &document, int symbols_number) : _symbols_number(symbols_number), Command(document) {}

void DeleteFewSymbolsCommand::Execute() {
    if (_symbols_number == 1) {
        DeleteSymbolCommand command = DeleteSymbolCommand(_document);
        command.Execute();
        return;
    }
    

    _document.GetDocumentText().erase(_document.GetCursorPosition() - _symbols_number + 1, _symbols_number);
    _document.GetCursorPosition() -= _symbols_number;
}

RemoveCommand::RemoveCommand(Document &document, int start_index, int end_index) : _start_index(start_index), _end_index(end_index), Command(document) {}

void RemoveCommand::Execute() {
    MoveCommand move = MoveCommand(_document, _end_index);
    move.Execute();

    DeleteFewSymbolsCommand del_command = DeleteFewSymbolsCommand(_document, _end_index - _start_index + 1);
    del_command.Execute();
}

MoveLeftOnSomeWordsCommand::MoveLeftOnSomeWordsCommand(Document &document, int words_number) : _words_number(words_number), Command(document) {}

void MoveLeftOnSomeWordsCommand::Execute() { ///////////////////////////////////////////////////////////////
    int space_cnt = 0;
    int new_index;
    for (int i = _document.GetCursorPosition(); i != 0; i--) {
        if (_document.GetDocumentText()[i] != ' ') {
            continue;
        }
        
        space_cnt++;
        if (space_cnt == _words_number) {
            new_index = i;
            break;
        }
    }

    if (space_cnt < _words_number) {
        return;
    }    
    
    MoveCommand move = MoveCommand(_document, new_index);
    move.Execute();
}

MoveRightOnSomeWordsCommand::MoveRightOnSomeWordsCommand(Document &document, int words_number) : _words_number(words_number), Command(document) {}

void MoveRightOnSomeWordsCommand::Execute() { ///////////////////////////////////////////////////////////////
    int space_cnt = 0;
    int new_index;
    for (int i = _document.GetCursorPosition(); _document.GetDocumentText()[i] != '\0'; i++) {
        if (_document.GetDocumentText()[i] != ' ') {
            continue;
        }
        
        space_cnt++;
        if (space_cnt == _words_number) {
            new_index = i;
            break;
        }
    }

    if (space_cnt < _words_number) {
        return;
    }
    
    MoveCommand move = MoveCommand(_document, new_index);
    move.Execute();
}

UpCaseCommand::UpCaseCommand(Document &document) : Command(document) {}

void UpCaseCommand::Execute() {
    int start_index = 0;
    int end_index = _document.GetDocumentText().length() - 1;
    for (int i = _document.GetCursorPosition(); i != 0; i--) {
        if (_document.GetDocumentText()[i] == ' ' && i < end_index) {
            start_index = i + 1;
            break;
        }
    }

    for (int i = _document.GetCursorPosition(); _document.GetDocumentText()[i] != '\0'; i++) {
        if (_document.GetDocumentText()[i] == ' ' && i >= 1) {
            end_index = i - 1;
            break;
        }
    }

    for (int i = start_index; i <= end_index; i++){
        _document.GetDocumentText()[i] = std::toupper(_document.GetDocumentText()[i]);
    }
}

LowCaseCommand::LowCaseCommand(Document &document) : Command(document) {}

void LowCaseCommand::Execute() {
    int start_index = 0;
    int end_index = _document.GetDocumentText().length() - 1;
    for (int i = _document.GetCursorPosition(); i != 0; i--) {
        if (_document.GetDocumentText()[i] == ' ' && i < end_index) {
            start_index = i + 1;
            break;
        }
    }

    for (int i = _document.GetCursorPosition(); _document.GetDocumentText()[i] != '\0'; i++) {
        if (_document.GetDocumentText()[i] == ' ' && i >= 1) {
            end_index = i - 1;
            break;
        }
    }

    for (int i = start_index; i <= end_index; i++){
        _document.GetDocumentText()[i] = std::tolower(_document.GetDocumentText()[i]);
    }
}

FindCommand::FindCommand(Document &document, std::string needed_text) : _needed_text(needed_text), Command(document) {}

void FindCommand::Execute() {
    int start_index = _document.GetDocumentText().find(_needed_text);
    while (start_index != std::string::npos && start_index < _document.GetDocumentText().length() - _needed_text.length()) {
        int end_index = start_index + _needed_text.length();
        _document.GetHighlighting()[start_index] = end_index;
        start_index = _document.GetDocumentText().find(_needed_text, end_index);
    }
}

ReplaceCommand::ReplaceCommand(Document &document, std::string old_text, std::string new_text) : _old_text(old_text), _new_text(new_text), Command(document) {}

void ReplaceCommand::Execute() {
    FindCommand find_old_text = FindCommand(_document, _old_text);
    find_old_text.Execute();

    std::string text = "";
    int old_start_index = 0;
    int new_start_index = 0;
    int new_end_index = 0;
    std::map<int, int> new_highlighter;
    for (auto pair : _document.GetHighlighting()) {
        text += _document.GetDocumentText().substr(old_start_index, pair.first - old_start_index);
        new_start_index += pair.first - old_start_index;
        text += _new_text;
        old_start_index = pair.second;
        new_end_index = new_start_index + _new_text.length();
        new_highlighter[new_start_index] = new_end_index;
        new_start_index = new_end_index;
    }
    
    text += _document.GetDocumentText().substr(old_start_index);
    _document.GetCursorPosition() += text.length() - _document.GetDocumentText().length();
    _document.GetDocumentText() = text;
    _document.GetHighlighting() = new_highlighter;
}

SaveCommand::SaveCommand(Document &document, std::string name) : _name(name), Command(document) {}

void SaveCommand::Execute() {
    std::string path = PATH_TO_FILES + _name + DOCUMENT_EXTENSION;
    std::ofstream out_file(path);

    if (!out_file) {
        _document.GetErrorMessage() = FILE_ACCESS_ERROR + std::string(". Путь: " + path);
        return;
    }

    out_file << _document.GetDocumentText();
    out_file.close();
}

LoadCommand::LoadCommand(Document &document, std::string name) : _name(name), Command(document) {}

void LoadCommand::Execute() {
    std::string path = PATH_TO_FILES + _name + DOCUMENT_EXTENSION;
    std::ifstream in_file(path);
    if (!in_file) {
        _document.GetErrorMessage() = FILE_ACCESS_ERROR + std::string(". Путь: " + path);
        return;
    }

    // in_file >> _document.GetDocumentText();
    std::getline(in_file, _document.GetDocumentText());
    _document.GetCursorPosition() = 0;
};
