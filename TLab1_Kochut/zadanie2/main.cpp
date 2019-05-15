#include <iostream>
#include <string>
#include "TableCipher.h"
using namespace std;
int main(int argc, char **argv)
{
	string stroka;
	double key;
	cout << "Введите ключ (целое число): ";
	cin >> key;
	if (key > 0 && (key - int(key) == 0))
		cout << "Ключ принят" << endl;
	else {
		cout << "Ключ введён неверно" << endl;
		return 1;
	}
	unsigned rejim;
	TableCipher cipher(key);
	do {
		cout << "Шифратор готов. Выберите операцию (0-выйти, 1-зашифровать, 2-рашифровать): ";
		cin >> rejim;
		if (rejim > 2) {
			cout << "Такой операции не существует!\n";
		} else if (rejim > 0) {
			cout << "Операция принята.\nПожалуйста, введите строку, которую хотите преобразовать: ";
			cin >> stroka;
			if (rejim==1) {
				cout << "Зашифрованный текст: ";
				cipher.encrypt(stroka);
				cout << endl;
			} else {
				cout << "Расшифрованный текст: ";
				cipher.decrypt(stroka);
				cout << endl;
			}
		}
		if (rejim == 0)
			cout << "Программа прекратила свою работу.\n";
	} while(rejim != 0);
}
