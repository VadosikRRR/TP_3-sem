#include "parser.hpp"


Parser * Parser::_instance = 0;

Parser * Parser::Instance() {
    if (!_instance) {
        _instance = new Parser();
    }
    
    return _instance;
}

Parser::Parser() {}

std::string Parser::Parse() {
    std::string input;
    std::cout << "> ";
    if (std::getline(std::cin, input)) {
        return input;
    }
    
    return "Ban";
}
