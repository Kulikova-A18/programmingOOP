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

	virtual void MultiMethod(Language* other, ofstream& ofst);
	virtual void MmProc(ofstream& ofst);
	virtual void MmOop(ofstream& ofst);

	ObjectOriented() {};
};