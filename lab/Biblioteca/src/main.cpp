#include <iostream>

#include "Biblioteca.h"

static void imprimir(const std::vector<Libro>& libros) {
    if (libros.empty()) std::cout << "  (sin resultados)\n";
    for (const auto& l : libros) { std::cout << "  "; l.mostrar(); }
}

int main() {
    Biblioteca biblioteca;
    biblioteca.agregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", "978-0307474728"));
    biblioteca.agregarLibro(Libro("El amor en los tiempos del cólera", "Gabriel García Márquez", "978-0307389732"));
    biblioteca.agregarLibro(Libro("Clean Code", "Robert C. Martin", "978-0132350884"));
    biblioteca.agregarLibro(Libro("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842"));

    std::cout << "ISBN repetido rechazado: "
              << (biblioteca.agregarLibro(Libro("Copia", "X", "978-0132350884")) ? "no" : "sí") << "\n\n";

    std::cout << "== Disponibles ==\n";
    biblioteca.mostrarDisponibles();

    std::cout << "\n== Buscar por autor 'márquez' ==\n";
    imprimir(biblioteca.buscarPorAutor("márquez"));
    std::cout << "== Buscar por título 'c++' ==\n";
    imprimir(biblioteca.buscarPorTitulo("c++"));

    std::cout << "\n== Eliminar 'El amor en los tiempos del cólera' ==\n";
    std::cout << "Eliminado: " << (biblioteca.eliminarLibro("978-0307389732") ? "sí" : "no") << '\n';
    biblioteca.mostrarDisponibles();
    return 0;
}
