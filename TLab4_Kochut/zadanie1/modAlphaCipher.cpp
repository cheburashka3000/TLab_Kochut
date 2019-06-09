/** @file
* @author Кочут Н.А.
* @version 1.0
* @date 2019
* @copyright ИБСТ ПГУ
* @warning Это учебный пример.
* @brief Заголовочный файл для модуля Gronsfeld для работы с текстами на русском языке.
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>
/** @brief Шифрование методом Гронсфельда на русском языке.
* @details Ключ устанавливается в конструкторе.
* Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
* @warning Реализация только для русского языка!
*/
class modAlphaCipher
{
private:
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";///< алфавит
	std::map <wchar_t,int> alphaNum;///< нумерованные буквы
	std::vector <int> key; ///< ключ.
	/** @brief Преобразование строка-вектор
* @param [in] ws Метод получает на вход строку
* @details Строку из русских букв преобразует в вектор.
* @return получившийся вектор.
*/
	std::vector <int> convert(const std::wstring& ws);
	/** @brief Преобразование вектор-строка.
* @param [in] v Метод получает на вход вектор.
* @details Вектор преобразует в строку из русских букв.
* Происходит преобразование из широких строк в узкие.
* @return получившуюся строку из русских букв.
*/
	std::string convert(const std::vector<int>& v);
	/** @brief Валидация ключа
* @param [in] ws Метод получает на вход ключ-строку.
* @details Метод проверяет:
* 	- есть ли какие-нибудь символы кроме русских букв;
* 	- есть ли строчные буквы;
* 	- пустая ли это строка.
* А также переводит буквы из нижнего регистра в верхний.
* Происходит преобразование из широких строк в узкие.
* @return обработанную ключ-строку.
*/
	std::wstring getValidKey(const std::wstring & ws);
	/** @brief Валидация открытого текста
* @param [in] ws Метод получает на вход открытый текст.
* @details Метод проверяет:
* 	- есть ли какие-нибудь символы кроме русских букв, если есть, то удаляет их;
* 	- пустая ли это строка.
* А также переводит буквы из нижнего регистра в верхний.
* @return обработанный открытый текст.
*/
	inline std::wstring getValidOpenText(const std::wstring & ws);
	/** @brief Валидация зашифрованного текста
* @param [in] ws Метод получает на вход зашифрованный текст.
* @details Метод проверяет:
* 	- пустая ли это строка;
* 	- есть ли какие-нибудь символы кроме прописных русских букв.
* Происходит преобразование из широких строк в узкие.
* @return обработанный зашифрованный текст.
*/
	inline std::wstring getValidCipherText(const std::wstring & ws);
public:
/** @brief Конструктор без параметров.
* @details Удаляет элемент класса, если ему не был присвоен параметр.
*/
	modAlphaCipher()=delete;
	/** @brief Конструктор для установки ключа.
* @param [in] skey Метод получает на вход ключ-строку. Не должен быть пустой строкой.
* Происходит преобразование из узких строк в широкие.
* Строчные символы автоматически преобразуются к прописным.
* Происходит преобразование строка-вектор.
* @return обработанную ключ-строку.
* @throw cipher_error, если ключ пустой или в ключе присутствуют символы, или ключ вырожденный.
*/
	modAlphaCipher(const std::string& skey);
	/** @brief Зашифровывание
* @param [in] open_text Открытый текст. Не должен быть пустой строкой.
* Происходит преобразование из узких строк в широкие.
* Строчные символы автоматически преобразуются к прописным.
* Все не буквы удаляются.
* @return зашифрованную строку.
* @throw cipher_error, если текст пустой.
*/
	std::string encrypt(const std::string& open_text);
	/** @brief Расшифровывание.
* @param [in] cipher_text Зашифрованный текст. Не должен быть пустой строкой.
* Происходит преобразование из узких строк в широкие.
* @return зашифрованную строку.
* @throw cipher_error, если текст пустой или содержит строчные символы, любые знаки.
*/
	std::string decrypt(const std::string& cipher_text);
	/** @brief Перевод из узкой строки в широкую.
* @param [in] s узкая строка.
* @return широкую строку.
*/
	std::wstring inhir(const std::string& s);
	/** @brief Перевод из широкой строки в узкую.
* @param [in] ws широкая строка.
* @return узкую строку.
*/
	std::string izhir(const std::wstring& ws);
};
/** @brief Обработчик ошибок.
*/
class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg):std::invalid_argument(what_arg) {};
	explicit cipher_error (const char* what_arg):std::invalid_argument(what_arg) {};
};
