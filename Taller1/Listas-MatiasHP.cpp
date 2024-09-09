#include "Listas.h"

void crearListaFamiliaReal (lista &L){
    L=NULL;
}

void cargarListaFamiliaReal(lista &L, FamiliaReal F){
    lista nuevo = new nodof;
    nuevo ->sig = NULL;
        if(L==NULL)
            L->info=F;
        else{
            lista aux = L;
            while(aux ->sig != NULL)
                aux = aux -> sig;
            aux -> sig = nuevo;
        }
    }


void imprimirListaFamiliaReal (lista L){
    while(L!=NULL){
        mostrarMiembroFamiliaReal(L->info);
        L=L->sig;
    }

}

boolean listaVacia (lista L){
    boolean es = FALSE;

    if (L == NULL)
        es = TRUE;
    return es;
}

boolean perteneceListaFamiliaReal(lista L, FamiliaReal f){
    boolean pertenece= FALSE;
    while(L!=NULL && !pertenece){
        if(streq(L->info.mr.nombre,f.mr.nombre)) //posible vercion correcta seria
            pertenece=TRUE; //(streq(dar(darNombre(L))darMiembroRealeza(darNombre(f))))
        else
            L=L->sig;
    }
return pertenece;
}

void InsBackIterLista (lista &L, FamiliaReal fM){
    lista nuevo = new nodof;
    nuevo->info = fM;
    if(L == NULL)
        L = nuevo;
    else{
        lista aux=L;
        while(aux ->sig != NULL)
            aux= aux ->sig;
        aux-> sig = nuevo;
    }
}

void InsHijoLuegoDePadre(lista &L, FamiliaReal fM){
    lista nuevo = new nodof;
    nuevo -> info = L->info;
    nuevo -> sig = NULL;
    if(L == NULL){
        L = nuevo;
    }
    else{
        lista aux = new nodof;
        while(streq(L->info.mr.nombreProgenitor == fM.mr.nombreProgenitor)){
            if(L->sig->info.mr.nombreProgenitor != fM.mr.nombreProgenitor){

            }
            aux->info = L->info;

        }
    }
}
   /* void InsBackIter (Lista &L, int e)
{
 Lista nuevo = new nodo;
 nuevo -> info = e;
 nuevo -> sig = NULL;
 if (L == NULL)
 L = nuevo;
 else
 {
 Lista aux = L;
 while (aux -> sig != NULL)
 aux = aux -> sig;
 aux -> sig = nuevo;
 }
}*/


Fecha devolverUltimaFecha(lista L){
    while(L != NULL){
        if(L ->sig == NULL){
            return L->info.mr.fechaNacimiento;
        }
        else
            L = L->sig;
    }
}

void imprimirMonarcas(lista L){
    while(L!=NULL){
        if(darFueMonarca(L->info)==TRUE){
            mostrarMiembroFamiliaReal(L->info);
            L->sig;
       }
       else
        L->sig;
    }
}
