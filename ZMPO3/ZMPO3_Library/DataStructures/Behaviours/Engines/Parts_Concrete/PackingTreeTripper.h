#pragma once
#include "Abstract\Perform.h"
#include "Abstract\Utils\Tuple.h"


class CPackingTreeTripper : public CPerform
{
	virtual void* apply(void* aDataBus)
	{
#pragma region *************** CONSTANT_PART_TO_EXTRACT ******************************

		void* vp = aDataBus;

		vector<CNode<string, float>*>* pMutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(vp);

		CNode<string, float>* buffMutableTree = new CNode<string, float>();
		buffMutableTree = pMutableTree->at(IDX_OF_MUTABLE_TREE);

		vector<vector<CTuple*>*>* pVectorOfTuples = reinterpret_cast<vector<vector<CTuple*>*>*>(vp);

		vector<CTuple*>* buffSummVector = new vector<CTuple*>();
		buffSummVector = pVectorOfTuples->at(IDX_OF_SUM_VECTOR_OF_TREE);

		CNode<string, float> *currentNode = new CNode<string, float>();
		currentNode = buffMutableTree;

		float traceMultipler = 1.0;
		string traceLabel = buffMutableTree->keyLabel;
		traceMultipler *= buffMutableTree->keyWage;

		string rootLabel = buffMutableTree->keyLabel;
		bool edge = false;

		while (buffMutableTree->nodes->size() != 0)
		{
			currentNode = buffMutableTree;

			do 
			{
				currentNode = currentNode->nodes->back();
				traceMultipler *= currentNode->keyWage;

				if (currentNode->nodes->size() == 0)
				{
					traceLabel = currentNode->keyLabel;
					currentNode = currentNode->parent;
					currentNode->PopBackAndCutWithParent();
					edge = true;
				}
			} while (edge!=true);
			
			buffSummVector->push_back(new CTuple(traceLabel, traceMultipler));
			traceLabel = "";
			traceMultipler = 1;
			edge = false;
		}

#pragma endregion

		pVectorOfTuples->at(IDX_OF_SUM_VECTOR_OF_TREE) = buffSummVector;

		vector<vector<bool>*>* pDoneFlagInterpret =
			reinterpret_cast<vector<vector<bool>*>*>(vp);

		vector<bool>* bufflag = new vector<bool>();
		bufflag = pDoneFlagInterpret->at(IDX_OF_DONE_FLAG);

		bufflag->at(IDX_OF_DONE_TRIP_SUBFLAG) = true;

		pDoneFlagInterpret->at(IDX_OF_DONE_FLAG) = bufflag;

		return vp;
	}
};