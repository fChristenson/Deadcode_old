//
//  FileData.hpp
//  Dead_code
//
//  Created by Fredrik Christenson on 30/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#ifndef FileData_hpp
#define FileData_hpp

#include <vector>
#include "Line.hpp"

struct FileData {
    const char* filepath;
    std::vector<Line> lines;

    FileData(const char* filepath, std::vector<Line> lines = std::vector<Line>()) {
        this->filepath = filepath;
        this->lines = lines;
    }
};
#endif /* FileData_hpp */
