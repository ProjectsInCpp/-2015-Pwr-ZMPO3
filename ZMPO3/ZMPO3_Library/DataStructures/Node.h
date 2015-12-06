#pragma once
#include <vector>

using namespace std;

template<class K,class W>
class CNode
{
public:
	K keyLabel;
	W keyWage;
	vector<CNode<K, W>*>* nodes;
	CNode<K, W>* parent;

	CNode()
	{
		nodes = new vector<CNode<K, W>*>();
	}

	void PushChild(CNode<K, W>* child)
	{
		child->parent = this;
		this->nodes->push_back(child);
	}

	void PopBackAndCutWithParent()
	{		
		this->nodes->back()->parent = NULL;
		this->nodes->pop_back();
	}

	~CNode();
};

