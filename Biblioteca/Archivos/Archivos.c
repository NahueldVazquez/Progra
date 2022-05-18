#include "Archivos.h"

int generarArchivo(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "wb");

    if(!fp)
    {
        puts("Error abriendo archivo");
        return ERR_ARCH;
    }
    return TODO_OK;
}
