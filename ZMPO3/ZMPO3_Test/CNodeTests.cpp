#include "stdafx.h"
#include "CppUnitTest.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\DeleteParser.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\TreeChainParser.h"
#include <Windows.h>
#include "DataStructures\Behaviours\Engines\PackingTreeCompiler.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\PTInterpreter.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\Abstract\Utils\NUtils.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\StackToTreeModulator.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\Abstract\Utils\Tuple.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\Abstract\Utils\ChainAndFilterPackage.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZMPO2_3_Tests
{
	TEST_CLASS(TestCNode)
	{
	public:
		TEST_METHOD(Root_ProperTest)
		{
			string inStr =
				"[""Paleta"", 1, ([""karton A"", 10, ([""detal A"", 20, ()], [""detal B"", 10, ()])], [""karton B"", 4, ([""karton D"",5, ([""Detal D"", 6, ()])])])]";
			vector<char>* inMainChain = new vector<char>();

			int i = 0;
			while (inStr[i] != '\0')
				inMainChain->push_back(inStr[i++]);

			// act
			CInit *parser = new CDeleteParser();
			CPerform *interpreter = new CPTInterpreter();
			CCleanUp *demodulator = new CStackToTreeModulator();

			CChainAndFilterPackage* input = new CChainAndFilterPackage(inMainChain);

			CTemplateMethodBool *runner =
				new CPackingTreeCompiler(
					parser,
					interpreter,
					demodulator,
					input->inMainChain,
					input->inFilterChain
					);

			void* pIdx = runner->Run();

			CNode<string, float>* pTreeEnd =
				reinterpret_cast<CNode<string, float>*>(pIdx);

			string expectedLabel = "Paleta";
			float expectedWage = 1.0;
			
			string reachedLabel = pTreeEnd->keyLabel;
			float reachedWage = pTreeEnd->keyWage;

			bool resultLabel = reachedLabel == expectedLabel;
			bool resultWage = reachedWage == expectedWage;

			Assert::IsTrue(resultWage&&resultWage);

			delete parser;
			delete interpreter;
			delete demodulator;
			delete runner;
			delete inMainChain;
		}

		TEST_METHOD(ChildTreeLast_ProperTest)
		{
			// arrange
			string inStr =
				"[""Paleta"", 1, ([""karton A"", 10, ([""detal A"", 20, ()], [""detal B"", 10, ()])], [""karton B"", 4, ([""karton D"",5, ([""Detal D"", 6, ()])])])]";
			vector<char>* inMainChain = new vector<char>();

			int i = 0;
			while (inStr[i] != '\0')
				inMainChain->push_back(inStr[i++]);

			// act
			CInit *parser = new CDeleteParser();
			CPerform *interpreter = new CPTInterpreter();
			CCleanUp *demodulator = new CStackToTreeModulator();

			CChainAndFilterPackage* input = new CChainAndFilterPackage(inMainChain);

			CTemplateMethodBool *runner =
				new CPackingTreeCompiler(
					parser,
					interpreter,
					demodulator,
					input->inMainChain,
					input->inFilterChain
					);

			void* pIdx = runner->Run();
			
			// arrange
			CNode<string, float>* pTreeEnd =
				reinterpret_cast<CNode<string, float>*>(pIdx);

			CNode<string, float>* lastChild = pTreeEnd->nodes->back();

			string expectedLabel = "karton B";
			float expectedWage = 4.0;

			string reachedLabel = lastChild->keyLabel;
			float reachedWage = lastChild->keyWage;

			bool resultLabel = reachedLabel == expectedLabel;
			bool resultWage = reachedWage == expectedWage;

			Assert::IsTrue(resultWage&&resultWage);

			delete parser;
			delete interpreter;
			delete demodulator;
			delete runner;
			delete inMainChain;
		}

		TEST_METHOD(ChildTreeFirst_ProperTest)
		{
			// arrange
			string inStr =
				"[""Paleta"", 1, ([""karton A"", 10, ([""detal A"", 20, ()], [""detal B"", 10, ()])], [""karton B"", 4, ([""karton D"",5, ([""Detal D"", 6, ()])])])]";
			vector<char>* inMainChain = new vector<char>();

			int i = 0;
			while (inStr[i] != '\0')
				inMainChain->push_back(inStr[i++]);

			// act
			CInit *parser = new CDeleteParser();
			CPerform *interpreter = new CPTInterpreter();
			CCleanUp *demodulator = new CStackToTreeModulator();

			CChainAndFilterPackage* input = new CChainAndFilterPackage(inMainChain);

			CTemplateMethodBool *runner =
				new CPackingTreeCompiler(
					parser,
					interpreter,
					demodulator,
					input->inMainChain,
					input->inFilterChain
					);

			void* pIdx = runner->Run();

			CNode<string, float>* pTreeEnd =
				reinterpret_cast<CNode<string, float>*>(pIdx);

			pTreeEnd->PopBackAndCutWithParent();
			CNode<string, float>* firstChild = pTreeEnd->nodes->back();

			string expectedLabel = "karton A";
			float expectedWage = 10.0;

			string reachedLabel = firstChild->keyLabel;
			float reachedWage = firstChild->keyWage;

			bool resultLabel = reachedLabel == expectedLabel;
			bool resultWage = reachedWage == expectedWage;

			Assert::IsTrue(resultWage&&resultWage);

			delete parser;
			delete interpreter;
			delete demodulator;
			delete runner;
			delete inMainChain;
		}

		TEST_METHOD(ParentOfLastChild_ProperTest)
		{

			// arrange
			string inStr =
				"[""Paleta"", 1, ([""karton A"", 10, ([""detal A"", 20, ()], [""detal B"", 10, ()])], [""karton B"", 4, ([""karton D"",5, ([""Detal D"", 6, ()])])])]";
			vector<char>* inMainChain = new vector<char>();

			int i = 0;
			while (inStr[i] != '\0')
				inMainChain->push_back(inStr[i++]);


			// act
			CInit *parser = new CDeleteParser();
			CPerform *interpreter = new CPTInterpreter();
			CCleanUp *demodulator = new CStackToTreeModulator();

			CChainAndFilterPackage* input = new CChainAndFilterPackage(inMainChain);

			CTemplateMethodBool *runner =
				new CPackingTreeCompiler(
					parser,
					interpreter,
					demodulator,
					input->inMainChain,
					input->inFilterChain
					);

			void* pIdx = runner->Run();

			CNode<string, float>* pTreeEnd =
				reinterpret_cast<CNode<string, float>*>(pIdx);

			CNode<string, float>* lastChild = pTreeEnd->nodes->back();

			string expectedLabel = pTreeEnd->keyLabel;
			float expectedWage = pTreeEnd->keyWage;

			string reachedLabel = lastChild->parent->keyLabel;
			float reachedWage = lastChild->parent->keyWage;

			bool resultLabel = reachedLabel == expectedLabel;
			bool resultWage = reachedWage == expectedWage;

			Assert::IsTrue(resultWage&&resultWage);

			delete parser;
			delete interpreter;
			delete demodulator;
			delete runner;
			delete inMainChain;
		}

		TEST_METHOD(ParentAfterPopBackChild_ProperTest)
		{

			// arrange
			string inStr =
				"[""Paleta"", 1, ([""karton A"", 10, ([""detal A"", 20, ()], [""detal B"", 10, ()])], [""karton B"", 4, ([""karton D"",5, ([""Detal D"", 6, ()])])])]";
			vector<char>* inMainChain = new vector<char>();
			vector<char>* inFilterChain = new vector<char>();

			int i = 0;
			while (inStr[i] != '\0')
				inMainChain->push_back(inStr[i++]);

			// act
			CInit *parser = new CDeleteParser();
			CPerform *interpreter = new CPTInterpreter();
			CCleanUp *demodulator = new CStackToTreeModulator();

			CChainAndFilterPackage* input = new CChainAndFilterPackage(inMainChain);

			CTemplateMethodBool *runner =
				new CPackingTreeCompiler(
					parser,
					interpreter,
					demodulator,
					input->inMainChain,
					input->inFilterChain
					);

			void* pIdx = runner->Run();

			CNode<string, float>* pTreeEnd =
				reinterpret_cast<CNode<string, float>*>(pIdx);

			CNode<string, float>* lastChild = pTreeEnd->nodes->back();
			pTreeEnd->PopBackAndCutWithParent();

			CNode<string, float>* expectedParent = NULL;

			CNode<string, float>* reachedParent = lastChild->parent;

			bool resultParent = expectedParent == reachedParent;

			Assert::IsTrue(resultParent);

			delete parser;
			delete interpreter;
			delete demodulator;
			delete runner;
			delete inMainChain;
		}
	};
}