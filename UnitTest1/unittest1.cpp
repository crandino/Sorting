#include "stdafx.h"
#include "CppUnitTest.h"

#include "../DynArray.h"
#include <random>
#include <time.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSorting)
		{
			DynArray<int> test(5);
			DynArray<int> solution(5);

			test.pushBack(5);
			test.pushBack(4);
			test.pushBack(10);
			test.pushBack(8);
			test.pushBack(3);

			solution.pushBack(3);
			solution.pushBack(4);
			solution.pushBack(5);
			solution.pushBack(8);
			solution.pushBack(10);
			
			test.sort();

			for (unsigned int i = 0; i < test.getNumElements(); i++)
				Assert::AreEqual(test[i], solution[i]);

			DynArray<int> d;

			d.pushBack(5);
			d.pushBack(4);
			d.pushBack(10);
			d.pushBack(8);
			d.pushBack(3);
			d.pushBack(3);
			d.pushBack(-63);
			d.pushBack(22);
			d.pushBack(0);
			d.pushBack(16);
			d.pushBack(-9);
			d.pushBack(-6);
			d.pushBack(15);
			d.pushBack(1);
			d.pushBack(0);

			d.sort();

			for (unsigned int i = 0; i < d.getNumElements() - 1; i++)
				Assert::IsTrue(d[i] <= d[i+1]);

			// ---- Bubble optimized ----

			DynArray<int> d_opt;
			srand(time(NULL));

			for (unsigned int i = 0; i < 10000; i++)
				d_opt.pushBack(rand());
			
			d_opt.sort_opt();

			for (unsigned int i = 0; i < d_opt.getNumElements() - 1; i++)
				Assert::IsTrue(d_opt[i] <= d_opt[i + 1]);
		}

	};
}