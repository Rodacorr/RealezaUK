#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "stringdinamico.h"
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

void ObtenerFechasDeString(strings s, int &dia, int &mes, int &anio);
//Obtiene un string en formato fecha(dd/mm/anio) y lo pasa a tres variables entras dia,mes,anio

boolean esFormatoFecha(strings s);
//Es formato fecha Si Cumple que tenga 2 // o sea del tipo
// 2/2/12, 02/02/02, 1/02/21, 1/2/1234, 1/01/1234, 01/1/1234

void CrearFechaCon3Variables(Fecha &fech, int dia, int mes, int anio);
//Crea una fecha con 3 variables enteras

void bajarFecha(Fecha fech, FILE* f);
void levantarFecha(Fecha &fech, FILE *b);

void cargarFechaSinPrintf(Fecha &f, int d, int m, int a);

void cargarFechaNula(Fecha &f1);
void copiarFecha1y2(Fecha &f1, Fecha f2);

boolean compararFechas(Fecha f1, Fecha f2);
#endif // FECHA_H_INCLUDED
