#include "src/include/text_editor.hpp"
#include <iostream>


int main() {
    TextEditor * text_editor = TextEditor::Instance();
    text_editor->Launch();
}
