// Utilidades.cpp

#include <iostream>
#include "Utilidades.h"

// Implementación de la función para mostrar la información de un vehículo
void mostrarInformacionVehiculo(const Vehiculo* vehiculo) {
    std::cout << "Tipo de vehículo: " << vehiculo->obtenerTipo() << std::endl;
    std::cout << "Marca: " << vehiculo->obtenerMarca() << std::endl;
    std::cout << "Cantidad de ruedas: " << vehiculo->obtenerCantidadRuedas() << std::endl;
    std::cout << "Control remoto: " << (vehiculo->tieneControlRemoto() ? "Sí" : "No") << std::endl;
    std::cout << "A�o de fabricacion: " << vehiculo->obtenerAnoFabricacion() << std::endl;
    std::cout << "Accesorios: " << vehiculo->obtenerAccesorios() << std::endl;
    std::cout << "Precio base: $" << vehiculo->obtenerPrecioBase() << std::endl;
}
