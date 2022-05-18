#include "ejercicio13.h"

#include <stdio.h>
#include <stdlib.h>
#define PARAM_EMP 1
#define PARAM_EST 2

int main(int argc, char* argv[])
{
    crearArchivoEmp(argv[PARAM_EMP]);

    crearArchivoEst(argv[PARAM_EST]);

    leerYMostrarArchivoEmp(argv[PARAM_EMP]);

    puts("");

    leerYMostrarArchivoEst(argv[PARAM_EST]);

    actualizarSueldo(argv[PARAM_EMP], argv[PARAM_EST]);

    puts("");

    leerYMostrarArchivoEmp(argv[PARAM_EMP]);
    return 0;
}
