#include "Container.h"
void Container::MultiMethod(ofstream& ofst)
{
	if (this->Next != nullptr)
	{
		ofst << endl << "Multimethod." << endl;
		Container* first;
		Container* second;
		first = this;
		int i = 0;
		//second = c.Next;
		while (first->Next != this) //from 0 to n-1
		{
			second = first->Next;
			while (second != this) //from first to n
			{
				if (first->L != NULL && second->L != NULL)
				{
					ofst << i << ": ";

					first->L->MultiMethod(second->L, ofst);
					first->L->Out(ofst);
					ofst << endl;
					second->L->Out(ofst);
					ofst << endl;
					ofst << endl;
					i++;
				}
				second = second->Next;
			}

			first = first->Next;
		}
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}


}