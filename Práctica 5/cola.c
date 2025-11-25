#include <stdio.h>
#define MAX 5


struct Cola {
    int datos[MAX];
    int frente;
    int final;
};

//inicializamos la cola
void inicializar(struct Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola vacia inicializada\n");
}

//hacemos enqueue (insertamos)
void enqueue(struct Cola *c, int valor) {
    if (c->final == MAX - 1) {
        printf("La cola esta llena, no se puede hacer enqueue\n");
    } else {
        c->final++;
        c->datos[c->final] = valor;
        printf("Se encolo: %d\n", valor);
    }
}

//hacemos dequeue (quitamos)
int dequeue(struct Cola *c) {
    if (c->frente > c->final) {
        printf("La cola esta vacia, no se puede extraer nada\n");
        return -1;
    } else {
        int valor = c->datos[c->frente];
        c->frente++;
        return valor;
    }
}

//mostramos la cola
void mostrar(struct Cola *c) {
    printf("Cola: ");
    if (c->frente > c->final) {
        printf("vacia\n");
    } else {
        for (int i = c->frente; i <= c->final; i++) {
            printf("%d ", c->datos[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Cola cola;
    inicializar(&cola);

    int n, valor;
    printf("Cuantos elementos quieres encolar (maximo 5)? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrar(&cola);
    }

    printf("Cuantos elementos quieres desencolar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int extraido = dequeue(&cola);
        if (extraido != -1) {
            printf("Se desencolo: %d\n", extraido);
        }
        mostrar(&cola);
    }

    return 0;
}