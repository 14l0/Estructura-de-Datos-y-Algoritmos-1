#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
    } else {
        struct Nodo *ultimo = (*inicio)->anterior;
        nuevo->siguiente = *inicio;
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        (*inicio)->anterior = nuevo;
    }
    printf("Se inserto: %d\n", valor);
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacia\n");
        return;
    }
    struct Nodo *temp = inicio;
    printf("Lista circular: ");
    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);
    printf("(regresa al inicio)\n");
}

//Eliminamos en lista circular
void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vacia\n");
        return;
    }

    struct Nodo *temp = *inicio;
    do {
        if (temp->dato == valor) {
            if (temp->siguiente == temp && temp->anterior == temp) {
                *inicio = NULL;
            } else {
                temp->anterior->siguiente = temp->siguiente;
                temp->siguiente->anterior = temp->anterior;
                if (temp == *inicio) {
                    *inicio = temp->siguiente;
                }
            }
            free(temp);
            printf("Se elimino: %d\n", valor);
            return;
        }
        temp = temp->siguiente;
    } while (temp != *inicio);

    printf("No se encontro el valor\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("Cuantos valores quieres insertar en la lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
        recorrerCircular(inicio);
    }

    printf("Que valor quieres eliminar? ");
    scanf("%d", &valor);
    eliminarCircular(&inicio, valor);
    recorrerCircular(inicio);

    return 0;
}