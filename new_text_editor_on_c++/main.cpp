#include "src/include/text_editor.hpp"
#include <iostream>


int main() {
    TextEditor * text_editor = TextEditor::Instance();
    text_editor->GetHeight() = 7;
    text_editor->GetWidth() = 80;
    text_editor->Launch();
}
