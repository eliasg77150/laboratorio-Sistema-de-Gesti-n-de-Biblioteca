#include "Auto.h"

#include <iostream>
#include <utility>

Auto::Auto(std::string marca, std::string modelo, std::string placa, int capacidadPasajeros)
    : Vehiculo(std::move(marca), std::move(modelo), std::move(placa)),
      capacidadPasajeros_(capacidadPasajeros) {}

int Auto::getCapacidadPasajeros() const { return capacidadPasajeros_; }

void Auto::mostrarInformacion() const {
    std::cout << "[Auto] ";
    Vehiculo::mostrarInformacion();
    std::cout << " | pasajeros: " << capacidadPasajeros_ << '\n';
}
