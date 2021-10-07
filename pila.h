#ifndef PILA_H
#define PILA_H

//Declaracion de Variables

/*DECLARANDO EL STRUCT DE LA PILA Y EL PUNTERO AL ULTIMO ELEMENTO ANIADIDO*/
typedef int Item;

typedef struct nodo {
    Item elemento;
    struct nodo *siguiente;
} Nodo;

typedef struct{
    Nodo *cima;//puntero al nodo que esta en la cima de la pila, seria el primer nodo de la lista enlazada
}Pila;

//Declaracion de funciones
void crearPila(Pila *pila);
int pilaVacia(Pila pila);
Item cima(Pila *pila);
void insertar(Pila *pila, Item elemento);
void eliminarPrimerNodo(Pila *pila);
Item quitar(Pila *pila);
void limpiarPila(Pila *pila);
int tamanioPila(Pila pila);

#endif /* PILA_H */

