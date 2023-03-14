//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#include <iostream>
#include "Table.hpp"

int main() {
    int key,option;
    char character;
    std::string text_g;

    do {
    std::cout << "Programa que cifra y descifra una frase" << std::endl;
    std::cout << "Ingresa la clave de cifrado (Tiene que ser un numero entero)" << std::endl;
    std::cin >> key;
    std::cout << "La clave ingresada es " << key << std::endl;
    std::cout<< "Ingresa el texto" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, text_g);
    std::cout << "Escribe el caracter para encriptar" << std::endl;
    std::cin >> character;
    auto *table = new Table(key, text_g, toupper(character));
    std::cout << "Caracter encriptacion usado por el usuario" << std::endl;
    std::cout << table->getEncryptedCharacter() << std::endl;


    std::cout << "Que desea hacer\n1) Desencriptar\n2) Encriptar\n3) Salir" << std::endl;
    std::cin >> option;

    switch (option) {
        case 1:
            std::cout << "La opcion deseada es Desencriptar" << std::endl;
            table->decrypt();
            std::cout << table->getDecryptedValue() << std::endl;
            break;
        case 2:
            std::cout << "La opcion deseada es Encriptar " << std::endl;
            table->encrypt();
            std::cout<< "El valor encriptado es el siguiente" << std::endl;
            std::cout << table->getEncryptedValue() << std::endl;

            break;
        case 3:
            std::cout<< "Gracias por usar el programa" << std::endl;
            delete table;
            option=0;
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            break;
    }
    }while (option != 0);
    return 0;
}
