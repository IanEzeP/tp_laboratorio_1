/*
 * InputsDatos.h
 *
 *  Created on: 25 abr. 2022
 *      Author: User
 */

#ifndef INPUTSDATOS_H_
#define INPUTSDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief Pide al usuario el ingreso de un numero entero.
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @param Recibe una cadena de texto para informar al usuario el dato solicitado.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero entero que actua como limite minimo a respetar.
/// @param Recibe un numero entero que actua como limite maximo a respetar.
/// @return Devuelve 0 en caso de haber obtenido una cadena correctamente y -1 en caso de que haya ocurrido un error.
int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @brief Pide al usuario el ingreso de un numero flotante.
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @param Recibe una cadena de texto para informar al usuario el dato solicitado.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero flotante que actua como limite minimo a respetar.
/// @param Recibe un numero flotante que actua como limite maximo a respetar.
/// @return Devuelve 0 en caso de haber obtenido una cadena correctamente y -1 en caso de que haya ocurrido un error.
int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);

/// @brief Pide al usuario el ingreso de un caracter.
/// @param Recibe una cadena de texto para informar al usuario el dato solicitado.
/// @return Devuelve el caracter ingresado.
char PedirCaracter(char[]);

/// @brief Pide al usuario el ingreso de una cadena de caracteres.
/// @param Recibe una cadena de texto para informar al usuario el dato solicitado.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @param Recibe un numero entero que definira el tamaño de la cadena.
/// @return Devuelve 0 en caso de haber obtenido una cadena correctamente y -1 en caso de que haya ocurrido un error.
int PedirString(char* mensaje, char* mensajeError, char* cadena, int lenght);

int PedirStringAlfaNumerico(char* mensaje, char* mensajeError, char* cadena, int lenght);

/// @brief Valida un numero entero en un rango especifico.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero entero que actua como limite minimo a respetar.
/// @param Recibe un numero entero que actua como limite maximo a respetar.
/// @param Recibe el numero entero a validar.
/// @return Devuelve el numero entero tras validar que es correcto.
int ValidarRangoEntero(char[], int, int, int);

int ValidarStringAlfaNumerico(char* string);

/// @brief Valida un numero entero por fuera de un rango especifico.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero entero que actua como limite minimo a respetar.
/// @param Recibe un numero entero que actua como limite maximo a respetar.
/// @param Recibe el numero entero a validar.
/// @return Devuelve el numero entero tras validar que es correcto.
int ValidarRangoInversoEntero(char[], int, int, int);

/// @brief Valida un numero flotante en un rango especifico.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero flotante que actua como limite minimo a respetar.
/// @param Recibe un numero flotante que actua como limite maximo a respetar.
/// @param Recibe el numero flotante a validar.
/// @return Devuelve el numero flotante tras validar que es correcto.
float ValidarRangoFlotante(char[], float, float, float);

/// @brief Valida un numero flotante por fuera de un rango especifico.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero flotante que actua como limite minimo a respetar.
/// @param Recibe un numero flotante que actua como limite maximo a respetar.
/// @param Recibe el numero flotante a validar.
/// @return Devuelve el numero flotante tras validar que es correcto.
float ValidarRangoInversoFlotante(char[], float, float, float);

/// @brief Valida un caracter en un rango especifico.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe el caracter que actua como limite minimo a respetar.
/// @param Recibe el caracter que actua como limite maximo a respetar.
/// @param Recibe el caracter a validar.
/// @return Devuelve el caracter tras validar que es correcto.
char ValidarCaracter(char[], char, char, char);

/// @brief Convierte la primer letra de un string en mayuscula y el resto de caracteres a minuscula.
/// @param Recibe la cadena de caracteres a formatear.
void FormatearNombreCompleto(char cadena[]);

/// @brief Despliega una pregunta de "SI o NO" con el fin de confirmar o cancelar una accion.
/// @return Devuelve un entero en funcion de la eleccion realizada.
int ConfirmarCambios();

/// @brief Valida que todos los elementos de una cadena de texto sean letras (excluyendo caracteres del codigo ASCII extendido).
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @return Devuelve 0 en caso de no encontrar fallas en la cadena y -1 en caso de encontrar un caracter erroneo.
int ValidarString(char* string);

/// @brief Lee una cadena de caracteres hasta haber encontrado un '\n' o hasta haber copiado en la cadena un maximo de "longitud-1" caracteres.
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @param Recibe un numero entero que definira el tamaño de la cadena.
/// @return Devuelve 0 en caso de haber obtenido una cadena correctamente y -1 en caso de que haya ocurrido un error.
int myGetString(char* cadena, int lenght);

//char ValidarDistintosCaracteres(char[], char, char, char);

#endif /* INPUTSDATOS_H_ */
