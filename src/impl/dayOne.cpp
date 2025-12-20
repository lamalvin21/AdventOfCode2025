
#include "dayOne.h"
#include <iostream>
#include "dayOneInput.h"

int processL(int currentPosition, int moveAmount) {
    // Normalise the move within bounds (1-99)
    int normalisedMove = moveAmount % 100;
    if (normalisedMove < 0) normalisedMove += 100;

    int newPosition = (currentPosition - normalisedMove) % 100;
    if (newPosition < 0) newPosition += 100;
    return newPosition;
}

int processR(int currentPosition, int moveAmount) {
    // Normalise the move within bounds (1-99)
    int normalisedMove = moveAmount % 100;
    if (normalisedMove < 0) normalisedMove += 100;

    int newPosition = (currentPosition + normalisedMove) % 100;
    if (newPosition < 0) newPosition += 100;
    return newPosition;
}

int dayOne() {
    int zeroCount = 0;
    int value = 50;

    auto moves = parseDayOneInput();
    for (auto &p : moves) {
        char dir = p.first;
        int m = p.second;
        if (dir == 'L' || dir == 'l') {
            value = processL(value, m);
        } else if (dir == 'R' || dir == 'r') {
            value = processR(value, m);
        }
        if (value == 0) ++zeroCount;
    }
    return zeroCount;
}