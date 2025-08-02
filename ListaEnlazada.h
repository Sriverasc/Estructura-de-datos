#include "Nodo.h"

struct ListaEnlazada {
    struct NodoS *frente;
    struct NodoS *final;
    enum Tipo tipo;
};

struct ListaEnlazada* iniciarLista(enum Tipo tipo) {
    struct ListaEnlazada *lista = (struct ListaEnlazada *)malloc(sizeof(struct ListaEnlazada));
    if (!lista) return NULL;
    lista->frente = NULL;
    lista->final = NULL;
    lista->tipo = validarTipoDato(tipo) ? tipo : Int;

    return lista;
}

int enlistarInicio(struct ListaEnlazada *lista, void *dato) {
    if (!lista) return -1;
    if (!dato) return -2;

    struct NodoS *nodo = (struct NodoS *)malloc(sizeof(struct NodoS));
    guardarValor(nodo, 1, lista->tipo, dato);
    nodo->siguiente = lista->frente;
    lista->frente = nodo;
    lista->final = !lista->final ? lista->frente : lista->final;

    return 1;
}

int enlistarFinal(struct ListaEnlazada *lista, void *dato) {
    if (!lista) return -1;
    if (!dato) return -2;

    struct NodoS *nodo = (struct NodoS *)malloc(sizeof(struct NodoS));
    guardarValor(nodo, 1, lista->tipo, dato);
    nodo->siguiente = NULL;
    lista->final->siguiente = nodo;
    lista->final = nodo;

    return 1;
}

int enlistarEn(struct ListaEnlazada* lista, void* dato, int pos) {
    if (!lista) return -1;
    if (!dato) return -2;

    if (!lista->frente || pos == 0) {
        return agregarInicio(lista, dato);
    } else if (pos == -1) {
        return agregarFinal(lista, dato);
    }
    
    int i = 0;
    struct NodoS *nodo = (struct NodoS *)malloc(sizeof(struct NodoS));
    
    guardarValor(nodo, 1, lista->tipo, dato);
    nodo->siguiente = NULL;
    
    if (pos > 0 ) {
        struct NodoS *temp = lista->frente;
        while(i < (pos - 1) && temp) {
            i++;
            temp = temp->siguiente;
        }

        nodo->siguiente = temp->siguiente;
        temp->siguiente = nodo;
    } else {
        return -4;
    }

    return 0;
}

void* desenlistarInicio(struct ListaEnlazada *lista) {
    if (!lista->frente) return NULL;
    
    struct NodoS *nodo = lista->frente;
    void *valor = nodo->dato;
    lista->frente = nodo->siguiente;

    free(nodo);
    return valor;
}

void* desenlistarFinal(struct ListaEnlazada *lista) {
    if (!lista->final) return NULL;

    struct NodoS *nodo = lista->frente;
    while(nodo->siguiente != lista->final) {
        nodo = nodo->siguiente;
    }

    void *valor = nodo->siguiente->dato;
    lista->final = nodo;
    nodo->siguiente = NULL;
    
    free(nodo->siguiente);

    return valor;
}

void* desenlistarEn(struct ListaEnlazada *lista, int pos) {
    if (!lista) return NULL;
    if (!lista->frente) return NULL;
    if (pos < -1) return NULL;
    if (pos == 0) return desenlistarInicio(lista);
    if (pos == -1) return desenlistarFinal(lista);

    int i = 0;
    void *valor;
    struct NodoS *temp;
    struct NodoS *nodo = lista->frente;
    
    while(i < (pos - 1) && nodo) {
        i++;
        nodo = nodo->siguiente;
    }

    temp = nodo->siguiente;
    nodo->siguiente = temp->siguiente;
    valor = temp->dato;

    free(temp);

    return NULL;
}

int longitudLista(struct ListaEnlazada *lista) {
    if (!lista) return -1;
    int i = 0;

    struct NodoS *nodo = lista->frente;
    while(nodo) {
        i++;
        nodo = nodo->siguiente;
    }

    return i;
}

void* mostrarInicio(struct ListaEnlazada *lista) {
    return lista->frente->dato;
}

void* mostrarFinal(struct ListaEnlazada *lista) {
    return lista->final->dato;
} 

void* mostrarPosicion(struct ListaEnlazada *lista, int pos) {
    if (pos == 0) return mostrarInicio(lista);
    if (pos == -1) return mostrarFinal(lista);

    int i = 0;
    struct NodoS *nodo = lista->frente;
    while(nodo) {
        if (i == pos) {
            return nodo->dato;
        } else {
            i++;
            nodo = nodo->siguiente;
        }
    }
}

void imprimirLista(struct ListaEnlazada *lista) {
    struct NodoS *nodo = lista->frente;

    while(nodo) {
        imprimirValor(nodo->dato, lista->tipo);
        nodo = nodo->siguiente;
    }
}

int limpiarLista(struct ListaEnlazada *lista) {
    if (!lista) return -1;
    
    struct NodoS *nodo = lista->frente;

    while(lista->frente) {
        nodo = lista->frente;
        lista->frente = nodo->siguiente;
        
        free(nodo->dato);
        free(nodo);
    }

    return 1;
}

int liberarLista(struct ListaEnlazada *lista) {
    int limpia = limpiarLista(lista);

    if (limpia > 0) {
        free(lista);
        return 1;
    } 

    return 0;
}