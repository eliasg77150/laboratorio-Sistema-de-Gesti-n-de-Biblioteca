#include "CarritoCompras.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

bool CarritoCompras::agregarProducto(Producto& producto, int cantidad) {
    if (cantidad <= 0) return false;
    auto it = std::find_if(items_.begin(), items_.end(), [&](const ItemCarrito& i) {
        return i.getProducto()->getNombre() == producto.getNombre();
    });
    int yaEnCarrito = (it == items_.end()) ? 0 : it->getCantidad();
    if (yaEnCarrito + cantidad > producto.getStock()) return false;
    if (it == items_.end()) items_.emplace_back(&producto, cantidad);
    else it->sumarCantidad(cantidad);
    return true;
}

bool CarritoCompras::eliminarProducto(const std::string& nombre) {
    auto it = std::remove_if(items_.begin(), items_.end(), [&](const ItemCarrito& i) {
        return i.getProducto()->getNombre() == nombre;
    });
    if (it == items_.end()) return false;
    items_.erase(it, items_.end());
    return true;
}

double CarritoCompras::calcularTotal() const {
    double total = 0.0;
    for (const auto& i : items_) total += i.subtotal();
    return total;
}

bool CarritoCompras::estaVacio() const { return items_.empty(); }

void CarritoCompras::mostrar() const {
    if (items_.empty()) { std::cout << "(carrito vacío)\n"; return; }
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& i : items_) {
        std::cout << i.getCantidad() << " x " << i.getProducto()->getNombre()
                  << " = " << i.subtotal() << '\n';
    }
    std::cout << "TOTAL: " << calcularTotal() << '\n';
}

Compra CarritoCompras::finalizarCompra() {
    Compra compra;
    compra.total = calcularTotal();
    for (const auto& i : items_) {
        std::ostringstream linea;
        linea << std::fixed << std::setprecision(2) << i.getCantidad() << " x "
              << i.getProducto()->getNombre() << " = " << i.subtotal();
        compra.lineas.push_back(linea.str());
        i.getProducto()->reducirStock(i.getCantidad());
    }
    items_.clear();
    return compra;
}
