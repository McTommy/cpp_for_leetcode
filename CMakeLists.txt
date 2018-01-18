cmake_minimum_required(VERSION 3.8)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FILES main.cpp
        leetcode_new/array/myArray.cpp
        leetcode_new/search/mySearch.cpp
        leetcode_new/myQueue/myQueue.cpp
        leetcode_new/recursion/recursionAndTree.cpp
        leetcode_new/myList/LinkedList.cpp leetcode_new/dataStructure.cpp)
add_executable(algorithm ${SOURCE_FILES})