#pragma once
#include <fstream>
using namespace std;
class Language
{

public:
	static Language * In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ����
	virtual void Out(ofstream &ofst) = 0;
	void InCommon(ifstream &ifst);
	void OutCommon(ofstream &ofst);

	virtual void MultiMethod(Language* other, ofstream& ofst) = 0;
	virtual void MmProc(ofstream& ofst) = 0;
	virtual void MmOop(ofstream& ofst) = 0;

protected:
	short int mData;
};