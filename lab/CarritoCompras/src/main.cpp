#include <iostream>

#include "CarritoCompras.h"
#include "Producto.h"
#include "Usuario.h"

int main() {
    Producto teclado("Teclado", 50.0, 10);
    Producto mouse("Mouse", 20.0, 3);
    Producto monitor("Monitor", 180.0, 2);

    Usuario maria("María");
    CarritoCompras carrito;

    carrito.agregarProducto(teclado, 2);
    carrito.agregarProducto(mouse, 1);
    carrito.agregarProducto(mouse, 1);   // se suma al ítem existente
    std::cout << "Agregar 5 monitores (stock 2): "
              << (carrito.agregarProducto(monitor, 5) ? "ok" : "rechazado") << "\n\n";

    carrito.mostrar();
    carrito.eliminarProducto("Mouse");
    std::cout << "\nTras eliminar Mouse:\n";
    carrito.mostrar();

    maria.agregarCompra(carrito.finalizarCompra());
    std::cout << "\nStock de Teclado tras comprar: " << teclado.getStock() << "\n\n";

    carrito.agregarProducto(monitor, 1);
    maria.agregarCompra(carrito.finalizarCompra());
    maria.mostrarHistorial();
    return 0;
}
