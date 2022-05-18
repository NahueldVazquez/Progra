#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERR_PUNTO 1
#define ERR_ARCHIVO 1

#define PARAM_PRODUCTOS 1
#define PARAM_MOVIMIENTOS 2
#define MAX_NOMBRE_ARCH 101
#define MAX_DESCR 101

typedef struct
{
    int codigo;
    char descr[MAX_DESCR];
    int cantidad;
    float precio;
}
Producto;

int generarProductos(const char* nomArchivoProds);
int generarMovimientos(const char* nomArchivoMovs);
int mostrarProductos(const char* nomArchivo);
int mostrarMovimientos(const char* nomArchivo);
int actualizarProductos(const char* nomProds, const char* nomMovs);
int cambiarExtension(const char* nombreOrig, char* nombreCambiado, const char* extension);

int main(int argc, char* argv[])
{
    generarProductos(argv[PARAM_PRODUCTOS]);
    generarMovimientos(argv[PARAM_MOVIMIENTOS]);

    puts("Productos");
    mostrarProductos(argv[PARAM_PRODUCTOS]);

    puts("\nMovimientos");
    mostrarProductos(argv[PARAM_MOVIMIENTOS]);

    actualizarProductos(argv[PARAM_PRODUCTOS], argv[PARAM_MOVIMIENTOS]);

    puts("\nProductos actualizados");
    mostrarProductos(argv[PARAM_PRODUCTOS]);

    return 0;
}


int generarProductos(const char* nomArchivoProds)
{
    FILE* archProds = fopen(nomArchivoProds, "wb");

    if(archProds == NULL)
    {
        puts("Error al abrir el archivo");
        return ERR_ARCHIVO;
    }


    Producto prod;
    prod.codigo = 1;
    strcpy(prod.descr, "Leche");
    prod.cantidad = 10;
    prod.precio = 2.5;
    fwrite(&prod, sizeof(Producto), 1, archProds);

    prod.codigo = 2;
    strcpy(prod.descr, "Pan");
    prod.cantidad = 20;
    prod.precio = 1.5;
    fwrite(&prod, sizeof(Producto), 1, archProds);

    prod.codigo = 3;
    strcpy(prod.descr, "Arroz");
    prod.cantidad = 30;
    prod.precio = 3.5;
    fwrite(&prod, sizeof(Producto), 1, archProds);

    prod.codigo = 4;
    strcpy(prod.descr, "Aceite");
    prod.cantidad = 10;
    prod.precio = 2.5;
    fwrite(&prod, sizeof(Producto), 1, archProds);

    prod.codigo = 5;
    strcpy(prod.descr, "Sal");
    prod.cantidad = 50;
    prod.precio = 5.5;
    fwrite(&prod, sizeof(Producto), 1, archProds);

    fclose(archProds);

    return TODO_OK;
}
int generarMovimientos(const char* nomArchivoMovs)
{
    FILE* archMov = fopen(nomArchivoMovs, "wb");

    if(archMov == NULL)
    {
        puts("Error al abrir el archivo");
        return ERR_ARCHIVO;
    }

    Producto mov;
    mov.codigo = 1;
    strcpy(mov.descr, "Leche");
    mov.cantidad = 10;
    mov.precio = 2.5;
    fwrite(&mov, sizeof(Producto), 1, archMov);

    fclose(archMov);

    return TODO_OK;
}

int mostrarProductos(const char* nomArchivo)
{
    FILE* archProds = fopen(nomArchivo, "rb");

    if(archProds == NULL)
    {
        puts("Error al abrir el archivo");
        return ERR_ARCHIVO;
    }

    Producto prod;
    fread(&prod, sizeof(Producto), 1, archProds);
    while(!feof(archProds))
    {
        printf("%d %s %d %.2f\n", prod.codigo, prod.descr, prod.cantidad, prod.precio);
        fread(&prod, sizeof(Producto), 1, archProds);
    }

    fclose(archProds);

    return TODO_OK;
}

int actualizarProductos(const char* nomProds, const char* nomMovs)
{
    FILE* archProds = fopen(nomProds, "rb");
    FILE* archMovs = fopen(nomMovs, "rb");

    if(archProds == NULL || archMovs == NULL)
    {
        puts("Error al abrir los archivos");
        return ERR_ARCHIVO;
    }

    char nombreTmp[MAX_NOMBRE_ARCH];
    cambiarExtension(nomProds, nombreTmp, "tmp");
    FILE* archProdsTemp = fopen(nombreTmp, "wb");

    if(archProdsTemp == NULL)
    {
        puts("Error al abrir el archivo temporal");
        return ERR_ARCHIVO;
    }

    Producto prod, prodNue, mov;
    int comp;

    fread(&prod, sizeof(Producto), 1, archProds);
    fread(&mov, sizeof(Producto), 1, archMovs);
    while(!feof(archProds) && !feof(archMovs))
    {
        comp = prod.codigo - mov.codigo;

        if(comp == 0) // Actualizar stock producto existente
        {
            prod.cantidad += mov.cantidad;
            fread(&mov, sizeof(Producto), 1, archMovs);
        }
        else if(comp < 0) // Producto sin movimientos
        {
            fwrite(&prod, sizeof(Producto), 1, archProdsTemp);
            fread(&prod, sizeof(Producto), 1, archProds);
        }
        else // Producto nuevo
        {
            prodNue = mov;

            fread(&mov, sizeof(Producto), 1, archMovs);
            while(!feof(archMovs) && prodNue.codigo == mov.codigo)
            {
                prodNue.cantidad += mov.cantidad;
                fread(&mov, sizeof(Producto), 1, archMovs);
            }

            fwrite(&prodNue, sizeof(Producto), 1, archProdsTemp);
        }
    }

    while(!feof(archProds))
    {
        fwrite(&prod, sizeof(Producto), 1, archProdsTemp);
        fread(&prod, sizeof(Producto), 1, archProds);
    }

    while(!feof(archMovs))
    {
        prodNue = mov;

        fread(&mov, sizeof(Producto), 1, archMovs);
        while(!feof(archMovs) && prodNue.codigo == mov.codigo)
        {
            prodNue.cantidad += mov.cantidad;
            fread(&mov, sizeof(Producto), 1, archMovs);
        }
        fwrite(&prodNue, sizeof(Producto), 1, archProdsTemp);
    }

    fclose(archProds);
    fclose(archMovs);
    fclose(archProdsTemp);

    remove(nomProds);
    rename(nombreTmp, nomProds);

    return TODO_OK;
}

int cambiarExtension(const char* nombreOrig, char* nombreCambiado, const char* extension)
{
    strcpy(nombreCambiado, nombreOrig);
    char* punto = strrchr(nombreCambiado, '.');

    if(!punto)
        return ERR_PUNTO;

    strcpy(punto + 1, extension);

    return TODO_OK;
}
