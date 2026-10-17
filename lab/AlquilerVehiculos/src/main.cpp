#include <iostream>
#include <memory>

#include "Auto.h"
#include "Bicicleta.h"
#include "SistemaAlquiler.h"

int main() {
    SistemaAlquiler sistema;
    sistema.registrarVehiculo(std::make_unique<Auto>("Toyota", "Corolla", "ABC123", 5));
    sistema.registrarVehiculo(std::make_unique<Auto>("Renault", "Duster", "XYZ789", 5));
    sistema.registrarVehiculo(std::make_unique<Bicicleta>("GW", "Zebra", "BIC001", TipoBicicleta::Montana));
    sistema.registrarVehiculo(std::make_unique<Bicicleta>("Trek", "FX", "BIC002", TipoBicicleta::Urbana));

    std::cout << "Placa repetida rechazada: "
              << (sistema.registrarVehiculo(std::make_unique<Auto>("Kia", "Rio", "ABC123", 5)) ? "no" : "sí")
              << "\n\n== Disponibles ==\n";
    sistema.mostrarDisponibles();

    std::cout << "\nAlquilar ABC123: " << (sistema.alquilar("ABC123") ? "ok" : "falló") << '\n';
    std::cout << "Alquilar ABC123 otra vez: " << (sistema.alquilar("ABC123") ? "ok" : "falló") << '\n';
    std::cout << "\n== Disponibles ==\n";
    sistema.mostrarDisponibles();

    std::cout << "\nDevolver ABC123: " << (sistema.devolver("ABC123") ? "ok" : "falló") << '\n';
    std::cout << "Devolver BIC001 (no alquilada): " << (sistema.devolver("BIC001") ? "ok" : "falló") << '\n';
    std::cout << "\n== Disponibles ==\n";
    sistema.mostrarDisponibles();
    return 0;
}
