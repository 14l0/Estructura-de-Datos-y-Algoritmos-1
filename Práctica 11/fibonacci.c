#include <stdio.h>

long long fibonacci(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    //hacemos la recursividad
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    //posiciones 7, 21, 40, 71 y 94
    int posiciones[] = {7, 21, 40, 71, 94};
    int total = 5;

    for (int i = 0; i < total; i++) {
        int pos = posiciones[i];
        long long resultado = fibonacci(pos);
        printf("Fibonacci en posicion %d = %lld\n", pos, resultado);
    }

    return 0;
}