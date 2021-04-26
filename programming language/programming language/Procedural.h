#pragma once
#include "Language.h"
class Procedural : public Language
{
	int mAbstractDT;
public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод

	virtual void MultiMethod(Language* other, ofstream& ofst);
	virtual void MmProc(ofstream& ofst);
	virtual void MmOop(ofstream& ofst);

	Procedural() {} // создание без инициализации.
};