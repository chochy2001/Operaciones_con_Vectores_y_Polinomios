//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//


#include "Tabla.hpp"


std::string Tabla::mayuscula(std::string texto) {
    for (int i = 0; i < texto.length(); ++i) {
        texto[i] = toupper(texto[i]);
    }
    return texto;
}

int Tabla::getClave() const {
    return clave;
}

void Tabla::setClave(int clave) {
    Tabla::clave = clave;
}

Tabla::Tabla(int clave) : clave(clave) {}

const std::string &Tabla::getTexto() const {
    return texto;
}

void Tabla::setTexto(const std::string &texto) {
    Tabla::texto = mayuscula(texto);
}
