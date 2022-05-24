#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

enum estados {FALSE , TRUE};

struct NodoEstructura;

typedef struct NodoEstructura * Nodo;

struct ListaEstructura;

typedef struct ListaEstructura * Lista;

//constructores

Nodo crearNodo(int item, Nodo proximo);

Lista crearLista();

//getters y setters

int insertarInicio(Lista l, int item);

int removerInicio(Lista l, int * item);

//utiles

int estaVacia(Lista l);

int obtenerElemento(Lista l, int * item, int pos);

int obtenerTamanio(Lista l, int * tamanio);

//mostrar - imprimir

void mostrarLista(Lista l);


#endif // LISTAS_H_INCLUDED
