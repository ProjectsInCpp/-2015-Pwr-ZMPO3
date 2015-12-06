#pragma once
#include "Abstract\CleanUp.h"

class CDuplicantCleaner :
	public CCleanUp
{
	virtual void* apply(void* aDataBus)
	{
		void* vp = aDataBus;

		vector<vector<CTuple*>*>* pVectorOfTuples = reinterpret_cast<vector<vector<CTuple*>*>*>(vp);

		vector<CTuple*>* buffSummVector = new vector<CTuple*>();
		buffSummVector = pVectorOfTuples->at(IDX_OF_SUM_VECTOR_OF_TREE);

		// arrange

		vector<CTuple*>* endValues = new vector<CTuple*>();

		vector<CTuple*> reachedValuesCopy(*buffSummVector);

		std::sort(buffSummVector->begin(), buffSummVector->begin() + buffSummVector->size(),
			[&](CTuple* i, CTuple* j) {
			return (i->label > j->label);
		});

		

		for (int i = buffSummVector->size() - 1; i > -1 && reachedValuesCopy.size()!=0;i--)
		{

			CTuple* suspect = reachedValuesCopy.back();

			CTuple* newValue = new CTuple();
			newValue->label = suspect->label;
			newValue->wage = suspect->wage;

			std::vector<CTuple*> buff(buffSummVector->size());

			// copy only positive numbers:
			auto it = std::copy_if(
				buffSummVector->begin(),
				buffSummVector->end(),
				buff.begin(),
				[&](CTuple* i) {
				return (i->label == suspect->label);
			});

			if (buff.size() != 1)
			{
				string buffLbl = suspect->label;
				float buffWage = 0;
				int buffSize = 0;

				for (int j = 0; j < buff.size() && buff.at(j) != NULL;j++)
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

		pVectorOfTuples->at(IDX_OF_SUM_VECTOR_OF_TREE) = endValues;
		vector<CTuple*>* retVal = new vector<CTuple*>();
		retVal = endValues;

		return retVal;
	}
};

