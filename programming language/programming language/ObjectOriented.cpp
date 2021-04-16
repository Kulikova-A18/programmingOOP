#include "ObjectOriented.h"
#include <vector>

void ObjectOriented::InData(vector<int>& tail) {
	if (tail.size() < 1) {
		mIncorrectType = true;
		return;
	} else if (tail[0] == 1 || tail[0] == 0 || tail[0] == 2) {
		mInher = static_cast<ObjectOriented::inheritance>(tail[0]);
	} else {
		mIncorrectType = true;
		return;
	}
	tail.erase(tail.begin() + 0);
	InCommon(tail);
};

void ObjectOriented::Out(ofstream& ofst) {
	if (mInher == 0) {
		ofst << "Object-Oriented:" << endl 
			<< "inheritance: single";
	} else if (mInher == 1) {
		ofst << "Object-Oriented:" << endl 
			<< "inheritance: multiple";
	} else if (mInher == 2) {
		ofst << "Object-Oriented:" << endl 
			<< "inheritance: interface";
	}
	ofst << endl;
	OutCommon(ofst);
};