#include <stdio.h>

int main() {
    int n;
    int a[20];

    printf("¿Cuántos números vas a ingresar? (máximo 20): ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Cantidad inválida.\n");
        return 1;
    }

    printf("Ingresa %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    // Invertir el arreglo sin usar otro arreglo
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("\nArreglo invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}