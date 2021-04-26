#pragma once

#include "Language.h"

class Procedural : public Language {

	int mAbstractDT;
public:
	void InData(vector<int>& tail); // ����
	void Out(ofstream& ofst); // �����
	void OutProc(ofstream& ofst);

	void MultiMethod(Language* other, ofstream& ofst);
	void MmProc(ofstream& ofst);
	void MmOop(ofstream& ofst);
	void MmFunc(ofstream& ofst);

	//�������� ��� �������������.
	Procedural() {}
	int GetmAbstractDT() { 
		return mAbstractDT; 
	}
	void SetmAbstractDT(int mAbstractDT) { 
		this->mAbstractDT = mAbstractDT; 
	}
};