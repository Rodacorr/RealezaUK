#include"Comandos.h"
void darComando( Comandos com, strings &s){
    strcop( com.comando, s);
}

int darParametro(Comandos com){
    return com.cantParametros;
}

int darCodigo(Comandos com){
    return com.codigo;
}

void bajarComando(Comandos com, FILE *b){
    bajarString(com.comando, b);
    fwrite (&com.cantParametros, sizeof(int), 1, b);
    fwrite (&com.codigo, sizeof(int), 1, b);
}

void levantarComando(Comandos &com, FILE *b){
    strings s;
    strcrear(s);
    levantarString(s,b);
    strcrear(com.comando);//habia que crearlo
    strcop(com.comando,s);
    fread(&com.cantParametros, sizeof(int), 1, b);
    fread(&com.codigo, sizeof(int), 1, b);
    strdestruir(s);
}

void crearComando(Comandos &com){ //ARREGLAR SELECTORA
    strcrear(com.comando);
    printf("ingrese comando:\n");
    fflush(stdin);
    scan(com.comando);
    printf("ingrese cantidad\n");
    scanf("%d",&com.cantParametros);
    printf("ingrese codigo\n");
    scanf("%d",&com.codigo);
}

void imprimircomandocomando(Comandos com){
    print(com.comando);
    printf("%d",com.cantParametros);
    printf("%d",com.codigo);
}

void copiarComando(Comandos com, Comandos &copiado){
    strcrear(copiado.comando);
    strcop(copiado.comando, com.comando);
    copiado.cantParametros=com.cantParametros;
    copiado.codigo=com.codigo;
}

void liberarComando (Comandos &com){
    strdestruir(com.comando);
}
