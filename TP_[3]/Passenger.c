/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include "InputsDatos.h"


Passenger* Passenger_new()
{
	Passenger* auxPasajero = NULL;
	auxPasajero = (Passenger*) malloc(sizeof(Passenger));
	return auxPasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoStr)
{
	Passenger* pPasajero;
	int idAuxiliar;
	pPasajero = Passenger_new();
/*	if(pPasajero != NULL)
	{

	}

	idAuxiliar = atoi(idStr);
	pPasajero->id = idAuxiliar;
	strcpy(pPasajero->nombre, nombreStr);
	strcpy(pPasajero->tipoPasajero, tipoPasajeroStr);
*/
	return pPasajero;
}

int Passenger_compareByName(void* p1, void* p2)//unboxing
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;


	return strcmp(pasajero1->nombre, pasajero2->nombre);
}

int Passenger_compareByID(void* p1, void* p2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	int compare;

	compare = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(pasajero1->id > pasajero2->id)
	{
		compare = 1;
	}
	else
	{
		if(pasajero1->id < pasajero2->id)
		{
			compare = -1;
		}
	}

	return compare;
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(this->nombre, nombre);
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{

}

int Passenger_setApellido(Passenger* this,char* apellido)
{

}
int Passenger_getApellido(Passenger* this,char* apellido)
{

}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno = -1;

	strcpy(this->codigoVuelo, codigoVuelo);
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	strcpy(codigoVuelo, this->codigoVuelo);
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{

}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{

}

int Passenger_setPrecio(Passenger* this,float precio)
{

}
int Passenger_getPrecio(Passenger* this,float* precio)
{

}
