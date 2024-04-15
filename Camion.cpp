// Camion.cpp

#include "Camion.h"

Camion::Camion(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anoFabricacion, const std::string& tipoAccesorio)
    : Vehiculo(cantidadRuedas, marca, controlRemoto, anoFabricacion), tipoAccesorio(tipoAccesorio) {}

Camion::~Camion() {
    // Implementación del destructor del camion
}

std::string Camion::obtenerTipo() const {
    return "Camion";
}

std::string Camion::obtenerAccesorios() const {
    return tipoAccesorio;
}

int Camion::obtenerPrecioBase() const {
    int precioBase = 0;
    if (marca == "Volvo") {
        precioBase = 100000;
    } else if (marca == "Iveco") {
        precioBase = 85000;
    } else if (marca == "Mercedes") {
        precioBase = 110000;
    } else if (marca == "Isuzu") {
        precioBase = 70000;
    } else if (marca == "MAN") {
        precioBase = 105000;
    } else if (marca == "Scania") {
        precioBase = 95000;
    }
    return precioBase;
}

void Camion::establecerTipoAccesorio(const std::string& nuevoTipoAccesorio) {
    tipoAccesorio = nuevoTipoAccesorio;
}
