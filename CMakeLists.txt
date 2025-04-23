cmake_minimum_required(VERSION 3.15)
project(mazePathfinding)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Сначала собираем подпроект inputData — он скопирует data.txt
add_subdirectory(inputData)

# Потом — основной код
add_subdirectory(src)
