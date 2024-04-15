#include <iostream>
#include <limits> // Para el manejo de errores de entrada

#include "Utilidades.h"
#include "VentaManager.h"

void mostrarMenu() {
    std::cout << "----- MENU DE OPCIONES -----" << std::endl;
    std::cout << "1. Venta de vehiculos a clientes" << std::endl;
    std::cout << "2. Venta de accesorios" << std::endl;
    std::cout << "3. Confirmar compra" << std::endl;
    std::cout << "4. Calcular cantidad total de vehiculos vendidos" << std::endl;
    std::cout << "5. Calcular promedio de ventas" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

int main() {
    VentaManager ventaManager;
    int opcion;

    do {
        std::cout << "\n=== Menu de ventas ===" << std::endl;
        std::cout << "1. Realizar venta de vehiculo" << std::endl;
        std::cout << "2. Vender accesorios" << std::endl;
        std::cout << "3. Confirmar compra" << std::endl;
        std::cout << "4. Calcular cantidad total de vehiculos vendidos" << std::endl;
        std::cout << "5. Calcular promedio de ventas" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                ventaManager.ventaAlCliente();
                break;
            case 2:
                ventaManager.ventaAccesorios();
                break;
            case 3:
            	ventaManager.verCarrito();
                ventaManager.solicitarInformacionCliente();
                ventaManager.confirmarCompra();
                break;
            case 4:
                ventaManager.calcularCantidadTotalVehiculosComprados();
                break;
            case 5:
                ventaManager.calcularPromedioVentas();
                break;                
            case 6:
            	ventaManager.generarResumenDiario();
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Por favor, seleccione una opcion del menu." << std::endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
