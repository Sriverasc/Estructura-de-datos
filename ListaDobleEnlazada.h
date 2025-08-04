#include "Nodo.h"

typedef struct {
    NodoD* frente;
    NodoD* final;
    enum Tipo tipo;
} ListaDobleEnlazada;

ListaDobleEnlazada* iniciarListaDobleEnlazada(enum Tipo tipo) {
    ListaDobleEnlazada* lista = (ListaDobleEnlazada *)malloc(sizeof( ListaDobleEnlazada));
    if (!lista) return NULL;
    lista->frente = NULL;
    lista->final = NULL;
    lista->tipo = tipo;

    return lista;
}

int enlistarListaDobleInicio(ListaDobleEnlazada* lista, void* valor) {
    if (!lista) return -1;
    else if (!valor) return -2;

    int res = 0;
    NodoD* nodo = (NodoD *)malloc(sizeof(NodoD));
    if (!nodo) return -3;

    res = guardarValor(nodo, 2, lista->tipo, valor);

    if (res != 1) {
        printf("Error al guardar el dato: %d\n", res);
        return -4;
    }

    if (!lista->frente) {
        nodo->anterior = nodo;
        nodo->siguiente = nodo;

        lista->frente = nodo;
        lista->final = nodo;
    } else {
        nodo->siguiente = lista->frente;
        nodo->anterior = lista->final;

        lista->final->siguiente = nodo;
        lista->frente->anterior = nodo;

        lista->frente = nodo;
    }

    return 1;
}

int enlistarListaDobleFinal(ListaDobleEnlazada* lista, void* valor) {
    if (!lista->frente) return enlistarListaDobleInicio(lista, valor);
    else if (!lista) return -1;
    else if (!valor) return -2;

    int res = 0;
    NodoD* nodo = (NodoD *)malloc(sizeof(NodoD));
    if (!nodo) return -3;

    res = guardarValor(nodo, 2, lista->tipo, valor);

    if (res != 1) {
        printf("Error al guardar el dato: %d", res);
        return -4;
    }

    nodo->siguiente = lista->frente;
    nodo->anterior = lista->final;

    lista->final->siguiente = nodo;
    lista->frente->anterior = nodo;

    lista->final = nodo;

    return 1;
}

int enlistarListaDobleEn(ListaDobleEnlazada* lista, void* valor, int posicion) {
    if (!lista->frente || posicion == 0) return enlistarListaDobleInicio(lista, valor);
    else if (!lista) return -1;
    else if (!valor) return -2;
    else if (posicion < 0) return -3;

    int res = 0, i= 0;
    NodoD* tempA;
    NodoD* tempS;
    NodoD* nodo = (NodoD *)malloc(sizeof(NodoD));
    if (!nodo) return -4;

    res = guardarValor(nodo, 2, lista->tipo, valor);
    
    if (res != 1) {
        printf("Error al guardar el dato: %d\n", res);
        return -5;
    }

    tempA = lista->frente;
    while (i < (posicion - 1) && tempA->siguiente != lista->frente) {
        i++;
        tempA = tempA->siguiente;
    }

    tempS = tempA->siguiente;

    nodo->siguiente = tempS;
    nodo->anterior = tempA;

    tempS->anterior = nodo;
    tempA->siguiente = nodo;

    if (nodo->siguiente == lista->frente) {
        lista->final = nodo;
    }

    return 1;
}

void imprimirListaDoble(ListaDobleEnlazada* lista) {
    if (!lista) printf("Error: La lista no debe ser nula");
    else if (!lista->frente) printf("La lista esta vacia");

    NodoD* nodo = lista->frente;

    do {
        imprimirValor(nodo->dato, lista->tipo);
        nodo = nodo->siguiente;
    } while (nodo != lista->frente);
}