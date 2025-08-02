#include "Nodo.h"

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
    if (!valor) return -2;

    int res = 0;
    struct NodoD* nodo = (struct NodoD *)malloc(sizeof(struct NodoD));
    if (!nodo) return -3;

    res = guardarValor(nodo, 2, lista->tipo, valor);

    if (res != 1) return -4;

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