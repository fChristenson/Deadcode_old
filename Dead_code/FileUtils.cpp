//
//  FileUtils.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 31/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include "FileUtils.hpp"
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
#include <regex>
#include "FileData.hpp"
#include "Line.hpp"
#include "StringUtils.hpp"
#include "Predicates.hpp"
#include "PathUtils.hpp"

std::vector<Line> findRelevantLines(
const char* filepath,
std::function<Line (std::string, int lineNumber)> callback,
std::vector<Line> result = std::vector<Line>()
) {
    int count = 1;
    std::ifstream file(filepath);
    std::string line;
    while(getline(file, line)) {
        if(isImport(line) || isRequire(line)) {
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

std::set<std::string> findUsedFiles(std::vector<FileData> files) {
    auto result = std::set<std::string>();
    for(auto data : files) {
        for (auto line : data.lines) {
            if(find(result.begin(), result.end(), line.text) == result.end()) {
                auto paths = lineToFilePaths(data.filepath, line.text);
                result.insert(paths.begin(), paths.end());
            }
        }
    }
    return result;
};

std::string removeFileEnding(const std::string& file) {
    std::regex rgx("(.+)\\.+");
    std::smatch match;
    regex_search(file.begin(), file.end(), match, rgx);
    if(match.length() > 1) {
        return trim(match[1]);
    }
    return "";
}

std::set<std::string> findFiles(std::vector<FileData> files) {
    auto results = std::set<std::string>();
    for(auto file : files) {
        results.insert(removeFileEnding(file.filepath));
    }
    return results;
}

std::set<std::string> findDeadFiles(std::vector<FileData> files) {
    auto usedFiles = findUsedFiles(files);
    auto allFiles = findFiles(files);
    auto matches = findPathMatches(usedFiles, allFiles);
    auto result = std::set<std::string>();
    std::set_difference(
                        allFiles.begin(),
                        allFiles.end(),
                        matches.begin(),
                        matches.end(),
                        std::inserter(result, result.begin()));
    std::set_difference(
                        matches.begin(),
                        matches.end(),
                        allFiles.begin(),
                        allFiles.end(),
                        std::inserter(result, result.begin()));
    return result;
};
