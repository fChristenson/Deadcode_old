//
//  main.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 30/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#include "PathUtils.hpp"
#include "FileUtils.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
    auto files = walkDirectory(argv[1], fileToFileData);
    auto possibleDeadFiles = findDeadFiles(files);
    cout << "===========================================" << endl;
    cout << "      The following files may be dead      " << endl;
    cout << "===========================================" << endl;
    for(auto file : possibleDeadFiles) {
        cout << file << endl;
    }
    return 0;
}
