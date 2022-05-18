#include "archivosDeTexto.h"

int txtABinV(char* linea, Empleado* empl)
{
    char* car = strchr(linea, '\n');
    if(!car)
        return ERR_LINEA_LARGA;

    *car = '\0';
    car = strrchr(linea, '|');
    //TODO: Validar campo
    scanf(car + 1, "%f", &empl->sueldo);
    *car = '\0';
    car = strrchr(linea, '|');
    sscanf(car + 1, "%d/%d/%d", &empl->fNac.d, &empl->fNac.m, &empl->fNac.a);
    *car = '\0';
    car = strrchr(linea, '|');
    empl->sexo = *(car + 1);
    *car = '\0';
    car = strrchr(linea, '|');
    strncpy(empl->apyn, car + 1, TAM_APYN);
    empl->apyn[TAM_APYN - 1] = '\0';
    *car = '\0';
    sscanf(linea, "%ld", &empl->dni);
    return TODO_OK;
}

int txtABinF(char* linea, Empleado* empl)
{
    char* car = strchr(linea, '\n');
    if(!car)
        return ERR_LINEA_LARGA;

    *car = '\0';
    car -= 10;
    car = strrchr(linea, '|');
    //TODO: Validar campo
    scanf(car, "%f", &empl->sueldo);
    *car = '\0';
    car -= 8;
    car = strrchr(linea, '|');
    sscanf(car, "%2d%2d%4d", &empl->fNac.d, &empl->fNac.m, &empl->fNac.a);
    *car = '\0';
    car --;
    car = strrchr(linea, '|');
    empl->sexo = *(car);
    *car = '\0';
    car -= TAM_APYN;
    car = strrchr(linea, '|');
    strncpy(empl->apyn, car, TAM_APYN);
    empl->apyn[TAM_APYN - 1] = '\0';
    *car = '\0';
    car -= 8;
    sscanf(linea, "%ld", &empl->dni);
    return TODO_OK;
}

int crearArchivo(char *nombreArchivo)
{
    Empleado vectorEmpleados[] =
    {
        {32534623, "Gonzalez Fernando", 'M', {3,3,2015}, 42700.56},
        {34823465, "Gomez Carlos", 'M', {5,4,2014}, 40300.41},
        {34912034, "Perez Juan", 'M', {15,5,2012}, 45400.78},
        {35756270, "Vazquez Nahuel", 'M', {2,6,2013}, 42700.56},
        {36235935, "Gutierrez Juana Carla", 'F', {25,9,2011}, 45700.56}
    };

    int cantElem = 5;
    Empleado* registro = vectorEmpleados;
    Empleado* finVec = vectorEmpleados + cantElem - 1;
    FILE *fp = fopen(nombreArchivo,"wb");
    if(!fp)
    {
        puts("Error de archivo");
        return ERR_ARCH;
    }

    while(registro <= finVec)
    {
        fwrite(registro, sizeof(Empleado), 1, fp);
        registro++;
    }

    fclose(fp);

    return TODO_OK;
}

int leerYmostrarArchivo(char *nombreArchivo)
{
    Empleado emp;
    FILE *fp = fopen(nombreArchivo, "rb");
    if(!fp)
    {
        puts("Error de archivo");
        return ERR_ARCH;
    }
    mostrarEmpleado(NULL);
    fread(&emp, sizeof(Empleado), 1, fp);
    while(!feof(fp))
    {
        mostrarEmpleado(&emp);
        fread(&emp, sizeof(Empleado), 1, fp);
    }
    fclose(fp);
    return TODO_OK;
}

void mostrarEmpleado(const Empleado *emp)
{
    if(!emp)
    {
        printf("DNI   NOMBRE Y APELLIDO   SEXO  FEC. NAC    SUELDO   \n"
               "------ ------------------  ---  ----------  --------\n");
    }
    else
    {
        printf("%08ld  %-*.*s   %c    %02d/%02d/%04d  %9.2f\n",
               emp->dni,
               (int)sizeof(emp->apyn)-1,
               (int)sizeof(emp->apyn)-1,
               emp->apyn,
               emp->sexo,
               emp->fNac.d,
               emp->fNac.m,
               emp->fNac.a,
               emp->sueldo);
    }
}
