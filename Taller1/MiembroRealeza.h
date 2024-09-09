#ifndef MIEMBROREALEZA_H_INCLUDED
#define MIEMBROREALEZA_H_INCLUDED
#include"Fecha.h"
#include "ListaComandos.h"
#include "listaStings.h"
#include "Archivos.h"

typedef struct{
        strings nombre;  //pasar nombres a mayusculas
		Fecha fechaNacimiento;  //dd/mm/aaaa
		boolean miembroInicialDinastia; //SI == TRUE, NO == FALSE.
		strings nombreProgenitor; //pasar a mayœscula

}MiembroRealeza;

void darNombre(MiembroRealeza miem, strings &s);

Fecha darNacimiento(MiembroRealeza miem);

boolean darMiembroInicio(MiembroRealeza miem);

void darProgenitor (MiembroRealeza miem, strings &s);

void cargarMiembro(MiembroRealeza &m,Fecha f,strings nom, strings pa);

void copiarMiembro(MiembroRealeza &m, MiembroRealeza m2);
void mostrarMiembro(MiembroRealeza m);

void esInicialONo(MiembroRealeza m);

void bajarMiembro(MiembroRealeza m, FILE *f);

void levantarMiembro(MiembroRealeza &m, FILE *f);
//hacer lenvantar miembro , bajar miembro
//levantar y bahar strings
#endif // MIEMBROREALEZA_H_INCLUDED
