#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "InputsDatos.h"
#include "parser.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int resultado;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			resultado = parser_PassengerFromText(pArchivo, pArrayListPassenger);
			if(resultado == 1)
			{
				retorno = 1;
			}
			else
			{
				printf("ERROR\n");
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* lecturaPasajeros;
	int cantidadPasajeros;
	int retorno = -1;
	char tipoPasajeroAuxiliar[50];
	char estadoVueloAuxiliar[50];
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;

	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		printf("||   ID   ||     NOMBRE     ||    APELLIDO    ||     PRECIO     ||CODIGO DE VUELO||TIPO DE PASAJERO||ESTADO DEL VUELO||\n");
		for(int i=0; i<cantidadPasajeros; i++)
		{
			lecturaPasajeros = ll_get(pArrayListPassenger, i);
			if(lecturaPasajeros != NULL)
			{
				if(Passenger_getId(lecturaPasajeros, &id)==0)
				{
					if(Passenger_getNombre(lecturaPasajeros, nombre)==0)
					{
						if(Passenger_getApellido(lecturaPasajeros, apellido)==0)
						{
							if(Passenger_getPrecio(lecturaPasajeros, &precio)==0)
							{
								if(Passenger_getCodigoVuelo(lecturaPasajeros, codigoVuelo)==0)
								{
									if(Passenger_getTipoPasajero(lecturaPasajeros, &tipoPasajero)==0)
									{
										if(Passenger_getEstado(lecturaPasajeros, &estadoVuelo)==0)
										{
											if(Passenger_showTipoPasajero(tipoPasajeroAuxiliar, tipoPasajero)==1)
											{
												if(Passenger_showEstadoVuelo(estadoVueloAuxiliar, estadoVuelo)==1)
												{
													printf("||%8d||%16s||%16s||%16.2f||%15s||%16s||%16s||\n",
															id,
															nombre,
															apellido,
															precio,
															codigoVuelo,
															tipoPasajeroAuxiliar,
															estadoVueloAuxiliar);
													retorno = 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
				else
				{
					printf("No se pudo mostrar al pasajero.\n");
				}
			}
		}
	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* lecturaPasajeros;
	Passenger auxiliar;
	int cantidadPasajeros;
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		for(int i=0; i<cantidadPasajeros-1; i++)
		{
			lecturaPasajeros = ll_get(pArrayListPassenger, i);
			for(int j=i+1; j<cantidadPasajeros; j++)
			{
				//Tengo que usar la funcion de Passenger_compareByName. Despues deberia usar una de las funciones LinkedList
				//ll_set , ll_push , ll_pop
			}

		}
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

