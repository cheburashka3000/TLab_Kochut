#pragma once
#include <string>
using namespace std;
class TableCipher
{
private:
	int kluch;
public:
	TableCipher()=delete;
	TableCipher(const int& key);
	void encrypt(string& open_text);
	void decrypt(string& cipher_text);
};
