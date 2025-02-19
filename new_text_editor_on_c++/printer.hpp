#pragma once
#include "document.hpp"


class Printer {
private:
    static Printer * _instance;
protected:
    Printer();
public:
    static Printer * Instance();
    void Print(Document &docement);
};
