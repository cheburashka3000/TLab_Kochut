/** @file
* @author Кочут Н.А.
* @version 0.9
* @date 2019
* @copyright ИБСТ ПГУ
* @warning Это учебный пример.
* @brief Заголовочный файл для модуля табличной перестановки.
*/
#pragma once
#include <string>
#include <map>
using namespace std;
/** @brief Шифрование методом табличной перестановки.
* @details Ключ устанавливается в конструкторе.
* Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
* @warning Реализация только для английского языка!
*/
class TableCipher
{
private:
int kluch;///< ключ.
/** @brief Валидация ключа
* @param [in] s Метод получает на вход целочисленный ключ.
* @details Метод проверяет:
* 	- ключ положительное число;
* 	- ключ равен 0;
* 	- ключ равен 1;
* А также переводит буквы из нижнего регистра в верхний.
* Происходит преобразование из широких строк в узкие.
* @return обработанную ключ-строку.
*/
int getValidKey(const int & s);
/** @brief Валидация открытого текста
* @param [in] s Метод получает открытый текст.
* [in] kluch Метод получает ключ.
* @details Метод проверяет:
* 	- пустая ли это строка;
* 	- больше ли ключ размера открытого текста.
* @return обработанный открытый текст.
*/
inline std::string getValidOpenText(const std::string & s, const unsigned int & kluch);
/** @brief Валидация зашифрованного текста
* @param [in] s Метод получает зашифрованный текст.
* [in] kluch Метод получает ключ.
* @details Метод проверяет:
* 	- пустая ли это строка;
* 	- больше ли ключ размера зашифрованного текста.
* @return обработанный зашифрованный текст.
*/
inline std::string getValidCipherText(const std::string & s, const unsigned int & kluch);
public:
/** @brief Конструктор без параметров.
* @details Удаляет элемент класса, если ему не был присвоен параметр.
*/
TableCipher()=delete;
/** @brief Конструктор для установки ключа.
* @param [in] key Метод получает на вход целочисленный ключ. Не должен быть меньше 2.
* @return ключ.
* @throw cipher_error, если ключ меньше 0, равен 0 или 1.
*/
TableCipher(const int& key);
/** @brief Зашифровывание
* @param [in] open_text Открытый текст. Не должен быть пустой строкой.
* @return зашифрованную строку.
* @throw cipher_error, если текст пустой или ключ больше длины текста.
*/
string encrypt(const string& open_text);
/** @brief Расшифровывание
* @param [in] cipher_text Зашифрованный текст. Не должен быть пустой строкой.
* @return открытый текст.
* @throw cipher_error, если текст пустой или ключ больше длины текста.
*/
string decrypt(const string& cipher_text);
};
/** @brief Обработчик ошибок.
*/
class cipher_error: public std::invalid_argument
{
public:
explicit cipher_error (const std::string& what_arg):std::invalid_argument(what_arg) {};
explicit cipher_error (const char* what_arg):std::invalid_argument(what_arg) {};
};
