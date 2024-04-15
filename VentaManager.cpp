#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>
#include <regex>
#include <locale>
#include <sstream>
#include "VentaManager.h"

// Implementacion de la funcion calcularPrecioFinalSinDescuento
double VentaManager::calcularPrecioFinalSinDescuento() {
    double precioFinalSinDescuento = 0.0;

    for (const auto& producto : productosSeleccionados) {
        precioFinalSinDescuento += producto.second.first * producto.second.second;
    }

    return precioFinalSinDescuento;
}

void VentaManager::ventaAlCliente() {
    std::vector<std::tuple<std::string, std::string, double>> preciosVehiculos;

    preciosVehiculos.emplace_back("Auto", "Toyota", 19000.0);
    preciosVehiculos.emplace_back("Auto", "Hyundai", 16000.0);
    preciosVehiculos.emplace_back("Auto", "Suzuki", 12000.0);
    preciosVehiculos.emplace_back("Auto", "Ford", 17000.0);
    preciosVehiculos.emplace_back("Auto", "Chevrolet", 18000.0);
    preciosVehiculos.emplace_back("Auto", "Honda", 21000.0);
    preciosVehiculos.emplace_back("Moto", "Yamaha", 14000.0);
    preciosVehiculos.emplace_back("Moto", "Suzuki", 8000.0);
    preciosVehiculos.emplace_back("Moto", "Honda", 15000.0);
    preciosVehiculos.emplace_back("Moto", "KTM", 5000.0);
    preciosVehiculos.emplace_back("Moto", "BMW", 18000.0);
    preciosVehiculos.emplace_back("Moto", "Kawasaki", 13000.0);
    preciosVehiculos.emplace_back("Camion", "Volvo", 100000.0);
    preciosVehiculos.emplace_back("Camion", "Iveco", 85000.0);
    preciosVehiculos.emplace_back("Camion", "Mercedes", 110000.0);
    preciosVehiculos.emplace_back("Camion", "Isuzu", 70000.0);
    preciosVehiculos.emplace_back("Camion", "MAN", 105000.0);
    preciosVehiculos.emplace_back("Camion", "Scania", 95000.0);

    std::cout << "Precios de vehiculos disponibles:" << std::endl;
    std::cout << std::setw(10) << "Tipo" << std::setw(15) << "Marca" << std::setw(10) << "Precio" << std::endl;

    std::string tipoActual = "";

    for (const auto& precio : preciosVehiculos) {
        if (std::get<0>(precio) != tipoActual) {
            std::cout << "-------------------------------------------" << std::endl;
            tipoActual = std::get<0>(precio);
        }
        std::cout << std::setw(10) << std::get<0>(precio) << std::setw(15) << std::get<1>(precio) << std::setw(10) << "$ " << std::fixed << std::setprecision(2) << std::get<2>(precio) << std::endl;
    }

    std::string tipoVehiculo;
    std::string marca;
    int cantidad;

    bool tipoVehiculoValido = false;

    do {
        std::cout << "Ingrese el tipo de vehiculo (Auto, Moto o Camion), o escriba 'exit' para salir: ";
        std::cin >> tipoVehiculo;
        tipoVehiculo[0] = toupper(tipoVehiculo[0]);

        if (tipoVehiculo == "Exit") {
            return;
        }

        if (tipoVehiculo != "Auto" && tipoVehiculo != "Moto" && tipoVehiculo != "Camion") {
            std::cout << "Tipo de vehiculo no valido. Por favor, intente nuevamente." << std::endl;
        } else {
            tipoVehiculoValido = true;
        }
    } while (!tipoVehiculoValido);

    std::vector<std::string> marcasValidas;

    if (tipoVehiculo == "Auto") {
        marcasValidas = {"Toyota", "Hyundai", "Suzuki", "Ford", "Chevrolet", "Honda"};
    } else if (tipoVehiculo == "Moto") {
        marcasValidas = {"Yamaha", "Suzuki", "Honda", "KTM", "BMW", "Kawasaki"};
    } else if (tipoVehiculo == "Camion") {
        marcasValidas = {"Volvo", "Iveco", "Mercedes", "Isuzu", "MAN", "Scania"};
    }

    bool marcaValida = false;

    do {
        std::cout << "Ingrese la marca del vehiculo";
        if (!marcasValidas.empty()) {
            std::cout << " (" << marcasValidas[0];
            for (size_t i = 1; i < marcasValidas.size(); ++i) {
                std::cout << ", " << marcasValidas[i];
            }
            std::cout << ")";
        }
        std::cout << ": ";
        std::cin >> marca;

        marca[0] = toupper(marca[0]);

        if (std::find(marcasValidas.begin(), marcasValidas.end(), marca) == marcasValidas.end()) {
            std::cout << "Marca no valida para el tipo de vehiculo seleccionado. Por favor, intente nuevamente." << std::endl;
        } else {
            marcaValida = true;
        }
    } while (!marcaValida);

    std::cout << "Ingrese la cantidad de vehiculos que desea comprar: ";
    std::cin >> cantidad;

    double precio = 0.0;

    for (const auto& precioVehiculo : preciosVehiculos) {
        if (std::get<0>(precioVehiculo) == tipoVehiculo && std::get<1>(precioVehiculo) == marca) {
            precio = std::get<2>(precioVehiculo);
            break;
        }
    }

    std::cout << "El precio unitario del vehiculo seleccionado es: $" << std::fixed << std::setprecision(2) << precio << std::endl;

    agregarProductoSeleccionado(tipoVehiculo, marca, precio, cantidad);
}

