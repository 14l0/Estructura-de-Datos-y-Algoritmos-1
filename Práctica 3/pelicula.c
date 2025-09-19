#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100 

struct Pelicula {
    char nombre[50];
    char director[50];
    int anio;
    char genero[30];
};

int main(void) {
    struct Pelicula videoteca[MAX]; 
    int numPeliculas;

    
    printf("¿Cuántas películas vas a registrar? ");
    scanf("%d", &numPeliculas);

    if (numPeliculas <= 0) {
        printf("Error: número de películas inválido.\n");
        return 1;
    }

    //captura de datos por teclado
    for (int i = 0; i < numPeliculas; i++) {
        printf("\nPelícula #%d\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", videoteca[i].nombre); //lee la cadena con los espacios

        printf("Director: ");
        scanf(" %[^\n]", videoteca[i].director);

        printf("Año: ");
        scanf("%d", &videoteca[i].anio);

        printf("Género: ");
        scanf(" %[^\n]", videoteca[i].genero);
    }

    //se imprimen en orden inverso
    printf("\n--- Películas en orden inverso ---\n");
    for (int i = numPeliculas - 1; i >= 0; i--) {
        printf("Nombre: %s | Director: %s | Año: %d | Género: %s\n",
               videoteca[i].nombre, videoteca[i].director,
               videoteca[i].anio, videoteca[i].genero);
    }

    //búsqueda por año, director o nombre
    char criterio[50];
    int opcion;

    printf("\nBuscar película por:\n1) Año\n2) Director\n3) Nombre\nOpción: ");
    scanf("%d", &opcion);

    printf("Ingresa el criterio de búsqueda: ");
    scanf(" %[^\n]", criterio);

    printf("\n--- Resultados de búsqueda ---\n");
    for (int i = 0; i < numPeliculas; i++) {
        if ((opcion == 1 && videoteca[i].anio == atoi(criterio)) ||
            (opcion == 2 && strcmp(videoteca[i].director, criterio) == 0) ||
            (opcion == 3 && strcmp(videoteca[i].nombre, criterio) == 0)) {
            printf("Nombre: %s | Director: %s | Año: %d | Género: %s\n",
                   videoteca[i].nombre, videoteca[i].director,
                   videoteca[i].anio, videoteca[i].genero);
        }
    }

    char generoBuscado[30];
    int contador = 0;

    printf("\nIngresa un género para contar cuántas películas hay: ");
    scanf(" %[^\n]", generoBuscado);

    for (int i = 0; i < numPeliculas; i++) {
        if (strcmp(videoteca[i].genero, generoBuscado) == 0) {
            contador++;
        }
    }

    printf("Hay %d película(s) del género '%s'.\n", contador, generoBuscado);

    //validación de directores, no son -1 o 0
    int directoresValidos = 0;
    for (int i = 0; i < numPeliculas; i++) {
        if (strcmp(videoteca[i].director, "-1") != 0 &&
            strcmp(videoteca[i].director, "0") != 0 &&
            strlen(videoteca[i].director) > 0) {
            directoresValidos++;
        }
    }

    if (directoresValidos == 0) {
        printf("Error: no hay directores válidos registrados.\n");
    } else {
        printf("Directores válidos registrados: %d\n", directoresValidos);
    }

    return 0;
}