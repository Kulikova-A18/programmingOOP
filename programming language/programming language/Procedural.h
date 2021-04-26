#pragma once

#include "Language.h"

class Procedural : public Language {

	int mAbstractDT;
public:
	void InData(vector<int>& tail); // ввод
	void Out(ofstream& ofst); // вывод
	void OutProc(ofstream& ofst);

	void MultiMethod(Language* other, ofstream& ofst);
	void MmProc(ofstream& ofst);
	void MmOop(ofstream& ofst);
	void MmFunc(ofstream& ofst);

	//создание без инициализации.
	Procedural() {}
	int GetmAbstractDT() { 
		return mAbstractDT; 
	}
	void SetmAbstractDT(int mAbstractDT) { 
		this->mAbstractDT = mAbstractDT; 
	}
};