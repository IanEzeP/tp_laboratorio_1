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
	Passenger* pPasajero;
	int idIngresado;
	int cantidadPasejeros;
	int idPasajero;
	char nombre[51];
	char apellido[51];
	int retorno = -1;
	int resultado;

	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		cantidadPasejeros = ll_len(pArrayListPassenger);
		PedirEntero(&idIngresado, "Ingrese el ID del pasajero que desea modificar:", "ERROR! Ingrese un numero valido.", 0, 999999999);
		for(int i=0; i<cantidadPasejeros; i++)
		{
			pPasajero = ll_get(pArrayListPassenger, i);
			if(pPasajero != NULL)
			{
				resultado = Passenger_getId(pPasajero, &idPasajero);
				if(resultado == 0 && idIngresado == idPasajero)
				{
					if(Passenger_getNombre(pPasajero, nombre) == 0 && Passenger_getApellido(pPasajero, apellido) == 0)
					{
						printf("Desea modificar al pasajero %s %s ?\n", nombre, apellido);
						PedirEntero(&resultado, "1. Si\n2. No", "ERROR! Ingrese el numero correspondiente a la opcion deseada.", 0, 3);
						if(resultado == 1)
						{
							if(Passenger_modifyData(pPasajero) != 1)
							{
								printf("ERROR al modificar pasajero.\n");
							}
						}
						else
						{
							printf("Accion cancelada. Regresando al menu.\n");
						}
						retorno = 1;
					}
					break;
				}
			}
		}
	}

    return retorno;
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
	Passenger* pPasajero;
	int idIngresado;
	int cantidadPasejeros;
	int idPasajero;
	char nombre[51];
	char apellido[51];
	int retorno = -1;
	int resultado;

	if(pArrayListPassenger != NULL)
	{
		retorno = 0;
		cantidadPasejeros = ll_len(pArrayListPassenger);
		PedirEntero(&idIngresado, "Ingrese el ID del pasajero que desea remover del sistema:", "ERROR! Ingrese un numero valido.", 0, 999999999);
		for(int i=0; i<cantidadPasejeros; i++)
		{
			pPasajero = ll_get(pArrayListPassenger, i);
			if(pPasajero != NULL)
			{
				resultado = Passenger_getId(pPasajero, &idPasajero);
				if(resultado == 0 && idIngresado == idPasajero)
				{
					if(Passenger_getNombre(pPasajero, nombre) == 0 && Passenger_getApellido(pPasajero, apellido) == 0)
					{
						printf("Desea remover del sistema al pasajero %s %s ?\n", nombre, apellido);
						PedirEntero(&resultado, "1. Si\n2. No", "ERROR! Ingrese el numero correspondiente a la opcion deseada.", 0, 3);
						if(resultado == 1)
						{
							if(ll_remove(pArrayListPassenger, i) == 0)
							{
								printf("Pasajero removido correctamente.\n");
							}
							else
							{
								printf("ERROR al remover al pasajero.\n");
							}
						}
						else
						{
							printf("Accion cancelada. Regresando al menu.\n");
						}
						retorno = 1;
					}
					break;
				}
			}
		}
	}

	return retorno;
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
			printf("||1. Ordenar por ID.\n");
			printf("||2. Ordenar por Nombre.\n");
			printf("||3. Ordenar por Apellido.\n");
			printf("||4. Ordenar por Precio.\n");
			printf("||5. Ordenar por Codigo de vuelo.\n");
			printf("||6. Ordenar por Tipo de Pasajero.\n");
			printf("||7. Ordenar por Estado de vuelo.\n");
			PedirEntero(&opcion, "||8. Regresar.", "Opcion invalida! Intente nuevamente.", 0, 9);
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
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
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

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL)
		{
			retorno = 1;
			cantidadPasajeros = ll_len(pArrayListPassenger);
			for(int i=0; i<cantidadPasajeros; i++)
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
					break;
				}
			}
			fclose(pArchivo);
		}
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
	FILE* pArchivo;
	Passenger* pPassenger;
	int retorno = -1;
	int cantidadPasajeros;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "wb");
		if(pArchivo != NULL)
		{
			retorno = 1;
			cantidadPasajeros = ll_len(pArrayListPassenger);
			for(int i=0; i<cantidadPasajeros; i++)
			{
				pPassenger = ll_get(pArrayListPassenger, i);
				if(pPassenger == NULL || fwrite(pPassenger, sizeof(Passenger), 1, pArchivo) != 1)
				{
					printf("No se pudo guardar un pasajero\n");
					retorno = 0;
					break;
				}
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}

/** \brief Lee el archivo con el ultimo Id guardado y lo devuelve
 *
 * \param path char*
 * \return int
 *
 */
int controller_getLastID(char* path)
{
	FILE* pArchivo;
	int ultimoId = -1;

	if(path != NULL)
	{
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			fread(&ultimoId, sizeof(int), 1, pArchivo);
			fclose(pArchivo);
		}
	}

	return ultimoId;
}

/** \brief Consigue el ultimo Id guardado y lo compara con el ultimo de lista dinamica. Si en la lista hay un Id mayor al anterior, lo escribe en el archivo.
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int  Devuelve el ultimo Id.
 *
 */
int controller_saveLastID(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	Passenger* pPasajero;
	int id = 0;
	int ultimoId = 0;
	int maximoId = 0;
	int cantidadPasajeros;
	int bandera = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		ultimoId = controller_getLastID(path);
		if(ultimoId != -1)
		{
			if(ll_isEmpty(pArrayListPassenger)==0)
			{
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
				{
					pArchivo = fopen(path, "wb");
					if(pArchivo != NULL)
					{
						fwrite(&maximoId, sizeof(int), 1, pArchivo);
						fclose(pArchivo);
						bandera = 1;
					}
				}
			}
			if(bandera == 0)
			{
				maximoId = ultimoId;
			}
		}
	}

	return maximoId;
}
