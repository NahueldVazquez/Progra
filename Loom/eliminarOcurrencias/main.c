
// ASUMO QUE EL VECTOR TIENE ELEMENTOS HASTA LA APARICIÓN DE UN 0 O SI ES IGUAL AL TAMAÑO DEL VECTOR

#include "eliminarOcurrencias.h"

int main()
{
    Vector vec = {{4, 1, 2, 7, 7, 9, 7, 3, 4, 7}, 10};
    mostrarVector(&vec);
    printf("\n");
    int ocurrencia = 7;
    eliminarOcurrencia(&vec, ocurrencia);
    mostrarVector(&vec);
    return 0;
}
