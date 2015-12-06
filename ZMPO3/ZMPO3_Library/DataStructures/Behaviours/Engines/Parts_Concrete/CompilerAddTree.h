#pragma once
#include "D:\Clouds\OneDrive\GitHub\-2015-Pwr-ZMPO3\ZMPO3\ZMPO3_Library\DataStructures\Behaviours\Engines\TemplateMethodBool.h"

class CCompilerAddTree : public CTemplateMethodBool
{
public:
	CCompilerAddTree(CInit *pInit,
		CPerform *pPerform,
		CCleanUp* pCleanUp,
		vector<char>* inMainChain,
		vector<char>* inFilterChain)
		:CTemplateMethodBool(
			pInit,
			pPerform,
			pCleanUp,
			inMainChain,
			inFilterChain)
	{

	}
};

