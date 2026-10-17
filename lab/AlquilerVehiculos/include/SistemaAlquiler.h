#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H

#include <memory>
#include <string>
#include <vector>

#include "Vehiculo.h"

/**
 * @class SistemaAlquiler
 * @brief Gestiona el registro, alquiler y devolución de vehículos.
 *
 * Es dueño de los vehículos (composición) mediante std::unique_ptr, lo que
 * permite almacenar Auto y Bicicleta en un mismo contenedor (polimorfismo).
 */
class SistemaAlquiler {
public:
    /**
     * @brief Registra un vehículo (el sistema toma su propiedad).
     * @return false si es nulo o la placa ya está registrada.
     */
    bool registrarVehiculo(std::unique_ptr<Vehiculo> vehiculo);

    /// @brief Alquila un vehículo disponible por placa.
    bool alquilar(const std::string& placa);
    /// @brief Devuelve un vehículo alquilado por placa.
    bool devolver(const std::string& placa);

    /// @brief Muestra los vehículos disponibles.
    void mostrarDisponibles() const;

private:
    std::vector<std::unique_ptr<Vehiculo>> vehiculos_;
    Vehiculo* buscar(const std::string& placa) const;
};

#endif // SISTEMAALQUILER_H
