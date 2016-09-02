//
//  PathUtils.hpp
//  Dead_code
//
//  Created by Fredrik Christenson on 30/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#ifndef PathUtils_hpp
#define PathUtils_hpp

#include <stdio.h>
#include <vector>
#include "FileData.hpp"
std::vector<FileData> walkDirectory(
const char* directory,
std::function<FileData (char*)> callback,
std::vector<FileData> list = std::vector<FileData>()
);
#endif /* PathUtils_hpp */
