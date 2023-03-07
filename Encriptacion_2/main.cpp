//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#include <iostream>
#include "Tabla.hpp"

int main() {
    int clave,opcion;
    std::string texto;

    do {
    std::cout << "Programa que cifra y descifra una frase" << std::endl;
    std::cout << "Ingresa la clave de cifrado (Tiene que ser un numero entero)" << std::endl;
    std::cin>> clave;
    auto *tabla = new Tabla(clave);
    std::cout << "La clave ingresada es "<<tabla->getClave() << std::endl;
    std::cout << "Que desea hacer\n1) Desencriptar\n2) Encriptar\n3) Salir" << std::endl;
    std::cin>>opcion;

    switch (opcion) {
        case 1:
            std::cout << "La opcion deseada es Desencriptar" << std::endl;
            std::cout<< "Ingresa el texto para Desencriptar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin,texto);
            tabla->setTexto(texto);
            std::cout<< "texto: " << tabla->getTexto()<< std::endl;
            break;
        case 2:
            std::cout << "La opcion deseada es Encriptar" << std::endl;
            std::cout<< "Ingresa el texto para Encriptar" << std::endl;
            std::cin.ignore();
            std::getline(std::cin,texto);
            tabla->setTexto(texto);
            std::cout<< "texto: " << tabla->getTexto()<< std::endl;
            break;
        case 3:
            std::cout<< "Gracias por usar el programa" << std::endl;
            opcion=0;
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            break;
    }
    }while (opcion!= 0);
    return 0;
}
