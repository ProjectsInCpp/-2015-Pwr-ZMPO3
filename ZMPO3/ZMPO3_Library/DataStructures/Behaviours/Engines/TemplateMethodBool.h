#pragma once

#include "Parts_Concrete\Abstract\Init.h"
#include "Parts_Concrete\Abstract\FunctionalClass.h"
#include "Parts_Concrete\Abstract\Perform.h"
#include "Parts_Concrete\Abstract\CleanUp.h"
#include "Parts_Concrete\Abstract\Utils\Tuple.h"
#include "Parts_Concrete\Abstract\Utils\NUtils.h"
#include <vector>
#include <Windows.h>

class CTemplateMethodBool
{
private:
	void* _inDataBus;

	bool _isDone;
	vector<int> *_inTrack;

	CFunctionalClass* _pInit;
	CFunctionalClass* _pPerform;
	CFunctionalClass* _pCleanUp;

protected:

	void Done(bool arg)
	{
		_isDone = arg;
	}
public:

	void* Run()
	{
		_inDataBus = _pInit->apply(_inDataBus);
		do
		{
			_inDataBus = _pPerform->apply(_inDataBus);

			vector<vector<bool>*>* pDoneFlagInterpret =
				reinterpret_cast<vector<vector<bool>*>*>(_inDataBus);

			bool isDone1 = pDoneFlagInterpret
				->at(IDX_OF_DONE_FLAG)
				->at(IDX_OF_DONE_INTERPRET_SUBFLAG);

			bool isDone2 = pDoneFlagInterpret
				->at(IDX_OF_DONE_FLAG)
				->at(IDX_OF_DONE_TRIP_SUBFLAG);

			bool isDone3 = pDoneFlagInterpret
				->at(IDX_OF_DONE_FLAG)
				->at(IDX_OF_DONE_INTERPRET_SUBFLAG_HELP);

			bool isDone4 = pDoneFlagInterpret
				->at(IDX_OF_DONE_FLAG)
				->at(IDX_OF_DONE_TRIP_SUBFLAG2);

			_isDone = isDone1^isDone2;

			if (_isDone == false)
			{
				if (isDone3)
				{
					_isDone = isDone3;
				}else
					if (isDone4)
					{
						_isDone = isDone4;
					}
			}


		} while (!_isDone);

		return _pCleanUp->apply(_inDataBus);
	}

	void* GetDataBus()
	{
		return _inDataBus;
	}

	void SetDataBus(void* dataBus)
	{
		_inDataBus = dataBus;
	}

	void SetTrack(vector<int> * track)
	{
		_inTrack = track;
	}

	void SetAdditinalTree(vector<char> *addTree)
	{

	}

	CTemplateMethodBool(CInit *pInit,
		CPerform *pPerform,
		CCleanUp* pCleanUp,
		vector<char>* inMainChain,
		vector<char>* inFilterChain)
	{
		vector<void*>* inDataBus = new vector<void*>();
		_inTrack = new vector<int>();

		_inDataBus = inDataBus;
		_isDone = false;
		_pInit = pInit;
		_pPerform = pPerform;
		_pCleanUp = pCleanUp;

		vector<vector<char>*>* pCharDataBus = reinterpret_cast<vector<vector<char>*>*>(_inDataBus);

		vector<vector<CNode<string, float>*>*>* pStackTree =
			reinterpret_cast<vector<vector<CNode<string, float>*>*>*>(_inDataBus);

		vector<CNode<string, float>*>* buffStackTree = new vector<CNode<string, float>*>();

		vector<CNode<string, float>*>* buffStackTreeHelp = new vector<CNode<string, float>*>();

		vector<vector<bool>*>* pDoneFlagInterpret =
			reinterpret_cast<vector<vector<bool>*>*>(_inDataBus);

		vector<bool>* bufflag = new vector<bool>();
		bufflag->push_back(false);

		vector<CNode<string, float>*>* pImmutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(_inDataBus);

		CNode<string, float>* immutableTree = new CNode<string, float>();

		vector<CNode<string, float>*>* pMmutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(_inDataBus);

		CNode<string, float>* mutableTree = new CNode<string, float>();

		vector<vector<CTuple*>*>* pSumVectorOfTree =
			reinterpret_cast<vector<vector<CTuple*>*>*>(_inDataBus);

		vector<CTuple*>* sumVectorOfTree = new vector<CTuple*>();

		vector<vector<bool>*>* pDoneFlagTrip =
			reinterpret_cast<vector<vector<bool>*>*>(_inDataBus);

		vector<vector<float>*>* pMultipler =
			reinterpret_cast<vector<vector<float>*>*>(_inDataBus);

		vector<float>* multipler = new vector<float>();

		bufflag->push_back(false);
		bufflag->push_back(false);
		bufflag->push_back(false);

		vector<char>* inMainChainCopy = new vector<char>();
		inMainChainCopy = inMainChain;

		vector<char>* inFilterChainCopy = new vector<char>();
		inFilterChainCopy = inFilterChain;

		vector<char>* inAdditionalChainCopy = new vector<char>();

		vector<CNode<string, float>*>* pAdditionalTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(_inDataBus);

		CNode<string, float>* additionalTree = new CNode<string, float>();

		vector<vector<int>*>* pSequenceOfTrack =
			reinterpret_cast<vector<vector<int>*>* >(_inDataBus);

		vector<int>* seqOfTrack = new vector<int>();

		//CHAIN 0
		//FILTER1 1
		//STACK_TREE 2
		//DONE_FLAG_INTERPRET 3
		//IMMUTABLE_TREE 4
		//MUTABLE_TREE 5
		//SUM_VECTOR_OF_TREE 6
		//MULTIPLER 7
		//ADDitionalChain 8
		//AdditionalTree 9
		//DONE_INTERPRET_SUBFLAG 0
		//DONE_TRIP_SUBFLAG 1
		//DONE_APPENDER_SUBFLAG 2

		pCharDataBus->push_back(inMainChainCopy); 				  //0
		pCharDataBus->push_back(inFilterChainCopy);				  //1
		pStackTree->push_back(buffStackTree);					  //2
		pDoneFlagInterpret->push_back(bufflag);					  //3
		pImmutableTree->push_back(immutableTree);				  //4
		pMmutableTree->push_back(mutableTree);					  //5
		pSumVectorOfTree->push_back(sumVectorOfTree);			  //6
		pMultipler->push_back(multipler);						  //7
		pCharDataBus->push_back(inAdditionalChainCopy);			  //8
		pAdditionalTree->push_back(additionalTree);				  //9
		pStackTree->push_back(buffStackTreeHelp);				  //10
		pSequenceOfTrack->push_back(seqOfTrack);
	}
};

