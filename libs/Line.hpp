#ifndef Line_hpp
#define Line_hpp

#include <iostream>

struct Line {
    std::string text;
    int number;

    Line(std::string text, const int number) {
        this->text = text;
        this->number = number;
    }
};

#endif /* Line_hpp */
