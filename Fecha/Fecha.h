#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSO, VERDADERO
}
booleano

typedef struct
{
    int dia, mes, anio;
} tFecha;

booleano esFechaValida(tFecha fec);
int cantDiasMes(int m, int a);
booleano esBisiesto(int a);

#endif // FECHA_H_INCLUDED
