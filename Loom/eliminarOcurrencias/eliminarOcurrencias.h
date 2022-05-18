#ifndef ELIMINAROCURRENCIAS_H
#define ELIMINAROCURRENCIAS_H
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct
{
    int v[TAM];
    int cantElem;
}
Vector;

void eliminarOcurrencia(Vector* vec, int ocurrencia);
void mostrarVector(Vector* vec);
void moverElementos(Vector* vec, int posActual, int ocurrencia);

#endif // ELIMINAROCURRENCIAS_H
