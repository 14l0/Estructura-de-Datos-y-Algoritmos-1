#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = *cabeza; //el nodo apunta a si mismo
    } else {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        (*ultimo)->siguiente = *cabeza; //el ultimo apunta al nuevo inicio
    }
    printf("Se inserto: %d\n", valor);
}

//recorremos la lista circular
void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacia\n");
        return;
    }
    struct Nodo *temp = cabeza;
    printf("Lista circular: ");
    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);
    printf("(regresa al inicio)\n");
}

void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }

    struct Nodo *temp = *cabeza;
    struct Nodo *prev = *ultimo;

    do {
        if (temp->dato == valor) {
            if (temp == *cabeza) {
                *cabeza = temp->siguiente;
                (*ultimo)->siguiente = *cabeza;
            } else if (temp == *ultimo) {
                prev->siguiente = *cabeza;
                *ultimo = prev;
            } else { 
                prev->siguiente = temp->siguiente;
            }
            free(temp);
            printf("Se elimino: %d\n", valor);
            return;
        }
        prev = temp;
        temp = temp->siguiente;
    } while (temp != *cabeza);

    printf("No se encontro el valor\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor;

    printf("Cuantos valores quieres insertar en la lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    printf("Que valor quieres eliminar? ");
    scanf("%d", &valor);
    eliminarCircular(&cabeza, &ultimo, valor);
    recorrerCircular(cabeza);

    return 0;
}