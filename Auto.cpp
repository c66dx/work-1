// Auto.cpp

#include "Auto.h"

Auto::Auto(int cantidadRuedas, const std::string& marca, bool controlRemoto, int anoFabricacion, const std::string& tipoAccesorio)
    : Vehiculo(cantidadRuedas, marca, controlRemoto, anoFabricacion), tipoAccesorio(tipoAccesorio) {}

Auto::~Auto() {
    // Implementación del destructor de Auto
}

std::string Auto::obtenerTipo() const {
    return "Auto";
}

std::string Auto::obtenerAccesorios() const {
    return tipoAccesorio;
}

int Auto::obtenerPrecioBase() const {
    int precioBase = 0;
    if (marca == "Toyota") {
        precioBase = 19000;
    } else if (marca == "Hyunday") {
        precioBase = 16000;
    } else if (marca == "Susuki") {
        precioBase = 12000;
    } else if (marca == "Ford") {
        precioBase = 17000;
    } else if (marca == "Chevrolet") {
        precioBase = 18000;
    } else if (marca == "Honda") {
        precioBase = 21000;
    }
    return precioBase;
}

void Auto::establecerTipoAccesorio(const std::string& nuevoTipoAccesorio) {
    tipoAccesorio = nuevoTipoAccesorio;
}
