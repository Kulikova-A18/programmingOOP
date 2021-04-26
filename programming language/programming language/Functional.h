#pragma once

#include "Language.h"

class Functional : public Language {

public:
	enum typification {
		STRICT,
		DYNAMIC
	};
	Functional() {}	
	void InData(vector<int>& tail); // ����
	void Out(ofstream& ofst); // �����	

	void MultiMethod(Language* other, ofstream& ofst);
	void MmProc(ofstream& ofst);
	void MmOop(ofstream& ofst);
	void MmFunc(ofstream& ofst);

	typification GetmType() { 
		return mType; 
	};	
	void SetmType(typification mType) { 
		this->mType = mType; 
	};
	unsigned short int GetmLazyCalculations() { 
		return mLazyCalculations; 
	}
	void SetmLazyCalculations(unsigned short int mLazyCalculations) { 
		this->mLazyCalculations = mLazyCalculations;
	}
private:
	unsigned short int mLazyCalculations;
	typification mType;

};