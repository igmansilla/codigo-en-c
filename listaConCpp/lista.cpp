#include <iostream>

#include "lista.h"

struct NodoE{
  int item;
  Nodo prox;
};



 struct ListaEncE {
  Nodo inicio;
  int tam;
};



ListaEnc crearLista() {
    ListaEnc lista = new ListaEncE;


    if (lista == NULL){
        return NULL;}


    lista->inicio = NULL;
    lista->tam = 0;


    return lista;
}




int liberarLista(ListaEnc lista) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;}

    // remove todos os elementos da lista
    while(!estaVacia(lista)){
        remover(lista, NULL, 0);}

    delete(lista);
    lista->inicio = NULL; //El tama�po ya quedo en cero por los remove tam--



    return OK;
}


int estaVacia(ListaEnc lista) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;}

    if (lista->inicio == NULL){
        return TRUE;}

    return FALSE;
}

Nodo crearNodo(int item, Nodo prox) {


	Nodo nodo = new NodoE;


	if (nodo == NULL){
        return NULL;}

	nodo->item = item;
	nodo->prox = prox;

	return nodo;


}

int insertarInicio(ListaEnc lista, int item) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;}

    Nodo nuevoNodo= crearNodo(item, lista->inicio);

    if (nuevoNodo== NULL){
        return ESTRUCTURA_NO_INICIALIZADA;}

    lista->inicio = nuevoNodo;
    lista->tam++;

    return OK;
}

int insertar(ListaEnc lista, int item, int pos) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    if (pos < 0 || pos > lista->tam)
        return INDICE_INVALIDO;

    Nodo nuevoNodo;
    if (pos == 0) {
        return insertarInicio(lista, item);
    } else {
        // prepara para inserir
        Nodo aux;
        aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }

        // adiciona o n�
        nuevoNodo= crearNodo(item, aux->prox);
        if (nuevoNodo== NULL)
            return ESTRUCTURA_NO_INICIALIZADA;
        aux->prox = nuevoNodo;
    }
    lista->tam++;
    return OK;
}

int insertarFin(ListaEnc lista, int item) {
    return insertar(lista, item, lista->tam);
}

int removerInicio(ListaEnc lista, int* item) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;
    Nodo aux = lista->inicio;
    if (item != NULL)
        *item = aux->item;
    lista->inicio = aux->prox;
    delete(aux);
    aux = NULL;
    lista->tam--;
    return OK;

}

int remover(ListaEnc lista, int* item, int pos) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    Nodo ant, atual;
    if (pos == 0) {
        return removerInicio(lista, item);
    } else {
        // prepara para remover
        ant = NULL;
        atual = lista->inicio;
        for(int i = 0; i < pos; i++) {
            ant = atual;
            atual = atual->prox;
        }

        // remove o n� atual
        ant->prox = atual->prox;
        if (item != NULL)
            *item = atual->item;
        delete(atual);
        atual = NULL;
    }
    lista->tam--;
    return OK;
}

int removerFin(ListaEnc lista, int* item) {
    return remover(lista, item, lista->tam - 1);
}

int obtenerElemento(ListaEnc lista, int* item, int pos) {

    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;

    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;


    if (item == NULL)
        return PARAMETRO_INVALIDO;

    Nodo aux;
    aux = lista->inicio;
    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    *item = aux->item;

    return OK;
}

int obtenerTamanio(ListaEnc lista, int* tam) {




    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (tam == NULL)
        return PARAMETRO_INVALIDO;

    *tam = lista->tam;




    return OK;
}

void imprimir(ListaEnc lista) {
    int cantidad;
    obtenerTamanio(lista, &cantidad);
    printf("[");
    for(int i = 0;i < cantidad; i++) {
        int el;
        obtenerElemento(lista, &el, i);
        printf(" %d ", el);
    }
    printf("]\n");
}

void ordenarLista(ListaEnc lista){

    //declaro un int donde voy  guardar el tamanio de la lista
    int tamanio;
    obtenerTamanio(lista, &tamanio);

    int auxItem;

    Nodo actual;


    for(int i = 0; i <tamanio; i++){

        actual = lista->inicio;

        for (int j = 0; j < tamanio - 1 ; j++){
            if( actual->item  >  actual->prox->item ){

                auxItem = actual->item;
                actual->item = actual->prox->item;
                actual->prox->item = auxItem;

            }
            actual = actual ->prox;
        }
    }
}
