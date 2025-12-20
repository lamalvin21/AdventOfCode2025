
#include "dayOne.h"
#include <iostream>
#include "dayOneInput.h"

std::pair<int,int> processL(int currentPosition, int moveAmount) {
    int fullTurns = moveAmount / 100;
    int remainder = moveAmount % 100;
    if (remainder < 0) {
        remainder += 100;
        fullTurns -= 1;
    }

    int timesPassedZero = 0;
    if (currentPosition == 0) {
        timesPassedZero = fullTurns;
    } else {
        timesPassedZero = fullTurns + (remainder >= currentPosition ? 1 : 0);
    }

    int normalizedMove = remainder;
    int newPosition = (currentPosition - normalizedMove) % 100;
    if (newPosition < 0) newPosition += 100;
    return {newPosition, timesPassedZero};
}

std::pair<int,int> processR(int currentPosition, int moveAmount) {
    int fullTurns = moveAmount / 100;
    int remainder = moveAmount % 100;
    if (remainder < 0) {
        remainder += 100;
        fullTurns -= 1;
    }

    int timesPassedZero = 0;
    if (currentPosition == 0) {
        timesPassedZero = fullTurns;
    } else {
        int need = 100 - currentPosition;
        timesPassedZero = fullTurns + (remainder >= need ? 1 : 0);
    }

    int normalizedMove = remainder;
    int newPosition = (currentPosition + normalizedMove) % 100;
    if (newPosition < 0) newPosition += 100;
    return {newPosition, timesPassedZero};
}

// Part 1: count landings on 0 only
int dayOnePart1() {
    int landingCount = 0;
    int currentPosition = 50;

    auto moves = parseDayOneInput();
    for (auto &p : moves) {
        char dir = p.first;
        int m = p.second;
        if (dir == 'L' || dir == 'l') {
            auto res = processL(currentPosition, m);
            currentPosition = res.first;
        } else if (dir == 'R' || dir == 'r') {
            auto res = processR(currentPosition, m);
            currentPosition = res.first;
        }
        if (currentPosition == 0) ++landingCount;
    }
    return landingCount;
}

// Part 2: count every pass over 0 (including multi-pass in a single move)
int dayOnePart2() {
    int passCount = 0;
    int currentPosition = 50;

    auto moves = parseDayOneInput();
    for (auto &p : moves) {
        char dir = p.first;
        int m = p.second;
        if (dir == 'L' || dir == 'l') {
            auto res = processL(currentPosition, m);
            currentPosition = res.first;
            passCount += res.second;
        } else if (dir == 'R' || dir == 'r') {
            auto res = processR(currentPosition, m);
            currentPosition = res.first;
            passCount += res.second;
        }
    }
    return passCount;
}

int dayOne() { return dayOnePart1(); }