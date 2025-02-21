#include "include/text_editor.hpp"
#include "include/manager.hpp"
#include "include/parser.hpp"
#include "include/printer.hpp"


TextEditor * TextEditor::_instance = 0;

TextEditor * TextEditor::Instance() {
    if (!_instance) {
        _instance = new TextEditor();
    }
    
    return _instance;
}

int & TextEditor::GetHeight() {
    return _height;
}

int & TextEditor::GetWidth() {
    return _width;
}

TextEditor::TextEditor() : _height(25), _width(80), _document(Document("", "NO NAME")) {}

void TextEditor::Launch() {
    Parser * p_parser = Parser::Instance();
    Manager * p_manager = Manager::Instance();
    Printer * p_printer = Printer::Instance();
    p_printer->GetHeight() = _height;
    p_printer->GetWidth() = _width;
    std::string input_text;
    while (true) {
        input_text = p_parser->Parse();
        p_manager->StringProcessing(_document, input_text);
        p_printer->Print(_document);
        _document.GetHighlighting().clear();
        _document.GetErrorMessage() = "";
    }
    
    delete p_parser;
    delete p_manager;
    delete p_printer;
}