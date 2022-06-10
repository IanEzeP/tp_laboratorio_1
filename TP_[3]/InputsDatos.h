/*
 * InputsDatos.h
 *
 *  Created on: 25 abr. 2022
 *      Author: Ian
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

/// @brief Pide al usuario el ingreso de una cadena de caracteres.
/// @param Recibe una cadena de texto para informar al usuario el dato solicitado.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @param Recibe un numero entero que definira el tamaño de la cadena.
/// @return Devuelve 0 en caso de haber obtenido una cadena correctamente y -1 en caso de que haya ocurrido un error.
int PedirString(char* mensaje, char* mensajeError, char* cadena, int lenght);

/// @brief Pide al usuario el ingreso de una cadena de caracteres compuesta por letras y numeros.
/// @param Recibe una cadena de texto para informar al usuario el dato solicitado.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @param Recibe un numero entero que definira el tamaño de la cadena.
/// @return Devuelve 0 en caso de haber obtenido una cadena correctamente y -1 en caso de que haya ocurrido un error.
int PedirStringAlfaNumerico(char* mensaje, char* mensajeError, char* cadena, int lenght);

/// @brief Valida que una cadena de texto esta compuesta por letras y numeros(excluyendo caracteres del codigo ASCII extendido).
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @return Devuelve 0 en caso de no encontrar fallas en la cadena y -1 en caso de encontrar un caracter erroneo.
int ValidarStringAlfaNumerico(char* string);

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

int isNumber(char* cadena, int limite);

int getInt(int* pResultado);

int isFloat(char* cadena, float limite);

int getFloat(float* pResultado);


#endif /* INPUTSDATOS_H_ */
