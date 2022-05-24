#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{
    printf("------ CLASE LISTAS ------- \n");

    //creamos la lista
    Lista lista = crearLista();

    //vemos que onda si está vacía. efectivamente
    printf("\nESTA VACIA:  %d\n\n", estaVacia(lista) );
    mostrarLista(lista);

    insertarInicio(lista, 51);
    insertarInicio(lista, 1);
    insertarInicio(lista, -63);
    insertarInicio(lista, 22);
    mostrarLista(lista);

     printf("\nESTA VACIA:  %d\n\n", estaVacia(lista) );

    int dato;
    removerInicio(lista, &dato );

    printf("\nEsto es lo que saque: %d", dato);




}
