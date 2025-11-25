#include <stdio.h>
#define MAX 5


struct Pila {
    int datos[MAX];
    int tope;
};

//inicializamos la pila
void inicializar(struct Pila *p) {
    p->tope = -1;
    printf("Pila vacia inicializada\n");
}

//hacemos push (insertar)
void push(struct Pila *p, int valor) {
    if (p->tope == MAX - 1) {
        printf("La pila está llena, no se puede hacer push\n");
    } else {
        p->tope++;
        p->datos[p->tope] = valor;
        printf("Se apilo: %d\n", valor);
    }
}

//hacemos pop (quitamos)
int pop(struct Pila *p) {
    if (p->tope == -1) {
        printf("La pila está vacía, no se puede quitar nada\n");
        return -1;
    } else {
        int valor = p->datos[p->tope];
        p->tope--;
        return valor;
    }
}

//mostramos la pila
void mostrar(struct Pila *p) {
    printf("Pila: ");
    if (p->tope == -1) {
        printf("vacia\n");
    } else {
        for (int i = 0; i <= p->tope; i++) {
            printf("%d ", p->datos[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Pila pila;
    inicializar(&pila);

    int n, valor;
    printf("Cuantos elementos quieres apilar (maximo 5)? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrar(&pila);
    }

    printf("Cuantos elementos quieres quitar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int extraido = pop(&pila);
        if (extraido != -1) {
            printf("Se desapilo: %d\n", extraido);
        }
        mostrar(&pila);
    }

    return 0;
}