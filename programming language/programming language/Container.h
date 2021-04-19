#pragma once
#include "Language.h"

class Container
{
	Container* Next;
	Language* L;

public:
	void In(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	void OutProc(ofstream& ofst);
	void Sort();
	void Swap(Container* first, Container* second);

	Container();

	~Container() {}
};