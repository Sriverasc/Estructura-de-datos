#include "Nodo.h"

typedef struct ListaEnlazada {
    NodoS *frente;
    NodoS *final;
    enum Tipo tipo;
} ListaEnlazada;

ListaEnlazada* iniciarLista(enum Tipo tipo) {
    ListaEnlazada *lista = (ListaEnlazada *)malloc(sizeof(ListaEnlazada));
    if (!lista) return NULL;
    lista->frente = NULL;
    lista->final = NULL;
    lista->tipo = validarTipoDato(tipo) ? tipo : Int;

    return lista;
}

int enlistarInicio(ListaEnlazada *lista, void *dato) {
    if (!lista) return -1;
    if (!dato) return -2;

    NodoS *nodo = (NodoS *)malloc(sizeof(NodoS));
    guardarValor(nodo, 1, lista->tipo, dato);
    nodo->siguiente = lista->frente;
    lista->frente = nodo;
    lista->final = !lista->final ? lista->frente : lista->final;

    return 1;
}

int enlistarFinal(ListaEnlazada *lista, void *dato) {
    if (!lista) return -1;
    if (!dato) return -2;

    NodoS *nodo = (NodoS *)malloc(sizeof(NodoS));
    guardarValor(nodo, 1, lista->tipo, dato);
    nodo->siguiente = NULL;
    lista->final->siguiente = nodo;
    lista->final = nodo;

    return 1;
}

int enlistarEn(ListaEnlazada* lista, void* dato, int pos) {
    if (!lista) return -1;
    if (!dato) return -2;

    if (!lista->frente || pos == 0) {
        return enlistarInicio(lista, dato);
    } else if (pos == -1) {
        return enlistarFinal(lista, dato);
    }
    
    int i = 0;
    NodoS *nodo = (NodoS *)malloc(sizeof(NodoS));
    
    guardarValor(nodo, 1, lista->tipo, dato);
    nodo->siguiente = NULL;
    
    if (pos > 0 ) {
        NodoS *temp = lista->frente;
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

void* desenlistarInicio(ListaEnlazada *lista) {
    if (!lista->frente) return NULL;
    
    NodoS *nodo = lista->frente;
    void *valor = nodo->dato;
    lista->frente = nodo->siguiente;

    free(nodo);
    return valor;
}

void* desenlistarFinal(ListaEnlazada *lista) {
    if (!lista->final) return NULL;

    NodoS *nodo = lista->frente;
    while(nodo->siguiente != lista->final) {
        nodo = nodo->siguiente;
    }

    void *valor = nodo->siguiente->dato;
    lista->final = nodo;
    nodo->siguiente = NULL;
    
    free(nodo->siguiente);

    return valor;
}

void* desenlistarEn(ListaEnlazada *lista, int pos) {
    if (!lista) return NULL;
    if (!lista->frente) return NULL;
    if (pos < -1) return NULL;
    if (pos == 0) return desenlistarInicio(lista);
    if (pos == -1) return desenlistarFinal(lista);

    int i = 0;
    void *valor;
    NodoS *temp;
    NodoS *nodo = lista->frente;
    
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

int longitudLista(ListaEnlazada *lista) {
    if (!lista) return -1;
    int i = 0;

    NodoS *nodo = lista->frente;
    while(nodo) {
        i++;
        nodo = nodo->siguiente;
    }

    return i;
}

void* mostrarInicio(ListaEnlazada *lista) {
    return lista->frente->dato;
}

void* mostrarFinal(ListaEnlazada *lista) {
    return lista->final->dato;
} 

void* mostrarPosicion(ListaEnlazada *lista, int pos) {
    if (pos == 0) return mostrarInicio(lista);
    if (pos == -1) return mostrarFinal(lista);

    int i = 0;
    NodoS *nodo = lista->frente;
    while(nodo) {
        if (i == pos) {
            return nodo->dato;
        } else {
            i++;
            nodo = nodo->siguiente;
        }
    }
}

void imprimirLista(ListaEnlazada *lista) {
    NodoS *nodo = lista->frente;

    while(nodo) {
        imprimirValor(nodo->dato, lista->tipo);
        nodo = nodo->siguiente;
    }
}

int limpiarLista(ListaEnlazada *lista) {
    if (!lista) return -1;
    
    NodoS *nodo = lista->frente;

    while(lista->frente) {
        nodo = lista->frente;
        lista->frente = nodo->siguiente;
        
        free(nodo->dato);
        free(nodo);
    }

    return 1;
}

int liberarLista(ListaEnlazada *lista) {
    int limpia = limpiarLista(lista);

    if (limpia > 0) {
        free(lista);
        return 1;
    } 

    return 0;
}