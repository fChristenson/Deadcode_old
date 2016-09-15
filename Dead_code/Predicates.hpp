//
//  Predicates.hpp
//  Dead_code
//
//  Created by Fredrik Christenson on 09/09/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#ifndef Predicates_hpp
#define Predicates_hpp

#include <stdio.h>

bool isFileMatch(std::string file, std::string path);

bool isValidFile(const char* file);

bool isDir(int possibleDir);

bool isRequire(std::string line);

bool isImport(std::string line);

#endif /* Predicates_hpp */
