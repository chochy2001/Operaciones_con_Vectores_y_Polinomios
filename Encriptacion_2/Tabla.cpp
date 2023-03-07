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

int Tabla::getClave() const {
    return clave;
}

[[maybe_unused]] void Tabla::setClave(int key) {
    Tabla::clave = key;
}


std::basic_string<char> Tabla::getTexto() {
    return tratarTexto(texto);
}

void Tabla::setTexto(const std::string &text) {
    Tabla::texto = mayuscula(text);
}

Tabla::~Tabla() = default;

[[maybe_unused]] Tabla::Tabla(int clave, std::string texto) : clave(clave), texto(std::move(texto)) {}

Tabla::Tabla(int clave) : clave(clave) {}

[[maybe_unused]] Tabla::Tabla(std::string texto) : texto(std::move(texto)) {}

Tabla::Tabla() = default;

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
