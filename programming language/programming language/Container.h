#pragma once
#include "Language.h"
class Container
{
	Container *Next;
	Language *L;

public:
	void In(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	void Clear(); // ������� ���������� �� �����

	void MultiMethod(ofstream& ofst);
	
	Container();

	~Container() { 
		/*Clear();*/ 
	}
};