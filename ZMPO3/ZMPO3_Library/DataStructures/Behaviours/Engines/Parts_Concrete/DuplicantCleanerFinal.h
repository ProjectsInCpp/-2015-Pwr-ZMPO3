#pragma once
#include "Abstract\CleanUp.h"
#include "Abstract\Utils\Tuple.h"

class CDuplicantCleanerFinal :
	public CCleanUp
{
	virtual void* apply(void* aDataBus)
	{
		void* vp = aDataBus;

		vector<CNode<string, float>*>* pMutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(vp);

		CNode<string, float>* buffMutableTree = new CNode<string, float>();
		buffMutableTree = pMutableTree->at(IDX_OF_MUTABLE_TREE);

		CNode<string, float>* retVal = new CNode<string, float>();
		retVal = buffMutableTree;

		return retVal;
	}
};

