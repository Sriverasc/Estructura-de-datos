#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NodoS {
    void *dato;
    struct NodoS *siguiente;
};

struct NodoD {
    void *dato;
    struct NodoD *siguiente;
    struct NodoD *anterior;
};

enum Tipo {
    Int,
    Char,
    Float,
    Double
};

int validarTipoDato(enum Tipo tipo) {
    switch (tipo)
    {
    case Int:
    case Char:
    case Float:
    case Double:
        return 1;
    default:
        return 0;
    }
}

void guardarValor(struct NodoS *nodo, enum Tipo tipo, void *dato) {
    switch(tipo)
    {
    case Int:
        nodo->dato = malloc(sizeof(int));
        memcpy(nodo->dato, dato, sizeof(int));
        break;
    case Char:
        nodo->dato = malloc(sizeof(char));
        memcpy(nodo->dato, dato, sizeof(char));
        break;
    case Float:
        nodo->dato = malloc(sizeof(float));
        memcpy(nodo->dato, dato, sizeof(float));
    case Double:
        nodo->dato = malloc(sizeof(double));
        memcpy(nodo->dato, dato, sizeof(double));
    }
}

void imprimirValor(void *dato, enum Tipo tipo) {
    switch (tipo)
    {
    case Int:
        printf("%d ", *(int *)dato);
        break;
    case Char:
        printf("%c ", *(char *)dato);
        break;
    case Float:
        printf("%f ", *(float *)dato);
        break;
    case Double:
        printf("%lf ", *(double *)dato);
        break;
    default:
        break;
    }
}