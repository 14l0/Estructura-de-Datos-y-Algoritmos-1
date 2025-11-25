#include <stdio.h>
#include <stdlib.h>

//definimos el nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza; //apuntamos al anterior inicio
    *cabeza = nuevo;            //y ahora la cabeza es el nuevo nodo
    printf("Se inserto: %d\n", valor);
}

//Recorremos la lista
void recorrer(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

//Eliminamos un nodo
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *temp = *cabeza;
    struct Nodo *prev = NULL;

    while (temp != NULL && temp->dato != valor) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("No se encontro el valor\n");
        return;
    }

    if (prev == NULL) { 
        *cabeza = temp->siguiente;
    } else { 
        prev->siguiente = temp->siguiente;
    }

    free(temp);
    printf("Se elimino: %d\n", valor);
}

//liberamos la memoria 
void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("Memoria liberada\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    int n, valor;

    printf("Cuantos valores quieres insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("Que valor quieres eliminar? ");
    scanf("%d", &valor);
    eliminar(&cabeza, valor);
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}