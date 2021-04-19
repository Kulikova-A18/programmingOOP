#include "ObjectOriented.h"
void ObjectOriented::InData(ifstream &ifst)
{
	int inh;
	ifst >> inh;
	if (inh == 0)
	{
		mInher = ObjectOriented::SINGLE;
	}
	else if (inh == 1)
	{
		mInher = ObjectOriented::MULTIPLE;
	}
	else if (inh == 2)
	{
		mInher = ObjectOriented::INTERFACE;
	}
	InCommon(ifst);
};

void ObjectOriented::Out(ofstream &ofst)
{
	if (mInher == 0)
	{
		ofst << "Object-Oriented:" << endl << "inheritance: single";
	}
	else if (mInher == 1)
	{
		ofst << "Object-Oriented:" << endl << "inheritance: multiple";
	}
	else if (mInher == 2) {
		ofst << "Object-Oriented:" << endl << "inheritance: interface";
	}
	else
	{
		ofst << "Incorrect type of language." << endl;
		return;
	}
	OutCommon(ofst);

};