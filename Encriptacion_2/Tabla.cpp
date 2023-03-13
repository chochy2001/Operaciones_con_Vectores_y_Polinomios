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

    for (int i = 0; i < (int)(getTexto().length()/getClave())+1; ++i) {
        for (int j = 0; j < getClave(); ++j) {
            std::cout << this->tablaValores[i][j];
        }
        std::cout << std::endl;
    }
}

Tabla::Tabla() = default;

Tabla::Tabla(int clave, std::string texto) {
    int r=0;
    setClave(clave);
    setTexto(tratarTexto(texto));
    char caracter = getCaracterEncriptacion();

    //Llenar la tabla con caracter usuario
    for (int i = 0; i < (int)(getTexto().length()/getClave())+1; ++i) {
        for (int j = 0; j < getClave(); ++j) {
            this->tablaValores[i][j] = caracter;
        }
    }

    for (int i = 0; i < (int)(getTexto().length()/getClave())+1; ++i) {
        for (int j = 0; j < getClave(); ++j) {
            char c = 'S';
            if (r < getTexto().length()) {
                c = getTexto()[r];
                if (c == '.') {
                    c = 'X';
                }
                r++;
            }
            this->tablaValores[i][j] = c;
        }
    }
}

const std::string &Tabla::getTexto() const {
    return texto;
}

void Tabla::encriptar() {
    std::string encriptado;
    for (int i = 0; i < getClave(); ++i) {
        for (int j = 0; j < (int)(getTexto().length()/getClave())+1; ++j) {
            encriptado += this->tablaValores[j][i];
        }
    }
    setValorEncriptado(encriptado);


}

void Tabla::setTexto(const std::string &texto) {
    Tabla::texto = texto;
}

int Tabla::getClave() const {
    return clave;
}

void Tabla::setClave(int clave) {
    Tabla::clave = clave;
}

char Tabla::getCaracterEncriptacion() const {
    return caracterEncriptacion;
}

void Tabla::setCaracterEncriptacion(char caracterEncriptacion) {
    Tabla::caracterEncriptacion = caracterEncriptacion;
}

const std::string &Tabla::getValorEncriptado() const {
    return valorEncriptado;
}

void Tabla::setValorEncriptado(const std::string &valorEncriptado) {
    Tabla::valorEncriptado = valorEncriptado;
}
