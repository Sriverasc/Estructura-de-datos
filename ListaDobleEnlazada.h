#include "Nodo.h"

struct ListaDobleEnlazada {
    struct NodoD *frente;
    struct NodoD *final;
    enum Tipo tipo;
};

struct ListaDobleEnlazada* iniciarListaDobleEnlazada(enum Tipo tipo) {
    struct ListaDobleEnlazada *lista = (ListaDobleEnlazada *)malloc(sizeof(ListaDobleEnlazada));
    lista->frente = NULL;
    lista->final = NULL;
    lista->tipo = tipo;

    return lista;
}