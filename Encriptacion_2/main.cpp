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
    char caracter;
    std::string texto;

    do {
    std::cout << "Programa que cifra y descifra una frase" << std::endl;
    std::cout << "Ingresa la clave de cifrado (Tiene que ser un numero entero)" << std::endl;
    std::cin>> clave;
    std::cout << "La clave ingresada es "<<clave << std::endl;
    std::cout<< "Ingresa el texto" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,texto);
    auto *tabla = new Tabla(clave,texto);
    std::cout<< "texto: " << tabla->getTexto()<< std::endl;
    std::cout << "Escribe el caracter para encriptar" << std::endl;
    std::cin>>caracter;
    tabla->setCaracterEncriptacion(caracter);
    std::cout << "Caracter encriptacion usado por el usuario" << std::endl;
    std::cout << tabla->getCaracterEncriptacion() << std::endl;

    

    std::cout << "Que desea hacer\n1) Desencriptar\n2) Encriptar\n3) Salir" << std::endl;
    std::cin>>opcion;


    switch (opcion) {
        case 1:
            std::cout << "La opcion deseada es Desencriptar" << std::endl;
            tabla->imprimirTabla();
            break;
        case 2:
            std::cout << "La opcion deseada es Encriptar " << std::endl;
            tabla->imprimirTabla();
            tabla->encriptar();
            tabla->getValorEncriptado();

            break;
        case 3:
            std::cout<< "Gracias por usar el programa" << std::endl;
            delete tabla;
            opcion=0;
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            break;
    }
    }while (opcion!= 0);
    return 0;
}
