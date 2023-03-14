//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#ifndef ENCRIPTACION_2_TABLE_HPP
#define ENCRIPTACION_2_TABLE_HPP
#include <iostream>
#include <cstring>
#include <string>
#define MAX_KEY 300
#define MAX_ROW 300

class Table {
private:

    int key_t{};//Es el numero de columnas que se creará la Table
    std::string text_t;
    std::string encryptedValue_t;
    std::string decryptedValue_t;
    char encryptedCharacter_t{};
public:
    std::string getEncryptedValue() const;

    std::string getDecryptedValue() const;

    void setDecryptedValue(const std::string &decryptedValue_l);

    void setEncryptedValue(const std::string &encryptedValue_l);

    char getEncryptedCharacter() const;

    void setEncryptedCharacter(char encryptedCharacter_l);

    char tableValues[MAX_ROW][MAX_KEY]{};
    void setText(const std::string &text);

    int getKey() const;

    void setKey(int key_l);

    Table();
    Table(int key, std::string text, char character);

    static std::string capitalLetter(std::string text_l);

    static std::string removeSpaces(std::string text_l);

    static std::string treatText(std::string text_l);

    const std::string & getText() const;

    void encrypt();

    void decrypt();

};


#endif //ENCRIPTACION_2_TABLE_HPP
