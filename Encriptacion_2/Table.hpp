//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#ifndef ENCRIPTACION_2_TABLE_HPP
#define ENCRIPTACION_2_TABLE_HPP
/**
 * directiva del preprocesador
 * que indica que se está incluyendo
 * el archivo de encabezado "Table.hpp".
 */
#include <iostream>
#include <cstring>
#include <string>
/**
 * directiva del preprocesador que
 * establece una macro que define el
 * valor máximo de columnas en la tabla como 300.
 *
 * directiva del preprocesador que establece
 * una macro que define el valor máximo de
 * filas en la tabla como 300.
 */
#define MAX_KEY 300
#define MAX_ROW 300

/**
 * se define una clase llamada "Table"
 * que contiene los atributos y métodos
 * necesarios para cifrar y descifrar
 * una cadena de texto.
 */

class Table {
    /**
     * definen las variables miembro privadas
     * de la clase, incluyendo la clave,
     * el texto original, el texto encriptado,
     * el texto desencriptado y el carácter encriptado.
     */
private:
    int key_t{};//Es el numero de columnas que se creará la Table
    std::string text_t;
    std::string encryptedValue_t;
    std::string decryptedValue_t;
    char encryptedCharacter_t{};
    /**
     * definen los miembros públicos de la clase,
     * incluyendo métodos para obtener y establecer
     * los valores de las variables miembro privadas,
     * así como para obtener la clave y establecer
     * la clave y para cifrar y descifrar el texto.
     */
public:
    /**
     * definen los miembros públicos de la clase,
     * incluyendo métodos para obtener y establecer
     * los valores de las variables miembro privadas,
     * así como para obtener la clave y establecer la
     * clave y para cifrar y descifrar el texto.
     */
    std::string getEncryptedValue() const;

    std::string getDecryptedValue() const;

    void setDecryptedValue(const std::string &decryptedValue_l);

    void setEncryptedValue(const std::string &encryptedValue_l);

    char getEncryptedCharacter() const;

    void setEncryptedCharacter(char encryptedCharacter_l);

    /**
     * define una matriz bidimensional de caracteres
     * para almacenar los valores de la tabla.
     */
    char tableValues[MAX_ROW][MAX_KEY]{};

    /**
     * definen los métodos miembro para establecer y
     * obtener el texto original, obtener la clave
     * y establecer la clave, y los constructores de la clase.
     * @param text
     */
    void setText(const std::string &text);

    int getKey() const;

    void setKey(int key_l);

    Table();
    Table(int key, std::string text, char character);
/**
 * definen los métodos estáticos
 * para convertir el texto a mayúsculas,
 * eliminar espacios y tratar el texto.
 * @param text_l
 * @return
 */
    static std::string capitalLetter(std::string text_l);

    static std::string removeSpaces(std::string text_l);

    static std::string treatText(std::string text_l);

    const std::string & getText() const;
/**
 * definen los métodos para obtener el
 * texto encriptado y desencriptado y
 * establecer el carácter encriptado.
 */
    void encrypt();

    void decrypt();

};


#endif //ENCRIPTACION_2_TABLE_HPP
/**
 * directiva del preprocesador que indica
 * el final del archivo de encabezado.
 */
