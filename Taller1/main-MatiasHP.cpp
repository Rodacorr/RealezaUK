#include <iostream>
#include "listas.h"
int main()
{
    listaComandos L;
    crearListaComandos(L);
    LevantarListaComandos(L,"listaComandos.txt");
    lista li; //lista de familia real
    crearListaFamiliaReal(li);
    listaStr lStr;   //lista strings

    strings comand;         //comando para pasar a lista strings

    MiembroRealeza miembro;
    arbol a; //arbol por nombre
    crear(a);
    FamiliaReal fam; //miembro de familiareal que se insertara en la lista de ascension

    //PARA PROBAR INICIAR


   /* if(streq(lStr->info,L->comandos.comando)&& L->comandos.cantParametros==LargoIter(lStr))
    {
        printf("entro");
        lStr=lStr->sig;
        int dia,mes,anio;
        ObtenerFechasDeString(lStr->info,dia,mes,anio);
        Fecha faux;
        CrearFechaCon3Variables(faux,dia,mes,anio);
        lStr=lStr->sig;
        strings saux;
        strings snombre;
        strcrear(saux);
        strcrear(snombre);
        strcop(snombre,lStr->info);
        if(esAlfabetico(lStr->info))
        {
            printf("LLEGO");
            cargarMiembro(miembro,faux,lStr->info,saux);
            miembro.miembroInicialDinastia = TRUE;
            mostrarMiembro(miembro);

            if(!perteneceAbb(a,lStr->info))
            {
//Podemos en vez de usar el bool para ver si existe el nombre, como es inicial podemos decir si el arbol no es vaio etnoces no se puede guardar el miembro inicial
                insertAbb(a, miembro);
                printf("\nCantidad de miembros en el arbol: %d.",contarMiembrosAbb(a));
                printf("\nMuesto los miembros dentro del arbol: \n");
                mostrarMiembrosArbol(a);

                cargarMiembroInicial(fam, miembro);
                printf("\nMuesto los miembros dentro de la lista de Ascension: \n");
                InsBackIterLista(li,fam);
                imprimirListaFamiliaReal(li);
            }
            else
                printf("\nERROR el nombre ya existe en la dinastia");
        }
        else
            printf("\nERROR el nombre no es aflabetico.");

        strdestruir(saux);
        strdestruir(snombre);
    }*/
    int cantPar,codigo;
    boolean encontre;
    do
    {
        borrarListaStrings(lStr);
        crearListaStrings(lStr);
        strcrear(comand);
        fflush(stdin);
        scan(comand);
        cargarPalabrasEnListas(lStr,comand); //carga string en lista
        buscarComandoEnLista(L,lStr->info,encontre,cantPar,codigo);
        int dia,mes,anio;
        Fecha faux;
        strings padre;
        strings puntero;
        strings snombre;
        strcrear(padre);
        strcrear(snombre);
        strcrear(puntero);
       // mostrarLista(lStr);

        //printf(" el codigo es %d\n",codigo);
        //imprimirComando(L);
        switch (codigo)
        {
        case 1:
            printf("\niniciar\n");
            lStr=lStr->sig;

            ObtenerFechasDeString(lStr->info,dia,mes,anio);

            CrearFechaCon3Variables(faux,dia,mes,anio);
            lStr=lStr->sig;

            strcop(snombre,lStr->info);
            if(esAlfabetico(lStr->info))
            {

                cargarMiembro(miembro,faux,lStr->info,padre);
                miembro.miembroInicialDinastia = TRUE;
                //mostrarMiembro(miembro);

                if(!perteneceAbb(a,snombre))
                {
//Podemos en vez de usar el bool para ver si existe el nombre, como es inicial podemos decir si el arbol no es vaio etnoces no se puede guardar el miembro inicial
                    insertAbb(a, miembro);
                    //printf("\nCantidad de miembros en el arbol: %d.",contarMiembrosAbb(a));
                   // printf("\nMuesto los miembros dentro del arbol: \n");
                  //  mostrarMiembrosArbol(a);

                    //cargarMiembroInicial(fam, miembro);
                    //printf("\nMuesto los miembros dentro de la lista de Ascension: \n");
                    //InsBackIterLista(li,fam);
                   // imprimirListaFamiliaReal(li);
                }
                else
                    printf("\nERROR el nombre ya existe en la dinastia\n");
            }
            else
                printf("\nERROR el nombre no es aflabetico\n.");

            strdestruir(padre);
            strdestruir(snombre);
            strdestruir(puntero);
            break;
        case 2:
            printf("\nnacimiento\n");

            lStr=lStr->sig;
            ObtenerFechasDeString(lStr->info,dia,mes,anio);

            CrearFechaCon3Variables(faux,dia,mes,anio);
            lStr=lStr->sig;

            strcop(snombre,lStr->info);
            if(esAlfabetico(lStr->info))
            {

                lStr=lStr->sig;
                lStr=lStr->sig;


                strcop(padre,lStr->info);

                cargarMiembro(miembro,faux,snombre,padre);
                miembro.miembroInicialDinastia=FALSE;

                //mostrarMiembro(miembro);

                if(!perteneceAbb(a,snombre))
                    if (perteneceAbb(a,padre))
                        insertAbb(a, miembro);
                    else
                    printf("\n no existe padre en dinastia");
                   // mostrarMiembrosArbol(a);
                   // InsBackIterLista(li,fam);
                else
                    printf("\nERROR el nombre ya existe en la dinastia");
            }
            else
                printf("\nERROR el nombre no es aflabetico.");

            strdestruir(padre);
            strdestruir(snombre);
            strdestruir(puntero);
            break;
        case 3:
            printf("\nfallecimiento\n");
            break;
        case 4:
            printf("\nabdicacion\n");
            break;
        case 5:
            printf("\nmiembros\n");
            mostrarMiembrosArbol(a);
            break;
        case 6:
            printf("\nmonarcas\n");
            //imprimirMonarcas(li);
            break;
        case 7:
            printf("\naspirantes\n");
            break;
        case 8:
            printf("\nhistorial\n");
            break;
        case 9:
            printf("\nguardar\n");
            break;
        case 10:
            printf("\nrecuperar\n");
            break;
        case 11:
            printf("\nsalir\n");
            break;


        }
    }while(codigo!= 11);



//PARA PROBAR NACIMIENTO
    /*
    boolean encontre = FALSE;
    int cantParametros = 0;
    int codigo = 0;
    mostrarLista(lStr);
    buscarComandoEnLista(L,lStr->info,encontre,cantParametros,codigo);
    if(encontre && cantParametros==LargoIter(lStr)){
        printf("\nEntro");

    }
    */
    /*
      Fecha f;
      MiembroRealeza m;
      strings nom,pa;
      strcrear(nom);
      strcrear(pa);
      FamiliaReal fam;
      scan(nom);
      fflush(stdin);
      scan(pa);
      CargarFecha(f);
      cargarMiembro(m,f,nom,pa);

      strdestruir(pa);
      strdestruir(nom);

    */

//mostrarMiembro(m);
// cargarMiembroInicial(fam,m);
//cargarNuevoMiembro(fam,m);

//   mostrarMiembroFamiliaReal(fam);
//cargarListaFamiliaReal(li,fam);
// printf("\nhola\n");
//imprimirListaFamiliaReal(li);
//carga los comandos a la la lista de comandos
//strings s,b,n,a,q;
//strcrear(s);
    /*
    strcrear(b);
    strcrear(n);
    strcrear(q);
    strcrear(a);
    */
    /*scan(s);
    pasarMayusculas(s);
    print(s);
    printf("\n");
    */
    /*
        strPrimerPalabraYResto(s,b,n);
        print(b);
        printf("\n");
        print(n);
        fflush(stdin);
        printf("\n");
        strPrimerPalabraYResto(n,a,q);

        fflush(stdin);
        print(a);
        printf("\n");
        print(q);

    */
    /*listaStr ls;
    crearListaStrings(ls);
    cargarPalabrasEnListas(ls,s);

    mostrarLista(ls);
    */
    /*if(esAlfabetico(s))
        printf("\nES ALFABETICO");
    else
        printf("\nNO ES ALFAETICO");

    strdestruir(s);*/
//siempre para implementar hacer un destruir de las variables
    /*for(int i=0; i<11;i++){
        crearComando(com);
        print(com.comando);
        printf("%d\n",com.cantParametros);
        printf("%d\n",com.codigo);
        InsBackComandos(L, com);
        liberarComando(com);
    }
    *///este for para ingresar los comandos manual

//BajarListaComandos(L,"listaComandos.txt");
//preguntar si nesecitamos bajarla

    borrarLista(L);
}

