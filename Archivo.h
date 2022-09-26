#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdio.h>
#include <stdlib.h>
#define ERR_ARCH 1
#define TODO_BIEN 0

typedef struct
{
    int dni;
    char nombre[10];
    float promedio;
}
Estudiante;

int crearArchivo(const char* nombreArchivo);
int crearArchivoTxt(const char* nombreArchivoOrigen, const char* nombreArchivoDestino, char tipoFormato);
int convertirTxtABin(const char* nombreArchivoOrigen, const char* nombreArchivoDestino, char tipoFormato);
int leerYMostrarArchivo(const char* nombreArchivo);
void mostrarEstudiante(Estudiante* est);

#endif // ARCHIVO_H
