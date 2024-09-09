#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "MiembroRealeza.h"

typedef struct nodoA{
    MiembroRealeza info;
    nodoA *hizq;
    nodoA *hder;
}nodo;

typedef nodo *arbol;

void crear (arbol &a);

boolean esVacio (arbol a);

void darNombreRaiz (arbol a, strings nombreRaiz);
//Devuelve el nombre de la raiz

arbol hijoIzquierdo (arbol a);

arbol hijoDerecho (arbol a);

//void orden(arbol a); // en orden

int contarMiembrosAbb(arbol a);
//Cuneta cunatos miembros hay en el arbol

boolean perteneceAbb(arbol a, strings nombreABuscar);
//Devuelve true si el nombre esta en el arbol

void insertAbb (arbol &a,MiembroRealeza m);

void bajarArbolAux(arbol a, FILE *f);

void bajarArbol(arbol a, strings archAbb);

void levantarArbol(arbol &a, strings archAbb);// levanta el arboliea

void mostrarMiembrosArbol(arbol a);

void Eliminar (arbol &a);

#endif // ARBOL_H_INCLUDED

