#include "Fecha.h"
#define esBisiesto(X)  (((X) % 4 == 0 && (X) % 100 != 0) || (X) % 400 == 0)

booleano esFechaValida(Fecha fec)
{
    if(fec.anio >= ANIO_BASE)
        if(fec.mes >= 1 && fec.mes <= 12)
            if(fec.dia >=1 && fec.dia <= cantDiasMes(fec.mes, fec.anio))
                return VERDADERO;
    return FALSO;

}

int cantDiasMes(int m, int a)
{
    const static int cdm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(m==2 && esBisiesto(a))
        return 29;

    return cdm[m];
}

Fecha sumarDiasAFecha(const Fecha* f, int dias)
{
    Fecha fechaCopia = *f;
    int cdm;

    fechaCopia.dia += dias;

    while(fechaCopia.dia > (cdm = cantDiasMes(fechaCopia.mes, fechaCopia.anio)))
    {
        fechaCopia.dia -= cdm;
//        fechaCopia.mes++;

//        if(fechaCopia.mes == 13)
//        {
//            fechaCopia.mes = 1;
//            fechaCopia.anio++;
//        }
        fechaCopia.anio += fechaCopia.mes/12;
        fechaCopia.mes = fechaCopia.mes % 12 +1;
    }

    return fechaCopia;
}

Fecha restarDiasAFecha(const Fecha* f, int dias)
{
    Fecha fechaCopia = *f;
    int cdm;

    fechaCopia.dia -= dias;

    while(fechaCopia.dia < 1)
    {
        cdm = cantDiasMes(fechaCopia.mes, fechaCopia.anio);
        fechaCopia.dia += cdm;
//        fechaCopia.mes++;

//        if(fechaCopia.mes == 13)
//        {
//            fechaCopia.mes = 1;
//            fechaCopia.anio++;
//        }
        fechaCopia.anio += fechaCopia.mes/12;
        fechaCopia.mes = fechaCopia.mes % 12 +1;
    }

    return fechaCopia;
}

int diasDelAnio(const Fecha* f)
{
    int acum = 0;

    acum += f->dia;

    int cantDiasAcumXMes[][13] =
    {
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
    };

    return acum + cantDiasAcumXMes[esBisiesto(f->anio)][f->mes];
}

int cantDiaAnio(int anio)
{
    return 365 + esBisiesto(anio);

}

int difDiasFechas(const Fecha* f1, const Fecha* f2)
{
    int dif = cantDiaAnio(f2->anio) - cantDiaAnio(f1->anio);
    int anioAct = f1->anio;

    while(anioAct < f2->anio)
    {
        dif += cantDiaAnio(anioAct);
        anioAct++;
    }

    return dif;
}
