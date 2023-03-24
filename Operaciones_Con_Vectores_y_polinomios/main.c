#include "vectores.h"     // Bibliotecas que se crearon
#include "polinomios.h"

int main() {
    int option; 
    char input[10];    
    do {                 // Ciclo do
        printf("Programa que realiza operaciones con vectores y polinomios");
        printf("\nSelecciona el tipo de operacion que quieres realizar\n"); 
        printf("0) Salir\n1) Vectores\n2) Polinomios\n");                     //Opciones disponibles
        if(fgets(input,10,stdin)==NULL){   // Si no se puede leer la entrada del usuario, muestra un mensaje de error y el programa termina
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        option=(int)strtol(input, NULL, 10 );   // Convierte la entrada del usuario a un entero y la almacena en la variable "option"
        switch (option) {    // Switch que permite evaluar la opción seleccionada por el usuario
            case 0:
                printf("*****Seleccionaste Salir*****\n");       // Si se escoge la opción 0
                break;
            case 1:
                printf("*****Seleccionaste Vectores*****\n");    // Si se escoge la opción 1 el programa llama a la función "vectors"
                vectors();
                break;
            case 2:
                printf("*****Seleccionaste Polinomios*****\n");  // Si se escoge la opción 2 el programa llama a la función "polynomials"
                polynomials();
                break;
            default:
                printf("Opcion no valida\n");                    // Si se introduce una opción que no existe se muestra un mensaje de error
                break;
        }

    } while (option != 0);    // Repite el ciclo mientras el usuario no seleccione la opción 0

    return 0;
}
