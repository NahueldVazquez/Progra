#include "ejercicio13.h"

int crearArchivoEmp(char* nombreArchivo)
{
    Empleado vecEmpleado[] =
    {
        {10468712, "Acosta", "Manuel", 148700.87},
        {1684521, "Benitez", "Agustin", 165200.88},
        {35756270, "Mansilla", "Jorge", 184300.42},
        {11811288, "Vazquez", "Emilio", 178000.48},
        {11811289, "Vazquez", "Emilio", 150000.48},
    };

    FILE* fp = fopen(nombreArchivo, "wb");

    if(fp)
    {
        fwrite(vecEmpleado, sizeof(vecEmpleado), 1, fp);
        fclose(fp);
        return TODO_OK;
    }

    return ERR_ARCH;

}

int crearArchivoEst(char* nombreArchivo)
{
    Estudiante vecEstudiante[] =
    {
        {10468712, "Acosta", "Manuel", 7.21},
        {1684521, "Benitez", "Agustin", 6.99},
        {35756270, "Mansilla", "Jorge", 8.14},
        {11811288, "Vazquez", "Emilio", 7.01},
        {11811289, "Vazquez", "Emilio", 5.84},
    };

    FILE* fp = fopen(nombreArchivo, "wb");

    if(fp)
    {
        fwrite(vecEstudiante, sizeof(vecEstudiante), 1, fp);
        fclose(fp);
        return TODO_OK;
    }

    return ERR_ARCH;

}

void mostrarEmpleados(const Empleado* emp)
{
    if(!emp)
    {
        printf("DNI      APELLIDO   NOMBRE     SUELDO\n");
        printf("======== ========== ========== ========\n");
        return;
    }

    printf("%08ld %-10s %-10s %9.2f\n",
               emp->dni,
               emp->apellido,
               emp->nombre,
               emp->sueldo);
}

void mostrarEstudiantes(const Estudiante* est)
{
    if(!est)
    {
        printf("DNI      APELLIDO   NOMBRE     PROMEDIO\n");
        printf("======== ========== ========== =======\n");
        return;
    }

    printf("%08ld %-10s %-10s %.2f\n",
               est->dni,
               est->apellido,
               est->nombre,
               est->promedio);
}

int leerYMostrarArchivoEmp(char* nombreArchivo)
{
    Empleado emp;
    FILE* fp = fopen(nombreArchivo, "rb");

    if(!fp)
    {
        puts("Error de archivo");
        return ERR_ARCH;
    }

    mostrarEmpleados(NULL);

    fread(&emp, sizeof(Empleado), 1, fp);
    while(!feof(fp))
    {
        mostrarEmpleados(&emp);
        fread(&emp, sizeof(Empleado), 1, fp);
    }

    fclose(fp);

    return TODO_OK;
}

int leerYMostrarArchivoEst(char* nombreArchivo)
{
    Estudiante est;
    FILE* fp = fopen(nombreArchivo, "rb");

    if(!fp)
    {
        puts("Error de archivo");
        return ERR_ARCH;
    }

    mostrarEstudiantes(NULL);

    fread(&est, sizeof(Estudiante), 1, fp);
    while(!feof(fp))
    {
        mostrarEstudiantes(&est);
        fread(&est, sizeof(Estudiante), 1, fp);
    }

    fclose(fp);

    return TODO_OK;
}

int actualizarSueldo(char* nombreArchivoEmp, char* nombreArchivoEst)
{
    FILE* fpEmp = fopen(nombreArchivoEmp, "r+b");
    if(!fpEmp)
    {
        puts("Error de archivo");
        return ERR_ARCH;
    }
    FILE* fpEst = fopen(nombreArchivoEst, "rb");
    if(!fpEst)
    {
        puts("Error de archivo");
        return ERR_ARCH;
    }

    Empleado emp;
    Estudiante est;

    fread(&est, sizeof(Estudiante), 1, fpEst);
    fread(&emp, sizeof(Empleado), 1, fpEmp);
    while(!feof(fpEst) && !feof(fpEmp))
    {
        if(est.promedio >= 7)
        {
            emp.sueldo *= 1.728;
            fseek(fpEmp, -1L * sizeof(Empleado), SEEK_CUR);
            fwrite(&emp, sizeof(Empleado), 1, fpEmp);
            fseek(fpEmp, 0L, SEEK_CUR);
        }
        fread(&est, sizeof(Estudiante), 1, fpEst);
        fread(&emp, sizeof(Empleado), 1, fpEmp);
    }

    fclose(fpEmp);
    fclose(fpEst);

    return TODO_OK;
}
