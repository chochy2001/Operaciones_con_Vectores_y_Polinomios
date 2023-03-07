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

class Tabla {
private:
    int clave;//Es el numero de columnas que se creará la Tabla
    std::string texto;
public:
    int getClave() const;
    void setClave(int clave);

    [[nodiscard]] const std::string &getTexto() const;

    void setTexto(const std::string &texto);

    explicit Tabla(int clave);


    //todo quitar espacios y convertir texto a mayuscula
    //todo formar Tabla con el numero de columnas
    //todo hacer metodos encriptar y desencriptar

    static std::string mayuscula(std::string texto);




};


#endif //ENCRIPTACION_2_TABLA_HPP
