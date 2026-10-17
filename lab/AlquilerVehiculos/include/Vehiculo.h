#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

/**
 * @class Vehiculo
 * @brief Clase base abstracta de los vehículos alquilables.
 */
class Vehiculo {
public:
    Vehiculo(std::string marca, std::string modelo, std::string placa);
    virtual ~Vehiculo() = default;

    /// @brief Imprime la información; las derivadas la personalizan.
    virtual void mostrarInformacion() const;

    const std::string& getMarca() const;
    const std::string& getModelo() const;
    const std::string& getPlaca() const;
    bool estaDisponible() const;
    void setDisponible(bool disponible);

private:
    std::string marca_;
    std::string modelo_;
    std::string placa_;
    bool disponible_;
};

#endif // VEHICULO_H
