//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#include <iostream>
#include "Table.hpp"
/**
 * Este código es el punto de entrada del programa.
 * En resumen, pide al usuario que ingrese una clave,
 * un texto y un caracter para encriptar,
 * y luego le da al usuario la opción de encriptar
 * o desencriptar el texto.
 * @return
 */

int main() {
    /**
     * se declara una variable "key"
     * de tipo entero que será
     * utilizada para almacenar
     * la clave de cifrado ingresada
     * por el usuario.
     *
     * se declara una variable "option"
     * de tipo entero que será utilizada
     * para almacenar la opción seleccionada
     * por el usuario
     * (encriptar, desencriptar o salir del programa).
     *
     * se declara una variable "character"
     * de tipo char que será utilizada para
     * almacenar el caracter que el usuario
     * quiere usar para encriptar.
     *
     * se declara una variable "text_g"
     * de tipo std::string que será utilizada
     * para almacenar el texto ingresado por el usuario.
     */

    int key,option;
    char character;
    std::string text_g;

    /**
     * comienza un bucle "do-while"
     * que se ejecutará mientras
     * el usuario no seleccione la opción "Salir".
     */
    do {
        //se muestra un mensaje al usuario que describe el propósito del programa.
    std::cout << "Programa que cifra y descifra una frase" << std::endl;
    std::cout << "Ingresa la clave de cifrado (Tiene que ser un numero entero)" << std::endl;
    std::cin >> key;
    //se lee la clave de cifrado ingresada por el usuario y se almacena en la variable "key".
    std::cout << "La clave ingresada es " << key << std::endl;
    std::cout<< "Ingresa el texto" << std::endl;
    //se ignora el primer caracter en el flujo de
    // entrada para evitar problemas con la lectura de caracteres.
    std::cin.ignore();
    std::getline(std::cin, text_g);
    std::cout << "Escribe el caracter para encriptar" << std::endl;
    std::cin >> character;
    //se lee el caracter ingresado por el
    // usuario y se convierte a mayúscula con la función "toupper()".

    //se crea un objeto "Table" con la clave,
    // el texto y el caracter de encriptación ingresados por el usuario.
    auto *table = new Table(key, text_g, toupper(character));
    std::cout << "Caracter encriptacion usado por el usuario" << std::endl;
    std::cout << table->getEncryptedCharacter() << std::endl;


    std::cout << "Que desea hacer\n1) Desencriptar\n2) Encriptar\n3) Salir" << std::endl;
    std::cin >> option;

    //se utiliza un switch para seleccionar
    // una acción en función de la opción
    // seleccionada por el usuario.
    switch (option) {
        //si el usuario selecciona la opción "Desencriptar",
        // se muestra un mensaje y se llama al método "decrypt()"
        // del objeto "Table".
        case 1:
            std::cout << "La opcion deseada es Desencriptar" << std::endl;
            table->decrypt();
            //se muestra el texto desencriptado
            // utilizando el método "getDecryptedValue()"
            // del objeto "Table".
            std::cout << table->getDecryptedValue() << std::endl;
            break;
            //Si el usuario selecciona la opción "Encriptar",
            // se muestra un mensaje y se llama al método
            // "encrypt()" del objeto "Table".
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
