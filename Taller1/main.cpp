#include <iostream>
#include "listas.h"

int main()
{
    listaComandos L;
    crearListaComandos(L);
    LevantarListaComandos(L,"listaComandos.txt");//levanta lista de comandos

    lista li;                                    //lista de familia real
    crearListaFamiliaReal(li);

    listaStr lStr;                              //lista strings

    strings comand;

    MiembroRealeza miembro;
    arbol a;                                    //arbol por nombre
    crear(a);
    FamiliaReal fam;                            //miembro de familiareal que se insertara en la lista de ascension

    Fecha fech;
    boolean encontre = FALSE;
    int cantParametros=0,codigo=0;

    do
    {
        fflush(stdin);
        printf("\n");
        strcrear(comand);
        crearListaStrings(lStr);
        scan(comand);
        cargarPalabrasEnListas(lStr,comand);    //carga string en lista
        buscarComandoEnLista(L,lStr->info,encontre,cantParametros,codigo);
        if(listaVacia(li)){
            cargarFechaNula(fech);
        }

        if(!encontre)
        {
            printf("\n---ERROR---\nEl comando ingresado es incorrecto.\n");
        }
        switch (codigo)
        {
        case 1:
            if(codigo==1 && LargoIter(lStr)==cantParametros)
            {
                lStr=lStr->sig;
                int dia,mes,anio;
                ObtenerFechasDeString(lStr->info,dia,mes,anio);
                Fecha faux;
                CrearFechaCon3Variables(faux,dia,mes,anio);

                if(fechaIgualMenor(fech,faux))
                {
                    lStr=lStr->sig;
                    strings saux;
                    strings snombre;
                    strcrear(saux);
                    strcrear(snombre);
                    strcop(snombre,lStr->info);
                    if(esAlfabetico(lStr->info))
                    {
                        cargarMiembro(miembro,faux,lStr->info,saux);
                        miembro.miembroInicialDinastia==TRUE;
                        if(esVacio(a))
                        {
                            insertAbb(a, miembro);
                            cargarMiembroInicial(fam, miembro);
                            InsBackIterLista(li,fam);
                            printf("\ndinastia iniciada");
                            copiarFecha1y2(fech,faux);
                        }
                        else
                            printf("\n---ERROR---\nya existe una dinastia");
                    }
                    else
                        printf("\n---ERROR---\nel nombre no es aflabetico.");

                    strdestruir(saux);
                    strdestruir(snombre);
                }
            }
            else
            {
                printf("---ERROR---\nel comando es invalido");
            }
            break;

        case 2:
            MiembroRealeza miembro2;
            if(codigo==2 && LargoIter(lStr)==cantParametros)
            {
                lStr=lStr->sig;
                int dia,mes,anio;
                ObtenerFechasDeString(lStr->info,dia,mes,anio);
                Fecha faux;
                CrearFechaCon3Variables(faux,dia,mes,anio);
                if(EsValida(faux))
                {
                   if(fechaIgualMenor(fech,faux)==TRUE)
                    {
                        lStr=lStr->sig;
                        strings proge;
                        strings nino;
                        strcrear(proge);
                        strcop(proge,lStr->info);
                        if(esAlfabetico(proge))
                        {
                            if(perteneceAbb(a, proge))
                            {
                                lStr=lStr->sig;
                                lStr=lStr->sig;
                                strcrear(nino);
                                strcop(nino,lStr->info);
                                if(esAlfabetico(nino))
                                {
                                    cargarMiembro(miembro,faux,nino,proge);
                                    copiarFecha1y2(fech,faux);
                                }
                                else
                                    printf("\n---ERROR---\nnombre del hijo no es alfabetico");

                                if(!perteneceAbb(a,nino))
                                {
                                    insertAbb(a, miembro);
                                    cargarNuevoMiembro(fam, miembro);
                                    insertarHijo(li,fam);
                                    printf("\nnacimiento registrado");
                                    copiarFecha1y2(fech,faux);
                                }
                                else
                                    printf("\n---ERROR---\nel nombre ya existe en la dinastia");
                            }
                            else
                                printf("\n---ERROR---\nno pertenece a la dinastia");
                        }
                        else
                        {
                            printf("\n---ERROR---\nnombre del padre no es alfabetico");
                            strdestruir(nino);
                            strdestruir(proge);
                        }
                   }
                    else
                    {
                        printf("\n---ERROR---\nFecha ingresada no es mayor");
                    }
                }
            }
                else
                    printf("\n---ERROR---\ncantidad de parametros invalidos");
                break;
            case 3:
                if(codigo==3 && LargoIter(lStr)==cantParametros)
                {
                    lStr=lStr->sig;
                    int dia,mes,anio;
                    ObtenerFechasDeString(lStr->info,dia,mes,anio);
                    Fecha faux;
                    CrearFechaCon3Variables(faux,dia,mes,anio);
                    if(EsValida(faux))
                    {
                        if(fechaIgualMenor(fech,faux)==TRUE)
                        {

                            lStr=lStr->sig;
                            strings fallecido;
                            strcrear(fallecido);
                            strcop(fallecido,lStr->info);
                            if(esAlfabetico(fallecido))
                            {
                                if(perteneceListaFamiliaReal(li,fallecido))
                                {
                                    marcarFallecido(li,fallecido,faux);
                                    printf("\nfallecimiento registrado");
                                    copiarFecha1y2(fech,faux);

                                }
                                else
                                    printf("\n---ERROR---\nmiembro no se encuentra en la lista");
                            }
                            else{
                                printf("\n---ERROR---\nel nombre no es alfabetico");
                                strdestruir(fallecido);
                            }
                        }
                        else{
                            printf("\n---ERROR---\nFecha ingresada no es mayor");
                        }

                    }
                    else
                        printf("\n---ERROR---\nFecha no Valida");
                }
                else
                {
                    printf("\n---ERROR---\ncantidad de parametros invalidos");
                }
                break;

            case 4:
                if(codigo==4 && LargoIter(lStr)==cantParametros)
                {
                    lStr=lStr->sig;
                    int dia,mes,anio;
                    ObtenerFechasDeString(lStr->info,dia,mes,anio);
                    Fecha faux;
                    CrearFechaCon3Variables(faux,dia,mes,anio);
                    if(EsValida(faux))
                    {
                        if(fechaIgualMenor(fech,faux)==TRUE)
                        {
                            lStr=lStr->sig;
                            strings abdicado;
                            strcrear(abdicado);
                            strcop(abdicado,lStr->info);
                            if(esAlfabetico(abdicado))
                            {
                                if(perteneceListaFamiliaReal(li,abdicado))
                                {
                                    marcarAbdicadolista(li,abdicado,faux);
                                    printf("\nabdicacion registrada");
                                    copiarFecha1y2(fech,faux);
                                }
                                else
                                    printf("\n---ERROR---\nmiembro no se encuentra en la lista");
                            }
                            else
                            {
                                strdestruir(abdicado);
                                printf("\n---ERROR---\nel nombre no es alfabetico");
                            }

                        }
                        else
                            printf("\n---ERROR---\nFecha ingresada no es mayor");
                    }
                    else
                        printf("\n---ERROR---\nFecha no Valida");
                }
                else
                {
                    printf("\n---ERROR---\n cantidad de parametros invalidos");
                }
                break;

            case 5:
                if(codigo==5 && LargoIter(lStr)==cantParametros)
                {
                    printf("\nEntro miembros\n");
                    mostrarMiembrosArbol(a);
                }
                else
                {
                    printf("cantidad de parametros invalidos");
                }
                break;
            case 6:
                if(codigo==6 && LargoIter(lStr)==cantParametros)
                {
                    printf("\nEntro monarcas");
                    imprimirMonarcas(li);
                }
                else
                {
                    printf("cantidad de parametros invalidos");
                }
                break;

            case 7:
                if(codigo==7 && LargoIter(lStr)==cantParametros)
                {
                    printf("\nEntro aspirantes");
                    imprimirAspirantes(li);
                }
                else
                {
                    printf("cantidad de parametros invalidos");
                }
                break;
            case 8:
                if(codigo==8 && LargoIter(lStr)==cantParametros)
                {
                    printf("\nEntro historial");
                    imprimirHistorial(li);
                }
                else
                {
                    printf("cantidad de parametros invalidos");
                }
                break;
            case 9:
                if(codigo==9 && LargoIter(lStr)==cantParametros)
                {
                    printf("\nrespaldo");
                    bajarArbol(a, "archAbb.txt");
                    bajarListaFamiliaReal(li, "archLiFamReal.txt");
                }
                else
                {
                    printf("cantidad de parametros invalidos");
                }
                break;
            case 10:
                if(codigo==10 && LargoIter(lStr)==cantParametros)
                {
                    printf("\nrecupero");
                    levantarArbol(a,"archAbb.txt");
                    levantarListaFamiliaReal(li, "archLiFamReal.txt");
                }
                else
                {
                    printf("cantidad de parametros invalidos");
                }
                break;
            case 11:
                if(codigo==11 && LargoIter(lStr)==cantParametros)
                {
                    printf("\nHASTA LA PROXIMA\n");
                    strdestruir(comand);
                    borrarListaStrings(lStr);
                    borrarLista(li);
                    Eliminar(a);
                }
                else
                {
                    printf("cantidad de parametros invalidos");
                }
                break;
            default:
                printf("\n---ERROR---\nComando incorrecto, ingrese nueva mente: ");
                break;
            }
        borrarListaStrings(lStr);
        strdestruir(comand);

        if(codigo!=11)
            codigo=0;

    }while(codigo!=11);
}
