#pragma once
#include "Abstract\CleanUp.h"

class CStackToTreeAddTree :
	public CCleanUp
{
	virtual void* apply(void* aDataBus)
	{
		void* vp = aDataBus;

		vector<vector<bool>*>* pDoneFlagTripper =
			reinterpret_cast<vector<vector<bool>*>*>(vp);

		vector<bool>* bufflag = new vector<bool>();
		bufflag = pDoneFlagTripper->at(IDX_OF_DONE_FLAG);

		bufflag->at(IDX_OF_DONE_INTERPRET_SUBFLAG_HELP) = false;

		vector<vector<CNode<string, float>*>*>* pStackTree =
			reinterpret_cast<vector<vector<CNode<string, float>*>*>*>(vp);

		vector<CNode<string, float>*>* pImmutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(vp);

		CNode<string, float>* immutableTree = new CNode<string, float>();
		immutableTree = pStackTree->at(IDX_OF_STACK_TREE_HELP)->back();

		pImmutableTree->at(IDX_OF_AdditionalTree) = immutableTree;

		CNode<string, float>* retVal = new CNode<string, float>();
		retVal = pImmutableTree->at(IDX_OF_AdditionalTree);

		return retVal;
	}
};

