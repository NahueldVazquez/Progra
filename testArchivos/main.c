#include <stdio.h>
#include <stdlib.h>

#define TODO_OK  0
#define ERR_ARCH 1

int generarArchivo(char* nombreArch);
int mostrarEmpleados(char* nombreArch);

typedef struct
{
    char nYa[10];
    int dni;
    float sueldo;
}
Empleado;

int main(int argc, char* argv[])
{
    generarArchivo(argv[1]);
    mostrarEmpleados(argv[1]);

    FILE* empleadosA = fopen(argv[1],"r+b");

    if(!empleadosA)
    {
        puts("Error absoluto.");
        return ERR_ARCH;
    }

    Empleado empl;

    fread(&empl, sizeof(Empleado), 1, empleadosA);

    while(!feof(empleadosA))
    {
        empl.sueldo += empl.sueldo*(atof(argv[2])/100);

        fseek(empleadosA, -(long)sizeof(Empleado), SEEK_CUR);
        fwrite(&empl, sizeof(Empleado), 1, empleadosA);
        fseek(empleadosA, 0L, SEEK_CUR);
        fread(&empl, sizeof(Empleado), 1, empleadosA);
    }

    fclose(empleadosA);

    printf("\nSueldos actualziados: \n");
    mostrarEmpleados(argv[1]);

    return 0;
}

int generarArchivo(char* nombreArch)
{
    FILE* empleadoA = fopen(nombreArch, "wb");

    if(!empleadoA)
    {
        puts("Error absoluto.");
        return ERR_ARCH;
    }

    Empleado empl[2] = {
                        {"Jonathan", 548451, 151515},
                        {"Nahuel", 48418, 100000},
                        };
    fwrite(empl, sizeof(Empleado), 2, empleadoA);
    fclose(empleadoA);

    return TODO_OK;
}

int mostrarEmpleados(char* nombreArch)
{
    FILE* empleadoA = fopen(nombreArch, "rb");

    if(!empleadoA)
    {
        puts("Error absoluto.");
        return ERR_ARCH;
    }

    Empleado empl;

    fread(&empl, sizeof(Empleado), 1, empleadoA);

    while(!feof(empleadoA))
    {
        printf("%s %d %f\n", empl.nYa, empl.dni, empl.sueldo);
        fread(&empl, sizeof(Empleado), 1, empleadoA);
    }

    return TODO_OK;
}
