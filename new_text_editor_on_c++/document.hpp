#pragma once
#include <iostream>


class Document {
private:
    int _cursor_position;
    std::string _name;
    // std::string _path_to_folder;
    std::string _text;
public:
    Document(std::string text, std::string name);
    std::string & GetDocumentText();
    int & GetCursorPosition();
};
