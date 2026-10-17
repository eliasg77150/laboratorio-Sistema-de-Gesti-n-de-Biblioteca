#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

/**
 * @class Producto
 * @brief Artículo de la tienda con nombre, precio y stock.
 */
class Producto {
public:
    Producto(std::string nombre, double precio, int stock);

    const std::string& getNombre() const;
    double getPrecio() const;
    int getStock() const;

    /// @brief Descuenta unidades. @return false si no hay stock suficiente.
    bool reducirStock(int cantidad);
    /// @brief Repone unidades (cantidad > 0).
    void aumentarStock(int cantidad);

private:
    std::string nombre_;
    double precio_;
    int stock_;
};

#endif // PRODUCTO_H
