cmake_minimum_required(VERSION 3.8)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FILES main.cpp
        leetcode/list/LinkedList.cpp
        leetcode/list/LinkedListStructure.h
        leetcode/list/LinkedListHelper.cpp

        leetcode/stackAndQueue/stackAndQueue.cpp
        leetcode/stackAndQueue/stackAndQueueHelper.cpp leetcode/recursion/recursionAndTree.cpp leetcode/stackAndQueue/structure.h leetcode/dynamicProgramming/dynamicProgramming.cpp)
add_executable(algorithm ${SOURCE_FILES})