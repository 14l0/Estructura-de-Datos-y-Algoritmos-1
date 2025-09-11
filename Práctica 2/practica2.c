#include <stdio.h> //libreria de entrada y salida

int main(void) {
    int a[5] = {2, 4, 6, 8, 10}; //declara un arreglo de 5 enteros con valores iniciales
                                 

    int *p = a; //un apuntador a entero 'p' que apunta al primer elemento del arreglo 
                

    printf("1) a[1] = %d\n", a[1]); //accede directamente al segundo elemento del arreglo índice 1 e imprime 4

    printf("2) *(a+3) = %d\n", *(a+3)); 
    /*
    (a+3) es una aritmética de puntero y es la dirección de a[3]
    (a+3) obtiene el valor en esa dirección
    */

    printf("3) *p++ = %d\n", *p++); 
    /*
    usa el valor actual y luego lo incrementa, *p usa el valor actual de p
    después imprime 2 pero p apunta a a[1]
    */

    printf("4) *++p = %d\n", *++p); 
    /*
    al igual que en el anterior, usa el valor actual y lo incrementa, pero ahora de a[1] 
    a a[2] y se obtiene el valor pero en esa nueva posición, imprime 6 pero p apunta a a[2]
    */

    printf("5) p[1] = %d\n", p[1]); 
    /*
    p[1] es *(p+1), y p[1] es a[3], porque p apunta ahorita a a[2] e imprime 8
    */

    printf("6) *(p+=2) = %d\n", *(p+=2)); 
    /*
    p+=2 hace que se mueva el puntero 2 posiciones hacia adelante
    ahora p apunta a a[4] y *(p) se toma el valor de a[4] e imprime 10
    */ 

    printf("7) p - a = %ld\n", p - a); 
    /*
    (p - a) es una resta de punteros y da la cantidad de elementos entre p y a
    y la diferencia sería de 4 debido a que p apunta a[4] y a a[4]
    */ 

    return 0; // Fin del programa
}