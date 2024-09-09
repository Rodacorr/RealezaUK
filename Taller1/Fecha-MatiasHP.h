#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "archivos.h"

typedef struct{
    int dia;
    int mes;
    int anio;
} Fecha;

void CargarFecha(Fecha &f);

int DarDia(Fecha f);

int DarMes(Fecha f);

int DarAnio(Fecha f);

void MostrarFecha(Fecha f);

boolean EsValida(Fecha f);

long int DeFechaaSumaTotal(Fecha f);

boolean fechaIgualMenor (Fecha f, Fecha f2);

int atoi(strings s);
//Obtiene un string y lo pasa a numero
void ObtenerFechasDeString(strings s, int &dia, int &mes, int &anio);
//Obtiene un string en formato fecha(dd/mm/anio) y lo pasa a tres variables entras dia,mes,anio

boolean esFormatoFecha(strings s);
//Es formato fecha Si Cumple que tenga 2 // o sea del tipo
// 2/2/12, 02/02/02, 1/02/21, 1/2/1234, 1/01/1234, 01/1/1234

void CrearFechaCon3Variables(Fecha &fech, int dia, int mes, int anio);
//Crea una fecha con 3 variables enteras
#endif // FECHA_H_INCLUDED
