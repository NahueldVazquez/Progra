#ifndef VECTORESDISJUNTOS_H
#define VECTORESDISJUNTOS_H
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef enum
{
    FALSO, VERDADERO
}
booleano;

void mostrarVector(int* vec);
booleano vectoresDisjuntos(int* vec1, int* vec2);
booleano compararVectores(int numero, int* vec2);

#endif // VECTORESDISJUNTOS_H
