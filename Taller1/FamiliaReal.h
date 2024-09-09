#ifndef FAMILIAREAL_H_INCLUDED
#define FAMILIAREAL_H_INCLUDED
#include "MiembroRealeza.h"


typedef struct{
		boolean monarcaActual;  // SI == TRUE, NO == FALSE.
		boolean fueoNoMonarca;  // SI == TRUE, NO == FALSE.
		boolean aspiarnteAlTrono;  // SI == TRUE, NO == FALSE.
		boolean abdico;  // SI == TRUE, NO == FALSE.
		boolean fallecimiento;  // SI == TRUE, NO == FALSE.
		Fecha fechaAscension;
		Fecha fechaFallecimiento;
		Fecha abdicacion; // 0 / 0 / 0 DEFAULT
        MiembroRealeza mr;

}FamiliaReal;

boolean darMonarcaActual(FamiliaReal fam);

boolean darFueMonarca (FamiliaReal fam);

boolean darAspirante(FamiliaReal fam);

boolean darAbdico (FamiliaReal fam);

boolean darFallecimiento(FamiliaReal fam);

Fecha darAscencion(FamiliaReal fam);

Fecha darAbdicacion(FamiliaReal fam);

MiembroRealeza darMiembroRealeza(FamiliaReal fam);//este no se si esta bien

void cargarMiembroInicial(FamiliaReal &fam, MiembroRealeza m); //carga miembro inicial

void cargarNuevoMiembro(FamiliaReal &fam, MiembroRealeza m);// carga resto de miembros

void copFamilia(FamiliaReal &fam, FamiliaReal fam2);
void marcarNuevoMonarca(FamiliaReal &fam,Fecha f);//marca nuevo monarca y fecha

void marcarAbdicado(FamiliaReal &fam, Fecha f); //marca abdicado y fecha

void mostrarMiembroFamiliaReal(FamiliaReal fam);
void mostrarMiembroFamiliaRealMonarcas(FamiliaReal fam);
void mostrarAspirantesFamilia (FamiliaReal fam);
void mostrarhistorial (FamiliaReal fam);


void bajarFamReal(FamiliaReal fam, FILE *f); //baja familia real al archivo

void levantarFamReal(FamiliaReal &fam, FILE *f); //levanta archivo famreal
#endif // FAMILIAREAL_H_INCLUDED
