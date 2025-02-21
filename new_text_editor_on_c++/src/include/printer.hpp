#pragma once
#include "document.hpp"


class Printer {
private:
    static Printer * _instance;
    int _height;
    int _width;
protected:
    Printer();
public:
    int & GetHeight();
    int & GetWidth();
    static Printer * Instance();
    void Print(Document &docement);
};
