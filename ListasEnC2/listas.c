#include <stdio.h> //standard input-output header
#include <stdlib.h>
#include "listas.h"

struct ListaEstructura{

    float tamanio;
    NodoPuntero inicio;

};

struct NodoEstructura{

    float item;
    NodoPuntero prox;

};

ListaPuntero crearLista()
{
    ListaPuntero l = malloc(sizeof(struct ListaEstructura)); // voy a retornar la posicion de memoria de una ListaEstructura

    l -> tamanio = 0;
    l -> inicio = NULL;

    return l;

}

NodoPuntero crearNodo(float item, NodoPuntero prox)
{
    NodoPuntero nodo = malloc(sizeof(struct NodoEstructura));

    nodo -> item = item;
    nodo -> prox = prox;

    return nodo;
}

int agregarInicio(ListaPuntero l, float item)
{
   NodoPuntero nodo = crearNodo(item, l -> inicio);

   l -> inicio = nodo;
   l -> tamanio ++;

   return 1;

}

int removerInicio(ListaPuntero l, float * item)
{   /*
    if(estaVacia(l)){

        return -1;
    }

    NodoPuntero auxiliar = l -> inicio; //este es el inicio que se va a devolver
    //lo guardo en una auxiliar NodoPuntero. esto va a tener un valor un puntero al prox;

    *item = auxiliar -> item; //el valor del item lo guardo en un puntero al tipo del valor del item

    //hago mierda el inicio ¿y lo seteo a NULL?
    free(auxiliar);
    auxiliar = NULL;

    //disminuyo el tamanio
    l ->tamanio--;*/

    if ( estaVacia(l)){

        return -1;
    }

    NodoPuntero aux = l->inicio;

    ///if <---------------
    //parematro pase por referencia
    *item =  aux->item;

    free(aux);
    aux = NULL;


    l->tamanio--;

    return 1;

}

int estaVacia(ListaPuntero l)
{

    if(l->tamanio == 0){

        return 1;
    }

    return 0;

}

int buscarItem(ListaPuntero l, float* punteroParaAlmacenarItem, int posicionDelItem)
{
    if(estaVacia(l)){
        return -1;
    }
    if(posicionDelItem<0 || posicionDelItem>= l->tamanio){
        return -1;
    }

    NodoPuntero auxiliar = l -> inicio;

    //este for va desde el inicio de la lista hasta donde indique la posicion del item
    for(int i = 0; i<posicionDelItem; i++){

            //voy "saltando" de puntero en puntero y termino donde indique la posicion del item
            auxiliar = auxiliar -> prox;
    }
    *punteroParaAlmacenarItem = auxiliar ->item;

    return 1;
}

int obtenerTamanio(ListaPuntero l)
{
    return l -> tamanio;
}

void imprimirLista(ListaPuntero l)
{

    int tamanioLista = obtenerTamanio(l);

    printf("[");
    for(int i = 0; i<tamanioLista; i++){
            float cadaElemento;
            //con ampersand hago referencia a la posicion de memoria de la varible "cadaElemento" y voy guardando en esa posicion el item
            buscarItem(l,&cadaElemento, i);

            printf("%.0f,", cadaElemento);
        }
    printf("]\n");
}





