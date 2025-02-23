#pragma once
#include <iostream>


class Parser {
private:
    static Parser * _instance;
protected:
    Parser();
public:
    static Parser * Instance();
    std::string Parse();
};
