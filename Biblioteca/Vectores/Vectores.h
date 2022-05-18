#ifndef VECTORES_H
#define VECTORES_H
#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD_VECTOR 5
#define TODO_OK         0
#define SIN_MEM         1
#define DUPLICADO       2
#define NO_ENCONTRADO   -1

typedef enum
{
    FALSO, VERDADERO
}
booleano;


typedef struct
{
    int vec[CAPACIDAD_VECTOR];
    int ce;
}
Vector;



void crearVector(Vector* vector);
booleano insertarEnVectorAlFinal(Vector* vector, int valor);
int insertarEnVectorEnOrdenConDup(Vector* vector, int valor);
int buscarEnVectorOrdenado(const Vector* vector, int valor);
booleano eliminarDeVectorOrdPorValor(Vector* vector, int valor);
void mostrarVector(const Vector* vector);


#endif // VECTORES_H
