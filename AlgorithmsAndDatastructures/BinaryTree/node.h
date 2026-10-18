#pragma once
#pragma once
class Node
{
public:
	int data;
	Node* pLeft;
	Node* pRight;

	Node(int data) {
		this->data = data;
		this->pLeft = nullptr;
		this->pRight = nullptr;
	}
private:

};

