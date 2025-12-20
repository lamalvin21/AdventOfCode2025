#include <iostream>
#include "impl/dayOne.h"

// ./run.sh

int main() {
    int part1 = dayOnePart1();
    int part2 = dayOnePart2();
    std::cout << "dayOne part1 (landings on 0): " << part1 << std::endl;
    std::cout << "dayOne part2 (passes over 0): " << part2 << std::endl;
    return 0;
}
