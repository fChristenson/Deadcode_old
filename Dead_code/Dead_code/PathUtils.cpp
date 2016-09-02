//
//  PathUtils.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 30/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include <iostream>
#include <dirent.h>
#include <vector>
#include "FileData.hpp"
#include "PathUtils.hpp"

bool isValidFile(const char* file) {
    return strcmp(file, ".") != 0 && strcmp(file, "..") != 0;
}

bool isDir(int possibleDir) {
    return possibleDir == DT_DIR;
}

char* getFilePath(const char* directory, const char* filename) {
    char* result = new char[100];
    strcpy(result, directory);
    strcat(result, "/");
    strcat(result, filename);
    return result;
}

std::vector<FileData> walkDirectory(
const char* directory,
std::function<FileData (char*)> callback,
std::vector<FileData> list
)
{
    if (!isValidFile(directory)) {
        return std::vector<FileData>();
    }

    DIR* dir=opendir(directory);
    dirent* pdir=readdir(dir);

    while (pdir) {
        char* filepath = getFilePath(directory, pdir->d_name);
        if (isDir(pdir->d_type) && isValidFile(pdir->d_name)) {
            return walkDirectory(filepath, callback, list);
        }
        if (isValidFile(pdir->d_name)&& !isDir(pdir->d_type)) {
            list.push_back(callback(filepath));
        }
        pdir=readdir(dir);
    }
    
    closedir(dir);
    return list;
}