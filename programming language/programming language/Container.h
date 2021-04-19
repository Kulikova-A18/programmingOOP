#pragma once
#include "Language.h"

class Container
{
	Container* Next;
	Language* L;

public:
	void In(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void Clear(); // ������� ���������� �� �����
	void OutProc(ofstream& ofst);
	void Sort();
	void Swap(Container* first, Container* second);

	Container();

	~Container() {}
};