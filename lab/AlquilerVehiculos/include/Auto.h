#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

/**
 * @class Auto
 * @brief Vehículo de cuatro ruedas con capacidad de pasajeros.
 */
class Auto : public Vehiculo {
public:
    Auto(std::string marca, std::string modelo, std::string placa, int capacidadPasajeros);

    int getCapacidadPasajeros() const;
    void mostrarInformacion() const override;

private:
    int capacidadPasajeros_;
};

#endif // AUTO_H
