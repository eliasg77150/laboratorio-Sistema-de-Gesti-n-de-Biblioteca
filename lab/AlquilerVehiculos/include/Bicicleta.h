#ifndef BICICLETA_H
#define BICICLETA_H

#include <string>

#include "Vehiculo.h"

/// @brief Tipos de bicicleta disponibles.
enum class TipoBicicleta { Montana, Ruta, Urbana };

/**
 * @class Bicicleta
 * @brief Vehículo de pedales con un tipo (montaña, ruta, urbana).
 */
class Bicicleta : public Vehiculo {
public:
    Bicicleta(std::string marca, std::string modelo, std::string placa, TipoBicicleta tipo);

    TipoBicicleta getTipo() const;
    void mostrarInformacion() const override;

private:
    TipoBicicleta tipo_;
    static const char* tipoATexto(TipoBicicleta tipo);
};

#endif // BICICLETA_H
