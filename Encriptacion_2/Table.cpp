//
// Created by
//Cortés Alvarado Iván Daniel
//Rodríguez Larios Alejandro
//Salgado Miranda Jorge
//on 3/7/2023.
//

#include "Table.hpp"
#include <utility>

/**
 *
 * se define una función llamada "capitalLetter"
 * que toma una cadena de texto como entrada y convierte
 * todas las letras a mayúsculas utilizando la función "toupper".
 * La función devuelve la cadena de texto modificada.
 * @param text_l
 * @return
 */

std::string Table::capitalLetter(std::string text_l) {
    for (char& i : text_l) {
        i = toupper(i);
    }
    return text_l;
}
/**
 * se define otra función llamada "removeSpaces"
 * que toma una cadena de texto como entrada
 * y elimina todos los espacios en blanco que se encuentran en la cadena.
 * La función utiliza un bucle "for" para recorrer la cadena de texto y,
 * si encuentra un espacio en blanco, utiliza la función "erase"
 * para eliminar el carácter en esa posición.
 * La función devuelve la cadena de texto modificada.
 * @param text_l
 * @return
 */
std::string Table::removeSpaces(std::string text_l) {
    for (int i = 0; i < text_l.length(); ++i) {
        if (text_l[i] == ' '){
            text_l.erase(i, 1);
            i--;
        }
    }
    return text_l;
}

/**
 * La función "treatText" se define a continuación y
 * se utiliza para tratar la cadena de texto de entrada antes de cifrarla o descifrarla.
 * Esta función utiliza la función "removeSpaces" y "capitalLetter"
 * para eliminar los espacios en blanco y convertir todas las letras a mayúsculas.
 * La función devuelve la cadena de texto modificada.
 * @param text_l
 * @return
 */
std::string Table::treatText(std::string text_l) {
    return removeSpaces(capitalLetter(std::move(text_l)));
}

/**
 * se define el constructor predeterminado "Table" que no toma ningún parámetro.
 * La implementación se define como "default" utilizando "= default".
 */
Table::Table() = default;

/**
 * El siguiente constructor toma tres parámetros:
 * una clave entera, una cadena de texto y un carácter.
 * La implementación comienza llamando a las funciones
 * "setKey", "setText" y "setEncryptedCharacter"
 * para establecer los valores de los atributos correspondientes.
 * A continuación, se llena una tabla de valores utilizando
 * el carácter de entrada en todas las posiciones.

Luego, se utiliza un bucle "for" anidado para recorrer
 la cadena de texto y asignar cada carácter a una posición en la tabla.
 Si el carácter es un punto ".", se sustituye por la letra "X".
 Finalmente, la función "encrypt" se llama para cifrar la cadena de texto.



 * @param key
 * @param text
 * @param character
 */
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
/**
 * A continuación, se definen los getters y setters para los atributos
 * "text_t", "key_t", "encryptedCharacter_t", "encryptedValue_t" y "decryptedValue_t".
 * Estos métodos permiten acceder y modificar los atributos correspondientes.
 */
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
/**
 * La función "encrypt" de la clase "Table".
 * En resumen, el método recorre los valores almacenados en la tabla de la clase
 * "Table" y los concatena en un solo string, que es establecido como el
 * valor cifrado de la instancia de la clase.
 * Más detalladamente, el método utiliza dos bucles anidados
 * para recorrer la tabla de valores almacenados por columnas.
 * En el primer bucle, la variable "i" recorre las columnas de la tabla
 * y en el segundo bucle, la variable "j" recorre las filas de la tabla.
 * El método agrega cada valor de la tabla a una cadena de caracteres
 * "encryptedValue_l" que se inicializa vacía al principio de la función.
 * La condición del segundo bucle asegura que se recorran todas
 * las filas de la tabla, incluso si la longitud del texto no es un
 * múltiplo del número de columnas. Esto se logra dividiendo la longitud
 * del texto por el número de columnas y sumándole 1 para asegurarse de
 * que todas las filas sean recorridas.
 * Finalmente, el valor de "encryptedValue_l"
 * se establece como el valor cifrado de la instancia
 * de la clase mediante el método
 * "setEncryptedValue()".
 *
*/
void Table::encrypt() {
    std::string encryptedValue_l;
    for (int i = 0; i < getKey(); ++i) {
        for (int j = 0; j < (int)(getText().length() / getKey()) + 1; ++j) {
            encryptedValue_l += this->tableValues[j][i];
        }
    }
    setEncryptedValue(encryptedValue_l);
}

/**
 *
 * Este código es la implementación del método decrypt()
 * de la clase Table, el cual se encarga de descifrar el
 * texto cifrado utilizando la tabla creada en el constructor.
 * En la primera línea se declara un arreglo de cadenas de
 * caracteres decryptedValue_l con tamaño igual a la clave
 * (this->getKey()), en el cual se guardarán los valores descifrados
 * de cada columna de la tabla.
 * Luego se calcula el tamaño de las partes del texto cifrado
 * (la longitud total dividida entre la clave) en la variable parts.
 * Después se inicia un bucle for que recorre las columnas de la tabla,
 * y para cada una de ellas se extrae una subcadena del texto cifrado
 * que contiene los valores de esa columna y se guarda en el arreglo
 * decryptedValue_l.
 * En el siguiente bucle for se recorren las columnas
 * de la tabla de nuevo y se guardan los valores descifrados
 * de cada columna en la tabla. Cada valor descifrado se
 * toma del arreglo decryptedValue_l.
 * Finalmente, se recorre la tabla para obtener el texto descifrado,
 * concatenando cada valor de la tabla en orden de izquierda a
 * derecha y de arriba hacia abajo. El resultado se guarda en la variable decryptedText_l.
 * Por último, se llama al método setDecryptedValue()
 * para establecer el valor del texto descifrado en la instancia de la clase.
 */
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
