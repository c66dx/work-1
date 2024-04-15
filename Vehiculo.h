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

    // M�todos virtuales puros para obtener informaci�n espec�fica de cada veh�culo
    virtual std::string obtenerTipo() const = 0;
    virtual std::string obtenerAccesorios() const = 0;
    virtual int obtenerPrecioBase() const = 0;

    // M�todo para obtener la marca del veh�culo
    std::string obtenerMarca() const;

    // M�todo para obtener la cantidad de ruedas del veh�culo
    int obtenerCantidadRuedas() const;

    // M�todo para obtener si el veh�culo tiene control remoto
    bool tieneControlRemoto() const;

    // M�todo para obtener el a�o de fabricaci�n del veh�culo
    int obtenerAnoFabricacion() const;

protected:
    int cantidadRuedas;
    std::string marca;
    bool controlRemoto;
    int anoFabricacion;
};

#endif // VEHICULO_H

