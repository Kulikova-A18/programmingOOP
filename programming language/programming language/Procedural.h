#pragma once
#include "Language.h"

class Procedural : public Language
{
	int mAbstractDT;

public:
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����

	Procedural() {} // �������� ��� �������������.

	int GetmAbstractDT() {
		return mAbstractDT;
	}
	void SetmAbstractDT(int mAbstractDT) {
		this->mAbstractDT = mAbstractDT;
	}
};