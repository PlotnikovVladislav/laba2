#include "Keeper.h"

Keeper::Keeper() {
}

Keeper::~Keeper() {
}

void Keeper::Print() {
	if (notes.empty())
		cout << "List is empty" << endl;
	for (size_t i = 0; i < notes.size(); i++)
	{
		cout << "Name: " << notes[i].GetName() << endl
			<< "Phone: " << notes[i].GetPhone() << endl
			<< "Birth date: "
			<< notes[i].GetBday()[0] << "/"
			<< notes[i].GetBday()[1] << "/"
			<< notes[i].GetBday()[2] << endl;
	}
}

Keeper& Keeper::operator--() {
	if (notes.empty())
		cout << "List is empty" << endl;
	else {
		Keeper reserve;
		int cnt = 0;
		cout << "Want to remove?" << endl;
		for (size_t i = 0; i < notes.size(); i++)
			cout << i + 1 << ": " << notes[i].GetName() << endl;
		cout << ">>> ";
		while (cnt < 1 || cnt > notes.size())
			cin >> cnt;
		cnt -= 1;
		notes.pop(cnt);
	}
	return *this;
}

Keeper& Keeper::operator++() {
	string name, phone;
	int bday[3];
	cout << " Add object " << endl;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter phone number: " << endl;
	cin >> phone;
	cout << endl << "Enter birth date: " << endl;
	cin >> bday[0];
	cin >> bday[1];
	cin >> bday[2];
	notes.push_back(Note(name, phone, bday));
	return *this;
}


void Keeper::SearchPhone()
{
	if (notes.empty())
		cout << "List is empty" << endl;
	string phone;
	int flag = 0;
	cout << "Phone: " << endl;
	cin >> phone;
	cout << endl;
	for (size_t i = 0; i < notes.size(); i++)
	{
		if (notes[i].GetPhone() == phone) {
			cout << "Name: " << notes[i].GetName() << endl
				<< "Phone: " << notes[i].GetPhone() << endl
				<< "Birth date: "
				<< notes[i].GetBday()[0] << "/"
				<< notes[i].GetBday()[1] << "/"
				<< notes[i].GetBday()[2] << endl;
			flag = 1;
		}
	}
	if (flag == 0) cout << "Data not found";
}

void Keeper::Sort()
{
	notes.sort();
}
