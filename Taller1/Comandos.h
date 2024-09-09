#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED
#include "stringdinamico.h"
typedef struct{
        strings comando;
		int cantParametros;
		int codigo;

}Comandos;

void darComando(Comandos com, strings &s);

int darParametro(Comandos com);

int darCodigo(Comandos com);

void bajarComando(Comandos com, FILE *b);

void levantarComando(Comandos &con, FILE *b);

void crearComando(Comandos &com);
void imprimircomandocomando(Comandos com);
void copiarComando(Comandos com, Comandos &copiado);
void liberarComando (Comandos &com);
#endif // COMANDOS_H_INCLUDED
