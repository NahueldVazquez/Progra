#include "matrizSimetrica.h"

int main()
{
    int mat[][COL] =
    {
        {1, 3, 5},
        {3, 3, 7},
        {5, 7, 2}

    };

    if(matEsSimetrica(mat, FIL, COL) == VERDADERO)
        puts("La matriz es simetrica");
    else
        puts("La matriz no es simetrica");

    return 0;
}
