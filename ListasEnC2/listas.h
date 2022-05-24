#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

struct NodoEstructura;

typedef struct NodoEstructura * NodoPuntero;
//un NodoPuntero es una variable que almacena la direccion de memoria de un Nodo estructura.

struct ListaEstructura;

typedef struct ListaEstructura * ListaPuntero;
//una ListaPuntero es una variable que almacena la direccion de memoria para una ListaPuntero


//constructores
ListaPuntero crearLista();

NodoPuntero crearNodo(float item, NodoPuntero prox);

//operaciones sobre listas
//retona 1 s logra agregar el item
int agregarInicio(ListaPuntero l, float item);

int  removerInicio(ListaPuntero l, float * item);

//utiles
int estaVacia(ListaPuntero);

int buscarItem(ListaPuntero l, float * punteroParaAlmacenarItem, int posicionDelItem);

int obtenerTamanio(ListaPuntero l);

//imprimir
void imprimirLista(ListaPuntero l);


#endif // LISTAS_H_INCLUDED
