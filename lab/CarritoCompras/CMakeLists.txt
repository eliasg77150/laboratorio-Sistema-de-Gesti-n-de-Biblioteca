cmake_minimum_required(VERSION 3.16)
project(carrito LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(carrito
    src/Producto.cpp
    src/ItemCarrito.cpp
    src/CarritoCompras.cpp
    src/Usuario.cpp
    src/main.cpp
)
target_include_directories(carrito PRIVATE include)
if(MSVC)
    target_compile_options(carrito PRIVATE /W4)
else()
    target_compile_options(carrito PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Documentación con Doxygen (opcional): cmake --build . --target docs_carrito
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs)
    set(DOXYGEN_EXTRACT_ALL YES)
    doxygen_add_docs(docs_carrito ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src
        COMMENT "Generando documentación de carrito")
endif()
