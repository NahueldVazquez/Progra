#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H
#include <stddef.h>

typedef int (*Cmp)(const void*, const void*);

void ordenarGenBurbujeo(void* vector, int ce, size_t tamElem, Cmp cmp);
void ordenarGenSeleccion(void* vector, int ce, size_t tamElem, Cmp cmp);
void ordenarGenInsercion(void* vector, int ce, size_t tamElem, Cmp cmp);

#endif // ORDENAMIENTO_H
