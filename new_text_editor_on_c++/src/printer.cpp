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
    
    int start_index = 0;

    for (auto pair : document.GetHigjligjting()) {
        if (start_index < document.GetCursorPosition() && document.GetCursorPosition() < pair.first) {
            std::cout << document.GetDocumentText().substr(start_index, document.GetCursorPosition() - start_index);
            std::cout << "\033[31m" << document.GetDocumentText()[document.GetCursorPosition()] << "\033[0m";
            std::cout << document.GetDocumentText().substr(document.GetCursorPosition() + 1, pair.first - (document.GetCursorPosition() + 1));
        }
        else {
            std::cout << document.GetDocumentText().substr(start_index, pair.first - start_index);
        }

        if (pair.first < document.GetCursorPosition() && document.GetCursorPosition() < pair.second) {
            std::cout << "\033[32m" << document.GetDocumentText().substr(pair.first, document.GetCursorPosition() - start_index);
            std::cout << "\033[31m" << document.GetDocumentText()[document.GetCursorPosition()];
            std::cout << "\033[32m" << document.GetDocumentText().substr(document.GetCursorPosition() + 1, pair.second - (document.GetCursorPosition() + 1)) << "\033[0m";
        }
        else {
            std::cout << "\033[32m" << document.GetDocumentText().substr(pair.first, pair.second - pair.first) << "\033[0m";
        }
        
        start_index = pair.second;
    }
    
    if (start_index > document.GetCursorPosition()) {
        std::cout << document.GetDocumentText().substr(start_index) << std::endl;
        return;
    }

    std::cout << document.GetDocumentText().substr(start_index, document.GetCursorPosition() - start_index);
    std::cout << "\033[31m" << document.GetDocumentText()[document.GetCursorPosition()] << "\033[0m";
    std::cout << document.GetDocumentText().substr(document.GetCursorPosition() + 1) << std::endl;
}
