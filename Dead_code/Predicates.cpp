//
//  Predicates.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 09/09/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include <regex>
#include <iostream>
#include <dirent.h>
#include "Predicates.hpp"
#include "StringUtils.hpp"

bool isFileMatch(std::string file, std::string path) {
    auto filePathArray = splitpath(file, {'/'});
    std::reverse(filePathArray.begin(), filePathArray.end());
    auto pathArray = splitpath(path, {'/'});
    std::reverse(pathArray.begin(), pathArray.end());
    for(auto i = 0; i < pathArray.size(); i++) {
        auto a = pathArray.at(i);
        auto b = filePathArray.at(i);
        if(a != b) {
            return false;
        }
    }
    return true;
}

bool isValidFile(const char* file) {
    return strcmp(file, ".") != 0 && strcmp(file, "..") != 0;
}

bool isDir(int possibleDir) {
    return possibleDir == DT_DIR;
}

bool isRequire(std::string line) {
    return std::regex_match(line, std::regex(".*require(.*)"));
}

bool isImport(std::string line) {
    return std::regex_match(line, std::regex("import.*from.*"));
}
