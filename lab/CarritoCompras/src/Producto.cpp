#include "Producto.h"

#include <utility>

Producto::Producto(std::string nombre, double precio, int stock)
    : nombre_(std::move(nombre)), precio_(precio), stock_(stock) {}

const std::string& Producto::getNombre() const { return nombre_; }
double Producto::getPrecio() const { return precio_; }
int Producto::getStock() const { return stock_; }

bool Producto::reducirStock(int cantidad) {
    if (cantidad <= 0 || cantidad > stock_) return false;
    stock_ -= cantidad;
    return true;
}

void Producto::aumentarStock(int cantidad) {
    if (cantidad > 0) stock_ += cantidad;
}
