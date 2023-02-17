#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int cantidad, opcion;

    printf("Programa que realiza operaciones con vectores\nde cuantas dimensiones es el vector\n");
    char input[10];
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    cantidad = (int)strtol(input, NULL, 10);
    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    } else if (cantidad <= 0) {
        printf("Error: La cantidad debe ser mayor que cero.\n");
        exit(1);
    }

    int *vector1 = (int *)calloc(cantidad, sizeof(int));
    int *vector2 = (int *)calloc(cantidad, sizeof(int));
    int *vectorResultado = (int *)calloc(cantidad, sizeof(int));

    for (int i = 0; i < cantidad; ++i) {
        printf("Ingresa el valor del vector 1 en el indice [%d]", i);
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        vector1[i] = (int)strtol(input, NULL, 10);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }

        printf("Ingresa el valor del vector 2 en el indice [%d]", i);
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        vector2[i] = (int)strtol(input, NULL, 10);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }
    }

    printf("Que operacion le gustaria realizar con los vectores\n");

    printf("1) Suma\n2) Resta\n3) Producto por un escalar\n4) Norma\n5) Angulo entre dos vectores\n");
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    opcion = (int)strtol(input, NULL, 10);
    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    } else if (opcion < 1 || opcion > 5) {
        printf("Error: Opción no válida.\n");
        exit(1);
    }

    switch (opcion) {
        case 1:
            printf("Seleccionaste Suma\n");
            for (int i = 0; i < cantidad; ++i) {
                vectorResultado[i] = vector1[i]+vector2[i];
            }
            printf("El resultado de tu vector es:\n");
            printf("(");
            for (int i = 0; i < cantidad; ++i) {
                printf("%d ",vectorResultado[i]);
            }
            printf(")");

            break;
        case 2:
            printf("Seleccionaste Resta\n");
            for (int i = 0; i < cantidad; ++i) {
                vectorResultado[i] = vector1[i]-vector2[i];
            }
            printf("El resultado de restar vector1 menos vector2 es:\n");
            printf("(");
            for (int i = 0; i < cantidad; ++i) {
                printf(" %d, ",vectorResultado[i]);
            }
            printf(")");
            for (int i = 0; i < cantidad; ++i) {
                vectorResultado[i] = vector2[i]-vector1[i];
            }
            printf("El resultado de restar vector2 menos vector1  es:\n");
            printf("(");
            for (int i = 0; i < cantidad; ++i) {
                printf(" %d, ",vectorResultado[i]);
            }
            printf(")");
            break;
        case 3:
            printf("Seleccionaste Producto por un Escalar\n");
            break;
        case 4:
            printf("Seleccionaste Norma\n");
            break;
        case 5:
            printf("Seleccionaste Angulo entre 2 vectores\n");
            break;
        default:
            printf("Opcion no disponible\n");
            break;

    }

    return 0;
}

