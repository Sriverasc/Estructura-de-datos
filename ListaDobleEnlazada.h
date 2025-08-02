#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"  // Asumo que aquí está la definición de NodoD, guardarValor y enum Tipo

struct ListaDobleEnlazada {
    struct NodoD* frente;
    struct NodoD* final;
    enum Tipo tipo;
};

struct ListaDobleEnlazada* iniciarListaDobleEnlazada(enum Tipo tipo) {
    struct ListaDobleEnlazada* lista = (struct ListaDobleEnlazada *)malloc(sizeof(struct ListaDobleEnlazada));
    if (!lista) return NULL;

    lista->frente = NULL;
    lista->final = NULL;
    lista->tipo = tipo;

    return lista;
}

int enlistarListaDobleInicio(struct ListaDobleEnlazada* lista, void* valor) {
    if (!lista) return -1;

    struct NodoD *nodo = (struct NodoD *)malloc(sizeof(struct NodoD));
    if (!nodo) return -2;

    guardarValor(nodo, 2, lista->tipo, valor);

    if (!lista->frente) {
        // Lista vacía: nodo apunta a sí mismo (circular)
        nodo->anterior = nodo;
        nodo->siguiente = nodo;
        lista->frente = nodo;
        lista->final = nodo;
    } else {
        nodo->siguiente = lista->frente;
        nodo->anterior = lista->final;

        lista->frente->anterior = nodo;
        lista->final->siguiente = nodo;

        lista->frente = nodo;
    }

    return 1;
}

int enlistarListaDobleFinal(struct ListaDobleEnlazada* lista, void* valor) {
    if (!lista) return -1;

    if (!lista->final) return enlistarListaDobleInicio(lista, valor);

    struct NodoD *nodo = (struct NodoD *)malloc(sizeof(struct NodoD));
    if (!nodo) return -2;

    guardarValor(nodo, 2, lista->tipo, valor);

    nodo->anterior = lista->final;
    nodo->siguiente = lista->frente;

    lista->frente->anterior = nodo;
    lista->final->siguiente = nodo;

    lista->final = nodo;

    return 1;
}

int enlistarListaDobleEn(struct ListaDobleEnlazada* lista, void* valor, int pos) {
    if (!lista) return -1;

    if (!lista->frente || pos <= 0) enlistarListaDobleInicio(lista, valor);

    struct NodoD* nodo = (struct NodoD *)malloc(sizeof(struct NodoD));
    if (!nodo) return -2;

    guardarValor(nodo, 2, lista->tipo, valor);

    struct NodoD* actual = lista->frente;
    int i = 0;

    while (i < pos - 1 && actual->siguiente != lista->frente) {
        actual = actual->siguiente;
        i++;
    }

    struct NodoD* siguiente = actual->siguiente;

    nodo->siguiente = siguiente;
    nodo->anterior = actual;

    actual->siguiente = nodo;
    siguiente->anterior = nodo;

    if (actual == lista->final) {
        lista->final = nodo;
    }

    return 1;
}


void imprimirListaDoble(struct ListaDobleEnlazada* lista) {
    struct NodoD* nodo = lista->frente;

    while(nodo->siguiente != lista->frente) {
        imprimirValor(nodo->dato, lista->tipo);
        nodo = nodo->siguiente;
    }
}