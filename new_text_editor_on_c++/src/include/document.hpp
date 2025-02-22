#pragma once
#include "constants.hpp"
#include <iostream>
#include <map>


class Document {
private:
    int _cursor_position;
    std::string _name;
    std::string _text;
    std::string _error_message;
    std::map<int, int> _highlighting;
public:
    Document(std::string text, std::string name);
    std::string & GetDocumentText();
    int & GetCursorPosition();
    std::string & GetErrorMessage();
    std::map<int, int> & GetHighlighting();
};
