#include "Boolean.h"

void cargaboolean(boolean &bul){
        int a;
        printf("\nIngrese 1 si hay Stock, 2 si no hay Stock\n");
        scanf("%d",&a);
        if (a==1)
            bul=TRUE;
        else
            bul=FALSE;
}

void desplegarboolean(boolean bul){
    if (bul==TRUE)
        printf("TRUE\n");
    else
        printf("FALSE\n");
}

void bajarBoolean(boolean bul, FILE *f){
    fwrite (&bul, sizeof(boolean), 1, f);
}
void levantarBoolean (boolean &bul, FILE*f){
        fread(&bul, sizeof(boolean), 1, f);

}
