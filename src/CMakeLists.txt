cmake_minimum_required(VERSION 3.15)
project(maze_src NONE)

# забираем зависимость от копирования
add_executable(maze_solver
        main.cpp
        Maze.cpp
        MazeLoader.cpp
        MazeTest.cpp
)
add_dependencies(maze_solver copy_data)
