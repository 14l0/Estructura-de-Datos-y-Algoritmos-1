#include <stdio.h>
#include <stdlib.h>

//lista circular
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

int main() {
    struct Nodo *inicio = NULL, *nuevo, *temp;
    int n, valor, i;

    printf("Cuantos elementos quieres en la lista circular? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Ingresa el tamaño #%d: ", i + 1);
        scanf("%d", &valor);

        nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
        nuevo->dato = valor;

        if (inicio == NULL) {
            inicio = nuevo;
            inicio->siguiente = inicio; //el primer nodo apunta al mismo nodo 
        } else {
            temp = inicio;
            while (temp->siguiente != inicio) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
            nuevo->siguiente = inicio; //el ultimo apunta al del inicio
        }
    }

    printf("\nLista circular:\n");
    temp = inicio;
    i = 0;
    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
        i++;
    } while (temp != inicio && i < n);
    printf("(regresa al inicio)\n");

    //liberamos la memoria
    temp = inicio->siguiente;
    while (temp != inicio) {
        struct Nodo *aux = temp;
        temp = temp->siguiente;
        free(aux);
    }
    free(inicio);

    return 0;
}