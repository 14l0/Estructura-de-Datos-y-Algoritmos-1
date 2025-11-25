#include <stdio.h>
#define MAX 5

//cola circular 
struct ColaCircular {
    int datos[MAX];
    int frente;
    int final;
    int size;
};

void inicializar(struct ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada\n");
}

int isEmpty(struct ColaCircular *c) {
    return c->size == 0;
}

int isFull(struct ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(struct ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("Cola llena\n");
    } else {
        c->datos[c->final] = valor;
        c->final = (c->final + 1) % MAX; //avanza de manera circular
        c->size++;
        printf("Se metio: %d\n", valor);
    }
}

int dequeue(struct ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Cola vacia\n");
        return -1;
    } else {
        int valor = c->datos[c->frente];
        c->frente = (c->frente + 1) % MAX; //avanza de manera circular
        c->size--;
        return valor;
    }
}

void printQueue(struct ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Cola vacía\n");
    } else {
        printf("Cola: ");
        int i = c->frente;
        for (int k = 0; k < c->size; k++) {
            printf("%d ", c->datos[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    struct ColaCircular cola;
    inicializar(&cola);

    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);

    int x = dequeue(&cola);
    printf("Salio: %d\n", x);
    printQueue(&cola);

    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola);

    return 0;
}