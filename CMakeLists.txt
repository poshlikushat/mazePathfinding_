# CMakeLists.txt (корень)
cmake_minimum_required(VERSION 3.16)
project(mazePathfinding
        VERSION 0.0.1
        DESCRIPTION "Maze Pathfinding"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
option(BUILD_TESTING "Enable tests" ON)

# 1) googletest
add_subdirectory(external)
enable_testing()

# 2) сначала подготовка данных
add_subdirectory(inputData)

# 3) основная логика и тесты
add_subdirectory(src)