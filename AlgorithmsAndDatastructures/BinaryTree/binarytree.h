#pragma once
#pragma once
#include "node.h"

class BinaryTree {
public:
	BinaryTree() {
		this->pRoot = nullptr;
	}

	bool IsEmpty();
	bool Insert(int value);
	void Print();
	bool Find(int value);
	int CountNodes();
	int CountLeaves();
	bool Delete(int value);

private:

	Node* pRoot;

};