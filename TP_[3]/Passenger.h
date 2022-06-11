/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;

}Passenger;

/// @brief Crea en memoria dinamica un dato del tipo Passenger
/// @return Devuelve la direccion donde se creo el dato.
Passenger* Passenger_new();

/// @brief Crea un dato del tipo Passenger y carga todos sus campos.
/// @param idStr Recibe una cadena de caracteres correspondiente al ID del pasajero.
/// @param nombreStr Recibe una cadena de caracteres correspondiente al nombre del pasajero.
/// @param apellidoStr Recibe una cadena de caracteres correspondiente al apellido del pasajero.
/// @param precioStr Recibe una cadena de caracteres correspondiente al precio del pasajero.
/// @param codigoStr Recibe una cadena de caracteres correspondiente al codigo de vuelo del pasajero.
/// @param tipoPasajeroStr Recibe una cadena de caracteres correspondiente al tipo de pasajero.
/// @param estadoStr Recibe una cadena de caracteres correspondiente al estado de vuelo del pasajero.
/// @return Devuelve al pasajero con todos sus datos cargados en caso de que estos sean correctos, en el caso contrario devuelve NULL.
Passenger* Passenger_newParametrosTxt(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoStr);

/// @brief Solcita al usuario la carga de datos para un nuevo pasajero.
/// @param lastId Recibe un entero correspondiente al ultimo ID cargado en el sistema.
/// @return Dvuelve al pasajero con todos sus datos cargados en caso de que estos sean correctos, en el caso contrario devuelve NULL.
Passenger* Passenger_requestData(int lastId);

/// @brief Libera el espacio en memoria de un pasajero.
/// @param this Recibe un dato del tipo Passenger para ser liberado.
void Passenger_delete(Passenger* this);

/// @brief Imprime en la consola todos los datos de un pasajero.
/// @param this Recibe un dato del tipo Passenger para ser imprimido en la consola.
void Passenger_listOne(Passenger* this);

/// @brief Desplega un submenu que permite modificar cualquier dato dentro de una estructura del tipo Passenger.
/// @param this Recibe un dato del tipo Passenger para ser modificado.
/// @return Devuelve 1 en caso de haber entrado y salido del submenu sin problemas, en caso de que los datos no se hayan podido obtener devuelve 0 y en el caso de error -1.
int Passenger_modifyData(Passenger* this);

/// @brief Carga en el dato del tipo Passenger el valor del Id.
/// @param this Recibe al pasajero.
/// @param id Recibe un entero que sera el valor que se cargara al Id del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_setId(Passenger* this,int id);

/// @brief Consigue el valor del campo Id del tipo Passenger.
/// @param this Recibe al pasajero.
/// @param id Recibe un puntero a entero que sera el valor correspondiente al Id del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_getId(Passenger* this,int* id);

/// @brief Carga en el dato del tipo Passenger el valor del Nombre.
/// @param this Recibe al pasajero.
/// @param nombre Recibe una cadena de caracteres que sera el valor que se cargara al Nombre del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief Consigue el valor del campo Nombre del tipo Passenger.
/// @param this Recibe al pasajero.
/// @param nombre Recibe una cadena de caracteres que sera el valor correspondiente al Nombre del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief Carga en el dato del tipo Passenger el valor del Apellido.
/// @param this Recibe al pasajero.
/// @param apellido Recibe una cadena de caracteres que sera el valor que se cargara al Apellido del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief Consigue el valor del campo Apellido del tipo Passenger.
/// @param this Recibe al pasajero.
/// @param apellido Recibe una cadena de caracteres que sera el valor correspondiente al Apellido del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief Carga en el dato del tipo Passenger el valor del CodigoVuelo.
/// @param this Recibe al pasajero.
/// @param codigoVuelo Recibe una cadena de caracteres que sera el valor que se cargara al CodigoVuelo del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Consigue el valor del campo Nombre del tipo CodigoVuelo.
/// @param this Recibe al pasajero.
/// @param codigoVuelo Recibe una cadena de caracteres que sera el valor correspondiente al CodigoVuelo del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Carga en el dato del tipo Passenger el valor del TipoPasajero.
/// @param this Recibe al pasajero.
/// @param tipoPasajero Recibe un entero que sera el valor que se cargara al TipoPasajero del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @brief Consigue el valor del campo TipoPasajero del tipo Passenger.
/// @param this Recibe al pasajero.
/// @param tipoPasajero Recibe un puntero a flotante que sera el valor correspondiente al TipoPasajero del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @brief Carga en el dato del tipo Passenger el valor del Precio.
/// @param this Recibe al pasajero.
/// @param precio Recibe un entero que sera el valor que se cargara al Precio del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief Consigue el valor del campo Precio del tipo Passenger.
/// @param this Recibe al pasajero.
/// @param precio Recibe un puntero a flotante que sera el valor correspondiente al Precio del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief Carga en el dato del tipo Passenger el valor del EstadoVuelo.
/// @param this Recibe al pasajero.
/// @param estado Recibe un entero que sera el valor que se cargara al EstadoVuelo del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_setEstado(Passenger* this,int estado);

