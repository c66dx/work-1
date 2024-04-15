# work-1
This is a vehicle and accessory sales management system developed in C++.

# Sistema de Gestión de Ventas de Vehículos

Este es un sistema de gestión de ventas de vehículos y accesorios desarrollado en C++. 

## Descripción

El sistema permite a los usuarios realizar ventas de vehículos y accesorios, calcular el precio final de una compra, registrar ventas en un archivo de registro y calcular estadísticas de ventas. 

## Características

- Realizar ventas de vehículos.
- Vender accesorios.
- Calcular el precio final de una compra.
- Registrar ventas en un archivo de registro.
- Calcular estadísticas de ventas, como la cantidad total de vehículos vendidos y el promedio de ventas.

## Requisitos

- Compilador de C++
- Bibliotecas estándar de C++
- Sistema operativo compatible (Windows, Linux, macOS, etc.)

## Instalación

1. Clona o descarga el repositorio.
2. Compila el código fuente utilizando un compilador de C++.
En este caso nosotros lo hacemos asi: g++ main.cpp VentaManager.cpp Auto.cpp Moto.cpp Camion.cpp Vehiculo.cpp -o programa
3. Ejecuta el programa resultante. "./programa"

## Uso

Opciones del Menú:
1. Realizar venta de vehículo: Permite al usuario seleccionar un vehículo de una lista predefinida y especificar la cantidad que desea comprar. 
2. Vender accesorios: Permite al usuario seleccionar accesorios de una lista predefinida y especificar la cantidad que desea comprar.
3. Confirmar compra: Muestra un resumen de los productos seleccionados y calcula el precio final de la compra, aplicando descuentos si corresponde. Luego, solicita al usuario información personal para registrar la venta como nombre y rut.
4. Calcular cantidad total de vehículos vendidos: Muestra la cantidad total de vehículos vendidos, discriminados por tipo (auto, moto, camión). También puede ofrecer la opción de buscar por nombre de cliente si hay ventas registradas con información de clientes.
5. Calcular promedio de ventas: Calcula el promedio de ventas realizadas, es decir, el promedio de los precios finales de todas las ventas registradas.
6. Salir: Finaliza el programa e imprime el resumen diario que incluye: el cliente que compro más vehículos entre autos, motos y camiones, el cliente que compro más accesorios entre autos, motos y camiones, la cantidad total de vehículos comprados y el promedio de ventas totales por cantidad de clientes.  

Pasos para Usar el Programa:
Seleccionar la opción deseada ingresando el número correspondiente en el menú.
Seguir las instrucciones proporcionadas por el programa para cada opción seleccionada. Por ejemplo, al realizar una venta de vehículo, el programa mostrará una lista de vehículos disponibles y solicitará al usuario que ingrese el tipo y la marca del vehículo, así como la cantidad deseada.
Una vez completadas las acciones requeridas, el programa mostrará los resultados correspondientes o solicitará más información si es necesario.
Después de cada acción, el programa volverá al menú principal, donde el usuario puede seleccionar otra opción o salir del programa si ya ha terminado.

Notas Adicionales:
El programa puede manejar múltiples ventas y calcular descuentos automáticamente según la cantidad total de productos comprados.
Los datos de las ventas se pueden registrar en un archivo de texto (ventas.txt) para mantener un registro histórico de las transacciones realizadas.
Algunas opciones, como la confirmación de compra, pueden requerir información adicional del cliente, como el nombre y el RUT, para fines de registro.
