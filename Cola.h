#include "Nodo.h"

typedef struct Cola {
    NodoS *final;
    NodoS *frente;
    enum Tipo tipo;
} Cola;

Cola* iniciarCola(enum Tipo tipo) {
    Cola *cola = (Cola *)malloc(sizeof(Cola));
    if (!cola) return NULL;
    cola->frente = NULL;
    cola->final = NULL;
    cola->tipo = tipo;

    return cola;
}

int encolar(Cola *cola, void* valor) {
    NodoS *nodo = (NodoS *)malloc(sizeof(NodoS));
    if (!nodo) return -1;

    enum Tipo tipo = cola->tipo;

    guardarValor(nodo, 1, cola->tipo, valor);

    nodo->siguiente = NULL;

    if (!cola->frente) {
        cola->frente = nodo;
        cola->final = nodo;
    }
    else {
        cola->final->siguiente = nodo;
        cola->final = nodo;
    }

    return 0;
}

void* desencolar(Cola *cola) {
    if (!cola || cola->frente == NULL) 
        return NULL;

    NodoS *nodo = cola->frente;
    void *valor = nodo->dato;

    cola->frente = nodo->siguiente;

    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    free(nodo);

    return valor; 
}

void* mostrarFrente(Cola *cola) {
    if (!cola) return NULL;

    return cola->frente->dato;
}

int estaVacia(Cola *cola) {
    if (!cola->final) return 1;

    return 0;
}

int longitud(Cola *cola) {
    if (!cola->final) return 0;

    int l = 0;

    NodoS *nodo = cola->final;
    while(nodo) {
        l++;
        nodo = nodo->siguiente;
    }

    return l;
}

int limpiarCola(Cola *cola) {
    if (estaVacia(cola)) return 0;

    NodoS *nodo;
    while(nodo->siguiente != NULL) {
        nodo = cola->frente;
        cola->frente = nodo->siguiente;
        
        free(nodo->dato);
        free(nodo);
    }

    cola->frente = NULL;
    cola->final = NULL;

    return 1;
}

int liberarCola(Cola *cola) {
    if (estaVacia(cola)) {
        free(cola);
        return 1;
    }

    limpiarCola(cola);
    free(cola);

    return 1;
}

void imprimirCola(Cola *cola) {
    if(estaVacia(cola)) printf("La cola esta vacia\n");

    NodoS *nodo = cola->frente;

    while(nodo) {
        imprimirValor(nodo->dato, cola->tipo);
        nodo = nodo->siguiente;
    }
}