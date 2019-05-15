#pragma once
#include <string>
#include <map>
using namespace std;
class TableCipher
{
private:
	int kluch;
	int getValidKey(const int & s);
	inline std::string getValidOpenText(const std::string & s);
	inline std::string getValidCipherText(const std::string & s);
public:
	TableCipher()=delete;
	TableCipher(const int& key);
	void encrypt(const string& open_text);
	void decrypt(const string& cipher_text);
};
class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg):std::invalid_argument(what_arg) {};
	explicit cipher_error (const char* what_arg):std::invalid_argument(what_arg) {};
};