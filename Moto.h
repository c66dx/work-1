// Moto.h

#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"


class Moto : public Vehiculo {
public:
    // Constructor
    Moto(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anoFabricacion, const std::string& tipoAccesorio);

    // Destructor virtual
    virtual ~Moto();

    // Métodos virtuales de la clase base
    virtual std::string obtenerTipo() const override;
    virtual std::string obtenerAccesorios() const override;
    virtual int obtenerPrecioBase() const override;

    // Nuevo método para establecer el tipo de accesorio
    void establecerTipoAccesorio(const std::string& nuevoTipoAccesorio);

private:
    std::string tipoAccesorio;
};


#endif // MOTO_H
