#pragma once
class Node
{
public:
	int data;
	Node* pNext; //Pointer Next

	Node(int data) {
		this->data = data;
		this->pNext = nullptr;
	}
private:

};

