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
#include <regex>
#include "FileData.hpp"
#include "FileUtils.hpp"
#include "StringUtils.hpp"
#include "Predicates.hpp"

std::set<std::string> findPathMatches(std::set<std::string> usedFiles, std::set<std::string> allFiles) {
    auto matches = std::set<std::string>();
    for(auto file : allFiles) {
        for(auto path : usedFiles) {
            if(isFileMatch(file, path)) {
                matches.insert(file);
                break;
            }
        }
    }
    return matches;
}

std::string importToFilePath(const std::string& line) {
    std::regex rgx(".*import.*from [\"\'](.*)[\"\'];?");
    std::smatch match;
    regex_search(line.begin(), line.end(), match, rgx);
    if(match.length() > 1) {
        return trim(match[1]);
    }
    return "";
};

std::string stripRelativePath(const std::string& path) {
    std::regex rgx("\\.+/([\\w/]+)");
    std::smatch match;
    regex_search(path.begin(), path.end(), match, rgx);
    if(match.length() > 1) {
        return trim(match[1]);
    }
    return path;
};

int countDirLevels(std::vector<std::string> pathArray) {
    int result = 0;
    for(auto item : pathArray) {
        if(item == ".." || item == ".") {
            result += 1;
        }
    }
    return result;
};

std::string relativeToAbsolute(std::string absolute, std::string relative) {
    auto absoluteArray = splitpath(absolute, {'/'});
    auto relativeArray = splitpath(relative, {'/'});
    auto relativeIndex = countDirLevels(relativeArray);
    auto result = std::string();

    absoluteArray = std::vector<std::string>(absoluteArray.begin(), absoluteArray.end() - relativeIndex);
    for(auto item : absoluteArray) {
        result += item;
        result += "/";
    }

    relativeArray = std::vector<std::string>(relativeArray.begin() + relativeIndex, relativeArray.end());
    for(auto i = 0; i < relativeArray.size(); i++) {
        result += relativeArray.at(i);
        if(i != relativeArray.size() - 1) {
            result += "/";
        }
    }

    return result;
};

char* getFilePath(const char* directory, const char* filename) {
    char* result = new char[255];
    strcpy(result, directory);
    strcat(result, "/");
    strcat(result, filename);
    return result;
}

std::string requireToFilePath(const std::string& line) {
    std::regex rgx(".*require\\([\"\'](.*)[\"\']\\)");
    std::smatch match;
    regex_search(line.begin(), line.end(), match, rgx);
    if(match.length() > 1) {
        return trim(match[1]);
    }
    return "";
};

std::set<std::string> lineToFilePaths(const std::string& filepath, const std::string& line) {
    auto result = std::set<std::string>();
    auto requirePath = requireToFilePath(line);
    auto importPath = importToFilePath(line);
    if(importPath != "") {
        result.insert(removeFileEnding(relativeToAbsolute(filepath, importPath)));
    }
    else if(requirePath != "") {
        result.insert(removeFileEnding(relativeToAbsolute(filepath, requirePath)));
    }
    return result;
};

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
            auto files = walkDirectory(getFilePath(directory, pdir->d_name), callback, list);
            list.insert(list.begin(), files.begin(), files.end());
        }
        if (isValidFile(pdir->d_name) && !isDir(pdir->d_type) && isJavascriptFile(pdir->d_name)) {
            list.push_back(callback(filepath));
        }
        pdir=readdir(dir);
    }
    
    closedir(dir);
    return list;
}
