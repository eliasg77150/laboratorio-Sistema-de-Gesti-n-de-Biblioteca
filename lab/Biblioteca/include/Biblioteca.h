#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <vector>

#include "Libro.h"

/**
 * @class Biblioteca
 * @brief Gestiona una colección de libros (composición).
 */
class Biblioteca {
public:
    /**
     * @brief Agrega un libro si su ISBN no existe ya.
     * @return true si se agregó, false si el ISBN estaba repetido.
     */
    bool agregarLibro(const Libro& libro);

    /**
     * @brief Elimina un libro por ISBN.
     * @return true si existía y se eliminó.
     */
    bool eliminarLibro(const std::string& isbn);

    /// @brief Busca por coincidencia parcial en el título (sin distinguir mayúsculas).
    std::vector<Libro> buscarPorTitulo(const std::string& texto) const;
    /// @brief Busca por coincidencia parcial en el autor (sin distinguir mayúsculas).
    std::vector<Libro> buscarPorAutor(const std::string& texto) const;

    /// @brief Imprime los libros con disponible == true.
    void mostrarDisponibles() const;

private:
    std::vector<Libro> libros_;

    bool existe(const std::string& isbn) const;
};

#endif // BIBLIOTECA_H
