cmake_minimum_required(VERSION 3.16)
project(LaboratorioPOO VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Biblioteca)
add_subdirectory(AlquilerVehiculos)
add_subdirectory(CarritoCompras)
