#include "Bicicleta.h"

#include <iostream>
#include <utility>

Bicicleta::Bicicleta(std::string marca, std::string modelo, std::string placa, TipoBicicleta tipo)
    : Vehiculo(std::move(marca), std::move(modelo), std::move(placa)), tipo_(tipo) {}

TipoBicicleta Bicicleta::getTipo() const { return tipo_; }

const char* Bicicleta::tipoATexto(TipoBicicleta tipo) {
    switch (tipo) {
        case TipoBicicleta::Montana: return "montaña";
        case TipoBicicleta::Ruta:    return "ruta";
        case TipoBicicleta::Urbana:  return "urbana";
    }
    return "desconocido";
}

void Bicicleta::mostrarInformacion() const {
    std::cout << "[Bicicleta] ";
    Vehiculo::mostrarInformacion();
    std::cout << " | tipo: " << tipoATexto(tipo_) << '\n';
}
