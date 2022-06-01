#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "InputsDatos.h"
#include "parser.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char codigoVuelo[50];
	char tipoPasajero[50];
	char estadoVuelo[50];
	int retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo)==7)
			{
				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
				if(unPasajero != NULL)
				{
					ll_add(pArrayListPassenger, unPasajero);
					retorno = 1;
				}
			}
			else
			{
				break;
			}
		}while(feof(pFile)==0);

	}

    return retorno;
}

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)//se puede dejar para despues
{

    return 1;
}
