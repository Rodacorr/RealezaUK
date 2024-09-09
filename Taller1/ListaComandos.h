#ifndef LISTACOMANDOS_H_INCLUDED
#define LISTACOMANDOS_H_INCLUDED
#include"Comandos.h"

typedef struct nodoCom {
    Comandos comandos;
    nodoCom * sig;
 } nodis;

typedef nodis * listaComandos;

void crearListaComandos(listaComandos &L);

void InsBackComandos(listaComandos &L, Comandos com);

void BajarListaComandos(listaComandos L , strings nomArch);

void LevantarListaComandos (listaComandos &L, strings nomArch);

void imprimirComando(listaComandos L);

void borrarLista(listaComandos &L);

void buscarComandoEnLista(listaComandos L, strings s,boolean &encontre, int &cantParametros, int &codigo);
//Nos retorna entcontre TRUE si encontro el comando que le pasamos por string en la lista de comando junto con su cantidad de parametros y su codigo
#endif // LISTACOMANDOS_H_INCLUDED
