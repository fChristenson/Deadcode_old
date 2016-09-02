//
//  Line.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 01/09/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

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