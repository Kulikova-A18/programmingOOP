#pragma once
#include "Language.h"
class ObjectOriented : public Language
{
	enum inheritance {
		SINGLE,
		MULTIPLE,
		INTERFACE
	};
	inheritance mInher;
public:
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	ObjectOriented() {};
};