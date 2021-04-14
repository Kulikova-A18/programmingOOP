#include "Language.h"
#include "Procedural.h"
#include "ObjectOriented.h"
Language* Language::In(ifstream &ifst)
{
	int k,error1,error2;
	Language * lg;
	ifst >> k;
	switch (k)
	{
	case 1:
		lg = new Procedural();
		break;
	case 2:
		lg = new ObjectOriented();
		break;
	default:
		ifst >> error1 >> error2;
		return NULL;
	}
	lg->InData(ifst);
	return lg;
};

void Language::InCommon(ifstream &ifst)
{
	ifst >> mData;
};
void Language::OutCommon(ofstream &ofst)
{
	ofst << "Year of programming language: " << mData << endl;
};

