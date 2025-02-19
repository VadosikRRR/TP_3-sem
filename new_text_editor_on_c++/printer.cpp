#include "printer.hpp"
#include <iostream>


Printer * Printer::_instance = 0;

Printer * Printer::Instance() {
    if (!_instance) {
        _instance = new Printer();
    }
    
    return _instance;
}

Printer::Printer() {}

void Printer::Print(Document &document) {
    if (document.GetDocumentText() == "") {
        return;
    }
    
    std::cout << document.GetDocumentText().substr(0, document.GetCursorPosition());
    std::cout << "\033[31m" << document.GetDocumentText()[document.GetCursorPosition()] << "\033[0m";
    std::cout << document.GetDocumentText().substr(document.GetCursorPosition() + 1) << std::endl;
}
