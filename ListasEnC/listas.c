#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

struct NodoEstructura{

    int item;
    Nodo prox; //puntero al proximo nodo

};

struct ListaEstructura{

    int tamanio;
    Nodo inicio;
};

Nodo crearNodo(int item, Nodo proximo)
{

    Nodo nodo= malloc(sizeof(struct NodoEstructura));

    nodo -> item = item;

    nodo -> prox = proximo;

    return nodo;
}

Lista crearLista()
{
    Lista lista = malloc(sizeof(struct ListaEstructura));

    lista -> inicio = NULL;

    lista -> tamanio = 0;

    return lista;
}

int insertarInicio(Lista l, int item)
{
    Nodo nuevoNo = crearNodo(item, l->inicio);

        l-> inicio = nuevoNo;
        l-> tamanio++;

        return 1;
}

int removerInicio(Lista l, int * item)
{
    if(estaVacia(l)){
        return -1;
    }else{

        Nodo aux = l -> inicio;

        *item = aux -> item;

        free(aux);

        aux = NULL;

        l -> tamanio--;

        return 1;
    }
}

int estaVacia(Lista l)
{
    if(l -> inicio == NULL){

        return TRUE;
    }else{

        return FALSE;
    }

}

int obtenerElemento(Lista l, int* item, int pos)
{

    if(estaVacia(l)){
        return -1;
    }

    if(pos < 0 || pos > l->tamanio){
        *item = -1;
        return -1;
    }

    if(item == NULL){

        return -1;
    }


    Nodo aux;

    aux = l -> inicio;

    for(int i; i<pos; i++){
        aux = aux -> prox;
    }

    *item = aux -> item;

    return 1;
}

int obtenerTamanio(Lista l, int * tamanio)
{
    * tamanio = l->tamanio;

    return 1;
}

void mostrarLista(Lista l)
{
    int cantidad;

    obtenerTamanio(l, &cantidad);

    printf("[");
    for(int i; i<cantidad; i++){

        int cadaElemento;
        obtenerElemento(l, &cadaElemento,i);
        printf(" %d ", cadaElemento);
    }
    printf("] \n");

}
