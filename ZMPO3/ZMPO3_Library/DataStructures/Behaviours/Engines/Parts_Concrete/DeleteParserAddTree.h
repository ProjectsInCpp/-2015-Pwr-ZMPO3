#pragma once
#include "Abstract\Parser.h"
#include <Windows.h>

class CDeleteParserAddTree :public CParser
{
public:
	virtual void* apply(void* aDataBus)
	{
		//init
		void* vp = aDataBus;

		vector<vector<char>*>* pChain = reinterpret_cast<vector<vector<char>*>*>(vp);
		vector<char>* updatedChain = pChain->at(IDX_OF_CHAIN);

		vector<vector<char>*>* pFilter = reinterpret_cast<vector<vector<char>*>*>(vp);
		vector<char>* copyOfFilter = new vector<char>();
		copyOfFilter = pFilter->at(IDX_OF_FILTER1);

		vector<vector<bool>*>* pDoneFlagInterpret =
			reinterpret_cast<vector<vector<bool>*>*>(vp);

		vector<bool>* bufflag = new vector<bool>();
		bufflag = pDoneFlagInterpret
			->at(IDX_OF_DONE_FLAG);

		vector<char>* outChain = new vector<char>();

		//perf
		std::for_each(
			updatedChain->begin(),
			updatedChain->end(),
			[&](char a)
		{if (NUtils::contains(a, *copyOfFilter))
			outChain->push_back(a);});

		pChain->at(IDX_OF_CHAIN) = outChain;
		pFilter->at(IDX_OF_FILTER1) = copyOfFilter;
		pDoneFlagInterpret->at(IDX_OF_DONE_FLAG) = bufflag;

		//cc
		return vp;
	};
};

