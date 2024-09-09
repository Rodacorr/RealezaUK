#include "Arbol.h"

void crear (arbol &a)
{
    a=NULL;
}

boolean esVacio (arbol a)
{
    boolean es=TRUE;
    if (a!=NULL)
        es=FALSE;
    return es;
}

void darNombreRaiz (arbol a, strings nombreRaiz)
{
    strcop(nombreRaiz, a->info.nombre);
}

arbol hijoIzquierdo (arbol a)
{
    return (a->hizq);
}

arbol hijoDerecho (arbol a)
{
    return (a->hder);
}


int contarMiembrosAbb(arbol a)
{
    if(a!=NULL)
    {
        return 1 + contarMiembrosAbb(a->hder)+contarMiembrosAbb(a->hizq);
    }
    else
        return 0;
}

boolean perteneceAbb(arbol a, strings nombreABuscar){
    if(a == NULL)
        return FALSE;
    else
        if(streq(a->info.nombre,nombreABuscar))
            return TRUE;
    else{
        if(strmen(a->info.nombre,nombreABuscar))
            return perteneceAbb(a->hder,nombreABuscar);
        else
            return perteneceAbb(a->hizq,nombreABuscar);
    }
}
void insertAbb(arbol &a,MiembroRealeza m){

        if(a==NULL){
            a=new nodo;
            a->info=m;
            a->hizq=NULL;
            a->hder=NULL;
        }
        else{
            if(strmen(m.nombre,a->info.nombre))
                insertAbb(a->hizq,m);
            else
                insertAbb(a->hder,m);
        }
}
/*
void Minimo(arbol a){
    if (a->hizq==NULL)
        return (a->info.nombre);
    else
        return Minimo(a->hizq);
}
*/


void bajarArbolAux(arbol a, FILE *f){
    if (a!= NULL){
        bajarMiembro(a->info,f);
        bajarArbolAux(a->hizq,f);
        bajarArbolAux(a->hder,f);
    }
}
void bajarArbol(arbol a, strings archAbb){
    FILE *f=fopen(archAbb,"wb");
    bajarArbolAux(a,f);
    fclose(f);

}

void levantarArbol(arbol &a, strings archAbb){
    FILE * f= fopen(archAbb,"rb");
    MiembroRealeza buffer;
    crear(a);
    levantarMiembro(buffer,f);
    while(!feof(f)){
        insertAbb(a,buffer);
        levantarMiembro(buffer,f);
    }
    fclose(f);
}

void mostrarMiembrosArbol(arbol a){
    if(!esVacio(a)){
        mostrarMiembrosArbol(a ->hizq);
        strings s;
        strcrear (s);
        print(a->info.nombre);
        if(!streq(a->info.nombreProgenitor,s))
            printf(" hijo/a de ");
        strdestruir(s);
        print(a->info.nombreProgenitor);
        printf(" nacio el ");
        MostrarFecha(a->info.fechaNacimiento);
        if(a->info.miembroInicialDinastia == TRUE){
            printf(" Es miembro Inicial.\n");
        }

        mostrarMiembrosArbol(a ->hder);
    }

}


 void Eliminar (arbol &a)
{
    if (a != NULL)
    {
        Eliminar (a -> hizq);
        Eliminar (a -> hder);
        delete a;
        a = NULL;
    }
}
