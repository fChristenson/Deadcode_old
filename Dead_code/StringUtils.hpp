//
//  StringUtils.hpp
//  Dead_code
//
//  Created by Fredrik Christenson on 02/09/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#ifndef StringUtils_hpp
#define StringUtils_hpp

#include <iostream>
#include <vector>
#include <set>
std::string trim(std::string str);
std::vector<std::string> splitpath(const std::string& str, const std::set<char> delimiters);
#endif /* StringUtils_hpp */
