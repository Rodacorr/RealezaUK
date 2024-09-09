#ifndef LISTASTINGS_H_INCLUDED
#define LISTASTINGS_H_INCLUDED
#include "stringdinamico.h"

typedef struct nodoL {
    strings info;
    nodoL * sig;
 } nodos;
typedef nodos * listaStr;

void crearListaStrings(listaStr &ls);
//crea la lista

void InsBackIter (listaStr &L, strings s);
//inserta lista strings

void cargarPalabrasEnListas(listaStr &ls,strings s);
//almacena las palabras en la lista
void cargarPalabra(listaStr &ls,strings s);
void mostrarLista(listaStr ls);
//muestra la lista

int LargoIter (listaStr ls);
//cuenta cuantos elementos tiene

void borrarListaStrings(listaStr &L);

boolean loEncontre(listaStr L, strings nom);
#endif // LISTASTINGS_H_INCLUDED
