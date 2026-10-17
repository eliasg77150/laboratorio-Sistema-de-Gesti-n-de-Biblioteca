#include "Biblioteca.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>

namespace {
std::string aMinuscula(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}
bool contiene(const std::string& texto, const std::string& patron) {
    return aMinuscula(texto).find(aMinuscula(patron)) != std::string::npos;
}
}  // namespace

bool Biblioteca::existe(const std::string& isbn) const {
    return std::any_of(libros_.begin(), libros_.end(),
                       [&](const Libro& l) { return l.getIsbn() == isbn; });
}

bool Biblioteca::agregarLibro(const Libro& libro) {
    if (existe(libro.getIsbn())) return false;
    libros_.push_back(libro);
    return true;
}

bool Biblioteca::eliminarLibro(const std::string& isbn) {
    auto it = std::remove_if(libros_.begin(), libros_.end(),
                             [&](const Libro& l) { return l.getIsbn() == isbn; });
    if (it == libros_.end()) return false;
    libros_.erase(it, libros_.end());
    return true;
}

std::vector<Libro> Biblioteca::buscarPorTitulo(const std::string& texto) const {
    std::vector<Libro> r;
    std::copy_if(libros_.begin(), libros_.end(), std::back_inserter(r),
                 [&](const Libro& l) { return contiene(l.getTitulo(), texto); });
    return r;
}

std::vector<Libro> Biblioteca::buscarPorAutor(const std::string& texto) const {
    std::vector<Libro> r;
    std::copy_if(libros_.begin(), libros_.end(), std::back_inserter(r),
                 [&](const Libro& l) { return contiene(l.getAutor(), texto); });
    return r;
}

void Biblioteca::mostrarDisponibles() const {
    bool alguno = false;
    for (const auto& l : libros_) {
        if (l.estaDisponible()) { l.mostrar(); alguno = true; }
    }
    if (!alguno) std::cout << "(no hay libros disponibles)\n";
}
