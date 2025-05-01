# собираем логику в lib
add_library(MazeLib
        Maze.cpp
        MazeLoader.cpp
)
target_include_directories(MazeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# собрали приложение
add_executable(MazeApp main.cpp)
add_dependencies(MazeApp copy_data)   # чтобы перед запуском копировался data.txt
target_link_libraries(MazeApp PRIVATE MazeLib)

# тесты
if (BUILD_TESTING)
    add_executable(MazeTest MazeTest.cpp)
    target_link_libraries(MazeTest PRIVATE MazeLib GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(MazeTest)
endif()