#pragma once
#include "DeleteParser.h"

class CTreeChainParser :
	public CDeleteParser
{
public:
	virtual void* apply(void* aValue)
	{	
		return CDeleteParser::apply(aValue);;
	}
};

