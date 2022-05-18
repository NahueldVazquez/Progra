#include <stdio.h>
#include <stdlib.h>
#include "archivosDeTexto.h"
#define PARAM_BIN 1
#define PARAM_TXT 2
#define PARAM_FORMATO 3

int main(int argc, char* argv[])
{
    crearArchivo(argv[PARAM_BIN]);

    leerYmostrarArchivo(argv[PARAM_BIN]);

    FILE* archBin = fopen(argv[PARAM_BIN], "rb");
    FILE* archTxt = fopen(argv[PARAM_TXT], "wt");
    if(!archBin || !archTxt)
    {
        puts("ERROR");
        return ERR_ARCH;
    }

    //char* cad;
    Empleado empl;
    const char* formato;
    argv[PARAM_FORMATO][0] == 'V' ? (formato = "%d|%[^|]|%c|%d|%d|%d|%.2f"): (formato = "%08d%-200s%c%02d%02d%04d%010.2f");
    fread(&empl, sizeof(Empleado), 1, archBin);
    while(!feof(archBin))
    {
        //txtABinV(cad, &empl);
        fprintf(archTxt,
                formato,
                empl.dni, empl.apyn, empl.sexo, empl.fNac.d, empl.fNac.m,
                empl.fNac.a, empl.sueldo);
        fread(&empl, sizeof(Empleado), 1, archBin);
    }

    fclose(archBin);
    fclose(archTxt);
    return 0;
}
/*  LEER DE ARCHIVO DE TEXTO

int main(int argc, char* argv[])
{
    FILE* archBin = fopen(argv[PARM_BIN], "wb");
    FILE* archTxt = fopen(argv[PARAM_TXT], "rt");
    if(!archBin || !archTxt)
    {
        puts("ERROR");
        return ERR_ARCH;
    }

    Empleado empl;
    const char* formato;
    argv[PARAM_FORMATO][0] == 'V'? formato = "%d|%[^|]|%c|%d|%d|%d|%.2f":
               formato = "%08d%-200s%c%02d%02d%04d%010.2f";
    while(fscanf(archTxt, archTxt, formato,
        &empl.dni, &empl.apyn, &empl.sexo, &empl.fnac.d, &empl.fnac.m,
        &empl.fnac.a, &empl.sueldo) != eof)
        fwrite(&empl, sizeof(Empleado), 1, archTxt);

    fclose(archBin);
    fclose(archTxt);
    return 0;
}
        SCANF

int main(int argc, char* argv[])
{
    FILE* archBin = fopen(argv[PARM_BIN], "wb");
    FILE* archTxt = fopen(argv[PARAM_TXT], "rt");
    if(!archBin || !archTxt)
    {
        puts("ERROR");
        return ERR_ARCH;
    }

    int ret;
    Empleado empl;
    char linea[TAM_LINEA];
    fgets(linea, TAM_LINEA, archTxt);
    while(!feof(archTxt) && !errorFatal(ret))
    {
        txtABin(linea, &empl);
        if(ret == TODO_OK)
            fwrite(&empl, sizeof(Empleado), 1, archBin);
        fgets(linea, TAM_LINEA, archTxt);
    }

    fclose(archBin);
    fclose(archTxt);
    return ?;

*/

