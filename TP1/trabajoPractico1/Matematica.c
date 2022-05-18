#include "Matematica.h"

double factorial(int x)
{
    double fact = 1;
    int i;
    for(i=2; i<=x; i++)
        fact*=i;

    return fact;
}

double combinatoria(int m, int n)
{
    double comb = factorial(m)/(factorial(n)*factorial(m-n));
    return comb;
}
