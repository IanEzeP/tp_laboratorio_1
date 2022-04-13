/*
 ============================================================================
 Name        : TP_1.c
 Author      : Ian Pereyra
 Version     :
 Copyright   : Your copyright notice
 Description : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesMenu.h"
#include "OperacionesFunciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	int kilometros;
	int precioAerolineas;
	int precioLatam;
	float precioDebitoAerolineas;
	float precioDebitoLatam;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioPorKmAerolineas;
	float precioPorKmLatam;
	int diferenciaPrecios;
	char seguir;
	int descuento;
	int interes;
	float cotizacionBTC;

	kilometros = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	precioPorKmLatam = 0;
	descuento = 10;
	interes = 25;
	cotizacionBTC = 4606954.55;
	seguir = 's';

	printf("Para interactuar con la interfaz, presione el numero correspondiente a la opcion deseada\n");
	do
	{
		opcion = CargarInterfaz(kilometros, precioAerolineas, precioLatam);

		switch(opcion)
		{
		case 1:
			kilometros = IngresarKilometros();
			break;
		case 2:
			precioAerolineas = IngresarPrecioAerolineas();
			precioLatam = IngresarPrecioLatam();
			break;
		case 3:
			if(kilometros > 0 && precioAerolineas > 0 && precioLatam > 0)
			{
				precioDebitoAerolineas = CalcularPrecioTarjetaDebito(descuento, precioAerolineas);
				precioCreditoAerolineas = CalcularPrecioTarjetaCredito(interes, precioAerolineas);
				precioBitcoinAerolineas = CalcularPrecioBitcoin(cotizacionBTC, precioAerolineas);
				precioPorKmAerolineas = CalcularPrecioPorKM(kilometros, precioAerolineas);

				precioDebitoLatam = CalcularPrecioTarjetaDebito(descuento, precioLatam);
				precioCreditoLatam = CalcularPrecioTarjetaCredito(interes, precioLatam);
				precioBitcoinLatam = CalcularPrecioBitcoin(cotizacionBTC, precioLatam);
				precioPorKmLatam = CalcularPrecioPorKM(kilometros, precioLatam);

				diferenciaPrecios = CalcularDiferenciaAerolineasLatam(precioAerolineas, precioLatam);
				printf("Precios calculados de forma exitosa.\n");
			}
			else
			{
				printf("ERROR No se puedieron realizar los calculos (Hacen falta datos!).\n");
			}
			break;
		case 4:
			if(precioPorKmLatam > 0)
			{
				printf("KMs Ingresados: %d km\n\n", kilometros);
				InformarResultadosAerolineas(precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioPorKmAerolineas);
				InformarResultadosLatam(precioLatam, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioPorKmLatam);
				printf("La diferencia de precio es: $ %d\n\n", diferenciaPrecios);
			}
			else
			{
				printf("ERROR No se pudieron informar los resultados (calculos no realizados!).\n");
			}
			break;
		case 5:
			printf("Carga forzada de datos:\n");

			kilometros = 7090;
			precioAerolineas = 162965;
			precioLatam = 159339;

			precioDebitoAerolineas = CalcularPrecioTarjetaDebito(descuento, precioAerolineas);
			precioCreditoAerolineas = CalcularPrecioTarjetaCredito(interes, precioAerolineas);
			precioBitcoinAerolineas = CalcularPrecioBitcoin(cotizacionBTC, precioAerolineas);
			precioPorKmAerolineas = CalcularPrecioPorKM(kilometros, precioAerolineas);
			precioDebitoLatam = CalcularPrecioTarjetaDebito(descuento, precioLatam);
			precioCreditoLatam = CalcularPrecioTarjetaCredito(interes, precioLatam);
			precioBitcoinLatam = CalcularPrecioBitcoin(cotizacionBTC, precioLatam);
			precioPorKmLatam = CalcularPrecioPorKM(kilometros, precioLatam);
			diferenciaPrecios = CalcularDiferenciaAerolineasLatam(precioAerolineas, precioLatam);

			printf("KMs Ingresados: %d km\n\n", kilometros);
			InformarResultadosAerolineas(precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioPorKmAerolineas);
			InformarResultadosLatam(precioLatam, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioPorKmLatam);
			printf("La diferencia de precio es: $ %d\n\n", diferenciaPrecios);

			kilometros = 0;
			precioAerolineas = 0;
			precioLatam = 0;
			precioPorKmLatam = 0;
			break;
		case 6:
			printf("Cerrando programa...\n");
			seguir = 'n';
			break;
		default:
			printf("Opcion invalida. Intente nuevamente\n");
			break;
		}
	}
	while(seguir == 's');

	system("pause");
	return 0;
}
