#include "Procedural.h"
void Procedural::InData(ifstream &ifst)
{
	int inh;
	ifst >> inh;
	if (inh == 1 || inh == 0)
	{
		mAbstractDT = inh;
	}
	else
	{
		mAbstractDT = -1;
	}
	InCommon(ifst);
};
void Procedural::Out(ofstream &ofst)
{
	if (mAbstractDT == -1)
	{
		ofst << "Incorrect type of language." << endl;
		return;
	}
	ofst << "Procedural" << endl<< "Abstrat data type: " <<  mAbstractDT<< endl;
	OutCommon(ofst);
};
void Procedural::OutProc(ofstream& ofst)
{
	Out(ofst);
};