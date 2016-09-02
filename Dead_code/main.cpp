//
//  main.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 30/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include <vector>
#include "PathUtils.hpp"
#include "FileData.hpp"
#include "FileUtils.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
    vector<FileData> results = walkDirectory(argv[1], fileToFileData);
    vector<string> possibleDeadFiles = findDeadFiles(results);
    return 0;
}
