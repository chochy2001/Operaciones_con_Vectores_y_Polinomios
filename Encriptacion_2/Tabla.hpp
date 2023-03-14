//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#ifndef ENCRIPTACION_2_TABLA_HPP
#define ENCRIPTACION_2_TABLA_HPP
#include <iostream>
#include <cstring>
#include <string>
#define MAX_CLAVE 300
#define MAX_FILA 300

class Tabla {
private:

    int clave{};//Es el numero de columnas que se creará la Tabla
    std::string texto;
    std::string valorEncriptado;
    std::string valorDesencriptado;
    char caracterEncriptacion{};
public:
    std::string getValorEncriptado() const;

    std::string getValorDesencriptado() const;

    void setValorDesencriptado(const std::string &valorDesencriptado_l);

    void setValorEncriptado(const std::string &valorEncriptado_l);

    char getCaracterEncriptacion() const;

    void setCaracterEncriptacion(char caracterEncriptacion_l);

    char tablaValores[MAX_FILA][MAX_CLAVE]{};
    void setTexto(const std::string &text);

    int getClave() const;

    void setClave(int clave_l);

    Tabla();
    Tabla(int clave, std::string text, char caracter);
    //todo quitar espacios y convertir texto a mayuscula
    //todo formar Tabla con el numero de columnas
    //todo hacer metodos encriptar y desencriptar

    static std::string mayuscula(std::string texto);

    static std::string quitarEspacios(std::string texto);

    static std::string tratarTexto(std::string texto);

    void imprimirTabla();

    const std::string & getTexto() const;

    void encriptar();

    void desencriptar();

};


#endif //ENCRIPTACION_2_TABLA_HPP
