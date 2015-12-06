#pragma once

#include <vector>
#include <algorithm>
#include <string.h>
#include "D:\Clouds\OneDrive\GitHub\-2015-Pwr-ZMPO3\ZMPO3\ZMPO3_Library\DataStructures\Node.h"

using namespace std;

#define ASCII_BASE 48
#define END_SIGN_SIZE 1
#define MINUS_SIGN_SIZE 1
#define IDX_OF_CHAIN 0
#define IDX_OF_FILTER1 1
#define IDX_OF_STACK_TREE 2
#define IDX_OF_DONE_FLAG 3
#define IDX_OF_IMMUTABLE_TREE 4
#define IDX_OF_MUTABLE_TREE 5
#define IDX_OF_SUM_VECTOR_OF_TREE 6
#define IDX_OF_MULTIPLER_TRIPPER 7 

#define IDX_OF_ADDitionalChain 8
#define IDX_OF_AdditionalTree 9
#define IDX_OF_STACK_TREE_HELP 10
#define IDX_OF_SEQ_OF_TRACK 11

#define IDX_OF_DONE_INTERPRET_SUBFLAG 0
#define IDX_OF_DONE_TRIP_SUBFLAG 1
#define IDX_OF_DONE_INTERPRET_SUBFLAG_HELP 2
#define IDX_OF_DONE_TRIP_SUBFLAG2 3

#define NEUTRAL_ADD_SIGN '0'
#define END_LINE_SIGN '\0'
#define PROPER_SIGN_0 '0'
#define MINUS_SIGN '-'
#define TETRADE_SIZE '4'

//typedef vector<vector<char>> pVecMatrix;
typedef vector<CNode<string,float>> treeStack;

namespace NUtils
{
	char ToEqualsChar(int aValue0);
	int ToEqualsInt(char aValue0);
	char* hexaTobinArrUnit(char aInChar);
	char BinTradeToHexaUnit(char *aInChar);
	bool contains(char aVal, vector<char> aTerminalVals);
	bool isNumber(char aVal);
	//char* AddZM(CHeksa* aValUp, CHeksa* aValDown);
};

