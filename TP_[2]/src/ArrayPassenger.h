/*
 * ArrayPassenger.h
 *
 *  Created on: 12 may. 2022
 *      Author: User
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LEN 2000

typedef struct
{
	int typePassenger;
	char descriptionType[21];
}sType;

typedef struct
{
	int statusFlight;
	char descriptionStatus[21];
}sStatus;

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight, int index);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len, int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order, sStatus* listStatus, int lenStat, sType* listType, int lenType);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int lenght, sStatus* listStatus, int lenStat, sType* listType, int lenType);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order, sStatus* listStatus, int lenStat, sType* listType, int lenType);

int modifyPassenger(Passenger* list, int len, int index, sType* listType, int lenType);

int AltaForzadaPasajeros(Passenger* list, int len);

int ModificarPasajero(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType);

int BajaLogicaPasajero(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType);

int CargarPasajeros(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType);

int PedidoDeDatos(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType);

void ListarTiposDePasajeros(sType* listType, int lenType);

void ListarEstadosDeVuelo(sStatus* listStatus, int lenStat);

void ImprimirUnPasajero(Passenger onePassenger, sStatus oneStatus, sType oneType);

int BuscarRelacionPasajeroEstado(Passenger onePassenger, sStatus* listStatus, int lenStat);

int BuscarRelacionPasajeroTipo(Passenger onePassenger, sType* listType, int lenType);

int BuscarEmpty(Passenger* list, int lenPass);

int MenuListados(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType);

int OrdenarPasajerosPorApellidoAscendente(Passenger* list, int len, sType* listType, int lenType);

int OrdenarPasajerosPorApellidoDescendente(Passenger* list, int len, sType* listType, int lenType);

int OrdenarPasajerosPorCodigoAscendente(Passenger* list, int len);

int OrdenarPasajerosPorCodigoDescendente(Passenger* list, int len);

int MostrarVuelosActivos(Passenger* list, int lenght, sStatus* listStatus, int lenStat, sType* listType, int lenType);

int MostrarTotalYPromedioDePrecios(Passenger* list, int lenPass);

int CalcularTotal(float* total, Passenger* list, int lenPass);

int ContarPasajeros(int* cantidad, Passenger* list, int lenPass);

#endif /* ARRAYPASSENGER_H_ */
