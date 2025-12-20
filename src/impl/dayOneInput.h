#pragma once

#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>

inline std::vector<std::pair<char,int>> parseDayOneInput(const std::string& path = "src/impl/dayOneInput.txt") {
    std::vector<std::pair<char,int>> out;
    std::ifstream ifs(path);
    if (!ifs) return out;
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        char dir = line[0];
        std::string num = line.substr(1);
        std::istringstream iss(num);
        int val = 0;
        iss >> val;
        out.emplace_back(dir, val);
    }
    return out;
}
