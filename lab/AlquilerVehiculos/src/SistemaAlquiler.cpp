#include "SistemaAlquiler.h"

#include <algorithm>
#include <iostream>

Vehiculo* SistemaAlquiler::buscar(const std::string& placa) const {
    auto it = std::find_if(vehiculos_.begin(), vehiculos_.end(),
                           [&](const std::unique_ptr<Vehiculo>& v) { return v->getPlaca() == placa; });
    return it == vehiculos_.end() ? nullptr : it->get();
}

bool SistemaAlquiler::registrarVehiculo(std::unique_ptr<Vehiculo> vehiculo) {
    if (!vehiculo || buscar(vehiculo->getPlaca())) return false;
    vehiculos_.push_back(std::move(vehiculo));
    return true;
}

bool SistemaAlquiler::alquilar(const std::string& placa) {
    Vehiculo* v = buscar(placa);
    if (!v || !v->estaDisponible()) return false;
    v->setDisponible(false);
    return true;
}

bool SistemaAlquiler::devolver(const std::string& placa) {
    Vehiculo* v = buscar(placa);
    if (!v || v->estaDisponible()) return false;
    v->setDisponible(true);
    return true;
}

void SistemaAlquiler::mostrarDisponibles() const {
    bool alguno = false;
    for (const auto& v : vehiculos_) {
        if (v->estaDisponible()) { v->mostrarInformacion(); alguno = true; }
    }
    if (!alguno) std::cout << "(no hay vehículos disponibles)\n";
}
