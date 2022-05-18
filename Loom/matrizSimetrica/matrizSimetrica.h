#ifndef MATRIZSIMETRICA_H
#define MATRIZSIMETRICA_H
#include <stdio.h>
#include <stdlib.h>
#define FIL 3
#define COL 3

typedef enum
{
    FALSO, VERDADERO
}
booleano;

booleano matEsSimetrica(int mat[][COL], int fil, int col);

#endif // MATRIZSIMETRICA_H
