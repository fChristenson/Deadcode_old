#ifndef Predicates_hpp
#define Predicates_hpp

#include <stdio.h>

bool isJavascriptFile(std::string path);

bool isFileMatch(std::string file, std::string path);

bool isValidFile(const char* file);

bool isDir(int possibleDir);

bool isRequire(std::string line);

bool isImport(std::string line);

#endif /* Predicates_hpp */
