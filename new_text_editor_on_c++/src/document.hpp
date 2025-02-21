#pragma once
#include <iostream>
#include <map>


class Document {
private:
    int _cursor_position;
    std::string _name;
    // std::string _path_to_folder;
    std::string _text;
    std::map<int, int> _highlighting;
public:
    Document(std::string text, std::string name);
    std::string & GetDocumentText();
    int & GetCursorPosition();
    std::map<int, int> & GetHigjligjting();
};
