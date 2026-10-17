#include "Libro.h"

#include <iostream>
#include <utility>

Libro::Libro(std::string titulo, std::string autor, std::string isbn)
    : titulo_(std::move(titulo)), autor_(std::move(autor)),
      isbn_(std::move(isbn)), disponible_(true) {}

const std::string& Libro::getTitulo() const { return titulo_; }
const std::string& Libro::getAutor() const { return autor_; }
const std::string& Libro::getIsbn() const { return isbn_; }
bool Libro::estaDisponible() const { return disponible_; }
void Libro::setDisponible(bool disponible) { disponible_ = disponible; }

void Libro::mostrar() const {
    std::cout << "[" << isbn_ << "] \"" << titulo_ << "\" de " << autor_
              << " - " << (disponible_ ? "Disponible" : "Prestado") << '\n';
}
