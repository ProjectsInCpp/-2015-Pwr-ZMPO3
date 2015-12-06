#pragma once
#include "Abstract\Perform.h"
#include <string>

class CPTInterpreterAddTree : public CPerform
{
	virtual void* apply(void* aDataBus)
	{
#pragma region *************** CONSTANT_PART_TO_EXTRACT ******************************
		//init
		void* vp = aDataBus;

		vector<vector<char>*>* pChain = reinterpret_cast<vector<vector<char>*>*>(vp);
		vector<char>* outChain = new vector<char>();
		outChain = pChain->at(IDX_OF_CHAIN);

		vector<vector<char>*>* pFilter = reinterpret_cast<vector<vector<char>*>*>(vp);
		vector<char>* copyOfFilter = new vector<char>();
		copyOfFilter = pFilter->at(IDX_OF_FILTER1);

		vector<vector<CNode<string, float>*>*>* pStackTree =
			reinterpret_cast<vector<vector<CNode<string, float>*>*>*>(vp);

		vector<CNode<string, float>*>* buffStackTree = new vector<CNode<string, float>*>();
		buffStackTree = pStackTree->at(IDX_OF_STACK_TREE_HELP);

		vector<vector<bool>*>* pDoneFlagInterpret =
			reinterpret_cast<vector<vector<bool>*>*>(vp);

		vector<bool>* bufflag = new vector<bool>();
		bufflag = pDoneFlagInterpret->at(IDX_OF_DONE_FLAG);


#pragma endregion

		// take a erase first char
		char aFirstDeq = outChain->front();

		while (aFirstDeq == ' ' || aFirstDeq == ',')
		{
			aFirstDeq = outChain->front();
			if (aFirstDeq == ' ' || aFirstDeq == ',')
				outChain->erase(outChain->begin(), outChain->begin() + 1);
		}

# pragma region ********************** [ *********************************

		if (aFirstDeq == '[')
		{
			buffStackTree->push_back(new CNode<string, float>());
			outChain->erase(outChain->begin(), outChain->begin() + 1);
		}

# pragma endregion
#pragma region ********************** Chars To Label ******************
		string buffLabel = "";

		while (aFirstDeq != ',') {
			aFirstDeq = outChain->front();
			outChain->erase(outChain->begin(), outChain->begin() + 1);

			if (aFirstDeq != ',')
				buffLabel.push_back(aFirstDeq);
		};

		buffStackTree->back()->keyLabel = buffLabel;

		while (aFirstDeq == ' ' || aFirstDeq == ',')
		{
			aFirstDeq = outChain->front();
			if (aFirstDeq == ' ' || aFirstDeq == ',')
				outChain->erase(outChain->begin(), outChain->begin() + 1);
		}
# pragma endregion
#pragma region ********************** Chars To Wage ******************
		string buffMulti = "";

		while (NUtils::isNumber(aFirstDeq)) {

			if (aFirstDeq != ',')
				buffMulti.push_back(aFirstDeq);

			outChain->erase(outChain->begin(), outChain->begin() + 1);
			aFirstDeq = outChain->front();
		};

		string::size_type sz;
		float outMulti = stof(buffMulti, &sz);
		buffStackTree->back()->keyWage = outMulti;
#pragma endregion

		while (aFirstDeq == ' ' || aFirstDeq == ',')
		{
			aFirstDeq = outChain->front();
			if (aFirstDeq == ' ' || aFirstDeq == ',')
				outChain->erase(outChain->begin(), outChain->begin() + 1);
		}


#pragma region *************** CONSTANT_PART_TO_EXTRACT ******************************
		//perf


		//DebugBreak();

		bool end = false;
		outChain->erase(outChain->begin(), outChain->begin() + 1);

		while (aFirstDeq != '[' && end == false && outChain->size()!=0)
		{
			if (outChain->size() != 1)
			{
				CNode<string, float>* buffChild = NULL;
				CNode<string, float>* buffParent = NULL;

				if (aFirstDeq == '(')
				{
					aFirstDeq = outChain->front();

					if (aFirstDeq == ')')
					{
						aFirstDeq = outChain->front();
						outChain->erase(outChain->begin(), outChain->begin() + 1);

						buffChild = buffStackTree->back();
						buffStackTree->pop_back();

						if (buffStackTree->size() == 0)
						{
							buffParent = buffChild;
						}
						else
						{
							buffParent = buffStackTree->back();
							buffStackTree->pop_back();

							buffParent->PushChild(buffChild);
						}
					}
				}

				if (aFirstDeq == ')')
				{
					aFirstDeq = outChain->front();
					outChain->erase(outChain->begin(), outChain->begin() + 1);

					/*buffStackTree->push_back(buffParent);*/
				}

				if (aFirstDeq == ']')
				{
					if (outChain->size() != 0)
					{
						aFirstDeq = outChain->front();
						outChain->erase(outChain->begin(), outChain->begin() + 1);
					}
					if (buffChild == NULL && buffParent == NULL)
					{
						buffChild = buffStackTree->back();
						buffStackTree->pop_back();

						if (buffStackTree->size() == 0)
						{
							buffParent = buffChild;
						}
						else
						{
							buffParent = buffStackTree->back();
							buffStackTree->pop_back();

							buffParent->PushChild(buffChild);
						}
					}
					buffStackTree->push_back(buffParent);
					//aFirstDeq = outChain->front();
				}

				while (aFirstDeq == ' ' || aFirstDeq == ',')
				{
					aFirstDeq = outChain->front();
					if (aFirstDeq == ' ' || aFirstDeq == ',')
						outChain->erase(outChain->begin(), outChain->begin() + 1);
				}

				buffChild = NULL;
				buffParent = NULL;

				pChain->at(IDX_OF_CHAIN) = outChain;
				pFilter->at(IDX_OF_FILTER1) = copyOfFilter;
				pStackTree->at(IDX_OF_STACK_TREE_HELP) = buffStackTree;

				if (outChain->size() == 0)
				{
					bufflag->at(IDX_OF_DONE_INTERPRET_SUBFLAG_HELP) = true;

					pDoneFlagInterpret->at(IDX_OF_DONE_FLAG) = bufflag;
				}
			}
			else
			{
				end = true;

				if (outChain->size() == 1)
				{
					bufflag->at(IDX_OF_DONE_INTERPRET_SUBFLAG_HELP) = true;

					pDoneFlagInterpret->at(IDX_OF_DONE_FLAG) = bufflag;
				}
			}
		}

		char a;
		a = 1;
		//cc
		return vp;
#pragma endregion
	}
};
