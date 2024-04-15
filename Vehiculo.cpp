// Vehiculo.cpp

#include "Vehiculo.h"

Vehiculo::Vehiculo(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anoFabricacion)
    : cantidadRuedas(cantidadRuedas), marca(marca), controlRemoto(controlRemoto), anoFabricacion(anoFabricacion) {}

Vehiculo::~Vehiculo() {
    // Destructor por defecto es suficiente
}

std::string Vehiculo::obtenerMarca() const {
    return marca;
}

int Vehiculo::obtenerCantidadRuedas() const {
    return cantidadRuedas;
}

bool Vehiculo::tieneControlRemoto() const {
    return controlRemoto;
}

int Vehiculo::obtenerAnoFabricacion() const {
    return anoFabricacion;
}
