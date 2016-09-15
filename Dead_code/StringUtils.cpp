//
//  StringUtils.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 02/09/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include "StringUtils.hpp"
#include <iostream>
#include <vector>
#include <set>

std::string trim(std::string str) {
    const std::string& delimiters = " \n\r\t";
    auto trim = str.erase(str.find_last_not_of(delimiters)+1);
    trim = str.erase(0, str.find_first_not_of(delimiters));
    return trim;
};

std::vector<std::string> splitpath(const std::string& str, const std::set<char> delimiters) {
    std::vector<std::string> result;
    char const* pch = str.c_str();
    char const* start = pch;
    for(; *pch; ++pch)
    {
        if (delimiters.find(*pch) != delimiters.end())
        {
            if (start != pch)
            {
                std::string str(start, pch);
                result.push_back(str);
            }
            else
            {
                result.push_back("");
            }
            start = pch + 1;
        }
    }
    result.push_back(start);
    return result;
}
