/*
 * FuncionesMenu.H
 *
 *  Created on: 10 abr. 2022
 *      Author: User
 */

#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

/// @brief Desde el menu principal es llamado para pedir los kilómetros del viaje.
/// @return Devuelve los kilómetros ingresados en un valor entero.
int IngresarKilometros();

/// @brief Desde el menu principal es llamado para pedir el precio del viaje con el servicio de Aerolineas.
/// @return Devuelve el precio ingresado en un valor entero.
int IngresarPrecioAerolineas();

/// @brief Desde el menu principal es llamado para pedir el precio del viaje con el servicio de Latam.
/// @return Devuelve el precio ingresado en un valor entero.
int IngresarPrecioLatam();

/// @brief Muestra en pantalla los resultados de los cálculos realizados anteriormente con el precio del servicio de Aerolineas.
/// @param Recibe el número entero correspondiente al precio ingresado del viaje con Aerolineas.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio a pagar con tarjeta de débito.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio a pagar con tarjeta de crédito.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio a pagar con Bitcoin.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio por kilómetro.
void InformarResultadosAerolineas(int, float, float, float, float);

/// @brief Muestra en pantalla los resultados de los cálculos realizados anteriormente con el precio del servicio de Latam.
/// @param Recibe el número entero correspondiente al precio ingresado del viaje con Latam.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio a pagar con tarjeta de débito.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio a pagar con tarjeta de crédito.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio a pagar con Bitcoin.
/// @param Recibe el número flotante correspondiente al resultado del cálculo del precio por kilómetro.
void InformarResultadosLatam(int, float, float, float, float);

/// @brief Carga la interfaz de usuario enumarando todas las opciones del programa.
/// @param Recibe el número entero con la cantidad actual de kilómetros ingresados.
/// @param Recibe el número entero con el precio ingresado para el viaje con el servicio de Aerolineas.
/// @param Recibe el número entero con el precio ingresado para el viaje con el servicio de Latam.
/// @return Devuelve un número entero ingresado por el usuario correspondiente a la opción elegida.
int CargarInterfaz(int, int, int);

#endif /* FUNCIONESMENU_H_ */
