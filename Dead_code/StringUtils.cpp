//
//  StringUtils.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 02/09/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include "StringUtils.hpp"
#include <iostream>

std::string trim(std::string str) {
    const std::string& delimiters = " \n\r\t";
    auto trim = str.erase(str.find_last_not_of(delimiters)+1);
    trim = str.erase(0, str.find_first_not_of(delimiters));
    return trim;
};