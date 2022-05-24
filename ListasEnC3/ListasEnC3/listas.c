#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


struct ListaEstructura{
    int tamanio;
    Nodo inicio;
};
struct NodoEstructura{
    int item;
    Nodo proximo;
};

Lista crearLista()
{
    Lista lista = malloc(sizeof(struct ListaEstructura));

    lista -> inicio = NULL;
    lista -> tamanio = 0;

    return lista;
}

Nodo crearNodo(int item, Nodo proximo)
{
    Nodo nodo = malloc(sizeof(struct NodoEstructura));

    nodo -> item = item;
    nodo -> proximo = proximo;

    return nodo;
}

int insertarInicio(Lista l, int item)
{
    //se crea el nodo que va  apuntar al inicio de la lista
    Nodo no = crearNodo(l->inicio, item);

    //ahora el inicio de la lista es igual al nuevo nodo
    //el nodo "viejo" nunca se elimina, sigue apuntando a null; aaah lo que contiene SIEMPRE la lista es el inicio de la lista;
    l ->inicio = no;
    l ->tamanio++;

    return 1;
}

int removerInicio(Lista l, int* item)
{
//    se declara un nodo uxiliar que se inicializa en el momento;

    Nodo nodoAuxiliar = l->inicio;

    *item = nodoAuxiliar->item;

    free(nodoAuxiliar);
    nodoAuxiliar = NULL;

    return 1;
}

int estaVacia(Lista l)
{
    if(l -> tamanio == NULL){
        return TRUE;
    }

    return FALSE;
}

int obtenerItem(Lista l, int* item, int posicion)
{
    if(estaVacia(l->tamanio)){return -1;}
    if(posicion<0||posicion>=l->tamanio){
            *item = -1;
            return -1;};
    if(item == NULL){return -1;}

    Nodo  auxiliar;
    auxiliar = l->inicio;

    for(int i = 0; i < posicion; i++) {
        auxiliar = auxiliar->proximo;
    }


    *item = auxiliar -> item;

    return 1;


}

int obtenerTamanio(Lista l)
{

}

void mostrarLista(Lista l)
{

}
