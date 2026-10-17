#ifndef LIBRO_H
#define LIBRO_H

#include <string>

/**
 * @class Libro
 * @brief Representa un libro de la biblioteca.
 */
class Libro {
public:
    /**
     * @brief Construye un libro (disponible por defecto).
     * @param titulo Título del libro.
     * @param autor  Autor del libro.
     * @param isbn   Identificador único (ISBN o número de serie).
     */
    Libro(std::string titulo, std::string autor, std::string isbn);

    const std::string& getTitulo() const;
    const std::string& getAutor() const;
    const std::string& getIsbn() const;
    bool estaDisponible() const;

    /// @brief Cambia el estado de disponibilidad.
    void setDisponible(bool disponible);

    /// @brief Imprime el libro en una línea.
    void mostrar() const;

private:
    std::string titulo_;
    std::string autor_;
    std::string isbn_;
    bool disponible_;
};

#endif // LIBRO_H
