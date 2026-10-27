#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.1R/pr6.1r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testPR61R
{
	TEST_CLASS(testPR61R)
	{
	public:
		
            TEST_METHOD(Test3)
            {
                int s[23] = {
                    5, 4, 6, 7, 11, 11, 9, 12, 14, 11, 16,
                    6, 13, 4, 8, 15, 10, 12, 5, 14, 6, 7, 16
                };

                Assert::AreEqual(150, SumREK(s, 23));
            }
            TEST_METHOD(Test4)
            {
                int s[23] = {
                    5, 4, 6, 7, 8, 10, 9, 12, 14, 11, 16,
                    6, 13, 4, 8, 15, 10, 12, 5, 14, 6, 7, 16
                };

                Assert::AreEqual(15, CountREK(s, 23));
            }
	};
}
