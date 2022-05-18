#ifndef CADENA_H
#define CADENA_H

#define esLetra(X) ((X)>='a' && (X)<='z') || ((X)>='A' && (X)<='Z') ? 1:0

typedef enum
{
    FALSO, VERDADERO
}
booleano;

typedef struct
{
    char* ini;
    char* fin;
}
Palabra;

typedef struct
{
    char* cur;
    char* inicad;
    booleano finSec;
}
secPal;

void crearSecPal(const secPal* sl, const char* cOrig);
booleano finSecPal(const secPal* sl);
void escribirPal(const secPal* se, const Palabra* pal);
void escribirCaracter(const secPal* se, char caracter);
void reposicionarSecPal(const secPal* se, int mov);
void rebobinarSecPal(const secPal* se);
void formatearPMayRMin(Palabra* pal);
void normalizar(const char* cOrig, char* cDest);
void leerPalabra (secPal* sl, Palabra* pal);


#endif // CADENA_H
