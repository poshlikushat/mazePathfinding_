# Указываем, что здесь — исходники
set(SRC
        main.cpp
        Maze.cpp
        MazeLoader.cpp
)

# Заголовки лежат в этой же папке
include_directories(${CMAKE_SOURCE_DIR}/src)

# Собираем исполняемый файл
add_executable(maze_solver ${SRC})
