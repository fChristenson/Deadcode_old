#ifndef PathUtils_hpp
#define PathUtils_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include "FileData.hpp"

std::set<std::string> findPathMatches(
    std::set<std::string> usedFiles,
    std::set<std::string> allFiles);

std::vector<FileData> walkDirectory(
    const char *directory,
    std::function<FileData(char *)> callback,
    std::vector<FileData> list = std::vector<FileData>());

std::set<std::string> lineToFilePaths(const std::string &filepath, const std::string &line);

std::string requireToFilePath(const std::string &line);

std::string relativeToAbsolute(std::string absolute, std::string relative);

std::string importToFilePath(const std::string &line);
#endif /* PathUtils_hpp */
