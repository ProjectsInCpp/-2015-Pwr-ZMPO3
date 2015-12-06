#include "stdafx.h"
#include "CppUnitTest.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\DeleteParser.h"
#include <Windows.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZMPO2_2_Tests
{
	TEST_CLASS(TestCCompiler_Compiler)
	{
	public:
		//TEST_METHOD(ModulingVectorWithFilterVector_ProperTest1)
		//{
		//	// arrange
		//	vector<char> inMainChain;
		//	inMainChain.push_back('0');
		//	inMainChain.push_back('0');
		//	inMainChain.push_back('0');
		//	inMainChain.push_back('1');

		//	vector<char> expected;
		//	expected.push_back('0');
		//	expected.push_back('0');
		//	expected.push_back('0');
		//	expected.push_back('1');

		//	vector<char> filterChain;
		//	filterChain.push_back('0');
		//	filterChain.push_back('1');
		//	filterChain.push_back('.');

		//	vector<void*> totalVector();
		//	void* pTotVec = &totalVector;

		//	//totalVector->push_back(inMainChain);
		//	//totalVector->push_back(filterChain);

		//	// act
		//	CParser *main = new CDeleteParser();
		//	//vector<char> reached = main->apply(&totalVector).back();

		//	// assert
		//	bool result = std::equal(
		//		expected.begin(),
		//		expected.begin() + expected.size(),
		//		reached.begin());

		//	Assert::IsTrue(result);

		//	// cleanUp
		//	delete main;
		//	main = NULL;
		//}

		//TEST_METHOD(ModulingVectorWithFilterVector_ProperTest2)
		//{
		//	// arrange
		//	vector<char> inMainChain;
		//	inMainChain.push_back('0');
		//	inMainChain.push_back('2');
		//	inMainChain.push_back('1');
		//	inMainChain.push_back('1');

		//	vector<char> expected;
		//	expected.push_back('0');
		//	expected.push_back('1');
		//	expected.push_back('1');

		//	vector<char> filterChain;
		//	filterChain.push_back('0');
		//	filterChain.push_back('1');
		//	filterChain.push_back('.');

		//	//vecMatrix totalVector;
		//	totalVector.push_back(inMainChain);
		//	totalVector.push_back(filterChain);

		//	// act
		//	CParser *main = new CDeleteParser();
		//	//vector<char> reached = main->apply(&totalVector).at(0);

		//	// assert
		//	bool result = std::equal(
		//		expected.begin(),
		//		expected.begin() + expected.size(),
		//		reached.begin());

		//	Assert::IsTrue(result);

		//	// cleanUp
		//	delete main;
		//	main = NULL;
		//}

	};
}