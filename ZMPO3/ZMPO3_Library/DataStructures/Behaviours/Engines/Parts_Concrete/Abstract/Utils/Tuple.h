#pragma once
#include <string>

using namespace std;

class CTuple
{
public:
	string label;
	float wage;

	CTuple()
	{
		this->label = "";
		this->wage = 0;
	}

	CTuple(string label, float wage)
	{
		this->label = label;
		this->wage = wage;
	}
};

