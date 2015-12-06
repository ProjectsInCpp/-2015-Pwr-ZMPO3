#pragma once
#include "TemplateMethodBool.h"

class CPackingTreeCompilerHelp : public CTemplateMethodBool
{
public:
	CPackingTreeCompiler(CInit *pInit,
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

