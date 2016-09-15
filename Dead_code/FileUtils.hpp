//
//  FileUtils.hpp
//  Dead_code
//
//  Created by Fredrik Christenson on 31/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#ifndef FileUtils_hpp
#define FileUtils_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include <fstream>
#include "FileData.hpp"
#include "Line.hpp"

FileData fileToFileData(const char* filepath);
std::set<std::string> findDeadFiles(std::vector<FileData> files);

#endif /* FileUtils_hpp */
