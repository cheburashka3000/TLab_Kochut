#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
using namespace std;
bool isValid(const wstring& ws)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	for(auto c:ws)
		if (!isalpha(c,loc) || !isupper(c,loc))
			return false;
	return true;
}
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	wstring wkey;
	wstring wtext;
	unsigned wop;
	wcout<<"Cipher ready. Input key: ";
	wcin>>wkey;
	if (!isValid(wkey)) {
		wcerr<<"key not valid\n";
		return 1;
	}
	wcout<<"Key loaded\n";
	modAlphaCipher cipher(wkey);
	do {
		wcout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
		wcin>>wop;
		if (wop > 2) {
			cout<<"Illegal operation\n";
		} else if (wop >0) {
			cout<<"Cipher ready. Input text: ";
			wcin>>wtext;
			if (isValid(wtext)) {
				if (wop==1) {
					wcout<<"Encrypted text: "<<cipher.encrypt(wtext)<<endl;
				} else {
					wcout<<"Decrypted text: "<<cipher.decrypt(wtext)<<endl;
				}
			} else {
				wcout<<"Operation aborted: invalid text\n";
			}
		}
	} while (wop!=0);
	return 0;
}
