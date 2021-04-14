#pragma once
#include "Functional.h"
void Functional::InData(ifstream &ifst)
{
	int inh;
	ifst >> inh;
	if (inh == 1 || inh == 0)
	{
		mLazyCalculations = inh;
	}
	else
	{
		mLazyCalculations = -1;
	}
	ifst >> inh;
	if (inh == 0)
	{
		mType = Functional::STRICT;
	}
	else if (inh == 1)
	{
		mType = Functional::DYNAMIC;
	}
	InCommon(ifst);
};
void Functional::Out(ofstream &ofst)
{
	if (mLazyCalculations == -1)
	{
		ofst << "Incorrect type of language." << endl;
		return;
	}
	ofst << "Functional." << endl << "lazy calculations: " << mLazyCalculations<<  endl<< "Typification: ";
	if (mType == 0)
	{
		ofst << "Strict";
	}
	else if (mType == 1)
	{
		ofst << " Dynamic";
	}
	else
	{
		ofst << "Incorrect type of language." << endl;
		return;
	}

	OutCommon(ofst);
};