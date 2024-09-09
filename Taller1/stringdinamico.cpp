#include "stringdinamico.h"

void strcrear (strings &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strdestruir (strings &s)
{
    delete [] s;
    s = NULL;
}

int strlar (strings s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strcop (strings &s1,strings s2)
{
    int i = 0;
    int largo = strlar(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan (strings &s)
{
    strings aux = new char[MAX];
    int i=0;
    char c;
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    strcop (s,aux);
    strdestruir (aux);
}

void strcon (strings &s1,strings s2)
{
    strings aux;
    strcrear (aux);
    strcop (aux, s1);
    int largo = strlar (s1) + strlar (s2) + 1;
    if (largo > MAX)
        largo = MAX;
    delete [] s1;
    s1 = new char[largo];
    int i = 0;
    while (aux[i] != '\0')
    {
        s1[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX-1)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    strdestruir (aux);
}

void strswp (strings &s1, strings &s2)
{
    strings aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}

void print (strings s)
{
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

boolean strmen (strings s1, strings s2)
{
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;
    return menor;
}

boolean streq(strings s1,strings s2)
{
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

void pasarMayusculas(strings &s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>=97&&s[i]<=122)
            s[i]=s[i]-32;
        i++;
    }
}

void bajarString(strings s, FILE *f){
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite (&s[i], sizeof(char), 1, f);
}

void levantarString(strings &s, FILE *f){
    int i=0;
    strings aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    strcop (s, aux);
    strdestruir(aux);
}


void eleminarEspacios(strings s, strings &sin){
    int i=0;
    while (s[i] != '\0')
    {
        if(s[i]==' ')
            i++;
        else{
            sin[i] = s[i];
            i++;
        }
    }
    sin[i] = '\0';
}

void strPrimerPalabraYResto(strings s2, strings &s1, strings &s3)
{
    int i=0;
    int s=0;
    int d=0;
    int largo = strlar(s2)+1;
    strings aux1, aux3;
    aux1=new char[largo];
    aux3=new char[largo];

    while(s2[i] == ' '){
        i++;
    }
    while (s2[i] != ' ' && s2[i] !='\0'){
        aux1[s] = s2[i];
        i++;
        s++;
    }
    aux1[s]='\0';
    strcop(s1,aux1);
    while(s2[i] != '\0'){
        aux3[d] = s2[i];
        i++;
        d++;
    }
    aux3[d]='\0';
    strcop(s3,aux3);
    strdestruir(aux1);
    strdestruir(aux3);
}

boolean strVacio(strings s){
    if(s[0]=='\0')
        return TRUE;
    else
        return FALSE;
}

int atoi(strings s){
    int i=0,j=0;
    int num=0,multiplicador= 1;
    int aux=0;

    while(s[j] != '\0')
        j++;

    for (i = j - 1; i >= 0; i--){
        if(s[i]!='/'){
            aux = s[i] - 48;
            num = aux * multiplicador + num;
            multiplicador = multiplicador * 10;
        }
    }
    return num;
}

boolean esAlfabetico(strings palabra){
    boolean alfabetico = TRUE;
    int i = 0;
    char c;

    while(palabra[i] != '\0' && alfabetico){

        if(palabra[i] < 65 || palabra[i] > 90){
            alfabetico = FALSE;
        }
        i++;
    }
    return alfabetico;
}
