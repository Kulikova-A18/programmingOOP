#include "Container.h"

Container::Container() {
	Next = this;
	L = NULL;
}

//ввод
void Container::In(ifstream& ifst) {
	while (!ifst.eof()) {
		Container* temp = new Container;
		if ((this == this->Next) && (!ifst.tellg())) {
			this->L = Language::In(ifst);
		} else {
			Container* counter = this->Next;
			while (counter->Next != this) {
				//добавление в конец
				counter = counter->Next;

			}
			counter->Next = temp;
			temp->L = Language::In(ifst);
			temp->Next = this;
		}
	}
};

// вывод
void Container::Out(ofstream& ofst) {
	if (this->Next != nullptr) {
		ofst << "Container contains that elements:" << endl;
		Container* temp;
		temp = this;
		int i = 0;
		do {
			ofst << i << ": ";
			if (temp->L == NULL) {
				ofst << "Incorrect type of language!!!	" << endl;
				ofst << endl;
			} else {
				temp->L->Out(ofst);
				ofst << "Number of years since the year the language was created (... - now): " 
					<< temp->L->YearsPassed() << endl;
				ofst << endl;
			}
			temp = temp->Next;
			i++;
		} while (temp != this);
	} else {
		ofst << "Container is empty!" << endl;
	}
}

// вывод только процедуры
void Container::OutProc(ofstream& ofst) {
	if (this->Next != nullptr) {
		ofst << endl << "Only Procedural languages:" << endl;		
		Container* temp;
		temp = this;
		int i = 0;		
		do {
			ofst << i << ": ";
			if (temp->L == NULL) {
				ofst << endl;
			} else {
				temp->L->OutProc(ofst);
				ofst << endl;
			}
			temp = temp->Next;
			i++;
		} while (temp != this);
	} else {
		ofst << "Container is empty!" << endl;
	}
}; 

void Container::Clear() {
	Container* temp;
	temp = this->Next;
	while (temp != this) {
		this->Next = temp->Next;
		delete temp;
		temp = this->Next;
	}
	this->Next = nullptr;
};

void Container::Swap(Container* first, Container* second) {
	Language* temp;
	temp = first->L;
	first->L = second->L;
	second->L = temp;
};

void Container::Sort() {
	//если контейнер содержит 1 элемент, ничего не делать
	if (this == this->Next) {
		return;
	}
	Container* current = this;
	bool flag = false;
	Language* temp;
	//Сортировка пузырьком
	do {
		current = this;
		//если бы мы не отсортировали контейнер со сменными элементами
		flag = false;
		do {
			if (current->L->Compare(current->Next->L)) {
				Swap(current, current->Next);
				flag = true;
			}
			current = current->Next;
		} while (current->Next != this);
	} while (flag);
};