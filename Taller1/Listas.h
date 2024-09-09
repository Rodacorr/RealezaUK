#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "FamiliaReal.h"
#include "Arbol.h"

typedef struct nodof {
    FamiliaReal info;
    nodof * sig;
 } nodof;

typedef nodof * lista;


void crearListaFamiliaReal (lista &L); // Crea la lista

void cargarListaFamiliaReal(lista &L, FamiliaReal F); // Carga la lista

void imprimirListaFamiliaReal (lista L);  //Imprime la lista

boolean listaVacia (lista L);  //Chequea si esta vacia

boolean perteneceListaFamiliaReal(lista L, strings nombre);
 //Verifica si ya existe
//verificar si esta hecho con

void InsBackIterLista (lista &L,FamiliaReal fM);
//inserta el miembor en la lista de FamiliaReal
void insertarHijo(lista &l, FamiliaReal fam);

int LargoRecu (listaStr L);

Fecha devolverUltimaFecha(lista L);
//Devuelve la ultima fecha ingresada en la lista

void marcarFallecido(lista &l, strings nombre, Fecha f);

void imprimirMonarcas(lista L); //imprime monarcas

void bajarListaFamiliaReal(lista L, strings archFamReal); // baja la lista famreal

void levantarListaFamiliaReal (lista &L, strings archFamReal); //levanta la lista famreal

void marcarAbdicadolista(lista &l, strings nombre, Fecha f); // marca persona como abdicada

void imprimirAspirantes(lista l); //Muestra los aspirantes que hay en la lista

void imprimirHistorial(lista l);

void borrarLista(lista &L);

boolean ningunAsipirante(lista l);
#endif // LISTAS_H_INCLUDED
