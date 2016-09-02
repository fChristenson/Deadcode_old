//
//  Line.hpp
//  Dead_code
//
//  Created by Fredrik Christenson on 01/09/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

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
