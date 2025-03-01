#include "include/constant.hpp"
#include "include/parser.hpp"
#include "include/constants.hpp"


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
    std::cout << START_OUTPUT;
    if (std::getline(std::cin, input)) {
        return input;
    }
    
    return INCORRECT_OUTPUT;
}
