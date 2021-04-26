#pragma once

#include "Functional.h"
#include <vector>

void Functional::InData(vector<int>& tail) {
	if (tail.size() < 2) {

		mIncorrectType = true;
		return;
	} else if (tail[0] == 1 || tail[0] == 0) {
		mLazyCalculations = tail[0];
		if (tail[1] == 1 || tail[1] == 0) {
			mType = static_cast<Functional::typification>(tail[1]);
		} else {
			mIncorrectType = true;
			return;
		}
	} else {
		mIncorrectType = true;
		return;
	}
	tail.erase(tail.begin() + 0, tail.begin() + 2);
	InCommon(tail);
};

void Functional::Out(ofstream& ofst) {
	ofst << "Functional." << endl << "lazy calculations: " 
		<< mLazyCalculations << endl << "Typification: ";
	if (mType == 0) {
		ofst << "Strict";
	} else if (mType == 1) {
		ofst << " Dynamic";
	}
	OutCommon(ofst);
};

void Functional::MultiMethod(Language* other, ofstream& ofst)
{
	other->MmFunc(ofst);
};
void Functional::MmProc(ofstream& ofst)
{
	ofst << "Functional and Procedural." << endl;

};
void Functional::MmOop(ofstream& ofst)
{
	ofst << "Functional and OOP." << endl;

};
void Functional::MmFunc(ofstream& ofst)
{
	ofst << "Functional and Functional." << endl;

};