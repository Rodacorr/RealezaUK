#include "ListaComandos.h"

void crearListaComandos(listaComandos &L){
    L = NULL;
}

void InsBackComandos(listaComandos &L, Comandos com){

    listaComandos nuevo = new nodis;
    copiarComando(com,nuevo->comandos);//nos habia faltado

    nuevo ->sig = NULL;

    if(L == NULL){
        L = nuevo;
    }
    else{
        listaComandos aux = L;
        while(aux ->sig != NULL)
            aux = aux -> sig;
        aux -> sig = nuevo;
    }
}

void BajarListaComandos(listaComandos L, strings nomArch){
    FILE * b = fopen (nomArch, "wb");
     while (L != NULL)
     {
        bajarComando(L ->comandos, b);
        L = L ->sig;
     }
     fclose (b);
}

void LevantarListaComandos (listaComandos &L, strings nomArch){
    FILE * b = fopen (nomArch, "rb");
    Comandos buffer;
    crearListaComandos(L);
    levantarComando(buffer, b);
    while (!feof(b)){
        InsBackComandos(L, buffer);
        levantarComando(buffer, b);
    }
    fclose (b);
}

void imprimirComando(listaComandos L){
    while(L != NULL){
        imprimircomandocomando(L->comandos);
        L=L->sig;
    }
}

void borrarLista(listaComandos &L){
    listaComandos aux;
    while(L!=NULL){
        aux=L;
        L=L->sig;
        delete aux;
    }
}

void buscarComandoEnLista(listaComandos L, strings s,boolean &encontre, int &cantParametros, int &codigo){
    encontre = FALSE;

    while(L != NULL && !encontre){
        if(esAlfabetico(s)){
            if(streq(L->comandos.comando,s)){
                encontre = TRUE;
                cantParametros = L->comandos.cantParametros;
                codigo = L->comandos.codigo;
                //print(s);
               // print(L->comandos.comando);
            }
            else
                L = L->sig;
        }
    }
    /*if(!encontre){
        printf("\n--ERROR--\nEl comando ingresado es incorrecto.\n");
    }*/
}
