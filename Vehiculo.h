// Vehiculo.h

#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
public:
    // Constructor
    Vehiculo(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anoFabricacion);

    // Destructor virtual
    virtual ~Vehiculo();

    // Métodos virtuales puros para obtener información específica de cada vehículo
    virtual std::string obtenerTipo() const = 0;
    virtual std::string obtenerAccesorios() const = 0;
    virtual int obtenerPrecioBase() const = 0;

    // Método para obtener la marca del vehículo
    std::string obtenerMarca() const;

    // Método para obtener la cantidad de ruedas del vehículo
    int obtenerCantidadRuedas() const;

    // Método para obtener si el vehículo tiene control remoto
    bool tieneControlRemoto() const;

    // Método para obtener el año de fabricación del vehículo
    int obtenerAnoFabricacion() const;

protected:
    int cantidadRuedas;
    std::string marca;
    bool controlRemoto;
    int anoFabricacion;
};

#endif // VEHICULO_H

