#include "../Biblioteca/Fecha/Fecha.h"
#include <ctype.h>

char continuar(char* mensaje);

int main()
{
    /*Fecha fec;

    do
    {
      printf("Ingrese una fecha (dd/mm/aaaa): ");
      scanf("%d/%d/%d", &fec.dia, &fec.mes, &fec.anio);

    if(esFechaValida(fec))
        printf("La fecha ingresada es valida\n");
    else
        printf("La fecha ingresada no es valida\n");
    }
    while(continuar("Desea ingresar otra fecha? (s/n)"));

    return 0;
}

char continuar(char* mensaje)
{
    char respuesta;

    puts(mensaje);
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta = tolower(respuesta);
    while(respuesta != 's' && respuesta != 'n')
    {
        puts("Respuesta invalida.");
        puts("Debe ingresar s o n.");
        puts(mensaje);
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = tolower(respuesta);
    }

    return respuesta == 's';
    */
    Fecha f1 = {13, 4, 2022};
    int dias = 20;
}
