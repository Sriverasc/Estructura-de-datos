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

    switch (tipo)
    {
    case Int: // Int
        nodo->dato = malloc(sizeof(int));
        memcpy(nodo->dato, valor, sizeof(int));
        break;
    case Char: // Char
        nodo->dato = malloc(sizeof(char));
        memcpy(nodo->dato, valor, sizeof(char));
        break;
    case Float: // Float
        nodo->dato = malloc(sizeof(float));
        memcpy(nodo->dato, valor, sizeof(float));
        break;
    case Double: // Double
        nodo->dato = malloc(sizeof(double));
        memcpy(nodo->dato, valor, sizeof(double));
        break;
    default:
        return -2;
        break;
    }

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

void* tope(struct Pila *pila) {
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
    do {
        l++;
        nodo = nodo->siguiente;
    } while(nodo);

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

int destruir(struct Pila *pila) {
    if (!pila) {
        free(pila);
        return 1;
    }

    limpiarPila(pila);
    free(pila);

    return 1;
}

void mostrar(struct Pila *pila) {
    if(estaVacio(pila)) printf("Pila vacia");

    struct NodoS *nodo = pila->cima;

    switch (pila->tipo)
    {
    case Int:
        do {
            printf("%d ", *(int *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
        break;
    case Char:
        
        do {
            printf("%c ", *(char *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
        break;
    case Float:
        
        do {
            printf("%f ", *(float *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
    case Double:
        do {
            printf("%lf ", *(double *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
        break;
    }
}