/*
 * OperacionesFunciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: User
 */

#ifndef OPERACIONESFUNCIONES_H_
#define OPERACIONESFUNCIONES_H_

/// @brief Pide el ingreso de un n�mero y lo valida en un rango espec�fico.
/// @param Recibe una cadena de texto explicando el numero que se debe ingresar.
/// @param Recibe una cadena de texto que se muestra cuando el numero ingresado esta fuera de los limites solicitados.
/// @param Recibe un numero entero que actua como limite minimo a respetar.
/// @param Recibe un numero entero que actua como limite maximo a respetar.
/// @return Devuelve el numero entero solicitado.
int PedirNumero(char mensaje[], char mensajeError[], int, int);

/// @brief Realiza los c�lculos de descuento del precio ingresado y lo resta del valor original.
/// @param Recibe un n�mero entero correspondiente al porcetaje de descuento a aplicar.
/// @param Recibe un n�mero entero correspondiente al precio ingresado sin importar la empresa de servicio.
/// @return Devuelve el precio final como numero flotante.
float CalcularPrecioTarjetaDebito(int, int);

/// @brief Realiza los c�lculos de aumento del precio ingresado y lo suma al valor original.
/// @param Recibe un n�mero entero correspondiente al porcetaje de aumento a aplicar.
/// @param Recibe un n�mero entero correspondiente al precio ingresado sin importar la empresa de servicio.
/// @return Devuelve el precio final como numero flotante.
float CalcularPrecioTarjetaCredito(int, int);

/// @brief Realiza el pasaje de pesos a Bitcoin del valor del viaje.
/// @param Recibe un n�mero flotante correspondiente a la cotizaci�n actual en pesos del Bitcoin.
/// @param Recibe un n�mero entero correspondiente al precio ingresado sin importar la empresa de servicio.
/// @return Devuelve el precio final como numero flotante.
float CalcularPrecioBitcoin(float, int);

/// @brief Realiza el calculo del precio por kilometro a recorrer.
/// @param Recibe un n�mero entero correspondiente a la cantidad de kil�metros ingresados.
/// @param Recibe un n�mero entero correspondiente al precio ingresado sin importar la empresa de servicio.
/// @return Devuelve el precio final como numero flotante.
float CalcularPrecioPorKM(int, int);

/// @brief Realiza el c�lculo de diferencia de precio para el viaje entre los servicios de Aerolineas y Latam.
/// @param Recibe un n�mero entero correspondiente al precio ingresado del viaje con Aerolineas.
/// @param Recibe un n�mero entero correspondiente al precio ingresado del viaje con Latam.
/// @return Devuelve el resultado de la diferencia como n�mero entero.
int CalcularDiferenciaAerolineasLatam(int, int);

#endif /* OPERACIONESFUNCIONES_H_ */
