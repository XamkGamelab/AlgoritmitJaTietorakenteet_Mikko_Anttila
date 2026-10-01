#pragma once
#include "node.h"

class LinkedList {
public:

	bool IsEmpty();
	bool Insert(int value);
	bool InsertEnd(int value);
	bool Find(int value);
	bool Delete(int value);
	void Print();
	void Invert();

	LinkedList(){
		this->pHead = nullptr;
	}

private:

	Node* pHead;

};