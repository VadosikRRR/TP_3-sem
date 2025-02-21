#include "text_editor.hpp"
#include "manager.hpp"
#include "parser.hpp"
#include "printer.hpp"


TextEditor * TextEditor::_instance = 0;

TextEditor * TextEditor::Instance() {
    if (!_instance) {
        _instance = new TextEditor();
    }
    
    return _instance;
}

TextEditor::TextEditor() : _document(Document("", "NO NAME")) {}

void TextEditor::Launch() {
    Parser * p_parser = Parser::Instance();
    Manager * p_manager = Manager::Instance();
    Printer * p_printer = Printer::Instance();
    std::string input_text;
    while (true) {
        input_text = p_parser->Parse();
        p_manager->StringProcessing(_document, input_text);
        p_printer->Print(_document);
        _document.GetHigjligjting().clear();
    }
    
    delete p_parser;
    delete p_manager;
    delete p_printer;
}