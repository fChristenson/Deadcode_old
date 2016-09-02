//
//  FileUtils.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 31/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include "FileUtils.hpp"
#include <vector>
#include <fstream>
#include <algorithm>
#include <regex>
#include "FileData.hpp"
#include "Line.hpp"
#include "StringUtils.hpp"

bool isId(std::string line) {
    return std::regex_match(line, std::regex(".*id=.*"));
}

bool isClass(std::string line) {
    return std::regex_match(line, std::regex(".*class(Name)?=.*"));
}

bool isRequire(std::string line) {
    return std::regex_match(line, std::regex(".*require(.*)"));
}

bool isImport(std::string line) {
    return std::regex_match(line, std::regex("import.*from.*"));
}

std::vector<Line> findRelevantLines(
const char* filepath,
std::function<Line (std::string, int lineNumber)> callback,
std::vector<Line> result = std::vector<Line>()
) {
    int count = 1;
    std::ifstream file(filepath);
    std::string line;
    while(getline(file, line)) {
        if(isImport(line) || isRequire(line) || isClass(line) || isId(line)) {
            result.push_back(callback(line, count));
        }
        ++count;
    }
    return result;
};

Line fileLineToLine(std::string line, int lineNumber) {
    return Line(line, lineNumber);
};

FileData fileToFileData(const char* filepath) {
    return FileData(filepath, findRelevantLines(filepath, fileLineToLine));
};

std::string importToFilePath(const std::string& line) {
    std::regex rgx(".*import.*from(.*)");
    std::smatch match;
    regex_search(line.begin(), line.end(), match, rgx);
    if(match.length() > 1) {
        return trim(match[1]);
    }
    return "";
};

std::string requireToFilePath(const std::string& line) {
    std::regex rgx(".*require\\((.*)\\)");
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
    return "";
};

bool stringsAreEqual(std::string a, std::string b) {
    return a == b;
}

std::vector<std::string> lineToFilePaths(const std::string& line) {
    auto result = std::vector<std::string>();
    auto requirePath = requireToFilePath(line);
    auto importPath = importToFilePath(line);
    if(importPath != "") {
        result.push_back(stripRelativePath(importPath));
    }
    else if(requirePath != "") {
        result.push_back(stripRelativePath(requirePath));
    }
    return result;
};

std::vector<std::string> findUsedFiles(std::vector<FileData> files) {
    auto result = std::vector<std::string>();
    for(auto data : files) {
        for (auto line : data.lines) {
            if(find(result.begin(), result.end(), line.text) == result.end()) {
                auto paths = lineToFilePaths(line.text);
                result.insert(result.end(), paths.begin(), paths.end());
            }
        }
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()));
    return result;
};

std::vector<std::string> findDeadFiles(std::vector<FileData> files) {
    std::vector<std::string> usedFiles = findUsedFiles(files);
    for(auto str : usedFiles) { //TODO: get all files and then get the diff
        std::cout << str << std::endl;
    }
    return usedFiles;
};
