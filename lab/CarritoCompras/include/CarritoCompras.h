#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include <string>
#include <vector>

#include "ItemCarrito.h"

/**
 * @struct Compra
 * @brief Registro inmutable de una compra finalizada (para el historial).
 */
struct Compra {
    std::vector<std::string> lineas;  ///< "2 x Teclado = 100.00"
    double total = 0.0;
};

/**
 * @class CarritoCompras
 * @brief Conjunto de ItemCarrito (composición) con operaciones de compra.
 */
class CarritoCompras {
public:
    /**
     * @brief Agrega unidades de un producto; si ya está, suma la cantidad.
     * @return false si la cantidad es inválida o supera el stock.
     */
    bool agregarProducto(Producto& producto, int cantidad);

    /// @brief Elimina un producto del carrito por nombre.
    bool eliminarProducto(const std::string& nombre);

    /// @brief Suma de los subtotales.
    double calcularTotal() const;

    bool estaVacio() const;
    void mostrar() const;

    /**
     * @brief Finaliza la compra: descuenta stock, vacía el carrito y devuelve el registro.
     */
    Compra finalizarCompra();

private:
    std::vector<ItemCarrito> items_;
};

#endif // CARRITOCOMPRAS_H
