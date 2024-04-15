// Camion.h

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"


class Camion : public Vehiculo {
public:
    // Constructor
    Camion(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anoFabricacion, const std::string& tipoAccesorio);

    // Destructor virtual
    virtual ~Camion();

    // Métodos virtuales de la clase base
    virtual std::string obtenerTipo() const override;
    virtual std::string obtenerAccesorios() const override;
    virtual int obtenerPrecioBase() const override;

    // Nuevo método para establecer el tipo de accesorio
    void establecerTipoAccesorio(const std::string& nuevoTipoAccesorio);

private:
    std::string tipoAccesorio;
};

#endif // CAMION_H
