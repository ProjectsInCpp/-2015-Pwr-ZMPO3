#include "stdafx.h"
#include "CppUnitTest.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\DeleteParser.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\TreeChainParser.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\DeleteParserAddTree.h"
#include <Windows.h>
#include <set>
#include "DataStructures\Behaviours\Engines\Parts_Concrete\CompilerAddTree.h"
#include "DataStructures\Behaviours\Engines\PackingTreeCompiler.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\PackingTreeTripper.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\Abstract\Utils\NUtils.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\StackToTreeModulator.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\StackToTreeAddTree.h"
#include "DataStructures\Behaviours\Engines\PackingTreePrinter.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\PureParser.h"
#include "DataStructures\Behaviours\Engines\PackingTreeCompiler.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\PTInterpreter.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\TemplateMethodBoolHelp2.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\PTInterpreterAddTree.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\DuplicantCleaner.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\Abstract\Utils\Tuple.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\Abstract\Utils\ChainAndFilterPackage.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\DuplicantCleanerFinal.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\PackingTreeTripperFinal.h"
#include "DataStructures\Behaviours\Engines\Parts_Concrete\PureParserFinal.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZMPO2_3_Tests
{
	TEST_CLASS(TestTreeTripper)
	{
	public:
		TEST_METHOD(ReturnVectorStackOfElements_Proper)
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

			CTemplateMethodBool *compiler =
				new CPackingTreeCompiler(
					parser,
					interpreter,
					demodulator,
					input->inMainChain,
					input->inFilterChain
					);

			void* pIdx = compiler->Run();
			void* pointToReachedDataBus = compiler->GetDataBus();

			// ********************** TRIPPER ****************************************

			CInit *parserTrip = new CPureParser();
			CPerform *performTrip = new CPackingTreeTripper();
			CCleanUp *demodulatorTrip = new CDuplicantCleaner();

			CTemplateMethodBool *tripper =
				new CPackingTreePrinter(
					parserTrip,
					performTrip,
					demodulatorTrip,
					input->inMainChain,
					input->inFilterChain
					);

			bool result = true;
			tripper->SetDataBus(pointToReachedDataBus);		

			void* endList = tripper->Run();

			vector<CTuple*> expectedValues;
			expectedValues.push_back(new CTuple("karton A", 10));
			expectedValues.push_back(new CTuple("detal A", 200));
			expectedValues.push_back(new CTuple("detal B", 100));
			expectedValues.push_back(new CTuple("karton B", 4));
			expectedValues.push_back(new CTuple("karton D", 20));
			expectedValues.push_back(new CTuple("Detal D", 120));
			


			vector<CNode<string, float>*>* pImmutableTree =
				reinterpret_cast<vector<CNode<string, float>*>*>(tripper->GetDataBus());

			CNode<string, float>* immutableTree = new CNode<string, float>();
			immutableTree = pImmutableTree->at(IDX_OF_IMMUTABLE_TREE);

			CNode<string, float>* mutableTree = new CNode<string, float>();
			mutableTree = pImmutableTree->at(IDX_OF_MUTABLE_TREE);

			vector<CTuple*>* reachedValues = reinterpret_cast<vector<CTuple*>*>(endList);
			vector<bool> results;

			for (int i = 0; i < expectedValues.size(); i++)
			{
				CTuple* comparator = reachedValues->at(i);
				bool partRes = false;

				for (int j = 0; j < expectedValues.size(); j++)
					if (expectedValues.at(j)->label == comparator->label &&
						expectedValues.at(j)->wage == comparator->wage)
							partRes = true;

				results.push_back(partRes);
			}

			bool endResult = true;
			for (int i = 0; i < results.size(); i++)
			{
				endResult &= results.at(i);
			}

			Assert::IsTrue(endResult);

			delete parser;
			delete interpreter;
			delete demodulator;
			delete compiler;
			delete inMainChain;

			delete parserTrip;
			delete performTrip;
			delete demodulatorTrip;

			delete tripper;
			delete reachedValues;

			// cleanUp
			//delete main;
			//main = NULL;
		}

		TEST_METHOD(UnitCheckingOccurenceOfDuplicates_ProperTest1)
		{
			// arrange
			vector<CTuple*> expectedValues;
			vector<CTuple*>* endValues = new vector<CTuple*>();

			expectedValues.push_back(new CTuple("karton A", 10));
			expectedValues.push_back(new CTuple("detal A", 200));
			expectedValues.push_back(new CTuple("detal B", 100));
			expectedValues.push_back(new CTuple("karton B", 4));
			expectedValues.push_back(new CTuple("karton D", 20));
			expectedValues.push_back(new CTuple("Detal D", 120));

			//vector<CTuple*> endValues(expectedValues.size());

			set<CTuple*> s(expectedValues.begin(), expectedValues.end());
			expectedValues.assign(s.begin(), s.end());

			if (s.size() == expectedValues.size())
				endValues = &expectedValues;

			vector<bool> results;

			for (int i = 0; i < expectedValues.size(); i++)
			{
				CTuple* comparator = endValues->at(i);
				bool partRes = false;

				for (int j = 0; j < expectedValues.size(); j++)
					if (expectedValues.at(j)->label == comparator->label &&
						expectedValues.at(j)->wage == comparator->wage)
						partRes = true;

				results.push_back(partRes);
			}

			bool endResult = true;
			for (int i = 0; i < results.size(); i++)
			{
				endResult &= results.at(i);
			}

			Assert::IsTrue(endResult);

			//delete endValues;
		}

		TEST_METHOD(UnitMergingOccurenceOfDuplicates_ProperTest1)
		{
			// arrange
			vector<CTuple*> reachedValues;
			vector<CTuple*>* endValues = new vector<CTuple*>();

			reachedValues.push_back(new CTuple("karton A", 10));
			reachedValues.push_back(new CTuple("detal A", 200));
			reachedValues.push_back(new CTuple("detal A", 400));
			reachedValues.push_back(new CTuple("detal B", 100));
			reachedValues.push_back(new CTuple("karton B", 4));
			reachedValues.push_back(new CTuple("karton D", 20));
			reachedValues.push_back(new CTuple("Detal D", 120));

			vector<CTuple*> reachedValuesCopy(reachedValues);

			std::sort(reachedValues.begin(), reachedValues.begin() + reachedValues.size(),
				[&](CTuple* i,CTuple* j) {
				return (i->label > j->label);
			});

			//DebugBreak();

			for (int i = reachedValues.size()-1; i > 0;i--)
			{
				CTuple* suspect = reachedValuesCopy.back();

				CTuple* newValue = new CTuple();
				newValue->label = suspect->label;
				newValue->wage = suspect->wage;

				std::vector<CTuple*> buff(reachedValues.size());

				// copy only positive numbers:
				auto it = std::copy_if(
					reachedValues.begin(),
					reachedValues.end(),
					buff.begin(),
					[&](CTuple* i) {
					return (i->label== suspect->label);
				});

				if (buff.size() != 1)
				{
					string buffLbl = suspect->label;
					float buffWage = 0;
					int buffSize = 0;

					for (int j = 0; j < buff.size() && buff.at(j)!=NULL ;j++)
					{
						buffSize++;
						buffWage += buff.at(j)->wage;
					}

					for (int k = 0; k < buffSize;k++)
					{
						reachedValuesCopy.pop_back();
					}

					newValue->label = buffLbl;
					newValue->wage = buffWage;
				}

				endValues->push_back(newValue);

				buff.clear();
			}
			
			//DebugBreak();

			vector<bool> results;

			// VECTOR EQUALS **************************************

			// end

			vector<CTuple*> expectedValues;
			expectedValues.push_back(new CTuple("karton A", 10));
			expectedValues.push_back(new CTuple("detal A", 600));
			expectedValues.push_back(new CTuple("detal B", 100));
			expectedValues.push_back(new CTuple("karton B", 4));
			expectedValues.push_back(new CTuple("karton D", 20));
			expectedValues.push_back(new CTuple("Detal D", 120));

			for (int i = 0; i < endValues->size(); i++)
			{
				CTuple* pivot = endValues->at(i);
				bool partRes = false;

				for (int j = 0; j < expectedValues.size(); j++)
					if (expectedValues.at(j)->label == pivot->label &&
						expectedValues.at(j)->wage == pivot->wage)
						partRes = true;

				results.push_back(partRes);
			}

			bool endResult = true;
			for (int i = 0; i < results.size(); i++)
			{
				endResult &= results.at(i);
			}

			Assert::IsTrue(endResult);

			//delete endValues;
		}

		TEST_METHOD(AddingNodeProperTree_ProperTest1)
		{
#pragma region ****************************** CREATING AND INTERPRETING MAIN TREE **************************************
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

			CTemplateMethodBool *compiler =
				new CPackingTreeCompiler(
					parser,
					interpreter,
					demodulator,
					input->inMainChain,
					input->inFilterChain
					);

			void* pIdx = compiler->Run();
			void* pointToReachedDataBus = compiler->GetDataBus();

#pragma endregion

#pragma region ****************************** CREATING AND INTERPRETING ADD TREE **************************************

			// ************************ ADdder ***************************************

			string insecondString = "[""detal B"", 10, ()]";
			vector<char>* inSecondChain = new vector<char>();

			int j = 0;
			while (insecondString[j] != '\0')
				inSecondChain->push_back(insecondString[j++]);


			CInit *parserHelp = new CDeleteParserAddTree();
			CPerform *interpreterHelp = new CPTInterpreterAddTree();
			CCleanUp *demodulatorHelp  = new CStackToTreeAddTree();

			vector<vector<char>*>* pCharDataBus = reinterpret_cast<vector<vector<char>*>*>(pointToReachedDataBus);
			pCharDataBus->at(IDX_OF_CHAIN) = inSecondChain;
			//pointToReachedDataBus
			
			CChainAndFilterPackage* inputAdd = new CChainAndFilterPackage(inSecondChain);

			CTemplateMethodBool *compiler2 =
				new CCompilerAddTree(
					parserHelp,
					interpreterHelp,
					demodulatorHelp,
					inputAdd->inMainChain,
					inputAdd->inFilterChain
					);

			compiler2->SetDataBus(pointToReachedDataBus);

			void *outTree = compiler2->Run();
			void *withAddTreeBus = compiler2->GetDataBus();

			vector<CNode<string, float>*>* pAdditionalTree =
				reinterpret_cast<vector<CNode<string, float>*>*>(withAddTreeBus);

			CNode<string, float>* pImmutableTree2 =
				reinterpret_cast<CNode<string, float>*>(outTree);

			CNode<string, float>* immutableTree2 = new CNode<string, float>();
			immutableTree2 = pImmutableTree2;

			pAdditionalTree->at(IDX_OF_AdditionalTree) = pImmutableTree2;


			CNode<string, float>* firstTreeFromBus = new CNode<string, float>();
			firstTreeFromBus = pAdditionalTree->at(IDX_OF_IMMUTABLE_TREE);

			CNode<string, float>* secondTreeFromBus = new CNode<string, float>();
			secondTreeFromBus = pAdditionalTree->at(IDX_OF_AdditionalTree);

#pragma endregion
#pragma region ****************************** WALK ACROSS MAIN TREE, FIND GOOD LEVEL , INJECT NODE  **************************************
			// ********************** TRIPPER ****************************************

			CInit *parserTrip = new CPureParserFinal();
			CPerform *performTrip = new CPackingTreeTripperFinal();
			CCleanUp *demodulatorTrip = new CDuplicantCleanerFinal();


			CTemplateMethodBool *tripper =
				new CPackingTreePrinter(
					parserTrip,
					performTrip,
					demodulatorTrip,
					input->inMainChain,
					input->inFilterChain
					);

			bool result = true;


			vector<int> *sequenceOfWalking = new vector<int>();
			sequenceOfWalking->push_back(1);

			vector<vector<int>*>* pSequenceOfTrack =
				reinterpret_cast<vector<vector<int>*>* >(withAddTreeBus);

			pSequenceOfTrack->at(IDX_OF_SEQ_OF_TRACK) = sequenceOfWalking;

			tripper->SetDataBus(withAddTreeBus);

			//DebugBreak();

			tripper->Run();

			vector<CNode<string, float>*>* pImmutableTree =
				reinterpret_cast<vector<CNode<string, float>*>*>(tripper->GetDataBus());

#pragma endregion
#pragma region ****************************** TESTS ********************************************************************

			CNode<string, float>* mutableTreeFinal = new CNode<string, float>();
			mutableTreeFinal = pImmutableTree->at(IDX_OF_MUTABLE_TREE);

			string expectedLabel = "detal B";
			int expectedInt = 10;

			string reachedLabel = mutableTreeFinal->nodes->back()->nodes->back()->keyLabel;
			int reachedInt = mutableTreeFinal->nodes->back()->nodes->back()->keyWage;

			bool resultString = expectedLabel == reachedLabel;
			bool resultInt = expectedInt == reachedInt;

			Assert::IsTrue(resultString && resultString);

			delete parser;
			delete interpreter;
			delete demodulator;
			delete compiler;
			delete inMainChain;

			delete parserTrip;
			delete performTrip;
			delete demodulatorTrip;

			//delete tripper;
			//delete reachedValues;

			// cleanUp
			//delete main;
			//main = NULL;

#pragma endregion
		}

	};
}