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
        L->sig=NULL;
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

boolean perteneceListaFamiliaReal(lista L, strings nombre){
    boolean pertenece= FALSE;
    while(L!=NULL && !pertenece){
        if(streq(L->info.mr.nombre,nombre)) //posible vercion correcta seria
            pertenece=TRUE; //(streq(dar(darNombre(L))darMiembroRealeza(darNombre(f))))
        else
            L=L->sig;
    }
return pertenece;
}

void InsBackIterLista (lista &L, FamiliaReal fM){
    lista nuevo = new nodof;
    nuevo->sig=NULL;
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
        while(L->info.mr.nombreProgenitor == fM.mr.nombreProgenitor){
            if(L->sig->info.mr.nombreProgenitor != fM.mr.nombreProgenitor){

            }
            aux->info = L->info;

        }
    }
}

void insertarHijo(lista &l, FamiliaReal fam){
    boolean encontrePadre=FALSE, encontre=FALSE;
    lista aux = l, lpadre;
    listaStr lproge;
    crearListaStrings(lproge);
    lista temp;

    // Busco nodo padre y guardo puntero a sublista.
    while(aux!=NULL && !encontrePadre){
        if(streq(fam.mr.nombreProgenitor,aux->info.mr.nombre)){
            encontrePadre = TRUE;
            lpadre        = aux;
        }
        else{
            aux=aux->sig;
        }
    }

    // Si hay mas nodos,
    // Busco nodo ultimo hijo si tuviera iterando por mismo nombre padre
    // Cuando salgo esto parado en el padre o en el ultimo hijo

    while(lpadre->sig!=NULL && !encontre){
        if(!streq(fam.mr.nombreProgenitor,lpadre->sig->info.mr.nombreProgenitor)){
            encontre = TRUE;
        }
        else{
            lpadre=lpadre->sig;
        }
    }

    temp=new nodof;
    copFamilia(temp->info,fam);

    temp->sig = lpadre->sig;
    lpadre->sig = temp;
}

Fecha devolverUltimaFecha(lista L){
    Fecha fech;
    cargarFechaNula(fech);
    while(L != NULL){
        if(L->sig==NULL)
            copiarFecha1y2(fech,L->info.mr.fechaNacimiento);

        L = L->sig;
    }
    return fech;
}

void marcarFallecido(lista &l, strings nombre, Fecha f){
    lista aux=l;
    boolean encontre =FALSE, monarca=FALSE;
    while(aux!=NULL && !encontre){
        if(streq(nombre,aux->info.mr.nombre)){
            if(darFallecimiento(aux->info))
               printf("el miembro ya fallecio");
            else{
                aux->info.fallecimiento=TRUE;
                copiarFecha1y2(aux->info.fechaFallecimiento,f);
                aux->info.aspiarnteAlTrono=FALSE;
                if(darMonarcaActual(aux->info)==TRUE){
                    aux->info.monarcaActual = FALSE;
                    encontre=TRUE;
                    if(aux->sig!=NULL){
                        aux=aux->sig;
                        while(aux!=NULL && !monarca){
                            if(darAspirante(aux->info) == TRUE){
                                aux->info.aspiarnteAlTrono=FALSE;
                                aux->info.monarcaActual=TRUE;
                                aux->info.fueoNoMonarca=TRUE;
                                copiarFecha1y2(aux->info.fechaAscension,f);
                                monarca=TRUE;
                            }
                            else
                                aux=aux->sig;
                        }
                    }
            }
            else{
              aux=aux->sig;
            }
        }
        }else{
            aux=aux->sig;
        }
    }
}

void imprimirMonarcas(lista L){
    int i=1;
    while(L!=NULL){
        if(darFueMonarca(L->info)==TRUE){
            printf("\n%d - ",i);
            i++;
            mostrarMiembroFamiliaRealMonarcas(L->info);
       }
        L=L->sig;
    }
}

void bajarListaFamiliaReal(lista L, strings archFamReal){
    FILE *f = fopen (archFamReal, "wb");
    while(L != NULL){
        bajarFamReal(L->info, f);
        L = L->sig;
    }
    fclose (f);
}

void levantarListaFamiliaReal (lista &L, strings archFamReal){
    FILE *f = fopen (archFamReal, "rb");
    FamiliaReal buffer;
    crearListaFamiliaReal(L);
    levantarFamReal(buffer,f);
    while (!feof(f)){
        InsBackIterLista(L,buffer);
        levantarFamReal(buffer,f);
    }
    fclose(f);
}
void marcarAbdicadolista(lista &l, strings nombre, Fecha f)
{
    lista aux = l;
    boolean encontre=FALSE;
    boolean encontreAspi = FALSE;
    while (aux!=NULL && !encontre)
    {
        if(streq(nombre, aux->info.mr.nombre))
        {
            if(darAbdico(aux->info)){
                printf("el miembro ya abdico");
            }
            else{
                aux->info.abdico=TRUE;
                copiarFecha1y2(aux->info.abdicacion,f);
                aux->info.aspiarnteAlTrono=FALSE;
                aux->info.monarcaActual=FALSE;
                if(darMonarcaActual(aux->info)==TRUE){
                    encontre = TRUE;
                    aux->info.monarcaActual = FALSE;
                    if(aux->sig!=NULL)
                    {
                        aux = aux->sig;
                        while(aux !=NULL && !encontreAspi)
                        {
                            if(darAspirante(aux->info)==TRUE)
                            {
                                aux->info.monarcaActual=TRUE;
                                aux->info.aspiarnteAlTrono=FALSE;
                                copiarFecha1y2(aux->info.fechaAscension,f);
                                aux->info.fueoNoMonarca=TRUE;
                                encontreAspi = TRUE;
                            }
                            else
                                aux=aux->sig;
                        }
                    }
            }
            else{
              aux=aux->sig;
            }
        }
        }else{
            aux=aux->sig;
        }
    }
}
void imprimirAspirantes(lista l){
    int i = 1;
    while(l != NULL){
            if(darAspirante(l->info)){
                printf("\n%d -",i);
                mostrarAspirantesFamilia(l->info);
                i++;
            }
        l = l->sig;
    }
}

void imprimirHistorial(lista l){
    int i = 1;
    while(l != NULL){
        printf("\n%d -",i);
        mostrarhistorial(l->info);
        l = l ->sig;
        i++;
    }
}

void borrarLista(lista &L){
    lista aux;
    while(L!=NULL){
        aux=L;
        L=L->sig;
        delete aux;
    }
}

boolean ningunAsipirante(lista l){
boolean hay = FALSE;
   while(l!=NULL && !hay){
      if(darAspirante(l->info))
          hay = TRUE;
      else
          l=l->sig;
   }
   return hay;
}
