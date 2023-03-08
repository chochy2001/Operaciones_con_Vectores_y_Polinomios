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
//#include <cctype.h>
#define MAX_CLAVE 300
#define MAX_FILA 300

class Tabla {
private:
    int clave{};//Es el numero de columnas que se creará la Tabla
    std::string texto;
    std::string valorEncriptado;
    char tablaValores[MAX_CLAVE][MAX_FILA]{};
public:
    Tabla();
    Tabla(int clave, const std::string& texto);
    //todo quitar espacios y convertir texto a mayuscula
    //todo formar Tabla con el numero de columnas
    //todo hacer metodos encriptar y desencriptar

    static std::string mayuscula(std::string texto);

    static std::string quitarEspacios(std::string texto);

    static std::string tratarTexto(std::string texto);

    void imprimirTabla();

    [[nodiscard]] const std::string &getTexto() const;

    void encriptar();

};


#endif //ENCRIPTACION_2_TABLA_HPP
