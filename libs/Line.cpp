#include <iostream>
#include "StringUtils.hpp"

struct Line {
    std::string text;
    int number;

    Line(std::string text, const int number) {
        this->text = trim(text);
        this->number = number;
    }
};