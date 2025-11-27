#include <stdio.h>

/*
funcion maximo(arreglo, inicio, fin):
    si inicio == fin:
        devolver arreglo[inicio] //este es nuestro caso base 
    mitad = (inicio + fin) / 2
    max_izquierdo = maximo(arreglo, inicio, mitad)
    max_derecho = maximo(arreglo, mitad+1, fin)
    si max_izquierdo > max_derecho:
        devolver max_izquierdo
    sino:
        devolver max_derecho
*/

//implementamos el pseudocodigo 
int max_recursivo(int arr[], int inicio, int fin) {
    //este es el caso base 
    if (inicio == fin) {
        return arr[inicio];
    }

    int mitad = (inicio + fin) / 2;

    //buscamos el maximo en el lado izquierdo
    int max_izquierdo = max_recursivo(arr, inicio, mitad);

    //este es para el lado derecho
    int max_derercho = max_recursivo(arr, mitad + 1, fin);

    //los comparamos y devolvemos el que este mas grande 
    if (max_izquierdo > max_derercho) {
        return max_izquierdo;
    } else {
        return max_derercho;
    }
}

int main() {
    int n;
    printf("Dime el tamaño del arreglo: ");
    scanf("%d", &n);

    int arr[n];
    printf("Dame los digitos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int resultado = max_recursivo(arr, 0, n - 1);
    printf("El valor máximo es: %d\n", resultado);

    return 0;
}