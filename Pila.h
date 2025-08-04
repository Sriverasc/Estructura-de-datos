#include "Nodo.h"

typedef struct Pila {
    NodoS *cima;
    enum Tipo tipo;
} Pila;

Pila* iniciarPila(enum Tipo tipo) {
    Pila *pila = (Pila *)malloc(sizeof(Pila));
    if (!pila) return NULL;
    pila->cima = NULL;
    pila->tipo = tipo;

    return  pila;
}

int apilar(Pila *pila, void *valor) {
    NodoS *nodo = ( NodoS *)malloc(sizeof( NodoS));
    if (!nodo) return -1;

    enum Tipo tipo = pila->tipo;

    guardarValor(nodo, 1, pila->tipo, valor);

    nodo->siguiente = pila->cima;
    pila->cima = nodo;

    return 0;
}

void* desapilar( Pila *pila) {
    void *valor;
    NodoS *cima = pila->cima;

    if (!cima) return NULL;

    pila->cima = cima->siguiente;
    valor = cima->dato;

    free(cima);

    return valor;
}

void* mostrarTope( Pila *pila) {
    return pila->cima->dato;
}

int estaVacio( Pila *pila) {
    if (pila->cima) return 0;

    return 1;
}

int longitud( Pila *pila) {
    if (!pila->cima) return 0;

    int l = 0;

    NodoS *nodo = pila->cima;
    while(nodo) {
        l++;
        nodo = nodo->siguiente;
    }

    return l;
}

int limpiarPila( Pila *pila) {
    if (estaVacio(pila)) return 0;

    NodoS *nodo;
    while (pila->cima != NULL) {
        nodo = pila->cima;
        pila->cima = pila->cima->siguiente;

        free(nodo->dato);
        free(nodo);
    }
    return 1;
}

int liberarPila( Pila *pila) {
    if (!pila) {
        free(pila);
        return 1;
    }

    limpiarPila(pila);
    free(pila);

    return 1;
}

void imprimirPila( Pila *pila) {
    if(estaVacio(pila)) printf("Pila vacia");

    NodoS *nodo = pila->cima;

    while(nodo) {
        imprimirValor(nodo->dato, pila->tipo);
        nodo = nodo->siguiente;
    }
}