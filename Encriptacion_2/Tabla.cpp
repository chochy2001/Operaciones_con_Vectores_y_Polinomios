//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//


#include "Tabla.hpp"

#include <utility>


std::string Tabla::mayuscula(std::string texto) {
    for (char& i : texto) {
        i = toupper(i);
    }
    return texto;
}

std::string Tabla::quitarEspacios(std::string texto) {
    for (int i = 0; i < texto.length(); ++i) {
        if (texto[i] == ' '){
            texto.erase(i,1);
            i--;
        }
    }
    return texto;
}

std::string Tabla::tratarTexto(std::string texto) {
    return quitarEspacios(mayuscula(std::move(texto)));
}


void Tabla::imprimirTabla() {
    for (int i = 0; i < clave; ++i) {
        for (int j = 0; j < (int)(texto.length()/clave)+1; ++j) {
            //std::cout<< "[" << i << "+" << j<< "]" << std::endl;
            std::cout<< "[" << texto[i] << "+" << texto[j]<< "]" << std::endl;
        }
    }
}

Tabla::Tabla() = default;


Tabla::Tabla(int clave, const std::string& texto) {
    this->clave = clave;
    this->texto = tratarTexto(texto);
    for (int i = 0; i < clave; ++i) {
        for (int j = 0; j < texto.length(); ++j) {
            this->tablaValores[i][j] = '\0';
        }
    }
}

const std::string &Tabla::getTexto() const {
    return texto;
}

void Tabla::encriptar() {
    for (int i = 0; i < this->clave; ++i) {
        for (int j = 0; j < this->texto.length(); ++j) {
            tablaValores[i][j] = texto[j];
        }
    }
    for (int i = 0; i < this->clave; ++i) {
        for (int j = 0; j < this->texto.length(); ++j) {
            std::cout<< this->tablaValores[i][j] << std::endl;
        }
    }

}
