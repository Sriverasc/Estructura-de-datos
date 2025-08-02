#include "Nodo.h"

struct Pila {
    struct NodoS *cima;
    enum Tipo tipo;
};

struct Pila* iniciarPila(enum Tipo tipo) {
    struct Pila *pila = (struct Pila *)malloc(sizeof(struct Pila));
    pila->cima = NULL;
    pila->tipo = tipo;

    return  pila;
}

int apilar(struct Pila *pila, void *valor) {
    struct NodoS *nodo = (struct NodoS *)malloc(sizeof(struct NodoS));
    if (!nodo) return -1;

    enum Tipo tipo = pila->tipo;

    guardarValor(nodo, 1, pila->tipo, valor);

    nodo->siguiente = pila->cima;
    pila->cima = nodo;

    return 0;
}

void* desapilar(struct Pila *pila) {
    void *valor;
    struct NodoS *cima = pila->cima;

    if (!cima) return NULL;

    pila->cima = cima->siguiente;
    valor = cima->dato;

    free(cima);

    return valor;
}

void* mostrarTope(struct Pila *pila) {
    return pila->cima->dato;
}

int estaVacio(struct Pila *pila) {
    if (pila->cima) return 0;

    return 1;
}

int longitud(struct Pila *pila) {
    if (!pila->cima) return 0;

    int l = 0;

    struct NodoS *nodo = pila->cima;
    while(nodo) {
        l++;
        nodo = nodo->siguiente;
    }

    return l;
}

int limpiarPila(struct Pila *pila) {
    if (estaVacio(pila)) return 0;

    struct NodoS *nodo;
    while (pila->cima != NULL) {
        nodo = pila->cima;
        pila->cima = pila->cima->siguiente;

        free(nodo->dato);
        free(nodo);
    }
    return 1;
}

int liberarPila(struct Pila *pila) {
    if (!pila) {
        free(pila);
        return 1;
    }

    limpiarPila(pila);
    free(pila);

    return 1;
}

void imprimirPila(struct Pila *pila) {
    if(estaVacio(pila)) printf("Pila vacia");

    struct NodoS *nodo = pila->cima;

    while(nodo) {
        imprimirValor(nodo->dato, pila->tipo);
        nodo = nodo->siguiente;
    }
}