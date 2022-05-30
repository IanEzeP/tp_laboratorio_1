#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

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
	char id[10];
	char nombre[50];
	char apellido[50];
	char precio[20];
	char codigoVuelo[10];
	char tipoPasajero[3];
	char estadoVuelo[3];
	int retorno = -1;

	pFile = fopen("./data.csv","r");//ya se envio abierto desde el controlador
	if(pFile != NULL)
	{
		retorno = 0;
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
					id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

			if(feof(pFile))//faltan verificaciones.
			{
				retorno = 1;
				break;
			}
			unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			ll_add(pArrayListPassenger, unPasajero);
		}
		fclose(pFile);//el controller lo cierra
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
