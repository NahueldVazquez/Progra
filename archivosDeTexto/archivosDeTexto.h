#ifndef ARCHIVOSDETEXTO_H_INCLUDED
#define ARCHIVOSDETEXTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_APYN 200
#define TODO_OK 0
#define ERR_ARCH 1
#define ERR_LINEA_LARGA 3

typedef struct
{
    int d, m, a;
}
Fecha;

typedef struct
{
    long dni;
    char* apyn;
    int sexo;
    Fecha fNac;
    float sueldo;
}
Empleado;

int crearArchivo(char *nombreArchivo);
void mostrarEmpleado(const Empleado *emp);
int leerYmostrarArchivo(char *nombreArchivo);
int txtABinV(char* linea, Empleado* empl);


#endif // ARCHIVOSDETEXTO_H_INCLUDED
