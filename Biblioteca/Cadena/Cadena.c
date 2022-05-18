#include "Cadena.h"

void normalizar(const char* cOrig, char* cDest)
{
    Palabra pal;
    secPal sl, se;
    crearSecPal(&sl, cOrig);
    crearSecPal(&se, cDest);
    leerPalabra(&sl, &pal);
    while(!finSecPal(&sl))
    {
        escribirPal(&se, &pal);
        escribirCaracter(&se, ' ');
        leerPalabra(&sl, &pal);
    }
    reposicionarSecPal(&se, -1);
    escribirCaracter(&se, '\0');
    rebobinarSecPal(&se);
    leerPalabra(&se, &pal);
    while(!finSecPal(&se))
    {
        formatearPMayRMin(&pal);
        leerPalabra(&se, &pal);
    }
}

void leerPalabra (secPal* sl, Palabra* pal)
{
    while(*sl->cur != '\0' && !esLetra(*sl->cur))
        sl->cur++;
    if(*sl->cur == '\0')
    {
        sl->finSec = VERDADERO;
        return;
    }
    pal->ini = sl->cur;

    while(*sl->cur != '\0' && esLetra(*sl->cur))
        sl->cur++;
    pal->fin = sl->cur-1;
}
