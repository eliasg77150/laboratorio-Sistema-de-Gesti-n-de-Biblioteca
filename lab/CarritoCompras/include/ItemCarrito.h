#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "Producto.h"

/**
 * @class ItemCarrito
 * @brief Un producto dentro del carrito con su cantidad.
 *
 * Guarda un puntero NO propietario al Producto (agregación): el producto
 * pertenece al catálogo de la tienda y sobrevive al carrito.
 */
class ItemCarrito {
public:
    ItemCarrito(Producto* producto, int cantidad);

    Producto* getProducto() const;
    int getCantidad() const;
    void sumarCantidad(int cantidad);
    /// @brief precio * cantidad.
    double subtotal() const;

private:
    Producto* producto_;
    int cantidad_;
};

#endif // ITEMCARRITO_H
