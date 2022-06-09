#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "InputsDatos.h"
#include "parser.h"
#include "Controller.h"

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
	FILE* pArchivo;
	int resultado;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorno = 0;
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			resultado = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
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

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int lastId)
{
	Passenger* nuevoPasajero;
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		nuevoPasajero = Passenger_requestData(lastId);
		if(nuevoPasajero != NULL)
		{
			ll_add(pArrayListPassenger, nuevoPasajero);
			retorno = 1;
		}
	}
    return retorno;
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

	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		printf("++--------++----------------++----------------++----------------++---------------++----------------++----------------++\n");
		printf("||   ID   ||     NOMBRE     ||    APELLIDO    ||     PRECIO     ||CODIGO DE VUELO||TIPO DE PASAJERO||ESTADO DEL VUELO||\n");
		printf("++--------++----------------++----------------++----------------++---------------++----------------++----------------++\n");
		for(int i=0; i<cantidadPasajeros; i++)
		{
			lecturaPasajeros = ll_get(pArrayListPassenger, i);
			if(lecturaPasajeros != NULL)
			{
				Passenger_listOne(lecturaPasajeros);
				retorno = 1;
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
	int opcion;
	int orden;
	int resultado;
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		do
		{
			printf("1. Ordenar por ID.\n");
			printf("2. Ordenar por Nombre.\n");
			printf("3. Ordenar por Apellido.\n");
			printf("4. Ordenar por Precio.\n");
			printf("5. Ordenar por Codigo de vuelo.\n");
			printf("6. Ordenar por Tipo de Pasajero.\n");
			printf("7. Ordenar por Estado de vuelo.\n");
			PedirEntero(&opcion, "8. Regresar.", "Opcion invalida! Intente nuevamente.", 0, 9);
			switch(opcion)
			{
				case 1:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						resultado = ll_sort(pArrayListPassenger, Passenger_compareByID, orden);
						if(resultado == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 2:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						resultado = ll_sort(pArrayListPassenger, Passenger_compareByName, orden);
						if(resultado == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 3:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						resultado = ll_sort(pArrayListPassenger, Passenger_compareByLastName, orden);
						if(resultado == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 4:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						resultado = ll_sort(pArrayListPassenger, Passenger_compareByPrice, orden);
						if(resultado == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 5:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						resultado = ll_sort(pArrayListPassenger, Passenger_compareByFlyCode, orden);
						if(resultado == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 6:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						resultado = ll_sort(pArrayListPassenger, Passenger_compareByTypePassenger, orden);
						if(resultado == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 7:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						resultado = ll_sort(pArrayListPassenger, Passenger_compareByStatusFlight, orden);
						if(resultado == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
			}
		}while(opcion != 8);
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
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)//ESTO
{
	FILE* pArchivo;
	Passenger* pPassenger;
	int retorno = -1;
	int cantidadPasajeros;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	char tipoPasajeroAuxiliar[50];
	char estadoVueloAuxiliar[50];

	pArchivo = fopen(path, "w");
	if(pArchivo != NULL)
	{
		retorno = 1;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		for(int i=1; i<cantidadPasajeros; i++)
		{
			pPassenger = ll_get(pArrayListPassenger, i);
			if(Passenger_getId(pPassenger, &id)==0 &&
			   Passenger_getNombre(pPassenger, nombre)==0 &&
			   Passenger_getApellido(pPassenger, apellido)==0 &&
			   Passenger_getPrecio(pPassenger, &precio)==0 &&
			   Passenger_getCodigoVuelo(pPassenger, codigoVuelo)==0 &&
			   Passenger_getTipoPasajero(pPassenger, &tipoPasajero)==0 &&
			   Passenger_getEstado(pPassenger, &estadoVuelo)==0 &&
			   Passenger_showTipoPasajero(tipoPasajeroAuxiliar, tipoPasajero)==1 &&
			   Passenger_showEstadoVuelo(estadoVueloAuxiliar, estadoVuelo)==1)
			{
				fprintf(pArchivo, "%d,%s,%s,%f,%s,%s,%s\n", id,
															nombre,
															apellido,
															precio,
															codigoVuelo,
															tipoPasajeroAuxiliar,
															estadoVueloAuxiliar);
			}
			else
			{
				printf("No se pudo guardar un pasajero\n");
				retorno = 0;
			}
		}
		fclose(pArchivo);
	}

    return retorno;
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

int controller_getLastID(char* path)
{
	FILE* pArchivo;
	int ultimoId = -1;
	printf("Llego a segunda funcion\n");
	if(path != NULL)
	{printf("Path no es nulo\n");
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{printf("obtengo el ultimo id\n");
			fread(&ultimoId, sizeof(int), 1, pArchivo);
			fclose(pArchivo);
		}
	}

	return ultimoId;
}

int controller_saveLastID(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	Passenger* pPasajero;
	int id = 0;
	int ultimoId = 0;
	int maximoId = 0;
	int cantidadPasajeros;
	int bandera = 0;
	printf("Entre en la funcion\n");
	if(path != NULL && pArrayListPassenger != NULL)
	{printf("Path y pArrayListPassenger no son nulos\n");
		ultimoId = controller_getLastID(path);
		printf("Valor de ultimo Id %d\n", ultimoId);
		//if(ultimoId != -1)
		//{
			if(ll_isEmpty(pArrayListPassenger)==0)
			{printf("pArrayListPassenger esta cargada\n");
				cantidadPasajeros = ll_len(pArrayListPassenger);
				for(int i=0; i<cantidadPasajeros; i++)
				{
					pPasajero = ll_get(pArrayListPassenger, i);
					if(pPasajero != NULL)
					{
						Passenger_getId(pPasajero, &id);
						if(id>maximoId)
						{
							maximoId = id;
						}
					}
				}
				if(maximoId > ultimoId)
				{printf("El valor maximo es mayor al anterior\n");
					pArchivo = fopen(path, "wb");
					if(pArchivo != NULL)
					{printf("Se escribio el nuevo valor\n");
						fwrite(&maximoId, sizeof(int), 1, pArchivo);
						fclose(pArchivo);
						bandera = 1;
					}
				}
			}
			if(bandera == 0)
			{printf("el valor maximo no es mayor al ultimo id\n");
				maximoId = ultimoId;
			}
		//}
	}

	return maximoId;
}
