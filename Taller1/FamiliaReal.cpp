#include "FamiliaReal.h"


boolean darMonarcaActual(FamiliaReal fam){
    return fam.monarcaActual;
}

boolean darFueMonarca (FamiliaReal fam){
    return fam.fueoNoMonarca;
}

boolean darAspirante(FamiliaReal fam){
    return fam.aspiarnteAlTrono;
}

boolean darAbdico (FamiliaReal fam){
    return fam.abdico;
}

boolean darFallecimiento(FamiliaReal fam){
    return fam.fallecimiento;
}

Fecha darAscencion(FamiliaReal fam){
    return fam.fechaAscension;
}
Fecha darAbdicacion(FamiliaReal fam){
    return fam.abdicacion;
}

void cargarMiembroInicial(FamiliaReal &fam, MiembroRealeza m){
        fam.monarcaActual = TRUE;
        fam.fueoNoMonarca = TRUE;
        fam.aspiarnteAlTrono= FALSE;
		fam.abdico=FALSE;
		fam.fallecimiento=FALSE;
		copiarFecha1y2(fam.fechaAscension,m.fechaNacimiento);
        cargarFechaNula(fam.fechaFallecimiento);
        cargarFechaNula(fam.abdicacion);
        cargarMiembro(fam.mr,m.fechaNacimiento,m.nombre,m.nombreProgenitor);}

void cargarNuevoMiembro(FamiliaReal &fam, MiembroRealeza m){
    fam.monarcaActual = FALSE;
    fam.fueoNoMonarca = FALSE;
    fam.aspiarnteAlTrono = TRUE;
    fam.abdico = FALSE;
    fam.fallecimiento = FALSE;
    cargarFechaNula(fam.fechaAscension);
    cargarFechaNula(fam.fechaFallecimiento);
    cargarFechaNula(fam.abdicacion);
    cargarMiembro(fam.mr,m.fechaNacimiento,m.nombre,m.nombreProgenitor);
    fam.mr.miembroInicialDinastia = FALSE;
}

void copFamilia(FamiliaReal &fam, FamiliaReal fam2){
    fam.monarcaActual=fam2.monarcaActual;
    fam.fueoNoMonarca=fam2.fueoNoMonarca;
    fam.aspiarnteAlTrono=fam2.aspiarnteAlTrono;
    fam.abdico=fam2.abdico;
    fam.fallecimiento=fam2.fallecimiento;
    copiarFecha1y2(fam.fechaAscension,fam2.fechaAscension);
    copiarFecha1y2(fam.fechaFallecimiento,fam2.fechaFallecimiento);
    copiarFecha1y2(fam.abdicacion,fam2.abdicacion);
    copiarMiembro(fam.mr, fam2.mr);
}

void marcarNuevoMonarca(FamiliaReal &fam,Fecha f){
    fam.monarcaActual=TRUE;
    fam.aspiarnteAlTrono=FALSE;
    fam.fechaAscension.dia=f.dia;
    fam.fechaAscension.mes=f.mes;
    fam.fechaAscension.anio=f.anio;
}



void marcarAbdicado(FamiliaReal &fam, Fecha f){
    fam.abdico=TRUE;
    fam.abdicacion.dia=f.dia;
    fam.abdicacion.mes=f.mes;
    fam.abdicacion.anio=f.anio;
}

void mostrarMiembroFamiliaReal(FamiliaReal fam){
    if (darMonarcaActual(fam)==TRUE){
        printf("\nEs monarca Actual\n");
        MostrarFecha(fam.fechaAscension);
    }
    else
        printf("\nNo es monarca Actual");
    if(darFueMonarca(fam)==TRUE){
        printf("\nFue monarca\n");
        MostrarFecha(fam.fechaAscension);
    }
    else
        printf("\nNo fue monarca");
    if(darAspirante(fam)==TRUE)
        printf("\nEs aspirante al trono");
    else
        printf("\nNo es aspirante al trono");
    if (darAbdico(fam)==TRUE){
        printf("\nAbdico");
        MostrarFecha(fam.abdicacion);
    }
    else
        printf("\nNo abdico");
    if (darFallecimiento(fam)==TRUE){
        printf("\nEsta muerto\n");
        MostrarFecha(fam.fechaFallecimiento);
    }
    else
        printf("\nEsta vivo");
    mostrarMiembro(fam.mr);
}

