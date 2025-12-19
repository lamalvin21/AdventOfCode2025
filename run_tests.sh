#!/usr/bin/env bash
set -euo pipefail

mkdir -p build
cmake -S . -B build
cmake --build build --config Debug --target dayOneTest
ctest --test-dir build --output-on-failure -R dayOneTest || (echo "Tests failed" && exit 1)
