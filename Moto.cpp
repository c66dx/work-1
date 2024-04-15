// Moto.cpp

#include "Moto.h"

Moto::Moto(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anoFabricacion, const std::string& tipoAccesorio)
    : Vehiculo(cantidadRuedas, marca, controlRemoto, anoFabricacion), tipoAccesorio(tipoAccesorio) {}

Moto::~Moto() {
    // Implementación del destructor de Moto
}

std::string Moto::obtenerTipo() const {
    return "Moto";
}

std::string Moto::obtenerAccesorios() const {
    return tipoAccesorio;
}

int Moto::obtenerPrecioBase() const {
    int precioBase = 0;
    if (marca == "Yamaha") {
        precioBase = 14000;
    } else if (marca == "Susuki") {
        precioBase = 8000;
    } else if (marca == "Honda") {
        precioBase = 15000;
    } else if (marca == "KTM") {
        precioBase = 5000;
    } else if (marca == "BMW") {
        precioBase = 18000;
    } else if (marca == "Kawasaki") {
        precioBase = 13000;
    }
    return precioBase;
}

void Moto::establecerTipoAccesorio(const std::string& nuevoTipoAccesorio) {
    tipoAccesorio = nuevoTipoAccesorio;
}
