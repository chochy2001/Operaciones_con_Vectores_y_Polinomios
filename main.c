#include "funcionesVectores.h"

int main() {
    int cantidad,opcion,opcionWhile=1;

    printf("Programa que realiza operaciones con vectores de n dimensiones\nDime que cuantas dimensiones ser%cn los vectores\n",160);
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

    float *vector1 = (float *)calloc(cantidad, sizeof(float));
    float *vector2 = (float *)calloc(cantidad, sizeof(float));
    float *vectorResultado = (float *)calloc(cantidad, sizeof(float));

    llenarVectores(vector1,vector2,cantidad);

    do {
    printf("\nQue operacion le gustaria realizar con los vectores\n");

    printf("0) Salir\n1) Suma\n2) Resta\n3) Producto por un escalar\n4) Norma\n5) Angulo entre dos vectores\n");
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    opcion = (int)strtol(input, NULL, 10);

    if(opcion == 0){
        opcionWhile = opcion;
    }

    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    } else if (opcion < 0 || opcion > 5) {
        printf("Numero fuera de rango\n");
        exit(1);
    }

        switch (opcion) {
            case 0:
                printf("Gracias por usar el programa\n");
                break;
            case 1:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Suma\n");
                sumaVectores(vectorResultado,vector1,vector2,cantidad);
                break;
            case 2:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Resta\n");
                restaVectores(vectorResultado,vector1,vector2,cantidad);
                break;
            case 3:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Producto por un Escalar\n");
                productoPorUnEscalar(vectorResultado,vector1,vector2,cantidad);

                break;
            case 4:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Norma\n");
                normaDeUnVector(vector1,vector2,cantidad);
                break;
            case 5:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Angulo entre 2 vectores\n");
                anguloEntreVectores(vector1,vector2,cantidad);
                break;
            default:
                printf("Opcion no disponible\n");
                break;

        }
    }while(opcionWhile!=0);

    free(vector1);
    free(vector2);
    free(vectorResultado);

    return 0;
}

