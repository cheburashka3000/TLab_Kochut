#include <iostream>
#include "TableCipher.h"
using namespace std;
void checkEncrypt(const string& Text, const int key)
{
	try {
		TableCipher cipher(key);
		cout << "key = " << key << endl;
		cout << Text;
		cipher.encrypt(Text);
	} catch (const cipher_error & e) {
		cerr << "Error: " << e.what() << endl;
	}
}
void checkDecrypt(const string& Text, const int key)
{
	try {
		TableCipher cipher(key);
		cipher.decrypt(Text);
	} catch (const cipher_error & e) {
		cerr << "Error: " << e.what() << endl;
	}
}
int main(int argc, char **argv)
{
	checkEncrypt("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",2);
	checkDecrypt("HQIKRWFXUPOETEAYOTEUCBONOJMSVRHLZDG",2);
	checkEncrypt("The Quick Brown Fox Jumps Over The Lazy Dog",6);
	checkDecrypt("uroprLoQBFme D   uve eknJOhyhcw  TzTioxs ag",6);
	checkEncrypt("0123456789#!=",3);
	checkDecrypt("258!147#0369=",3);
	checkEncrypt("",5);
	checkDecrypt("",5);
	checkEncrypt("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",0);
	checkEncrypt("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",-7);
	return 0;
}
