#pragma once
#include "Language.h"
class Functional : public Language
{
public:
	Functional() {/**/ }
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
private:
	unsigned short int mLazyCalculations;
	enum typification
	{
		STRICT,
		DYNAMIC
	} mType;
};