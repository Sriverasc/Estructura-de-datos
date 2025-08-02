#include "Nodo.h"

struct ListaDobleEnlazada {
    struct NodoD* frente;
    struct NodoD* final;
    enum Tipo tipo;
};

struct ListaDobleEnlazada* iniciarListaDobleEnlazada(enum Tipo tipo) {
    struct ListaDobleEnlazada* lista = (ListaDobleEnlazada *)malloc(sizeof(ListaDobleEnlazada));
    lista->frente = NULL;
    lista->final = NULL;
    lista->tipo = tipo;

    return lista;
}

int enlistarListaDobleInicio(struct ListaDobleEnlazada* lista, void* valor) {
    if (!lista) return -1;
    
    struct NodoD *nodo = (NodoD *)malloc(sizeof(NodoD *));

    guardarValor(nodo, 2, lista->tipo, valor);
    nodo->siguiente = lista->frente;
    nodo->anterior = lista->final;
    lista->frente = nodo;
    lista->final->siguiente = nodo;

    return 1;
}

int enlistarListaDobleFinal(struct ListaDobleEnlazada* lista, void* valor) {
    if (!lista) return -1;

    struct NodoD *nodo = (NodoD *)malloc(sizeof(NodoD *));

    guardarValor(nodo, 2, lista->tipo, valor);
    nodo->anterior = lista->final;
    nodo->siguiente = lista->frente;
    lista->final->siguiente = nodo;
    lista->final = nodo;

    return 1;
}