#include "Vectores.h"

void crearVector(Vector* vector)
{
    vector->ce = 0;
}

booleano insertarEnVectorAlFinal(Vector* vector, int valor)
{
    if(vector->ce == CAPACIDAD_VECTOR)
        return FALSO;

    vector->vec[vector->ce] = valor;
    vector->ce++;

    return VERDADERO;
}

int insertarEnVectorEnOrdenConDup(Vector* vector, int valor)
{
    if(vector->ce == CAPACIDAD_VECTOR)
        return SIN_MEM;

    int i = vector->ce -1;

    while(i >= 0 && valor < vector->vec[i])
    {
       vector->vec[i + 1] = vector->vec[i];
       i--;
    }

    vector->vec[i + 1] = valor;
    vector->ce++;

    return TODO_OK;
}

int buscarEnVectorOrdenado(const Vector* vector, int valor)
{
    int i = 0;

    while(i < vector->ce && valor > vector->vec[i])
        i++;

    if(i == vector->ce || valor < vector->vec[i])
        return NO_ENCONTRADO;

    return i;
}

booleano eliminarDeVectorOrdPorValor(Vector* vector, int valor)
{
    int posElim = buscarEnVectorOrdenado(vector, valor);

    if(posElim == NO_ENCONTRADO)
        return FALSO;

    int i;
    for(i = posElim; i <= vector->ce - 2; i++)
        vector->vec[i] = vector->vec[i + 1];

    vector->ce--;

    return VERDADERO;

}

void mostrarVector(const Vector* vector)
{
    int i;

    for(i = 0; i < vector->ce; i++)
        printf("|%d|", vector->vec[i]);

    printf("\n");
}

int eliminarOcurrencia(const Vector* vector, int valor)
{
    int i;
    for(i=0; i<= vector->ce, i++)
    {
        if(*vector->*vec == valor)
        {
            moverElementos(vector->vec[i]);
        }
    }
}

void moverElementos(Vector* vector)
{
    Vector* psig = vector;
    psig++;
    int i;
    for(i=psig; i <= psig; i++)
    {
        *vec = *psig;
    }
}
