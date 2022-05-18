#include "matrizSimetrica.h"

booleano matEsSimetrica(int mat[][COL], int fil, int col)
{
    int i, j;
    for(i = 0; i < fil - 1; i++)
    {
        for(j = i + 1; j <= col - 1; j++)
        if(mat[i][j] != mat[j][i])
            return FALSO;
    }
    return VERDADERO;
}
