#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Inicializando una pila, haciendo que cima apunte a un null*/
void crearPila(Pila *pila) {
    pila->cima = NULL;
}

/*Devuelve 1 si la pila esta vacia, y 0 en caso contrario*/
int pilaVacia(Pila pila) {
    return (pila.cima == NULL);
}

/*Devuelve el elemento que esta en la cima de la pila, sin retirarlo*/
Item cima(Pila *pila) {
    if (pilaVacia(*pila)) {
        puts("Underflow");
        exit(1);
    }
    return pila->cima->elemento;
}

/*Inserta un nuevo elemento a la pila (en la cima, que seria al inicio de la lista enlazada)*/
void insertar(Pila *pila, Item elemento) {
    Nodo *nuevo;
    nuevo = (Nodo*) malloc(sizeof (Nodo));
    nuevo->elemento = elemento;
    nuevo->siguiente = pila->cima;
    pila->cima = nuevo;
}

/*Funcion auxiliar que elimina el primer nodo de la lista enlazada (liberando el espacio que ocupa)*/
void eliminarPrimerNodo(Pila *pila) {
    if (!pilaVacia(*pila)) {
        Nodo *f;
        f = pila->cima;
        pila->cima = f->siguiente;
        free(f);
    }
}

/*Devuelve el elemento que esta en la cima, sacandolo de la pila*/
Item quitar(Pila *pila) {
    if (pilaVacia(*pila)) {
        puts("Underflow");
        exit(1);
    }
    Item temp = pila->cima->elemento;
    eliminarPrimerNodo(pila);
    return temp;
}

/*"LIMPIA" un pila, libereando el espacio que ocupan los elementos*/
void limpiarPila(Pila *pila) {
    while (!pilaVacia(*pila)) {
        eliminarPrimerNodo(pila);
    }
}

/*Devuelve la cantidad de elementos almacenados en la pila*/
int tamanioPila(Pila pila) {
    Nodo *act;
    int cantElementos = 0;
    for (act = pila.cima; act != NULL; act = act->siguiente) {
        cantElementos++;
    }
    return cantElementos;
}
