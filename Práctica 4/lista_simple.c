#include <stdio.h>
#include <stdlib.h>

//lista simple
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

int main() {
    struct Nodo *inicio = NULL, *nuevo, *temp;
    int n, valor, i;

    printf("Cuantos elementos quieres en la lista simple? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Ingresa el tamaño #%d: ", i + 1);
        scanf("%d", &valor);

        nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if (inicio == NULL) {
            inicio = nuevo; //primer nodo
        } else {
            temp = inicio;
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo; //conecta al final 
        }
    }

    printf("\nLista simple:\n");
    temp = inicio;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");

    //liberar la memoria
    temp = inicio;
    while (temp != NULL) {
        struct Nodo *aux = temp;
        temp = temp->siguiente;
        free(aux);
    }

    return 0;
}