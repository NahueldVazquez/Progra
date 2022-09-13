#include "Generico.h"

void ordenarVectorSeleccion(void* vec, const int cantElem, size_t tamElem,
                            Cmp cmp)
{
    void* ultimo = vec + (cantElem - 1) * tamElem;
    void* i;
    void* menor;

    for(i = vec; i < ultimo; i += tamElem)
    {
        menor = buscarMenor(i, ultimo, tamElem, cmp);

        if(menor != i)
            intercambiar(menor, i, tamElem);
    }
}

void* buscarMenor(void* inicio, void* fin, size_t tamElem, Cmp cmp)
{
    void* menor = inicio;
    void* j;

    for(j = inicio + 1; j <= fin; j += tamElem)
        if(cmp(j, menor) < 0)
            menor = j;

    return menor;
}

void intercambiar(void* elem1, void* elem2, size_t tamElem)
{
    char* aux[tamElem];
    memcpy(aux, elem1, tamElem);
    memcpy(elem1, elem2, tamElem);
    memcpy(elem2, aux, tamElem);
}
