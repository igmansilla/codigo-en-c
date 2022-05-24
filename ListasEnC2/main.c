#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{
    ListaPuntero lista = crearLista();

    agregarInicio(lista, 56);
    agregarInicio(lista, 56);
    agregarInicio(lista, 56);
    agregarInicio(lista, 56);

    imprimirLista(lista);

    float itemARemover;
    int eliminado = removerInicio(lista,&itemARemover);
    printf("%d\n", eliminado);
    imprimirLista(lista);

    return 0;
}
