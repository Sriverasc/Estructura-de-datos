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

int guardarEnNodoS(struct NodoS* temp, enum Tipo tipo, void *dato) {
    switch (tipo)
    {
    case Int:
        temp->dato = malloc(sizeof(int));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(int));
        break;
    case Char:
        temp->dato = malloc(sizeof(char));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(char));
        break;
    case Float: 
        temp->dato = malloc(sizeof(float));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(float));
    case Double:
        temp->dato = malloc(sizeof(double));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(double));
        break;
    default:
        return -2;
        break;
    }

    return 1;
}

int guardarEnNodoD(struct NodoD* temp, enum Tipo tipo, void *dato) {
    switch (tipo)
    {
    case Int:
        temp->dato = malloc(sizeof(int));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(int));
        break;
    case Char:
        temp->dato = malloc(sizeof(char));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(char));
        break;
    case Float: 
        temp->dato = malloc(sizeof(float));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(float));
    case Double:
        temp->dato = malloc(sizeof(double));
        if (!temp->dato) return -1;
        memcpy(temp->dato, dato, sizeof(double));
        break;
    default:
        return -2;
        break;
    }

    return 1;
}

int guardarValor(void *nodo, int tipoNodo, enum Tipo tipo, void *dato) {
    if (tipoNodo == 1) {
        struct NodoS *ns = (struct NodoS *)nodo;
        return guardarEnNodoS(ns, tipo, dato);
    } else if (tipoNodo == 2) {
        struct NodoD *nd = (struct NodoD *)nodo;
        return guardarEnNodoD(nd, tipo, dato);
    } else {
        return -3;    
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