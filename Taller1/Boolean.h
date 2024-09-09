#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

#include <stdio.h>

typedef enum {FALSE,TRUE} boolean;

void cargaboolean(boolean &bul);

void desplegarboolean(boolean bul);

void bajarBoolean(boolean bul, FILE *f);

void levantarBoolean (boolean &bul, FILE*f);
#endif // BOOLEAN_H_INCLUDED
