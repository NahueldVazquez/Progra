#include "vectoresDisjuntos.h"

int main()
{
    int vec1[TAM] = {1, 5, 7, 6, 8, 4, 2};
    int vec2[TAM] = {3, 9};
    mostrarVector(vec1);
    printf("\n");
    mostrarVector(vec2);
    printf("\n");
    if(vectoresDisjuntos(vec2, vec1) == VERDADERO)
        puts("Los vectores son disjuntos");
    else
        puts("Los vectores no son disjuntos");
    return 0;
}
