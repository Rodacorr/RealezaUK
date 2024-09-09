#include "MiembroRealeza.h"

void darNombre(MiembroRealeza miem, strings &s){
    strcop(s, miem.nombre);
}
Fecha darNacimiento(MiembroRealeza miem){
    return miem.fechaNacimiento;
}
boolean darMiembroInicio(MiembroRealeza miem){
    return miem.miembroInicialDinastia;
}

void darProgenitor (MiembroRealeza miem, strings &s){
    strcop(s,miem.nombreProgenitor);
}

void cargarMiembro(MiembroRealeza &m,Fecha f,strings nom, strings pa){

    strcrear(m.nombre);
    strcop(m.nombre,nom);

    m.fechaNacimiento.dia=f.dia;
    m.fechaNacimiento.mes=f.mes;
    m.fechaNacimiento.anio=f.anio;

    strcrear(m.nombreProgenitor);
    strcop(m.nombreProgenitor,pa);

}
void copiarMiembro(MiembroRealeza &m, MiembroRealeza m2){
     strcrear(m.nombre);
    strcop(m.nombre,m2.nombre);
    copiarFecha1y2(m2.fechaNacimiento,m.fechaNacimiento);
    strcrear(m.nombreProgenitor);
    strcop(m.nombreProgenitor,m2.nombreProgenitor);
}
void mostrarMiembro(MiembroRealeza m){
    printf("\nNombre: ");
    print(m.nombre);
    printf("\nFecha de nacimiento: ");
    MostrarFecha(m.fechaNacimiento);
    esInicialONo(m);
    if(!m.miembroInicialDinastia){
        printf("\nNombre progenitor: ");
        print(m.nombreProgenitor);
    }

}

void esInicialONo(MiembroRealeza m){
    if (m.miembroInicialDinastia==TRUE)
        printf("\nEs el miembro inicial");
    else
        printf("\nNo es el miembro inicial");
}

void bajarMiembro(MiembroRealeza m, FILE *f){
    bajarString(m.nombre, f);
    bajarFecha(m.fechaNacimiento,f);
    bajarBoolean(m.miembroInicialDinastia,f);
    bajarString(m.nombreProgenitor,f);
}

void levantarMiembro(MiembroRealeza &m, FILE *f){
    strings s;
    strcrear(s);
    levantarString(s,f);
    strcrear(m.nombre);
    strcop(m.nombre,s);
    levantarFecha(m.fechaNacimiento, f);
    levantarBoolean(m.miembroInicialDinastia, f);
    strdestruir(s);
    strcrear(s);
    strcrear(m.nombreProgenitor);
    levantarString(s,f);
    strcop(m.nombreProgenitor,s);
    strdestruir(s);
}
