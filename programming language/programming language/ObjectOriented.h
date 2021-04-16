#pragma once

#include "Language.h"

class ObjectOriented : public Language {

public:

	enum inheritance {
		SINGLE,
		MULTIPLE,
		INTERFACE
	};

	void InData(vector<int>& tail); // ����
	void Out(ofstream& ofst); // �����

	ObjectOriented() {
	};

	inheritance GetmInher() { 
		return mInher; 
	}

	void SetmInher(inheritance mInher) { 
		this->mInher = mInher; 
	}

private:

	inheritance mInher;

};