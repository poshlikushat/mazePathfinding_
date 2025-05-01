cmake_minimum_required(VERSION 3.15)
project(mazePathfinding)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1) Подключаем googletest
add_subdirectory(external/googletest-1.16.0)
enable_testing()

# 2) Собираем основную библиотеку/приложение
add_subdirectory(src)
add_subdirectory(inputData)

# 3) Определяем тестовый исполняемый таргет
#    Предположим, что у тебя в src/tests.cpp лежат юнит-тесты
add_executable(maze_tests src/MazeTest.cpp)

# 4) Линкуем к нему гугл-тесты
#    В зависимости от версии CMake/Googletest у тебя могут быть
#    либо таргеты gtest и gtest_main,
#    либо именованные алиасы GTest::gtest и GTest::gtest_main
target_link_libraries(maze_tests
        PRIVATE
        gtest         # или GTest::gtest
        gtest_main    # или GTest::gtest_main
)

# 5) Регистрируем тесты, чтобы `ctest` их видел
add_test(NAME MazeTests COMMAND maze_tests)