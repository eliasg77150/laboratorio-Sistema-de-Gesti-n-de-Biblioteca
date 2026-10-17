#include "Vehiculo.h"

#include <iostream>
#include <utility>

Vehiculo::Vehiculo(std::string marca, std::string modelo, std::string placa)
    : marca_(std::move(marca)), modelo_(std::move(modelo)),
      placa_(std::move(placa)), disponible_(true) {}

void Vehiculo::mostrarInformacion() const {
    std::cout << marca_ << " " << modelo_ << " | placa: " << placa_
              << " | " << (disponible_ ? "Disponible" : "Alquilado");
}

const std::string& Vehiculo::getMarca() const { return marca_; }
const std::string& Vehiculo::getModelo() const { return modelo_; }
const std::string& Vehiculo::getPlaca() const { return placa_; }
bool Vehiculo::estaDisponible() const { return disponible_; }
void Vehiculo::setDisponible(bool disponible) { disponible_ = disponible; }
