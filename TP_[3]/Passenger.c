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
	int resultado;
	int idAuxiliar;
	float precioAuxiliar;
	int tipoPasajeroAuxiliar;
	int estadoAuxiliar;
	pPasajero = Passenger_new();
	if(pPasajero != NULL)
	{
		resultado = isNumber(idStr, sizeof(idStr));
		if(resultado != 0)
		{
			printf("ID en string NO es un numero\n");
		}
		else
		{
			idAuxiliar = atoi(idStr);
			resultado = Passenger_setId(pPasajero, idAuxiliar);
			if(resultado != 0)
			{
				printf("ERROR en setID!\n");//sacar
			}
		}

		resultado = Passenger_setNombre(pPasajero, nombreStr);
		if(resultado != 0)
		{
			printf("ERROR en setNombre!\n");
		}

		resultado = Passenger_setApellido(pPasajero, apellidoStr);
		if(resultado != 0)
		{
			printf("ERROR en setApellido!\n");
		}

		resultado = isFloat(precioStr, sizeof(precioStr));
		if(resultado != 0)
		{
			printf("Precio en string NO es un flotante\n");
		}
		else
		{
			precioAuxiliar = atof(precioStr);
			resultado = Passenger_setPrecio(pPasajero, precioAuxiliar);
			if(resultado != 0)
			{
				printf("ERROR en setPrecio!\n");
			}
		}

		resultado = Passenger_setCodigoVuelo(pPasajero, codigoStr);
		if(resultado != 0)
		{
			printf("ERROR en setCodigoVuelo!\n");
		}

		resultado = isNumber(tipoPasajeroStr, sizeof(tipoPasajeroStr));
		if(resultado != 0)
		{
			printf("TipoPassjero en string NO es un numero\n");
		}
		else
		{
			tipoPasajeroAuxiliar = atoi(tipoPasajeroStr);
			resultado = Passenger_setTipoPasajero(pPasajero, tipoPasajeroAuxiliar);
			if(resultado != 0)
			{
				printf("ERROR en setTipoPasajero!\n");
			}
		}

		resultado = isNumber(estadoStr, sizeof(estadoStr));
		if(resultado != 0)
		{
			printf("Estado en string NO es un numero\n");
		}
		else
		{
			estadoAuxiliar = atoi(estadoStr);
			resultado = Passenger_setEstado(pPasajero, estadoAuxiliar);
			if(resultado != 0)
			{
				printf("ERROR en setEstado!\n");
			}
		}
	}

	return pPasajero;
}

void Passenger_delete(Passenger* this)//hace free
{

}

int Passenger_compareByName(void* p1, void* p2)
{
	int retorno;
	char* nombre1;
	char* nombre2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	retorno = Passenger_getNombre(pasajero1, nombre1);
	if(retorno != 0)
	{
		printf("ERROR en getNombre!\n");
	}
	retorno = Passenger_getNombre(pasajero2, nombre2);
	if(retorno != 0)
	{
		printf("ERROR en getNombre!\n");
	}
	return strcmp(nombre1, nombre2);
}

int Passenger_compareByID(void* p1, void* p2)
{
	int retorno;
	int id1;
	int id2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int compare;

	compare = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	retorno = Passenger_getId(pasajero1, &id1);
	if(retorno != 0)
	{
		printf("ERROR en getId!\n");
	}
	retorno = Passenger_getId(pasajero2, &id2);
	if(retorno != 0)
	{
		printf("ERROR en getId!\n");
	}
	if(id1 > id2)
	{
		compare = 1;
	}
	else
	{
		if(id1 < id2)
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
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre, this->nombre);
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strcpy(this->apellido, apellido);
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strcpy(apellido, this->apellido);
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strcpy(this->codigoVuelo, codigoVuelo);
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strcpy(codigoVuelo, this->codigoVuelo);
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		retorno = 0;
		this->tipoPasajero = tipoPasajero;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}


int Passenger_setEstado(Passenger* this,int estado)
{
	int retorno = -1;

	if(this != NULL && estado > 0)
	{
		retorno = 0;
		this->estadoVuelo = estado;
	}
	return retorno;
}

int Passenger_getEstado(Passenger* this,int* estado)
{
	int retorno = -1;

	if(this != NULL && estado != NULL)
	{
		retorno = 0;
		*estado = this->estadoVuelo;
	}
	return retorno;
}
