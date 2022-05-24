#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


enum estados {PARAMETRO_INVALIDO = -4, INDICE_INVALIDO, ESTRUCTURA_VACIA, ESTRUCTURA_NO_INICIALIZADA, FALSE, TRUE, OK=1};

// Declaramos la estructura del nodo, prox es un puntero al siguiente nodo
struct NodoE;

typedef struct NodoE * Nodo;

struct ListaEncE ;

typedef struct ListaEncE * ListaEnc;




ListaEnc crearLista();
Nodo crearNodo(int item, Nodo prox);

int liberarLista(ListaEnc lista);
int estaVacia(ListaEnc lista);

int insertarInicio(ListaEnc lista, int item);
int insertar(ListaEnc lista, int item, int pos);
int insertarFin(ListaEnc lista, int item);

int removerInicio(ListaEnc lista, int* item);
int remover(ListaEnc lista, int* item, int pos);
int removerFin(ListaEnc lista, int* item);

int obtenerElemento(ListaEnc lista, int* item, int pos);
int obtenerTamanio(ListaEnc lista, int* tam);


void imprimir(ListaEnc lista);

void ordenarLista(ListaEnc lista);


#endif // LISTA_H_INCLUDED
