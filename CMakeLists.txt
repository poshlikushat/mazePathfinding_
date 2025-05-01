cmake_minimum_required(VERSION 3.16)
project(mazePathfinding
        VERSION 0.0.1
        DESCRIPTION "Maze Pathfinding"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
option(BUILD_TESTING "Enable tests" ON)

add_subdirectory(external)
enable_testing()

add_subdirectory(inputData)

add_subdirectory(src)