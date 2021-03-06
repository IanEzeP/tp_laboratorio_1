/*
 * FuncionesMenu.H
 *
 *  Created on: 10 abr. 2022
 *      Author: User
 */

#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

/// @brief Desde el menu principal es llamado para pedir los kil�metros del viaje.
/// @return Devuelve los kil�metros ingresados en un valor entero.
int IngresarKilometros();

/// @brief Desde el menu principal es llamado para pedir el precio del viaje con el servicio de Aerolineas.
/// @return Devuelve el precio ingresado en un valor entero.
int IngresarPrecioAerolineas();

/// @brief Desde el menu principal es llamado para pedir el precio del viaje con el servicio de Latam.
/// @return Devuelve el precio ingresado en un valor entero.
int IngresarPrecioLatam();

/// @brief Muestra en pantalla los resultados de los c�lculos realizados anteriormente con el precio del servicio de Aerolineas.
/// @param Recibe el n�mero entero correspondiente al precio ingresado del viaje con Aerolineas.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio a pagar con tarjeta de d�bito.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio a pagar con tarjeta de cr�dito.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio a pagar con Bitcoin.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio por kil�metro.
void InformarResultadosAerolineas(int, float, float, float, float);

/// @brief Muestra en pantalla los resultados de los c�lculos realizados anteriormente con el precio del servicio de Latam.
/// @param Recibe el n�mero entero correspondiente al precio ingresado del viaje con Latam.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio a pagar con tarjeta de d�bito.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio a pagar con tarjeta de cr�dito.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio a pagar con Bitcoin.
/// @param Recibe el n�mero flotante correspondiente al resultado del c�lculo del precio por kil�metro.
void InformarResultadosLatam(int, float, float, float, float);

/// @brief Carga la interfaz de usuario enumarando todas las opciones del programa.
/// @param Recibe el n�mero entero con la cantidad actual de kil�metros ingresados.
/// @param Recibe el n�mero entero con el precio ingresado para el viaje con el servicio de Aerolineas.
/// @param Recibe el n�mero entero con el precio ingresado para el viaje con el servicio de Latam.
/// @return Devuelve un n�mero entero ingresado por el usuario correspondiente a la opci�n elegida.
int CargarInterfaz(int, int, int);

#endif /* FUNCIONESMENU_H_ */
