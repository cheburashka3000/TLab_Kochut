#include "TableCipher.h"
#include <iostream>
using namespace std;
void TableCipher::encrypt(const string& open_text)
{
	string OpenText = getValidOpenText(open_text);
	int strok;
	unsigned int k = 0;
	if (OpenText.length() % kluch == 0)
		strok = OpenText.length() / kluch;
	else 	strok = (OpenText.length() / kluch) + 1;
	int i = strok;
	int j = kluch;
	string sekret[i][j];
	for (i = 0; i < strok; i++)
		for (j = 0; j < kluch; j++) {
			if (k >= OpenText.length())
				sekret[i][j] = "";
			else sekret[i][j] = OpenText[k];
			k++;
		}
	cout << endl;
	for (j = kluch - 1; j >= 0; j--)
		for (i = 0; i < strok; i++)
			cout << sekret[i][j];
	cout << endl;
};
void TableCipher::decrypt(const string& cipher_text)
{
	string CipherText = getValidCipherText(cipher_text);
	int strok;
	unsigned int k = 0;
	if (CipherText.length() % kluch == 0)
		strok = CipherText.length() / kluch;
	else 	strok = (CipherText.length() / kluch) + 1;
	int i = strok;
	int j = kluch;
	int pysto = kluch - (CipherText.length() % kluch);
	string nesekret[i][j];
	for (j = kluch - 1; j >= 0; j--)
		for (i = 0; i < strok; i++) {
			if (i == (strok - 1) && pysto > 0) {
				nesekret[i][j] = "";
				pysto--;
			} else {
				nesekret[i][j] = CipherText[k];
				k++;
			}
		}
	for (i = 0; i < strok; i++)
		for (j = 0; j < kluch; j++)
			cout << nesekret[i][j];
	cout << endl;
	return otvet;
};
TableCipher::TableCipher(const int& key)
{
	kluch = getValidKey(key);
};
inline int TableCipher::getValidKey(const int & k)
{
	if (k < 0)
		throw cipher_error("The key cannot be less than 0");
	if (k == 0)
		throw cipher_error("The key cannot be 0");
	if (k == 1)
		throw cipher_error("The key cannot be 1");
	return k;
};
inline std::string TableCipher::getValidOpenText(const std::string & s)
{
	if (s.empty())
		throw cipher_error("Empty open text");
	if (s.length() < kluch) {
		cout << endl;
		throw cipher_error("Open text less key");
	}
	return s;
};
inline std::string TableCipher::getValidCipherText(const std::string & s)
{
	if (s.empty())
		throw cipher_error("Empty cipher text");
	if (s.length() < kluch)
		throw cipher_error("Cipher text less key");
	return s;
};
