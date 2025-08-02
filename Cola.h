#include "Nodo.h"

struct Cola {
    struct Nodo *final;
    struct Nodo *frente;
    enum Tipo tipo;
};

struct Cola* iniciarCola(enum Tipo tipo) {
    struct Cola *cola = (struct  Cola *)malloc(sizeof(struct Cola));
    cola->frente = NULL;
    cola->final = NULL;
    cola->tipo = tipo;

    return cola;
}

int encolar(struct Cola *cola, void* valor) {
    struct Nodo *nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    struct Nodo *temp;
    if (!nodo) return -1;

    enum Tipo tipo = cola->tipo;

    switch(tipo)
    {
    case Int:
        nodo->dato = malloc(sizeof(int));
        memcpy(nodo->dato, valor, sizeof(int));
        break;
    case Char:
        nodo->dato = malloc(sizeof(char));
        memcpy(nodo->dato, valor, sizeof(char));
        break;
    case Float:
        nodo->dato = malloc(sizeof(float));
        memcpy(nodo->dato, valor, sizeof(float));
        break;
    case Double:
        nodo->dato = malloc(sizeof(double));
        memcpy(nodo->dato, valor, sizeof(double));
        break;
    default:
        return -2; 
        break;
    }

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

    struct Nodo *nodo = cola->frente;
    void *valor = nodo->dato;

    cola->frente = nodo->siguiente;

    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    free(nodo);

    return valor; 
}

void* frente(struct Cola *cola) {
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

    struct Nodo *nodo = cola->final;
    do {
        l++;
        nodo = nodo->siguiente;
    } while(nodo);

    return l;
}

int limpiarCola(struct Cola *cola) {
    if (estaVacia(cola)) return 0;

    struct Nodo *nodo;
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

void mostrar(struct Cola *cola) {
    if(estaVacia(cola)) printf("La cola esta vacia\n");

    struct Nodo *nodo = cola->frente;

    switch (cola->tipo)
    {
    case Int:
        do {
            printf("%d ", *(int *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
        break;
    case Char:
        do {
            printf("%c ", *(char *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
        break;
    case Float:
        do {
            printf("%f ", *(float *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
        break;
    case Double:
        do {
            printf("%lf ", *(double *)nodo->dato);
            nodo = nodo->siguiente;
        } while(nodo);
        break;
    }
}