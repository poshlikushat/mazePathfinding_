cmake_minimum_required(VERSION 3.16)
project(inputData NONE)

set(DATA_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data.txt)
set(DATA_DST ${CMAKE_BINARY_DIR}/src/data1.txt)

add_custom_target(copy_data ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DATA_SRC}
        ${DATA_DST}
        DEPENDS ${DATA_SRC}
        COMMENT "Копируем data.txt в папку сборки src/"
)