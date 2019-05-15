#include "TableCipher.h"
#include <iostream>
using namespace std;
void TableCipher::encrypt(string& open_text)
{
	int strok;
	unsigned int k = 0;
	if (open_text.length() % kluch == 0)
		strok = open_text.length() / kluch;
	else 	strok = (open_text.length() / kluch) + 1;
	int i = strok;
	int j = kluch;
	string sekret[i][j];
	for (i = 0; i < strok; i++)
		for (j = 0; j < kluch; j++) {
			if (k >= open_text.length())
				sekret[i][j] = "";
			else sekret[i][j] = open_text[k];
			k++;
		}
	for (j = kluch - 1; j >= 0; j--)
		for (i = 0; i < strok; i++)
			cout << sekret[i][j];
	return;
};
void TableCipher::decrypt(string& cipher_text)
{
	int strok;
	unsigned int k = 0;
	if (cipher_text.length() % kluch == 0)
		strok = cipher_text.length() / kluch;
	else 	strok = (cipher_text.length() / kluch) + 1;
	int i = strok;
	int j = kluch;
	int pysto = kluch - (cipher_text.length() % kluch);
	string nesekret[i][j];
	for (j = kluch - 1; j >= 0; j--)
		for (i = 0; i < strok; i++) {
			if (i == (strok - 1) && pysto > 0) {
				nesekret[i][j] = "";
				pysto--;
			} else {
				nesekret[i][j] = cipher_text[k];
				k++;
			}
		}
	for (i = 0; i < strok; i++)
		for (j = 0; j < kluch; j++)
			cout << nesekret[i][j];
	return;
};
TableCipher::TableCipher(const int& key)
{
	kluch = key;
};
