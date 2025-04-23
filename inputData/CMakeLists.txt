cmake_minimum_required(VERSION 3.15)
project(inputData NONE)

# Исходник:
set(DATA_SRC ${CMAKE_CURRENT_SOURCE_DIR}/data.txt)
# Куда копировать: в папку сборки src/ (где будет бинарник)
set(DATA_DST ${CMAKE_BINARY_DIR}/src/data.txt)

# Правило: копировать data.txt при каждом билде, если он изменился
add_custom_target(copy_data ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DATA_SRC}
        ${DATA_DST}
        DEPENDS ${DATA_SRC}
        COMMENT "Копируем data.txt в сборку src/"
)

# Указываем, что это правило — просто таргет без выходных артефактов
