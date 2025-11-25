#include <stdio.h>
#define MAX 5

//deque (cola doble)
struct Deque {
    int datos[MAX];
    int front;
    int size;
};

void inicializar(struct Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado\n");
}

int rear(struct Deque *d) {
    return (d->front + d->size - 1) % MAX;
}

void insert_front(struct Deque *d, int valor) {
    if (d->size == MAX) {
        printf("Deque lleno\n");
    } else {
        d->front = (d->front - 1 + MAX) % MAX;
        d->datos[d->front] = valor;
        d->size++;
        printf("Se metio al frente: %d\n", valor);
    }
}

void insert_rear(struct Deque *d, int valor) {
    if (d->size == MAX) {
        printf("Deque lleno\n");
    } else {
        int pos = (d->front + d->size) % MAX;
        d->datos[pos] = valor;
        d->size++;
        printf("Se metio al final: %d\n", valor);
    }
}

int delete_front(struct Deque *d) {
    if (d->size == 0) {
        printf("Deque vacio\n");
        return -1;
    } else {
        int valor = d->datos[d->front];
        d->front = (d->front + 1) % MAX;
        d->size--;
        return valor;
    }
}

int delete_rear(struct Deque *d) {
    if (d->size == 0) {
        printf("Deque vacio\n");
        return -1;
    } else {
        int pos = rear(d);
        int valor = d->datos[pos];
        d->size--;
        return valor;
    }
}

void printDeque(struct Deque *d) {
    if (d->size == 0) {
        printf("Deque vacio\n");
    } else {
        printf("Deque: ");
        int i = d->front;
        for (int k = 0; k < d->size; k++) {
            printf("%d ", d->datos[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    struct Deque d;
    inicializar(&d);

    insert_front(&d, 10);
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    insert_front(&d, 30);
    insert_rear(&d, 40);
    printDeque(&d);

    int x = delete_front(&d);
    printf("Salio del frente: %d\n", x);
    int y = delete_rear(&d);
    printf("Salio del final: %d\n", y);
    printDeque(&d);

    insert_rear(&d, 50);
    insert_front(&d, 60);
    printDeque(&d);

    return 0;
}