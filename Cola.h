#include "Nodo.h"

struct Cola {
    struct NodoS *final;
    struct NodoS *frente;
    enum Tipo tipo;
};

struct Cola* iniciarCola(enum Tipo tipo) {
    struct Cola *cola = (struct Cola *)malloc(sizeof(struct Cola));
    if (!cola) return NULL;
    cola->frente = NULL;
    cola->final = NULL;
    cola->tipo = tipo;

    return cola;
}

int encolar(struct Cola *cola, void* valor) {
    struct NodoS *nodo = (struct NodoS *)malloc(sizeof(struct NodoS));
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

void* desencolar(struct Cola *cola) {
    if (!cola || cola->frente == NULL) 
        return NULL;

    struct NodoS *nodo = cola->frente;
    void *valor = nodo->dato;

    cola->frente = nodo->siguiente;

    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    free(nodo);

    return valor; 
}

void* mostrarFrente(struct Cola *cola) {
    if (!cola) return NULL;

    return cola->frente->dato;
}

int estaVacia(struct Cola *cola) {
    if (!cola->final) return 1;

    return 0;
}

int longitud(struct Cola *cola) {
    if (!cola->final) return 0;

    int l = 0;

    struct NodoS *nodo = cola->final;
    while(nodo) {
        l++;
        nodo = nodo->siguiente;
    }

    return l;
}

int limpiarCola(struct Cola *cola) {
    if (estaVacia(cola)) return 0;

    struct NodoS *nodo;
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

int liberarCola(struct Cola *cola) {
    if (estaVacia(cola)) {
        free(cola);
        return 1;
    }

    limpiarCola(cola);
    free(cola);

    return 1;
}

void imprimirCola(struct Cola *cola) {
    if(estaVacia(cola)) printf("La cola esta vacia\n");

    struct NodoS *nodo = cola->frente;

    while(nodo) {
        imprimirValor(nodo->dato, cola->tipo);
        nodo = nodo->siguiente;
    }
}