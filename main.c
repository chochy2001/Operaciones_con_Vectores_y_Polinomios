#include "vectores.h"
#include "polinomios.h"

int main() {
    int opcion;
    char input[10];
    printf("Programa que realiza operaciones con vectores y polinomios\n");
    printf("Selecciona el tipo de operacion que quieres realizar\n");
    printf("1) Vectores\n2) Polinomios\n");
    if(fgets(input,10,stdin)==NULL){
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    opcion=(int)strtol( input, NULL, 10 );
    switch (opcion) {
        case 1:
            printf("*****Seleccionaste Vectores*****\n");
            vectores();
            break;
        case 2:
            printf("*****Seleccionaste polinomios*****\n");
            polinomios();
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }

    return 0;
}