void mostrarMiembroFamiliaRealMonarcas(FamiliaReal fam){
    strings s;
    strcrear(s);
    darNombre(fam.mr, s);
    if(darFueMonarca(fam)==TRUE){
        print(s);
        printf(" desde el ");
        MostrarFecha(fam.fechaAscension);

        if (darFallecimiento(fam)==TRUE){
            printf(" hasta el ");
            MostrarFecha(fam.fechaFallecimiento);
            printf("(fallecio)");
        }
        if (darAbdico(fam)==TRUE){
            printf(" hasta el ");
            MostrarFecha(fam.abdicacion);
            printf("(abdico)");
        }
        if (darMonarcaActual(fam)==TRUE){
            printf(" hasta la actualidad\n");
        }
    }
    strdestruir(s);
}

void mostrarAspirantesFamilia (FamiliaReal fam){
    strings s;
    strcrear(s);
    darNombre(fam.mr, s);
    if(fam.aspiarnteAlTrono==TRUE){
        print(s);
        printf(" hijo/a de ");
        strdestruir(s);
        strcrear(s);
        darProgenitor(fam.mr,s);
        print(s);
    }
}
void mostrarhistorial (FamiliaReal fam){
    strings s;
    strcrear(s);
    darNombre(fam.mr, s);
    if(darMiembroInicio(fam.mr)==TRUE){
        print(s);
        printf(" primer monarca");
        strdestruir(s);
    }
    else{
        print(s);
        printf(" hijo/a de ");
        strdestruir(s);
        strcrear(s);
        darProgenitor(fam.mr,s);
        print(s);
        strdestruir(s);
    }
    printf("\n");
    if(darFueMonarca(fam)){
        strcrear(s);
        print(s);
        printf(" desde el ");
        MostrarFecha(fam.fechaAscension);
        strdestruir(s);
    }
    if (darFallecimiento(fam)==TRUE){
            printf(" hasta el ");
            MostrarFecha(fam.fechaFallecimiento);
            printf("(fallecio)");
    }
    if(darAbdico(fam)==TRUE){
        printf(" hasta el ");
            MostrarFecha(fam.abdicacion);
            printf("(abdico)");
    }
    if((fam.aspiarnteAlTrono)==TRUE){
        printf("\n");
        printf("aspirante al trono");
    }
    if(darMonarcaActual(fam)==TRUE){
        printf("es monarca actual");
    }

}

void bajarFamReal(FamiliaReal fam, FILE *f){
    bajarBoolean(fam.monarcaActual,f);
    bajarBoolean(fam.fueoNoMonarca,f);
    bajarBoolean(fam.aspiarnteAlTrono,f);
    bajarBoolean(fam.abdico,f);
    bajarBoolean(fam.fallecimiento,f);
    bajarFecha(fam.fechaAscension,f);
    bajarFecha(fam.fechaFallecimiento,f);
    bajarFecha(fam.abdicacion,f);
    bajarMiembro(fam.mr,f);
}

void levantarFamReal (FamiliaReal &fam, FILE *f){
    levantarBoolean(fam.monarcaActual,f);
    levantarBoolean(fam.fueoNoMonarca,f);
    levantarBoolean(fam.aspiarnteAlTrono,f);
    levantarBoolean(fam.abdico,f);
    levantarBoolean(fam.fallecimiento,f);
    levantarFecha(fam.fechaAscension,f);
    levantarFecha(fam.fechaFallecimiento,f);
    levantarFecha(fam.abdicacion,f);
    levantarMiembro(fam.mr,f);
}
