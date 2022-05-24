#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#define TRUE 1
#define FALSE -1

#define OK 1
#define INDICE_INVALIDO -2
#define PILA_NO_INICIALIZADA -3

struct PilaE;

typedef struct PilaE * Pila;

struct NodoE;

typedef struct NodoE * Nodo;

//Constructores
void crearPila(int cantidad_bytes):
Nodo crearNodo(Pila pila, void *dato);

//operaciones
int pushPila(Pila pila, void *dato);
int popPila(Pila pila, void *dato_recuperado);

//utiles
int pilaVacia(Pila pila);
int tamanioPila(Pila pila);

//utiles nodos
Nodo obtenerNodo(Pila pila, int posicion);
void * obtenerDato(Pila pila, int posicion);

//destroyer
void destruirPila(Pila pila);

#endif // PILAS_H_INCLUDED
