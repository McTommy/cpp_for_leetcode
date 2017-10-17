cmake_minimum_required(VERSION 3.8)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp leetcode/search/intersectionofTwoArrays2.cpp leetcode/search/validAnagram.cpp)
add_executable(algorithm ${SOURCE_FILES})