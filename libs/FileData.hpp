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
