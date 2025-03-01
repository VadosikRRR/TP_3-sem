#pragma once
#include <memory>
#include <iostream>


class Parser {
private:
    static std::shared_ptr<Parser> _instance;
protected:
    Parser();
public:
    static Parser & Instance();
    std::string Parse();
};
