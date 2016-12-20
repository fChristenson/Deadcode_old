#ifndef FileUtils_hpp
#define FileUtils_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include <fstream>
#include "FileData.hpp"
#include "Line.hpp"

std::string removeFileEnding(const std::string& file);
FileData fileToFileData(const char* filepath);
std::set<std::string> findDeadFiles(std::vector<FileData> files);

#endif /* FileUtils_hpp */
