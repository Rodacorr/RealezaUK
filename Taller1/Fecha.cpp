#include "Fecha.h"

void CargarFecha(Fecha &f){
    printf("\nIngrese el dia: ");
    scanf("%d",&f.dia);
    printf("\nIngrese el mes: ");
    scanf("%d",&f.mes);
    printf("\nIngrese el anio: ");
    scanf("%d",&f.anio);
}

int DarDia(Fecha f){
    return f.dia;
}

int DarMes(Fecha f){
    return f.mes;
}

int DarAnio(Fecha f){
    return f.anio;
}

void MostrarFecha(Fecha f){
    printf(" %d / %d / %d.\n",f.dia,f.mes,f.anio);
}

boolean EsValida(Fecha f){
    boolean Valida=FALSE;

    switch (f.mes)
        {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                            if (f.dia >= 1 && f.dia <= 31)
                                Valida = TRUE;
                            else
                                Valida = FALSE;
                        break;
                case 4:
                case 6:
                case 9:
                case 11:
                            if (f.dia >= 1 && f.dia <= 30)
                                Valida = TRUE;
                            else
                                Valida = FALSE;
                        break;
                 case 2:
                        if (f.anio % 4 == 0)
                            if (f.dia >= 1 && f.dia <= 29)
                                Valida = TRUE;
                            else
                                Valida = FALSE;
                            else
                                if (f.dia >= 1 && f.dia <= 28)
                                    Valida = TRUE;
                                else
                                    Valida = FALSE;
                        break;
                 default:
                        Valida = FALSE;
                        break;
 }
    return Valida;
}

long int DeFechaaSumaTotal(Fecha f){
    return f.anio * 10000 + f.mes * 100 + f.dia;
}

boolean fechaIgualMenor (Fecha f, Fecha f2){
    if(DeFechaaSumaTotal(f) <= DeFechaaSumaTotal(f2))
        return TRUE;
    else
        return FALSE;
}

void ObtenerFechasDeString(strings s, int &dia, int &mes, int &anio){
    int i=0,j=0,k=0,m=0;
    dia = 0; mes = 0; anio=0;
    int multiplicador = 0;
    int auxdia, auxmes, auxanio;
    int largo = strlar(s)+1;

    strings aux1, aux2, aux3;
    aux1=new char[largo];
    aux2=new char[largo];
    aux3=new char[largo];

    while(s[i]!='\0' && s[i]!='/'){
        aux1[j] = s[i];
        j++;
        i++;
    }
    aux1[j]='\0';
    i++;
    auxdia = atoi(aux1);
    if(auxdia>0 && auxdia<32){
        dia = auxdia;
    }
    else{
        printf("\nERROR DIA NO VALIDO");
        dia = 0;
    }

    while(s[i]!='\0' && s[i]!='/'){
        aux2[k] = s[i];
        k++;
        i++;
    }
    aux2[k]='\0';
    i++;
    auxmes = atoi(aux2);
    if(auxmes>0 && auxmes<13){
        mes = auxmes;
    }
    else{
        printf("\nERROR MES NO VALIDO");
        mes = 0;
    }

    while(s[i]!='\0' && s[i]!='/'){
        aux3[m] = s[i];
        m++;
        i++;
    }
    aux3[m]='\0';
    i++;
    auxanio = atoi(aux3);
    if(auxdia>0){
        anio = auxanio;
    }
    else{
        printf("\nERROR ANIO NO VALIDO");
        anio = 0;
    }

    strdestruir(aux1);
    strdestruir(aux2);
    strdestruir(aux3);
}
boolean esFormatoFecha(strings s){
    int cantBarras = 2;
    int cantNumerosOP1 = 4;
    int cantNumerosOP2 = 5;
    int cantNumerosOP3 = 6;
    int cantNumerosOP4 = 7;
    int cantNumerosOP5 = 8;
    int i=0;
    int contadorNum = 0;
    int contadorBarras = 0;
    boolean ES = FALSE;

    while(s[i] != '\0'){
        if(s[i] == '/'){
            contadorBarras++;
        }
        else
            contadorNum++;
        i++;
    }
    if(contadorBarras == cantBarras && (contadorNum == cantNumerosOP1 || contadorNum == cantNumerosOP2 || contadorNum == cantNumerosOP3 ||contadorNum == cantNumerosOP4 || contadorNum == cantNumerosOP5))
        ES = TRUE;

     return ES;
}
void CrearFechaCon3Variables(Fecha &fech, int dia, int mes, int anio){

    fech.dia = dia;
    fech.mes = mes;
    fech.anio = anio;
}

void bajarFecha(Fecha fech, FILE* f){
    fwrite (&fech.dia, sizeof(int), 1, f);
    fwrite (&fech.mes, sizeof(int), 1, f);
    fwrite (&fech.anio, sizeof(int), 1, f);
}

void levantarFecha(Fecha &fech, FILE *b){
    fread(&fech.dia, sizeof(int), 1, b);
    fread(&fech.mes, sizeof(int), 1, b);
    fread(&fech.anio, sizeof(int), 1, b);
}

void cargarFechaSinPrintf(Fecha &f, int d, int m, int a){
    f.dia=d;
    f.mes=m;
    f.anio=a;
}

void cargarFechaNula(Fecha &f1){
    f1.dia=00;
    f1.mes=00;
    f1.anio=0000;
}
void copiarFecha1y2(Fecha &f1, Fecha f2){
    f1.dia=f2.dia;
    f1.mes=f2.mes;
    f1.anio=f2.anio;
}

boolean compararFechas(Fecha f1, Fecha f2)
{
    if(f1.anio > f2.anio)
        return FALSE;
    else
    {
        if(f1.anio == f2.anio)
        {
            if(f1.mes > f2.mes)
                return FALSE;
            else
            {
                if(f1.mes == f2.mes)
                {
                    if(f1.dia > f2.dia)
                        return FALSE;
                    else
                    {
                        if(f1.dia == f2.dia)
                        {
                            return TRUE;
                        }
                        else
                        {
                            return TRUE;
                        }
                    }
                }
                else
                {
                    return TRUE;
                }
            }
        }
        else
        {
            return TRUE;
        }
    }
}
