#ifndef EJERCICIO13_H
#define EJERCICIO13_H
#include <stdio.h>
#include <stdlib.h>
#define TODO_OK 0
#define ERR_ARCH 1

typedef struct
{
    long dni;
    char* apellido;
    char* nombre;
    double sueldo;
}
Empleado;

typedef struct
{
    long dni;
    char* apellido;
    char* nombre;
    float promedio;
}
Estudiante;

int crearArchivoEmp(char* nombreArchivo);
int crearArchivoEst(char* nombreArchivo);
void mostrarEstudiantes(const Estudiante* est);
void mostrarEmpleados(const Empleado* emp);
int leerYMostrarArchivoEmp(char* nombreArchivo);
int leerYMostrarArchivoEst(char* nombreArchivo);
int actualizarSueldo(char* nombreArchivoEmp, char* nombreArchivoEst);

#endif // EJERCICIO13_H
