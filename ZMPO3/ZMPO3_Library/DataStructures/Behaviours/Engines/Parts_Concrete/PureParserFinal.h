#pragma once
#include "Abstract\Parser.h"
#include "Abstract\Utils\Tuple.h"

class CPureParserFinal :public CParser
{
public:
	virtual void* apply(void* aDataBus)
	{
		//init
		void* vp = aDataBus;

		//DebugBreak();

		

		vector<CNode<string, float>*>* pImmutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(vp);

		CNode<string, float>* buffImmutableTree = new CNode<string, float>();
		buffImmutableTree = pImmutableTree->at(IDX_OF_IMMUTABLE_TREE);

		vector<CNode<string, float>*>* pMutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(vp);

		CNode<string, float>* buffMutableTree = new CNode<string, float>();
		buffMutableTree->keyLabel = buffImmutableTree->keyLabel;
		buffMutableTree->keyWage = buffImmutableTree->keyWage;
		buffMutableTree->nodes = buffImmutableTree->nodes;

		pMutableTree->at(IDX_OF_MUTABLE_TREE) = buffMutableTree;

		CNode<string, float>* buffAdditionalTree = new CNode<string, float>();
		buffAdditionalTree = pImmutableTree->at(IDX_OF_AdditionalTree);

		pImmutableTree->at(IDX_OF_AdditionalTree) = buffAdditionalTree;

		//buffMutableTree->keyLabel = buffImmutableTree->keyLabel;
		//buffMutableTree->keyWage = buffImmutableTree->keyWage;
		//buffMutableTree->nodes = buffImmutableTree->nodes;




		//buffMutableTree->pop_back();

		//cc
		return vp;
	};
};
