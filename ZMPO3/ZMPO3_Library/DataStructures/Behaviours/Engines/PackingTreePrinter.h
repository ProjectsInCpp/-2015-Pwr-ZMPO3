#pragma once
#include "TemplateMethodBool.h"


class CPackingTreePrinter : public CTemplateMethodBool
{
public:
	CPackingTreePrinter(CInit *pInit,
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

