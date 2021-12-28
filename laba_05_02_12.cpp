/*
1. Стандартные потоки
Определить класс с именем NОТЕ, содержащий следующие поля:
● фамилия, имя;
● номер телефона;
● день рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа NОТЕ.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по датам дней рождения;
● вывод на экран информации о человеке, номер телефона которого
введен с клавиатуры;
● если такого нет, выдать на дисплей соответствующее сообщение.

*/
#include <iostream>
#include <fstream>
#include <string>
#include "Keeper.h"
#include "List.h"
#include "Note.h"
using namespace std;

void StringStream()
{
	ifstream f("test.txt");
	if (!f.good()) return;
	bool tere = false;
	char c;
	while (!f.eof()) {
		f >> c;
		tere = c == '-';
		if (!isspace(c) && tere) {
			cout << c;
			while (tere) {
				f >> c;
				if (f.eof()) break;
				if (c == '.' || c == '!' || c == '?')
					tere = false;
				cout << c;
				if (f.peek() == ' ')
					cout << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	Keeper list;
	int menu = 1;
	while (true) {
		cout << "menu" << endl;
		cout << "1. Add object" << endl;
		cout << "2. Print list" << endl;
		cout << "3. Search by phone" << endl;
		cout << "4. Delete object" << endl;
		cout << "5. Sort by birthday" << endl;
		cout << "6. String stream task" << endl;
		cout << "0. Exit" << endl;
		cout << ">>> ";
		cin >> menu;

		while (menu < 0 || menu > 6 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect entered, retry" << endl;
			cin >> menu;
		}

		try {

			switch (menu) {
			case 1: {
				++list;
				break; }
			case 2: {
				list.Print();
				break; }
			case 3: {
				list.SearchPhone();
				break; }
			case 4: {
				--list;
				break; }
			case 5: {
				list.Sort();
				break; }
			case 6: {
				StringStream();
				break; }

			case 0: {
				return 0; }

			}
		}	
		catch (int) {
			cout << "error" << endl;
		}
	}
}