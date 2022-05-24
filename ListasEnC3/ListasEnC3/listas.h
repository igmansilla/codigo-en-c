#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

enum {FALSE, TRUE};

struct ListaEstructura;

typedef struct ListaEstructura * Lista;

struct NodoEstructura;

typedef struct NodoEstructura * Nodo;

//constructores

Lista crearLista();
Nodo crearNodo(int item, Nodo proximo);

//operaciones
int insertarInicio(Lista l, int item);
int removerInicio(Lista l, int * item);

//utiles
int estaVacia(Lista l);
int obtenerItem(Lista l, int * item, int posicion);
int obtenerTamanio(Lista l);


//mostrar
void mostrarLista(Lista l);


#endif // LISTAS_H_INCLUDED
