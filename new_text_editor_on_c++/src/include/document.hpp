#pragma once
#include <iostream>
#include <map>


#define PATH_TO_FILES "../files/"

class Document {
private:
    int _cursor_position;
    std::string _name;
    std::string _text;
    std::map<int, int> _highlighting;
public:
    Document(std::string text, std::string name);
    std::string & GetDocumentText();
    int & GetCursorPosition();
    std::map<int, int> & GetHigjligjting();
};
