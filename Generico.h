#ifndef GENERICO_H
#define GENERICO_H
#include <stdio.h>
#include <stdlib.h>

typedef int(*Cmp)(const void*, const void*);

void ordenarVectorSeleccion(void* vec, const int cantElem, size_t tamElem,
                            Cmp cmp);
void* buscarMenor(void* inicio, void* fin, size_t tamElem, Cmp cmp);
void intercambiar(void* elem1, void* elem2, size_t tamElem);

#endif // GENERICO_H
