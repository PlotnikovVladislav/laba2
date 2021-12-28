#pragma once
#include <iostream>
#include <string>
#include "Note.h"
#include "List.h"
using namespace std;

class Keeper {
private:
	List<Note> notes;
public:
	Keeper();
	~Keeper();

	void Print();

	Keeper& operator--();//удаление
	Keeper& operator++();//добавление

	void SearchPhone();
	void Sort();

};

