#include <iostream>

int main() {
    int clave,opcion;
    std::cout << "Programa que cifra y descifra una frase" << std::endl;
    std::cout << "Ingresa la clave de cifrado (Tiene que ser un numero entero)" << std::endl;
    std::cin>> clave;
    std::cout << "La clave ingresada es " <<clave<< std::endl;
    std::cout << "Que desea hacer\n1) Desencriptar\n2) Encriptar" << std::endl;
    std::cin>>opcion;
    switch (opcion) {
        case 1:
            std::cout << "La opcion deseada es Desencriptar" << std::endl;
            break;
        case 2:
            std::cout << "La opcion deseada es Encriptar" << std::endl;
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            break;
    }
    return 0;
}
