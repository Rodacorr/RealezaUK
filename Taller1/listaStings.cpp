#include "listaStings.h"


void crearListaStrings(listaStr &ls){
    ls = NULL;
}


void InsBackIter (listaStr &L, strings s){
    listaStr nuevo = new nodos;
    int largo = strlar(s)+1;
    int i=0;
    strcrear(nuevo->info);
    strcop(nuevo->info, s);
    nuevo -> sig = NULL;
    if (L == NULL)
        L = nuevo;
    else
        {
        listaStr aux = L;
        while (aux -> sig != NULL)
        aux = aux -> sig;
        aux -> sig = nuevo;
        }
}

void cargarPalabrasEnListas(listaStr &ls,strings s){
    strings palabra,resto;
    strcrear(palabra);
    strcrear(resto);
    pasarMayusculas(s);
    strPrimerPalabraYResto(s,palabra, resto);
    InsBackIter(ls,palabra);
    while(!strVacio(resto)){
        strPrimerPalabraYResto(resto,palabra,resto);
        if(!strVacio(palabra))
           InsBackIter(ls,palabra);
    }
    strdestruir(palabra);
    strdestruir(resto);
}

void cargarPalabra(listaStr &ls,strings s){
    if(ls== NULL){
        strcrear(ls->info);
        strcop(ls->info,s);
        ls->sig = NULL;
    }
    else{
        cargarPalabra(ls->sig,s);
    }
}

void mostrarLista(listaStr ls){
    while(ls!=NULL){
        print(ls->info);
        printf("\n");
        ls=ls->sig;
    }
}

int LargoIter (listaStr ls){
    int cant = 0;
    while (ls != NULL){
        cant++;
        ls = ls -> sig;
        }
    return cant;
}

void borrarListaStrings(listaStr &L){
    listaStr aux;
    while(L!=NULL){
        aux=L;
        L=L->sig;
        delete aux;
    }
}

boolean loEncontre(listaStr L, strings nom){
    boolean enco = FALSE;
    while(L != NULL && !enco){
        if(streq(L->info,nom))
            enco = TRUE;
        else
            L = L->sig;
    }
    return enco;
}
