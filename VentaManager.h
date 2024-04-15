#ifndef VENTAMANAGER_H
#define VENTAMANAGER_H

#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class VentaManager {
private:
    // Estructura para almacenar la información del cliente
    struct Cliente {
        std::string nombre;
        std::string apellido;
        std::string rut;
    };

    // Mapa para almacenar los productos seleccionados durante la venta
    std::map<std::string, std::pair<int, double>> productosSeleccionados;
    Cliente cliente;

    // Función para verificar si una cadena contiene solo letras
    bool esNombreValido(const std::string& nombre) {
        // Verificar que el nombre solo contenga letras
        for (char c : nombre) {
            if (!std::isalpha(c)) {
                return false;
            }
        }
        return true;
    }

public:
    void ventaAlCliente();
    void ventaAccesorios();
    void confirmarCompra();
    void verCarrito();
    void agregarProductoSeleccionado(const std::string& tipo, const std::string& marca, double precio, int cantidad);
    void mostrarProductosSeleccionados();
    double calcularPrecioFinal();
    double calcularPrecioFinalSinDescuento(); // Declaración de la función calcularPrecioFinalSinDescuento
    void aplicarDescuentos(double& precioFinal);
    void solicitarInformacionCliente();
    double calcularDescuento(double precio, int cantidad);
    bool validarRUT(const std::string& rut);
    void registrarVenta(const std::string& tipoVehiculo, const std::string& marca, double precio);
    void calcularCantidadTotalVehiculosComprados();
    void calcularPromedioVentas();
    void generarResumenDiario();
    double calcularPromedioVentas1(double totalVentas, int cantidadClientes);
};

#endif // VENTAMANAGER_H

