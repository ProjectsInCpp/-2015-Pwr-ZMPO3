#pragma once
#include <vector>
#include <string>

using namespace std;

class CChainAndFilterPackage
{
public:
	vector<char>* inMainChain;
	vector<char>* inFilterChain;

	CChainAndFilterPackage(vector<char>* aChain)
	{

		inMainChain = new vector<char>();
		inMainChain = aChain;
		inFilterChain = new vector<char>();

		inFilterChain->push_back('(');
		inFilterChain->push_back(')');
		inFilterChain->push_back('[');
		inFilterChain->push_back(']');
		inFilterChain->push_back('0');
		inFilterChain->push_back('1');
		inFilterChain->push_back('2');
		inFilterChain->push_back('3');
		inFilterChain->push_back('4');
		inFilterChain->push_back('5');
		inFilterChain->push_back('6');
		inFilterChain->push_back('7');
		inFilterChain->push_back('8');
		inFilterChain->push_back('9');
		inFilterChain->push_back(',');
		inFilterChain->push_back('"');
		inFilterChain->push_back(' ');

		for (int i = 97; i < 123; i++)
		{
			inFilterChain->push_back(char(i));
			inFilterChain->push_back(char(toupper(i)));
		}
	}
	~CChainAndFilterPackage()
	{
		delete inMainChain;
		delete inFilterChain;
	}
};

