#include "Matematica.h"

int main()
{
    int x = 0;
    double fact = factorial(x);
    printf("El factorial de %d es %.0lf\n", x, fact);
    int m = 9, n = 5;
    double comb = combinatoria(m, n);
    printf("La combinatoria de %d y %d es %.0lf\n", m, n, comb);
    return 0;
}
