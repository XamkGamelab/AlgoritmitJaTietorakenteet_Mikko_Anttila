#pragma once
#include "node.h"
#include <string>
template<typename T>

class Stack
{
public:
	Stack() { pTop = nullptr; }

	bool IsEmpty() { return pTop == nullptr; }

	void Push(T data)
	{
		Node<T>* newNode = new Node(data);
		newNode->pNext = pTop;
		pTop = newNode;
	};

	T Pop()
	{
		if (IsEmpty())
		{
			std::cout << "Stack is empty.\n";
			return T();
		}

		Node<T>* toBeDeleted = pTop;
		T tbdData = toBeDeleted->data;
		pTop = toBeDeleted->pNext;
		delete toBeDeleted;
		return tbdData;
	};

	T Top()
	{
		if (IsEmpty())
		{
			std::cout << "Stack is empty.\n";
			return T();
		}

		return pTop->data;
	};

private:
	Node<T>* pTop;
};