#include <vector>
#include "Line.hpp"

struct FileData {
    const char* filepath;
    std::vector<Line> lines;

    FileData(const char* filepath, std::vector<Line> lines) {
        this->filepath = filepath;
        this->lines = lines;
    }
};
