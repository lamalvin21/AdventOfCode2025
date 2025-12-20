cmake_minimum_required(VERSION 3.10)
project(AdventOfCode2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(advent src/main.cpp src/dayOne/dayOne.cpp)

# Tests
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(dayOneTest src/test/dayOneTest.cpp src/dayOne/dayOne.cpp)
target_link_libraries(dayOneTest gtest_main)
add_test(NAME dayOneTest COMMAND dayOneTest)
