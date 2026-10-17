cmake_minimum_required(VERSION 3.16)
project(alquiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(alquiler
    src/Vehiculo.cpp
    src/Auto.cpp
    src/Bicicleta.cpp
    src/SistemaAlquiler.cpp
    src/main.cpp
)
target_include_directories(alquiler PRIVATE include)
if(MSVC)
    target_compile_options(alquiler PRIVATE /W4)
else()
    target_compile_options(alquiler PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Documentación con Doxygen (opcional): cmake --build . --target docs_alquiler
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs)
    set(DOXYGEN_EXTRACT_ALL YES)
    doxygen_add_docs(docs_alquiler ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src
        COMMENT "Generando documentación de alquiler")
endif()
