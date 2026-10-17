cmake_minimum_required(VERSION 3.16)
project(biblioteca LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(biblioteca
    src/Libro.cpp
    src/Biblioteca.cpp
    src/main.cpp
)
target_include_directories(biblioteca PRIVATE include)
if(MSVC)
    target_compile_options(biblioteca PRIVATE /W4)
else()
    target_compile_options(biblioteca PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Documentación con Doxygen (opcional): cmake --build . --target docs_biblioteca
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs)
    set(DOXYGEN_EXTRACT_ALL YES)
    doxygen_add_docs(docs_biblioteca ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src
        COMMENT "Generando documentación de biblioteca")
endif()
