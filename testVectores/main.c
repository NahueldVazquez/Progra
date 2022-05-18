#include "../Biblioteca/Vectores/Vectores.h"

int main()
{
    Vector vector;

    crearVector(&vector);

    if(insertarEnVectorAlFinal(&vector, 78))
        printf("Se inserto el valor 78 en el vector\n");
    else
        printf("No se pudo insertar el valor 78 en el vector\n");
    if(insertarEnVectorAlFinal(&vector, 100))
        printf("Se inserto el valor 100 en el vector\n");
    else
        printf("No se pudo insertar el valor 100 en el vector\n");
    if(insertarEnVectorAlFinal(&vector, 200))
        printf("Se inserto el valor 200 en el vector\n");
    else
        printf("No se pudo insertar el valor 100 en el vector\n");

    mostrarVector(&vector);

    if(eliminarDeVectorOrdPorValor(&vector, 100))
       printf("Se elimino el valor 100 del vector\n");
       else
        printf("No se elimino el valor 100 del vector\n");

    mostrarVector(&vector);

    return 0;
}
