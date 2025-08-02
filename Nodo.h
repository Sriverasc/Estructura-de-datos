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

void guardarValor(void *nodo, int tipoNodo, enum Tipo tipo, void *dato) {
    if (tipoNodo == 1) {
        struct NodoS *ns = (struct NodoS *)nodo;
    } else if (tipoNodo == 2) {
        struct NodoD *nd = (struct NodoD *)nodo;
    }
    
    switch(tipo)
    {
    case Int:
        ((struct NodoS *)nodo)->dato = malloc(sizeof(int));
        memcpy(((struct NodoS *)nodo)->dato, dato, sizeof(int));
        break;
    case Char:
        ((struct NodoS *)nodo)->dato = malloc(sizeof(char));
        memcpy(((struct NodoS *)nodo)->dato, dato, sizeof(char));
        break;
    case Float:
        ((struct NodoS *)nodo)->dato = malloc(sizeof(float));
        memcpy(((struct NodoS *)nodo)->dato, dato, sizeof(float));
        break;
    case Double:
        ((struct NodoS *)nodo)->dato = malloc(sizeof(double));
        memcpy(((struct NodoS *)nodo)->dato, dato, sizeof(double));
        break;
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