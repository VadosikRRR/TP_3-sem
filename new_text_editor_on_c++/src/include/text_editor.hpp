#pragma once
#include "document.hpp"
#include <iostream>


class TextEditor {
private:
    static TextEditor * _instance;
    Document _document;
    void ChooseText();
protected:
    TextEditor();
public:
    static TextEditor * Instance();
    void Launch();
};
