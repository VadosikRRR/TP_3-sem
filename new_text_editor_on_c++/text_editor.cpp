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

// std::string & TextEditor::ChooseText() {
// void TextEditor::ChooseText() {
//     std::string name;
//     std::string text;
//     std::cout << "What do you want: to create new file or load file?" << std::endl;
//     std::cout << "Write 1 if you want to create new file" << std::endl;
//     std::cout << "Write 2 if you want to load file" << std::endl;
//     std::string choose;
//     std::cin >> choose;
//     if (choose == "1") { 
//         std::cout << "Write name of new file, name not must empty" << std::endl;
//         std::cin >> name;
//         text = "";
//     }
//     else {
//         std::cout << "Mmm, are you stuped?";
//     }
// }

void TextEditor::Launch() {
    Parser * p_parser = Parser::Instance();
    Manager * p_manager = Manager::Instance();
    Printer * P_printer = Printer::Instance();
    std::string input_text;
    while (true) {
        input_text = p_parser->Parse();
        p_manager->StringProcessing(_document, input_text);
        P_printer->Print(_document);
    }
}