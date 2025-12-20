#!/usr/bin/env bash
set -euo pipefail

mkdir -p build
if command -v clang++ >/dev/null 2>&1; then
  COMPILER=clang++
elif command -v g++ >/dev/null 2>&1; then
  COMPILER=g++
else
  echo "No C++ compiler found (clang++ or g++ required)." >&2
  exit 2
fi

${COMPILER} -std=c++17 -g src/main.cpp src/dayOne/dayOne.cpp src/dayTwo/dayTwo.cpp -o build/advent
./build/advent