void VentaManager::ventaAccesorios() {
    std::vector<std::tuple<std::string, double>> preciosAccesorios;

    preciosAccesorios.emplace_back("Puertas", 100.0);
    preciosAccesorios.emplace_back("Luces", 60.0);
    preciosAccesorios.emplace_back("Pedales", 100.0);
    preciosAccesorios.emplace_back("Espejos", 800.0);
    preciosAccesorios.emplace_back("Caja", 1000.0);
    preciosAccesorios.emplace_back("Ejes", 800.0);

    std::cout << "Accesorios disponibles:" << std::endl;
    std::cout << std::setw(20) << "Accesorio" << std::setw(10) << "Precio" << std::endl;

    for (const auto& precio : preciosAccesorios) {
        std::cout << std::setw(20) << std::get<0>(precio) << std::setw(10) << "$ " << std::fixed << std::setprecision(2) << std::get<1>(precio) << std::endl;
    }

    std::string accesorio;
    int cantidad;

    bool accesorioValido = false;

    do {
        std::cout << "Ingrese el nombre del accesorio que desea comprar, o escriba 'exit' para salir: ";
        std::cin >> accesorio;

        if (accesorio == "Exit") {
            return;
        }

        bool encontrado = false;
        for (const auto& precio : preciosAccesorios) {
            if (std::get<0>(precio) == accesorio) {
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            std::cout << "Accesorio no valido. Por favor, intente nuevamente." << std::endl;
        } else {
            accesorioValido = true;
        }
    } while (!accesorioValido);

    double precio = 0.0;

    for (const auto& precioAccesorio : preciosAccesorios) {
        if (std::get<0>(precioAccesorio) == accesorio) {
            precio = std::get<1>(precioAccesorio);
            break;
        }
    }

    std::cout << "Ingrese la cantidad de accesorios que desea comprar: ";
    std::cin >> cantidad;

    agregarProductoSeleccionado(accesorio, "", precio, cantidad);
}

void VentaManager::confirmarCompra() {
    // Variable para almacenar la informacion de la compra
    std::stringstream compraInfo;

    verCarrito();

    double precioFinal = calcularPrecioFinal();
    double precioFinalSinDescuento = calcularPrecioFinalSinDescuento();
    double descuentoAplicado = 0.0; // Inicializamos el descuento aplicado en 0

    // Calculamos la cantidad total de productos comprados
    int cantidadTotal = 0;
    for (const auto& producto : productosSeleccionados) {
        cantidadTotal += producto.second.first;
    }

    // Aplicamos los descuentos segun la cantidad de productos comprados
    if (cantidadTotal > 10000) {
        descuentoAplicado = precioFinalSinDescuento * 0.1; // Descuento del 10%
    } else if (cantidadTotal >= 5000 && cantidadTotal <= 10000) {
        descuentoAplicado = precioFinalSinDescuento * 0.05; // Descuento del 5%
    } else if (cantidadTotal >= 1000 && cantidadTotal < 5000) {
        descuentoAplicado = precioFinalSinDescuento * 0.03; // Descuento del 3%
    } else if (cantidadTotal < 1000) {
        descuentoAplicado = precioFinalSinDescuento * 0.01; // Descuento del 1%
    }

    // Calculamos el precio final restando el descuento aplicado
    precioFinal -= descuentoAplicado;

    std::cout << "El precio final a pagar es: $" << std::fixed << std::setprecision(2) << precioFinal << std::endl;

    // Almacenar la informacion de la compra en la variable compraInfo
    compraInfo << "Nombre: " << cliente.nombre << std::endl;
    compraInfo << "Apellido: " << cliente.apellido << std::endl;
    compraInfo << "RUT: " << cliente.rut << std::endl;
    compraInfo << "Articulos comprados:" << std::endl;
    for (const auto& producto : productosSeleccionados) {
        compraInfo << producto.first << " / " << producto.second.first << " x " << producto.second.second << " = $" << (producto.second.first * producto.second.second) << std::endl;
    }

    // Agregar informacion de descuento si corresponde
    if (descuentoAplicado > 0) { // Si se aplico algun descuento
        double porcentajeDescuento = (descuentoAplicado / precioFinalSinDescuento) * 100.0;
        compraInfo << "Descuento aplicado: " << std::fixed << std::setprecision(2) << porcentajeDescuento << "%" << std::endl;
    } else {
        compraInfo << "Descuento aplicado: No se aplico descuento" << std::endl;
    }

    compraInfo << "Precio final: $" << std::fixed << std::setprecision(2) << precioFinal << std::endl;
    compraInfo << "-------------------------------------------" << std::endl;

    // Escribir la informacion de la compra en el archivo ventas.txt
    std::ofstream registroVenta("ventas.txt", std::ios::app);

    if (registroVenta.is_open()) {
        registroVenta << compraInfo.str();
        registroVenta.close();
        std::cout << "La compra ha sido registrada correctamente." << std::endl;

        // Limpiar el carrito de compras despues de confirmar la compra
        productosSeleccionados.clear();
    } else {
        std::cerr << "Error al abrir el archivo de registro de ventas." << std::endl;
    }
}

void VentaManager::verCarrito() {
    std::cout << "Productos seleccionados en el carrito:" << std::endl;
    mostrarProductosSeleccionados();
}

void VentaManager::agregarProductoSeleccionado(const std::string& tipo, const std::string& marca, double precio, int cantidad) {
    if (productosSeleccionados.find(tipo) != productosSeleccionados.end()) {
        productosSeleccionados[tipo].first += cantidad;
    } else {
        productosSeleccionados[tipo] = std::make_pair(cantidad, precio);
    }
}

void VentaManager::mostrarProductosSeleccionados() {
    for (const auto& producto : productosSeleccionados) {
        std::cout << "Tipo: " << producto.first;
        if (!producto.first.empty()) {
            std::cout << " - ";
        }
        std::cout << "Cantidad: " << producto.second.first << ", Precio unitario: $" << std::fixed << std::setprecision(2) << producto.second.second << std::endl;
    }
}

double VentaManager::calcularPrecioFinal() {
    double precioFinal = 0.0;

    for (const auto& producto : productosSeleccionados) {
        precioFinal += producto.second.first * producto.second.second;
    }

    return precioFinal;
}

double VentaManager::calcularDescuento(double precioFinalSinDescuento, int cantidadTotal) {
    double descuento = 0.0;

    if (cantidadTotal > 10000) {
        descuento = precioFinalSinDescuento * 0.10; // 10% de descuento
    } else if (cantidadTotal >= 5000 && cantidadTotal <= 10000) {
        descuento = precioFinalSinDescuento * 0.05; // 5% de descuento
    } else if (cantidadTotal >= 1000 && cantidadTotal < 5000) {
        descuento = precioFinalSinDescuento * 0.03; // 3% de descuento
    } else if (cantidadTotal < 1000) {
        descuento = precioFinalSinDescuento * 0.01; // 1% de descuento
    }

    return descuento;
}

void VentaManager::solicitarInformacionCliente() {
    std::cout << "Por favor, ingrese su nombre: ";
    std::string nombre;
    std::cin >> nombre;
    while (!esNombreValido(nombre)) {
        std::cout << "Nombre no valido. Por favor, ingrese su nombre nuevamente: ";
        std::cin >> nombre;
    }
    cliente.nombre = nombre;

    std::cout << "Por favor, ingrese su apellido: ";
    std::string apellido;
    std::cin >> apellido;
    while (!esNombreValido(apellido)) {
        std::cout << "Apellido no valido. Por favor, ingrese su apellido nuevamente: ";
        std::cin >> apellido;
    }
    cliente.apellido = apellido;

    std::string rut;
    bool rutValido = false;

    do {
        std::cout << "Por favor, ingrese su RUT (sin puntos ni guion, ej: 12345678K): ";
        std::cin >> rut;

        rutValido = validarRUT(rut);

        if (!rutValido) {
            std::cout << "RUT no valido. Por favor, intente nuevamente." << std::endl;
        }
    } while (!rutValido);

    cliente.rut = rut;
}

bool VentaManager::validarRUT(const std::string& rut) {
    // Expresion regular para validar RUT con o sin digito verificador
    std::regex rutRegex("^[0-9]{1,8}-?[0-9kK]$");
    return std::regex_match(rut, rutRegex);
}

void VentaManager::registrarVenta(const std::string& tipoVehiculo, const std::string& marca, double precio) {
    std::ofstream registroVenta("ventas.txt", std::ios::app);

    if (registroVenta.is_open()) {
        registroVenta << "Venta registrada - Tipo: " << tipoVehiculo << ", Marca: " << marca << ", Precio: $" << std::fixed << std::setprecision(2) << precio << std::endl;
        registroVenta.close();
        std::cout << "La venta ha sido registrada correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo de registro de ventas." << std::endl;
    }
}

void VentaManager::calcularCantidadTotalVehiculosComprados() {
    std::ifstream registroVenta("ventas.txt");
    std::string linea;
    int cantidadAutos = 0, cantidadMotos = 0, cantidadCamiones = 0;
    std::string nombreClienteActual = "";

    int modoBusqueda;
    std::cout << "�Desea buscar por nombre de cliente? (1: Si, 2: No): ";
    std::cin >> modoBusqueda;

    if (modoBusqueda == 1) {
        std::string nombreBuscar;
        std::cout << "Ingrese el nombre del cliente a buscar: ";
        std::cin.ignore();
        std::getline(std::cin, nombreBuscar);

        bool encontrado = false;

        if (registroVenta.is_open()) {
            while (getline(registroVenta, linea)) {
                if (linea.find("Nombre: ") != std::string::npos) {
                    nombreClienteActual = linea.substr(linea.find("Nombre: ") + 8);
                    if (nombreClienteActual == nombreBuscar) {
                        encontrado = true;
                    }
                } else if (encontrado && linea.find("Articulos comprados:") != std::string::npos) {
                    while (getline(registroVenta, linea) && linea.find("-------------------------------------------") == std::string::npos) {
                        if (linea.find("/") != std::string::npos) {
                            std::istringstream iss(linea);
                            std::string tipo, marca;
                            char slash;
                            int cantidad;
                            double precio;
                            iss >> tipo >> slash >> cantidad >> marca >> slash >> precio;
                            if (tipo == "Auto") {
                                cantidadAutos += cantidad;
                            } else if (tipo == "Moto") {
                                cantidadMotos += cantidad;
                            } else if (tipo == "Camion") {
                                cantidadCamiones += cantidad;
                            }
                        }
                    }
                    // Mostrar la cantidad de vehiculos vendidos por el cliente encontrado
                    std::cout << "Cantidad total de vehiculos vendidos por " << nombreClienteActual << ":" << std::endl;
                    std::cout << "Autos: " << cantidadAutos << std::endl;
                    std::cout << "Motos: " << cantidadMotos << std::endl;
                    std::cout << "Camiones: " << cantidadCamiones << std::endl;
                    // Restablecer las cantidades para el siguiente cliente
                    cantidadAutos = 0;
                    cantidadMotos = 0;
                    cantidadCamiones = 0;
                    encontrado = false;
                }
            }
            registroVenta.close();
        } else {
            std::cerr << "Error al abrir el archivo de registro de ventas." << std::endl;
        }
    } else if (modoBusqueda == 2) {
        if (registroVenta.is_open()) {
            while (getline(registroVenta, linea)) {
                if (linea.find("Articulos comprados:") != std::string::npos) {
                    while (getline(registroVenta, linea) && linea.find("-------------------------------------------") == std::string::npos) {
                        if (linea.find("/") != std::string::npos) {
                            std::istringstream iss(linea);
                            std::string tipo, marca;
                            char slash;
                            int cantidad;
                            double precio;
                            iss >> tipo >> slash >> cantidad >> marca >> slash >> precio;
                            if (tipo == "Auto") {
                                cantidadAutos += cantidad;
                            } else if (tipo == "Moto") {
                                cantidadMotos += cantidad;
                            } else if (tipo == "Camion") {
                                cantidadCamiones += cantidad;
                            }
                        }
                    }
                }
            }
            // Mostrar la cantidad total de vehiculos vendidos sin filtrar por nombre
            std::cout << "Cantidad total de vehiculos vendidos:" << std::endl;
            std::cout << "Autos: " << cantidadAutos << std::endl;
            std::cout << "Motos: " << cantidadMotos << std::endl;
            std::cout << "Camiones: " << cantidadCamiones << std::endl;

            registroVenta.close();
        } else {
            std::cerr << "Error al abrir el archivo de registro de ventas." << std::endl;
        }
    } else {
        std::cout << "Opcion no valida. Saliendo..." << std::endl;
    }
}

void VentaManager::calcularPromedioVentas() {
    std::ifstream registroVenta("ventas.txt");
    std::string linea;
    double totalVentas = 0.0;
    int cantidadVentas = 0;

    if (registroVenta.is_open()) {
        while (getline(registroVenta, linea)) {
            if (linea.find("Precio final: $") != std::string::npos) {
                std::smatch match;
                std::regex precioRegex("\\$\\s*([0-9]+\\.[0-9]+)");
                if (std::regex_search(linea, match, precioRegex)) {
                    totalVentas += std::stod(match[1]);
                    cantidadVentas++;
                }
            }
        }
        registroVenta.close();

        if (cantidadVentas > 0) {
            double promedioVentas = totalVentas / cantidadVentas;
            std::cout << "El promedio de ventas es: $" << std::fixed << std::setprecision(2) << promedioVentas << std::endl;
        } else {
            std::cout << "No hay ventas registradas para calcular el promedio." << std::endl;
        }
    } else {
        std::cerr << "Error al abrir el archivo de registro de ventas." << std::endl;
    }
}

void VentaManager::generarResumenDiario() {
    std::ifstream registroVenta("ventas.txt");
    std::string linea;
    std::map<std::string, int> cantidadVehiculosPorCliente;
    std::map<std::string, int> cantidadAccesoriosPorCliente;
    std::string clienteActual = "";
    int cantidadTotalVehiculos = 0;
    int cantidadClientes = 0;
    double totalVentas = 0.0;

    if (registroVenta.is_open()) {
        while (getline(registroVenta, linea)) {
            if (linea.find("Nombre: ") != std::string::npos) {
                clienteActual = linea.substr(linea.find("Nombre: ") + 8);
                cantidadClientes++;
            } else if (linea.find("Articulos comprados:") != std::string::npos) {
                while (getline(registroVenta, linea) && linea.find("-------------------------------------------") == std::string::npos) {
                    if (linea.find("/") != std::string::npos) {
                        std::istringstream iss(linea);
                        std::string tipo, marca;
                        char slash;
                        int cantidad;
                        iss >> tipo >> slash >> cantidad >> marca;
                        if (tipo == "Auto" || tipo == "Moto" || tipo == "Camion") {
                            cantidadVehiculosPorCliente[clienteActual] += cantidad;
                            cantidadTotalVehiculos += cantidad;
                        } else {
                            cantidadAccesoriosPorCliente[clienteActual] += cantidad;
                        }
                    }
                }
            } else if (linea.find("Precio final: $") != std::string::npos) {
                std::smatch match;
                std::regex precioRegex("\\$\\s*([0-9]+\\.[0-9]+)");
                if (std::regex_search(linea, match, precioRegex)) {
                    totalVentas += std::stod(match[1]);
                }
            }
        }
        registroVenta.close();

        // Mostrar el resumen diario
        std::cout << "Resumen diario de ventas:" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        calcularPromedioVentas();

        // Mostrar cantidad de vehiculos comprados por tipo para cada cliente
        std::cout << "Cantidad de vehiculos comprados por cliente:" << std::endl;
        for (const auto& pair : cantidadVehiculosPorCliente) {
            std::cout << pair.first << ": " << pair.second << " vehiculos" << std::endl;
        }
        std::cout << "-------------------------------------------" << std::endl;

        // Mostrar cantidad de accesorios comprados por tipo de vehiculo para cada cliente
        std::cout << "Cantidad de accesorios comprados por cliente:" << std::endl;
        for (const auto& pair : cantidadAccesoriosPorCliente) {
            std::cout << pair.first << ": " << pair.second << " accesorios" << std::endl;
        }
        std::cout << "-------------------------------------------" << std::endl;

        // Mostrar cantidad total de vehiculos comprados en el dia
        std::cout << "Cantidad total de vehiculos comprados en el dia: " << cantidadTotalVehiculos << std::endl;
        std::cout << "-------------------------------------------" << std::endl;

        // Mostrar el cliente que compro mas vehiculos y el que compro mas accesorios
        std::string clienteMasVehiculos = "";
        int maxVehiculos = 0;
        std::string clienteMasAccesorios = "";
        int maxAccesorios = 0;

        for (const auto& pair : cantidadVehiculosPorCliente) {
            if (pair.second > maxVehiculos) {
                clienteMasVehiculos = pair.first;
                maxVehiculos = pair.second;
            }
        }

        for (const auto& pair : cantidadAccesoriosPorCliente) {
            if (pair.second > maxAccesorios) {
                clienteMasAccesorios = pair.first;
                maxAccesorios = pair.second;
            }
        }

        std::cout << "Cliente que compro mas vehiculos: " << clienteMasVehiculos << " (" << maxVehiculos << " vehiculos)" << std::endl;
        std::cout << "Cliente que compro mas accesorios: " << clienteMasAccesorios << " (" << maxAccesorios << " accesorios)" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;

        // Mostrar el promedio de ventas totales por cantidad de clientes
        double promedioVentas = (cantidadClientes > 0) ? (totalVentas / cantidadClientes) : 0.0;
    } else {
        std::cerr << "Error al abrir el archivo de registro de ventas." << std::endl;
    }
}
