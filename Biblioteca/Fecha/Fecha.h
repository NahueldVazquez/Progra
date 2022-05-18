#ifndef FECHA_H
#define FECHA_H
#include <stdio.h>
#include <stdlib.h>

#define ANIO_BASE   1601

typedef enum
{
    FALSO, VERDADERO
}
booleano;

typedef struct
{
    int dia, mes, anio;
}
Fecha;

booleano esFechaValida(Fecha fec);
int cantDiasMes(int m, int a);
Fecha sumarDiasAFecha(const Fecha* f, int dias);
Fecha restarDiasAFecha(const Fecha* f, int dias);
int cantDiaAnio(int anio);
int difDiasFechas(const Fecha* f1, const Fecha* f2);
int diasDelAnio(const Fecha* f);



#endif // FECHA_H
