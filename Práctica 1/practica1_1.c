#include <stdio.h>

int main() {
    int n;
    int a[20];

    printf("Ingresa una cantidad (máximo 20): ");
    scanf("%d", &n);

    // Validar que n esté en el rango permitido
    if (n <= 0 || n > 20) {
        printf("Número inválido. Debe estar entre 1 y 20.\n");
        return 1; // Salir del programa con error
    }

    printf("Ingrese %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nLos elementos del array son:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}