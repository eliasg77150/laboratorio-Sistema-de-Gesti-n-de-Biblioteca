#include "ItemCarrito.h"

ItemCarrito::ItemCarrito(Producto* producto, int cantidad)
    : producto_(producto), cantidad_(cantidad) {}

Producto* ItemCarrito::getProducto() const { return producto_; }
int ItemCarrito::getCantidad() const { return cantidad_; }
void ItemCarrito::sumarCantidad(int cantidad) { cantidad_ += cantidad; }
double ItemCarrito::subtotal() const { return producto_->getPrecio() * cantidad_; }
