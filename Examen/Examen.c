#include <stdio.h>
#include <stdlib.h> //libreria que contiene las funciones 'malloc', 'realloc' y 'free'

int main(void) {
    int n; //numero inicial de los estudiantes
    float *calificaciones = NULL; //usamos un apuntador dinamico para las calificaciones
    float suma = 0.0;
    char respuesta;

    //le pedimos al usuario cuantos estudiantes va a poner
    printf("\n¿Cuantos estudiantes quieres registrar? ");
    scanf("%d", &n);

    //vamos a reservar la memoria dinamica con malloc
    calificaciones = (float *)malloc(n * sizeof(float));

    //usaremos el condicional 'if' para verificar si malloc fallo
    if (calificaciones == NULL) {
        printf("\nERROR NO SE ASIGNO MEMORIA");
        return 1;
    }

    //almacenamos las calificaciones y calculamos el promedio usando 'for'
    for (int i = 0; i < n; i++) {
        printf("la calificacion del estudiante %d. es de: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    //mostramos todas las calificaciones y el promedio de estas
    printf("\tCALIFICACIONES REGISTRADAS");
    for (int i = 0; i < n; i++) {
        printf("\nEstudiante %d. %.2f", i + 1, calificaciones[i]);
    }
    printf("\nPromedio general: %.2f", suma / n);

    //le vamos a preguntar al usuario si desea agregar mas estudiantes
    printf("\n¿Deseas agregar mas estudiantes? (s/n): ");
    scanf(" %c", &respuesta);

    /* 
    aqui con un 'if' verificamos la respuesta del usuario
    no importa si responde con una 's' minuscula o 'S' mayuscula
    de igual manera lo detecta 
    */
    if (respuesta == 's' || respuesta == 'S') {
        int nuevos;
        printf("\n¿Cuantos estudiantes desea agregar? ");
        scanf("%d", &nuevos);

        //usamos la funcion realloc para ampliar el arreglo
        float *temp = (float *)realloc(calificaciones, (n + nuevos) * sizeof(float));

        //con el condicional 'if' verificamos si realloc fallo
        if (temp == NULL) {
            printf("\nERROR NO SE PUDO AMPLIAR LA MEMORIA");
            free(calificaciones); //Liberamos la memoria original
            return 1;
        }

        calificaciones = temp; //el apuntador que teniamos antes lo vamos a actualizar
        //almacenamos las nuevas calificaciones usando 'for'
        for (int i = n; i < n + nuevos; i++) {
            printf("La Calificacion del estudiante %d. es de: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }

        //actualizamos el tamaño total de la lista de los estudiantes anteriores y los que agregamos despues
        n += nuevos;

        //vamos a mostrar todas las calificaciones y el nuevo promedio
        printf("\tCALIFICACIONES ACTUALIZADAS");
        for (int i = 0; i < n; i++) {
            printf("\nEstudiante %d. %.2f", i + 1, calificaciones[i]);
        }
        printf("\nNuevo promedio general: %.2f", suma / n);
    }

    //mediante el uso de 'free' liberamos la memoria que ya usamos
    free(calificaciones);
    printf("\nMemoria liberada correctamente");

    return 0;
}