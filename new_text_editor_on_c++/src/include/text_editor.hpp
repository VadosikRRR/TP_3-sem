#pragma once
#include "document.hpp"
#include <iostream>


class TextEditor {
private:
    int _height;
    int _width;
    static TextEditor * _instance;
    Document _document;
    void ChooseText();
protected:
    TextEditor();
public:
    int & GetHeight();
    int & GetWidth();
    static TextEditor * Instance();
    void Launch();
};
