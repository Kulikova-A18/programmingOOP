#include "stdafx.h"
#include "CppUnitTest.h"

#include "../programming language/programming language/Container.h"
#include "../programming language/programming language/Functional.h"
#include "../programming language/programming language/Language.h"
#include "../programming language/programming language/ObjectOriented.h"
#include "../programming language/programming language/Procedural.h"
#include "../programming language/programming language/Container.cpp"
#include "../programming language/programming language/Functional.cpp"
#include "../programming language/programming language/Language.cpp"
#include "../programming language/programming language/ObjectOriented.cpp"
#include "../programming language/programming language/Procedural.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ProceduralInputM) //проверка только вводимых данных. взяли процедурный
		{
			ifstream fin("In_Proc_Test.txt"); //значения лежат в самом файле
			if (fin.is_open())
			{
				// 1 0 2000 20000
				Procedural actual;
				actual.InData(fin);
				Procedural expected;
				expected.SetmAbstractDT(0);
				expected.SetmData(2000);
				expected.SetmRef(20000);
				Assert::AreEqual(expected.GetmAbstractDT(), actual.GetmAbstractDT(), L"Не совпадает");
				Assert::AreEqual(expected.GetmData(), actual.GetmData(), L"Не совпадает");
				Assert::AreEqual(expected.GetmRef(), actual.GetmRef(), L"Не совпадает");
			}
		}

		TEST_METHOD(ProceduralOutput)
		{
			ofstream fout("Out_Proc_Test_Act.txt"); //файл, куда запишем данные: 1 0 2020 20000
			//ofstream f("Out_Proc_Test_Exp.txt");
			Procedural act;
			act.SetmAbstractDT(0);
			act.SetmData(2000);
			act.SetmRef(20000);

			act.Out(fout); //запишем данные
			//act.Out(f);
			fout.close();
			ifstream fin_act("Out_Proc_Test_Act.txt");
			ifstream fin_exp("Out_Proc_Test_Exp.txt"); //проверяем на совпадение. при любом изменении выводимого файла произойдет ошибка
			string expected, actual;
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual, L"Не совпадает");

		}
		TEST_METHOD(ContainerStream) //проверка реализации контейнера
		{
			ifstream fin("ContainerOutputIn.txt");
			ofstream fout("ContainerOutput.txt");
			//ofstream f("ContainerOutputExp.txt");
			if (fin.is_open())
			{

				Container c;
				c.In(fin);
				c.Out(fout);

				//c.Out(f);

				fout.close();
			}
			ifstream fin_exp("ContainerOutputExp.txt");
			ifstream fin_act("ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual, L"Не совпадает");
		}
		TEST_METHOD(SortContainer) //проверка на сортированный контейнер
		{
			ifstream fin("ContainerOutputIn.txt");
			ofstream fout("SortContainerOutput.txt");
			//ofstream f ("SortContainerExp.txt");
			Container c;
			c.In(fin);
			c.Sort();
			c.Out(fout);

			//c.Out(f);

			fout.close();
			ifstream fin_exp("SortContainerExp.txt");
			ifstream fin_act("SortContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual, L"Не совпадает");
		}
		TEST_METHOD(OnlyProc) //вывод только процедурного типа 
		{
			ifstream fin("ContainerOutputIn.txt"); //читка
			ofstream fout("OnlyProcContainerOutput.txt"); //вывод
			//ofstream f("OnlyProcExp.txt");
			Container c;
			c.In(fin);
			c.OutProc(fout);
			//c.OutProc(f);
			fout.close();
			ifstream fin_exp("OnlyProcExp.txt");
			ifstream fin_act("OnlyProcContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual, L"Не совпадает");
		}
	};
}