/// @brief Consigue el valor del campo EstadoVuelo del tipo Passenger.
/// @param this Recibe al pasajero.
/// @param estado Recibe un puntero a entero que sera el valor correspondiente al EstadoVuelo del pasajero.
/// @return Devuelve 0 en caso de que la asignacion haya sido exitosa o -1 si hubo un error.
int Passenger_getEstado(Passenger* this,int* estado);

/// @brief Compara el campo Id de dos datos del tipo Passenger.
/// @param p1
/// @param p2
/// @return Devuelve 0 si los Id son iguales, 1 si el primero es mayor al segundo y -1 si el primero es menor al segundo.
int Passenger_compareByID(void* p1, void* p2);

/// @brief Compara el campo Nombre de dos datos del tipo Passenger.
/// @param p1
/// @param p2
/// @return Devuelve 0 si los Nombre son iguales, 1 si la comparacion resulta en que el primero es mayor al segundo y -1 si el primero es menor al segundo.
int Passenger_compareByName(void* p1, void* p2);

/// @brief Compara el campo Apellido de dos datos del tipo Passenger.
/// @param p1
/// @param p2
/// @return Devuelve 0 si los Apellido son iguales, 1 si la comparacion resulta en que el primero es mayor al segundo y -1 si el primero es menor al segundo.
int Passenger_compareByLastName(void* p1, void* p2);

/// @brief Compara los campo Precio de dos datos del tipo Passenger.
/// @param p1
/// @param p2
/// @return Devuelve 0 si los Precios son iguales, 1 si el primero es mayor al segundo y -1 si el primero es menor al segundo.
int Passenger_compareByPrice(void* p1, void* p2);

/// @brief Compara el campo CodigoVuelo de dos datos del tipo Passenger.
/// @param p1
/// @param p2
/// @return Devuelve 0 si los CodigoVuelo son iguales, 1 si la comparacion resulta en que el primero es mayor al segundo y -1 si el primero es menor al segundo.
int Passenger_compareByFlyCode(void* p1, void* p2);

/// @brief Compara el campo TipoPasajero de dos datos del tipo Passenger.
/// @param p1
/// @param p2
/// @return Devuelve 0 si los campos TipoPasajero son iguales, 1 si el primero es mayor al segundo y -1 si el primero es menor al segundo.
int Passenger_compareByTypePassenger(void* p1, void* p2);

/// @brief Compara el campo EstadoVuelo de dos datos del tipo Passenger.
/// @param p1
/// @param p2
/// @return Devuelve 0 si los campos EstadoVuelo son iguales, 1 si el primero es mayor al segundo y -1 si el primero es menor al segundo.
int Passenger_compareByStatusFlight(void* p1, void* p2);

/// @brief Cambia el valor de la cadena de texto especifica al Tipo de pasajero por un numero para poder ser asignado a la estructura sin problemas.
/// @param tipoPasajero Recibe la cadena de texto correspondiente al tipo de pasajero.
/// @return Devuelve 1 en caso de haber realizado el cambio del valor sin problemas, en caso de que los datos no coincidan devuelve 0 y en el caso de error -1.
int Passenger_changeTipoPasajeroToInt(char* tipoPasajero);

/// @brief Traduce el valor numerico del Tipo pasajero a su equivalente en texto.
/// @param tipoPasajero Recibe la cadena de texto que mostrara el tipo de pasajero.
/// @param numberTipoPasajero Recibe el entero correspondiente al tipo de pasajero.
/// @return Devuelve 1 en caso de haber realizado la traduccion del dato sin problemas, en caso de que los datos no coincidan devuelve 0 y en el caso de error -1.
int Passenger_showTipoPasajero(char* tipoPasajero, int numberTipoPasajero);

/// @brief Cambia el valor de la cadena de texto especifica al Estado de vuelo por un numero para poder ser asignado a la estructura sin problemas.
/// @param estadoVuelo Recibe la cadena de texto correspondiente al estado del vuelo.
/// @return Devuelve 1 en caso de haber realizado el cambio del valor sin problemas, en caso de que los datos no coincidan devuelve 0 y en el caso de error -1.
int Passenger_changeEstadoVueloToInt(char* estadoVuelo);

/// @brief Traduce el valor numerico del Estado de vuelo a su equivalente en texto.
/// @param estadoVuelo Recibe la cadena de texto que mostrara el estado de vuelo.
/// @param numberEstadoVuelo Recibe el entero correspondiente al estado de vuelo.
/// @return Devuelve 1 en caso de haber realizado la traduccion del dato sin problemas, en caso de que los datos no coincidan devuelve 0 y en el caso de error -1.
int Passenger_showEstadoVuelo(char* estadoVuelo, int numberEstadoVuelo);

#endif /* PASSENGER_H_ */
