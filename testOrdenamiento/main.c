#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/OrdenamientoGenerico/Ordenamiento.h"

void mostrarVector(int* vector, int ce);

int cmpInt(const void* a, const void* b);

int main()
{
    int vector[10] = {8, 10, 2, 3, 6, 1, 4, 5, 9, 7};

    mostrarVector(vector, 10);

    puts("");

    ordenarGenSeleccion(vector, 10, sizeof(int), cmpInt);

    mostrarVector(vector, 10);

    return 0;
}

void mostrarVector(int* vector, int ce)
{
    int i;

    for(i = 0; i < ce; i++)
    {
        printf("|%2d|", *vector);
        vector++;
    }
}

int cmpInt(const void* a, const void* b)
{
    int* ai = (int*)a;
    int* bi = (int*)b;
    return *ai - *bi;
}
