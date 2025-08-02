#include "Nodo.h"

struct ListaDobleEnlazada {
    struct NodoD* frente;
    struct NodoD* final;
    enum Tipo tipo;
};

struct ListaDobleEnlazada* iniciarListaDobleEnlazada(enum Tipo tipo) {
    struct ListaDobleEnlazada* lista = (struct ListaDobleEnlazada *)malloc(sizeof(struct ListaDobleEnlazada));
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
    if (!lista->final) {
        enlistarListaDobleInicio(lista, valor);
        return 1;
    }

    struct NodoD *nodo = (struct NodoD *)malloc(sizeof(struct NodoD *));
    if(!nodo) return -2;

    guardarValor(nodo, 2, lista->tipo, valor);

    nodo->anterior = lista->final;
    nodo->siguiente = lista->frente;

    lista->frente->anterior = nodo;
    lista->final->siguiente = nodo;

    lista->final = nodo;

    return 1;
}