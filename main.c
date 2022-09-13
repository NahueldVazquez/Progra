#include "Generico.h"
#include "Producto.h"

int cmpProdStockCod(const void* p1, const void* p2);

int main()
{
    int cantElemProd;
    Producto vProd[100] =
    {
        {1, "manzana", 20, 80.56},
        {5, "pera", 15, 98.34},
        {3, "banana", 8, 76.32},
        {2, "naranja", 14, 65.76},
        {1, "durazno", 16, 78.85},
    };
    ordenarSel(vProd, cantElemProd, sizeof(Producto), cmpProdStockCod);
    //mostrarVec(vProd, cantElemProd, sizeof(Producto),mostrarProd);

    return 0;
}

int cmpProdStockCod(const void* p1, const void* p2)
{
    const Producto* prod1 = (Producto*)prod1;
    const Producto* prod2 = (Producto*)prod2;
    int comp = prod1->stock - prod2->stock;

    if(comp != 0)
        return comp;

    return strcmp(prod1->cod, prod2->cod);
}
