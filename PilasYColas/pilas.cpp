#include "pilas.h"

struct PilaE{

	int bytes_pila;
	int tamanio;
	Nodo cima;

};

typedef struct PilaE * Pila;

struct NodoE{

	void *dato;
	Nodo prox;
};

typedef struct NodoE * Nodo;

//Constructores
void crearPila(int cantidad_bytes){

	Nodo nuevaPila = new Pila;

	if(nuevaPila == NULL)
    {
        return NULL;
    }

    nuevaPila -> bytes_pila = cantidad_bytes;
    nuevaPila -> tamanio = 0;
    nuevaPila->inicio = NULL;

	return nuevaPila;

}:
Nodo crearNodo(Pila pila, void *dato){

    //pido el espacio que necesito con NEW
	Nodo nuevoNodo = new NodoE;

    //si no se inicializa, deleteo el nodo
    // y retorno NULL
	if(nuevoNodo == NULL)
    {
        delete(nuevoNodo);
        return NULL;
    }

    //si la pila ya viene vácía devuelvo NULL
    if(pila == NULL)
    {
        return NULL;
    }

    /*como el dato es de tipo void
    no sé qué me va a venir por parámetro,
    entonces tengo que usa memcy,  la manera de 
    srtcpy de los char. meto el dato en el nuevo
    nodo de esta forma */
    memcpy(nuevoNodo->dato, dato, pila->bytes_pila);

    /*como esto lo uso para inicializar la lista 
    el proximo lo igualo a null. Cuando pushee
    algo a la pila y haga uso de esta función, 
    en vez de dejar el nodo en NULL, voy a hacer
    que el próximo sea el que antes era la cima */
    nuevoNodo->prox = NULL;

    return nuevoNodo;
};

//operaciones
int pushPila(Pila pila, void *dato){

    if(pila == NULL){
        return PILA_NO_INICIALIZADA; 
    }

    //para pushear un elemento a pila se crea un nuevo nodo
    // y le pone el dato que se le pasa por parámetro
    Nodo nuevoNodo = crearNodo(pila, dato);

    // si la pila no tiene elementos entonces el primer elemento 
    //de la lista es el nodo inicializado anteriormente
    if(tamanioPila(pila) === 0){
        pila->cima = nuevoNodo;
    }else{

    //si no es así...
    //guardo el dato de la cima en un nodo uxiliar 
    // para no perderlo
    Nodo auxiliar = pila->cima;
    
    //piso la cima con el nuevo nodo creado
    pila->cima = nuevoNodo;

    //y el nodo que antes era la cima
    //ahora es el siguiente de la cima
    nuevoNodo -> prox = auxiliar;
    }

    //aumento el tamanio de la pila
    pila->tamanio++;

    return OK;

};
int popPila(Pila pila, void *dato_recuperado){

    //Si la pila es nula devuelvo un int para avisar
    if(pila == NULL){
        return PILA_NO_INICIALIZADA;
    }

    //guardo la cima en un auxiliar para no perderlo
    Nodo auxiliar = pila -> cima;

    //guardo el dato del auxiliar en la direccion de memoria
    // que me pasan por parametro 
    if(dato_recuperado != NULL){
        memcpy(dato_recuperado, auxiliar->dato, pila-> bytes_pila);
    }

    //si la pila tiene un solo elemento igual este elemento a NULL
    if(tamanioPila(pila) == 1){
        
        pila -> cima = NULL;
    
    }else{

    //en cambio, si la pila tiene más de un elemnto
    //la cima la igualo al próximo nodo de la actual, 
    //es decir, el elemento que esta inmediatamente "debajo" 
        pila -> cima = auxiliar -> prox;
    }

    //ahora sí, deleteo el nodo de la cima guardado en auxiliar
    delete(auxiliar);
    auxiliar=NULL;

    pila->tamanio--;

    return OK;
};

//utiles
int pilaVacia(Pila pila){

    //si la pila es nula ¿está vacía? TRUE
    if(pila == NULL){
        return TRUE;
    }

    //si la pila es de tamanio 0 ¿está vacía? TRUE
    if(tamanioPila(pila) == 0){
        return TRUE;
    }

    return FALSE;

};
int tamanioPila(Pila pila){
    return pila->tamanio
};

//utiles nodos
Nodo obtenerNodo(Pila pila, int posicion){

     if(pila == NULL){
        return NULL;
    }

    if(posicion < 0 || posicion > tamanioPila(pila) - 1){
        return NULL;
    }

    //lo interesante de la obtención de un nodo es acá
    //voy a recorrer desde la cima hasta la posicion que me pasan

    Nodo auxiliar = pila->cima;
    for (int i = 0; i < posicion; ++i)
    {
        auxiliar = auxiliar -> prox;
    }

};
void * obtenerDato(Pila pila, int posicion){

    if(pila == NULL){
        return NULL;
    }

    if(posicion < 0 || posicion > tamanioPila(pila) -1){
        return NULL;
    }

    Nodo auxiliar = obtenerNodo(pila, posicion);

    return auxiliar->dato;

};

//destroyer
void destruirPila(Pila pila){

    if(pila == NULL){
        return PILA_NO_INICIALIZADA;
    }

    //mientras la pila no esté vacía
    // la voy popeando hasta dejarla vacía
    while(pilaVacia(pila) == FALSE){
        popPila(pila, NULL);
    }

    pila->cima=NULL;
    pila->bytes_pila = 0;
    pila->tamanio = 0;

    delete(pila);

    return OK;

};
