#include "Usuario.h"

#include <iomanip>
#include <iostream>
#include <utility>

Usuario::Usuario(std::string nombre) : nombre_(std::move(nombre)) {}

const std::string& Usuario::getNombre() const { return nombre_; }
const std::vector<Compra>& Usuario::getHistorial() const { return historial_; }

void Usuario::agregarCompra(const Compra& compra) { historial_.push_back(compra); }

void Usuario::mostrarHistorial() const {
    std::cout << "Historial de " << nombre_ << " (" << historial_.size() << " compras)\n";
    int n = 1;
    for (const auto& c : historial_) {
        std::cout << " Compra #" << n++ << ":\n";
        for (const auto& l : c.lineas) std::cout << "   " << l << '\n';
        std::cout << "   Total: " << std::fixed << std::setprecision(2) << c.total << '\n';
    }
}
