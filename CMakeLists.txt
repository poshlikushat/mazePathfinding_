cmake_minimum_required(VERSION 3.15)
project(mazePathfinding)

# Требуем C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем подпапку со своим кодом
add_subdirectory(src)
