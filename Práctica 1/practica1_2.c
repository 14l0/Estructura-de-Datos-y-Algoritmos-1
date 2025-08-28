#include <stdio.h>

int main() {
    int n, suma = 0;
    int a[20];
    int min, max;
    int posMin = 0, posMax = 0;

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
        suma += a[i];

        // Inicializar min y max en el primer ciclo
        if (i == 0) {
            min = max = a[i];
        } else {
            if (a[i] < min) {
                min = a[i];
                posMin = i;
            }
            if (a[i] > max) {
                max = a[i];
                posMax = i;
            }
        }
    }

    float promedio = (float)suma / n;

    printf("\nSuma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);
    printf("Mínimo: %d (posición %d)\n", min, posMin);
    printf("Máximo: %d (posición %d)\n", max, posMax);

    return 0;
}