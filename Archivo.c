#include "Archivo.h"

int crearArchivo(const char* nombreArchivo)
{
    Estudiante vecEst[5] =
    {
        {35756270, "Nahuel", 7.25},
        {36472798, "Lucas", 8.41},
        {36845217, "Marcos", 7.10},
        {37219863, "Matias", 8.65},
        {37642178, "Tomas", 9.21},
    };

    FILE* fp = fopen(nombreArchivo, "wb");

    if(!fp)
    {
        puts("Error de archivo");
        return ERR_ARCH;
    }

    fwrite(vecEst, sizeof(Estudiante), 5, fp);

    fclose(fp);

    return TODO_BIEN;
}

int crearArchivoTxt(const char* nombreArchivoOrigen, const char* nombreArchivoDestino, char tipoFormato)
{
    Estudiante est;
    char* formato = tipoFormato == 'v'? "%d\t%s\t%.2f\n" : "%-8d%-10s%.2f\n";
    FILE* fpBin = fopen(nombreArchivoOrigen, "rb");
    FILE* fpTxt = fopen(nombreArchivoDestino, "wt");

    if(!fpBin || !fpTxt)
    {
        puts("Error de apertura de archivo");
        return ERR_ARCH;
    }

    fread(&est, sizeof(Estudiante), 1, fpBin);
    while(!feof(fpBin))
    {
        fprintf(fpTxt, formato, &est.dni, est.nombre, &est.promedio);
        fread(&est, sizeof(Estudiante), 1, fpBin);
    }

    fclose(fpBin);
    fclose(fpTxt);

    return TODO_BIEN;
}

int convertirTxtABin(const char* nombreArchivoOrigen, const char* nombreArchivoDestino, char tipoFormato)
{
    Estudiante est;
    char* formato = tipoFormato == 'v'? "%d\t%s\t%.2f\n" : "%-8d%-10s%.2f\n";
    FILE* fpTxt = fopen(nombreArchivoOrigen, "rt");
    FILE* fpBin = fopen(nombreArchivoDestino, "wb");

    if(!fpBin || !fpTxt)
    {
        puts("Error de apertura de archivo");
        return ERR_ARCH;
    }

    while(fscanf(fpTxt, formato, &est.dni, est.nombre, &est.promedio) != EOF)
    {
        fwrite(&est, sizeof(Estudiante), 1, fpBin);
    }

    fclose(fpBin);
    fclose(fpTxt);

    return TODO_BIEN;
}

int leerYMostrarArchivo(const char* nombreArchivo)
{
    Estudiante est;
    FILE* fp = fopen(nombreArchivo, "rb");

    if(!fp)
    {
        puts("Error de apertura de archivo");
        return ERR_ARCH;
    }


    fread(&est, sizeof(Estudiante), 1, fp);
    while(!feof(fp))
    {
        mostrarEstudiante(&est);
        fread(&est, sizeof(Estudiante), 1, fp);
    }

    fclose(fp);

    return TODO_BIEN;
}

void mostrarEstudiante(Estudiante* est)
{
    printf("%d\t%s\t%.2f\n", est->dni, est->nombre, est->promedio);
}
