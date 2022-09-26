#include "Archivo.h"

int main()
{
    crearArchivo("Estudiantes.dat");
    crearArchivoTxt("Estudiantes.dat", "Estudiantes.txt", 'f');
    convertirTxtABin("Estudiantes.txt", "Estudiantes.dat", 'f');
    leerYMostrarArchivo("Estudiantes.dat");
    return 0;
}
