//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#include "Table.hpp"
#include <utility>

std::string Table::capitalLetter(std::string text_l) {
    for (char& i : text_l) {
        i = toupper(i);
    }
    return text_l;
}

std::string Table::removeSpaces(std::string text_l) {
    for (int i = 0; i < text_l.length(); ++i) {
        if (text_l[i] == ' '){
            text_l.erase(i, 1);
            i--;
        }
    }
    return text_l;
}

std::string Table::treatText(std::string text_l) {
    return removeSpaces(capitalLetter(std::move(text_l)));
}

Table::Table() = default;

Table::Table(int key, std::string text, char character) {
    int r=0;
    setKey(key);
    setText(treatText(std::move(text)));
    setEncryptedCharacter(character);

    //Llenar la tabla con character usuario
    for (int i = 0; i < (int)(getText().length() / getKey()) + 1; ++i) {
        for (int j = 0; j < getKey(); ++j) {
            this->tableValues[i][j] = character;
        }
    }

    for (int i = 0; i < (int)(getText().length() / getKey()) + 1; ++i) {
        for (int j = 0; j < getKey(); ++j) {
            char c = this->getEncryptedCharacter();
            if (r < getText().length()) {
                c = getText()[r];
                if (c == '.') {
                    c = 'X';
                }
                r++;
            }
            this->tableValues[i][j] = c;
        }
    }
}

const std::string &Table::getText() const {
    return text_t;
}


void Table::setText(const std::string &text) {
    Table::text_t = text;
}

int Table::getKey() const {
    return key_t;
}

void Table::setKey(int key_l) {
    Table::key_t = key_l;
}

char Table::getEncryptedCharacter() const {
    return encryptedCharacter_t;
}

void Table::setEncryptedCharacter(char encryptedCharacter_l) {
    Table::encryptedCharacter_t = encryptedCharacter_l;
}

std::string Table::getEncryptedValue() const {
    return encryptedValue_t;
}

void Table::setEncryptedValue(const std::string &encryptedValue_l) {
    Table::encryptedValue_t = encryptedValue_l;
}

std::string Table::getDecryptedValue() const {
    return decryptedValue_t;
}

void Table::setDecryptedValue(const std::string &decryptedValue_l) {
    Table::decryptedValue_t = decryptedValue_l;
}

void Table::encrypt() {
    std::string encryptedValue_l;
    for (int i = 0; i < getKey(); ++i) {
        for (int j = 0; j < (int)(getText().length() / getKey()) + 1; ++j) {
            encryptedValue_l += this->tableValues[j][i];
        }
    }
    setEncryptedValue(encryptedValue_l);
}

void Table::decrypt() {

    std::string decryptedValue_l[this->getKey()];
    int parts = (int)this->text_t.length() / this->getKey();
    std::string decryptedText_l;


    for (int i = 0; i < this->getKey(); ++i) {
        std::string subtext  = this->text_t.substr(i * parts, parts);
        decryptedValue_l[i] = subtext;

    }
    for (int i = 0; i < this->getKey(); ++i) {
        for (int j = 0; j < parts; ++j) {
            tableValues[j][i] = decryptedValue_l[i][j];
        }
    }

    for (int i = 0; i < (int)(getText().length() / getKey()); ++i) {
        for (int j = 0; j < this->getKey(); ++j) {
            decryptedText_l += this->tableValues[i][j];
        }
    }

    setDecryptedValue(decryptedText_l);
}
