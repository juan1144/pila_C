#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(int argc, char** argv) {
    Pila pila;
    crearPila(&pila); //INICIALIZAMOS LA PILA

    for (int i = 0; i < 5; i++) {
        insertar(&pila, (i + 1));
    }

    printf("\nLa pila tiene %d elementos\n", tamanioPila(pila));
    printf("\nLos elementos de la pila son:\n");
    while (!pilaVacia(pila)) {
        printf("%d\n", quitar(&pila));
    }

    limpiarPila(&pila);

    return (EXIT_SUCCESS);
}

