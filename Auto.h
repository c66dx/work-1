// Auto.h

#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

class Auto : public Vehiculo {
public:
    // Constructor
    Auto(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anFabricacion, const std::string& tipoAccesorio);

    // Destructor virtual
    virtual ~Auto();

    // Métodos virtuales de la clase base
    virtual std::string obtenerTipo() const override;
    virtual std::string obtenerAccesorios() const override;
    virtual int obtenerPrecioBase() const override;

    // Nuevo método para establecer el tipo de accesorio
    void establecerTipoAccesorio(const std::string& nuevoTipoAccesorio);

private:
    std::string tipoAccesorio;
};

#endif // AUTO_H
