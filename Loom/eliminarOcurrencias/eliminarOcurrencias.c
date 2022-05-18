#include "eliminarOcurrencias.h"


void eliminarOcurrencia(Vector* vec, int ocurrencia)
{
    int *copiaVec = vec->v;
    int i;
    for(i = 0; i < vec->cantElem; i++)
    {
        if(*copiaVec == ocurrencia)
        {
            moverElementos(vec, i, ocurrencia);
        }
        else
        {
           copiaVec++;
        }
    }
}

void moverElementos(Vector* vec, int posActual, int ocurrencia)
{
    int *pSig = vec;
    int i;

    pSig++;
    for(i = posActual; i < vec->cantElem; i++)
    {
        *vec = *pSig;
        vec++;
        pSig++;
    }
}

void mostrarVector(Vector* vec)
{
    int *copiaVec = vec->v;
    int i;
    for(i = 0; i < vec->cantElem; i++)
    {
        printf("|%d|", *copiaVec);
        copiaVec++;
    }
}
