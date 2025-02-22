#include "include/printer.hpp"
#include "include/constant.hpp"
#include <iostream>
#include <vector>


void hash_line(int hash_symbols_number);
void clear_console();

Printer * Printer::_instance = 0;

Printer * Printer::Instance() {
    if (!_instance) {
        _instance = new Printer();
    }
    
    return _instance;
}

int & Printer::GetHeight() {
    return _height;
}

int & Printer::GetWidth() {
    return _width;
}


Printer::Printer() {}

void Printer::Print(Document &document) {
    clear_console();
    hash_line(_width + 2);
    int cursor_position = document.GetCursorPosition();
    std::string & text = document.GetDocumentText();
    std::map<int, int> & highlighter = document.GetHighlighting();
    std::vector<int> keys;
    int keys_cnt = 0;
    for (auto pair : document.GetHighlighting()) {
        keys.push_back(pair.first);
    }

    for (int ind1 = 0; ind1 < _height; ind1++) {
        std::cout << BOUNDARY_SYMBOL;
        for (int ind2 = 0; ind2 < _width; ind2++) {
            int index = ind1 * _width + ind2;
            if (index >= text.length()) {
                std::cout << ' ';
                continue;
            }
            
            if (keys_cnt < keys.size() && index == keys[keys_cnt]) { 
                std::cout << GREEN_COLOR;
            }

            if (keys_cnt < keys.size() && index == highlighter[keys[keys_cnt]]) {
                keys_cnt++;
                std::cout << STANDART_COLOR;
            }
            
            if (index == cursor_position) {
                std::cout << RED_COLOR << text[index] << STANDART_COLOR;
                if (index >= keys[keys_cnt] && index < highlighter[keys[keys_cnt]]) {
                    std::cout << GREEN_COLOR;
                }
                
                continue;
            }
            
            std::cout << text[index];
        }

        std::cout << BOUNDARY_SYMBOL << std::endl;
    }

    hash_line(_width + 2);
    std::cout << document.GetErrorMessage() << std::endl;
}



    // if (document.GetDocumentText() == "") {
    //     return;
    // }
    
    // clear_console();
    // hash_line(_width);
    // int start_index = 0;
    // std::vector<int> keys;
    // int keys_cnt = 0;
    // for (auto pair : document.GetHighlighting()) {
    //     keys.push_back(pair.first);
    // }
    // int cursor_position = document.GetCursorPosition();
    // std::string & text = document.GetDocumentText();

    // for (int ind = 0; ind < text.length(); ind++) {
    //     std::cout << '#';
    //     int end_line = (ind / _width) * (_width + 1);

    //     if ((keys_cnt >= keys.size() || ind / _width != keys[keys_cnt] / _width) && 
    //         (ind > cursor_position || end_line < (ind > cursor_position))) {
    //         int end_index = end_line < text.length() ? 
    //                         end_line :
    //                         text.length();
    //         std::cout << text.substr(ind, end_index - ind);
    //         std::cout << '#' << std::endl;
    //         ind += end_index - ind - 1;
    //         continue;
    //     }
    //     else if ((keys_cnt >= keys.size() || ind / _width != keys[keys_cnt] / _width) && 
    //               ind < cursor_position && end_line > cursor_position) {
    //         std::cout << text.substr(ind, cursor_position - ind);
    //         std::cout << "\033[31m" << text[cursor_position] << "\033[0m";
    //         int end_index = end_line < text.length() ? 
    //                         end_line :
    //                         text.length();
    //         std::cout << text.substr(cursor_position + 1, end_index - (cursor_position + 1));
    //         std::cout << '#' << std::endl;
    //         ind += end_index - ind - 1;
    //         continue;
    //     }
        
    //     if (ind / _width == keys[keys_cnt] / _width && ind < keys[keys_cnt]) {
    //         /* code */
    //     }   
    // }
    


    // for (auto pair : document.GetHighlighting()) {
    //     if (start_index < document.GetCursorPosition() && document.GetCursorPosition() < pair.first) {
    //         std::cout << document.GetDocumentText().substr(start_index, document.GetCursorPosition() - start_index);
    //         std::cout << "\033[31m" << document.GetDocumentText()[document.GetCursorPosition()] << "\033[0m";
    //         std::cout << document.GetDocumentText().substr(document.GetCursorPosition() + 1, pair.first - (document.GetCursorPosition() + 1));
    //     }
    //     else {
    //         std::cout << document.GetDocumentText().substr(start_index, pair.first - start_index);
    //     }

    //     if (pair.first < document.GetCursorPosition() && document.GetCursorPosition() < pair.second) {
    //         std::cout << "\033[32m" << document.GetDocumentText().substr(pair.first, document.GetCursorPosition() - start_index);
    //         std::cout << "\033[31m" << document.GetDocumentText()[document.GetCursorPosition()];
    //         std::cout << "\033[32m" << document.GetDocumentText().substr(document.GetCursorPosition() + 1, pair.second - (document.GetCursorPosition() + 1)) << "\033[0m";
    //     }
    //     else {
    //         std::cout << "\033[32m" << document.GetDocumentText().substr(pair.first, pair.second - pair.first) << "\033[0m";
    //     }
        
    //     start_index = pair.second;
    // }
    
    // if (start_index > document.GetCursorPosition()) {
    //     std::cout << document.GetDocumentText().substr(start_index) << std::endl;
    //     return;
    // }

    // std::cout << document.GetDocumentText().substr(start_index, document.GetCursorPosition() - start_index);
    // std::cout << "\033[31m" << document.GetDocumentText()[document.GetCursorPosition()] << "\033[0m";
    // std::cout << document.GetDocumentText().substr(document.GetCursorPosition() + 1) << std::endl;


void hash_line(int hash_symbols_number) {
    for (int i = 0; i < hash_symbols_number; i++) {
        std::cout << '#';
    }
    
    std::cout << std::endl;
}

void clear_console() {
    std::cout << "\033[2J\033[1;1H";
}
