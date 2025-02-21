#include "include/document.hpp"


// Document::Document(std::string text, std::string name, std::string path_to_folder) : _name(name), _path_to_folder(path_to_folder), _text(text) {}
Document::Document(std::string text, std::string name) : _name(name), _text(text), _cursor_position(0), _error_message("") {}

std::string & Document::GetDocumentText() {
    return _text;
}

int & Document::GetCursorPosition() {
    return _cursor_position;
}

std::map<int, int> & Document::GetHighlighting() {
    return _highlighting;
}

std::string & Document::GetErrorMessage() {
    return _error_message;
}