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
    int clave{};//Es el numero de columnas que se creará la Tabla
    std::string texto;
public:
    [[nodiscard]] int getClave() const;

    [[maybe_unused]] void setClave(int key);

    [[nodiscard]] std::basic_string<char> getTexto();

    void setTexto(const std::string &text);

    virtual ~Tabla();

    [[maybe_unused]] Tabla(int clave, std::string texto);

    explicit Tabla(int clave);

    [[maybe_unused]] explicit Tabla(std::string texto);

    Tabla();
    //todo quitar espacios y convertir texto a mayuscula
    //todo formar Tabla con el numero de columnas
    //todo hacer metodos encriptar y desencriptar

    static std::string mayuscula(std::string texto);

    static std::string quitarEspacios(std::string texto);

    static std::string tratarTexto(std::string texto);




};


#endif //ENCRIPTACION_2_TABLA_HPP
