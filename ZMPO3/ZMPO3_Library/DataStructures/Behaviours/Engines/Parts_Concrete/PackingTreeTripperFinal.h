#pragma once
#include "Abstract\Perform.h"
#include "Abstract\Utils\Tuple.h"


class CPackingTreeTripperFinal : public CPerform
{
	virtual void* apply(void* aDataBus)
	{
#pragma region *************** CONSTANT_PART_TO_EXTRACT ******************************

		void* vp = aDataBus;



		vector<CNode<string, float>*>* pMutableTree =
			reinterpret_cast<vector<CNode<string, float>*>*>(vp);

		vector<vector<int>*>* pSequenceOfTrack =
			reinterpret_cast<vector<vector<int>*>* >(vp);

		vector<int>* seqOfTrack = new vector<int>();
		seqOfTrack = pSequenceOfTrack->at(IDX_OF_SEQ_OF_TRACK);

		CNode<string, float>* buffMutableTree = new CNode<string, float>();
		buffMutableTree = pMutableTree->at(IDX_OF_MUTABLE_TREE);

		CNode<string, float>* buffNewTree = new CNode<string, float>();
		buffNewTree = pMutableTree->at(IDX_OF_AdditionalTree);

		vector<vector<CTuple*>*>* pVectorOfTuples = reinterpret_cast<vector<vector<CTuple*>*>*>(vp);

		CNode<string, float> *currentNode = new CNode<string, float>();
		currentNode = buffMutableTree;

		string rootLabel = buffMutableTree->keyLabel;
		bool edge = false;
		bool end = false;


		while (buffMutableTree->nodes->size() != 0 && end!=true )
		{
			currentNode = buffMutableTree;

			do
			{
				if (seqOfTrack->size() != 0)
				{
					int nextIdxOfChild = seqOfTrack->back();
					seqOfTrack->pop_back();

					currentNode = currentNode->nodes->at(nextIdxOfChild);
				}
				else
				{
					currentNode->PushChild(buffNewTree);
					edge = true;
					end = true;
				}

			} while (edge != true);

		}

#pragma endregion

		//pVectorOfTuples->at(IDX_OF_SUM_VECTOR_OF_TREE) = buffSummVector;

		vector<vector<bool>*>* pDoneFlagInterpret =
			reinterpret_cast<vector<vector<bool>*>*>(vp);

		vector<bool>* bufflag = new vector<bool>();
		bufflag = pDoneFlagInterpret->at(IDX_OF_DONE_FLAG);

		bufflag->at(IDX_OF_DONE_TRIP_SUBFLAG2) = true;

		pDoneFlagInterpret->at(IDX_OF_DONE_FLAG) = bufflag;

		return vp;
	}
};