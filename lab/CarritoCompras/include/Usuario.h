#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

#include "CarritoCompras.h"

/**
 * @class Usuario
 * @brief Cliente de la tienda con su historial de compras.
 */
class Usuario {
public:
    explicit Usuario(std::string nombre);

    const std::string& getNombre() const;
    const std::vector<Compra>& getHistorial() const;

    /// @brief Agrega una compra al historial.
    void agregarCompra(const Compra& compra);
    void mostrarHistorial() const;

private:
    std::string nombre_;
    std::vector<Compra> historial_;
};

#endif // USUARIO_H
