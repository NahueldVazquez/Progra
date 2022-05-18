#include "vectoresDisjuntos.h"

void mostrarVector(int* vec)
{
    while(*vec)
    {
        printf("|%d|", *vec);
        vec++;
    }
}

booleano vectoresDisjuntos(int* vec1, int* vec2)
{
    while(*vec1)
    {
        if(compararVectores(*vec1, vec2) == FALSO)
            return FALSO;
        vec1++;
    }
    return VERDADERO;
}

booleano compararVectores(int numero, int* vec2)
{
    while(*vec2)
    {
        if(numero == *vec2)
            return FALSO;
        vec2++;
    }
    return VERDADERO;
}
