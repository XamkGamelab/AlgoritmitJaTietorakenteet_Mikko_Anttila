#include "heap.h"
#include <iostream>

void Heap::insert(int value)
{
	if(length () >= size) {
		std::cout << "Heap is full, cannot insert more values.\n";
		return;
	}

	if (length() < 1) {
		array[1] = value;
		array[0]++;
		return;
	}

	int new_Index = length() + 1;
	array[new_Index] = value;
	array[0]++;

	int parent_Index = new_Index / 2;
	while (array[parent_Index] > array[new_Index] && new_Index > 1) {
		int tmp = array[parent_Index];
		array[parent_Index] = array[new_Index];
		array[new_Index] = tmp;

		new_Index = parent_Index;
		parent_Index = new_Index / 2;
	}
}

int Heap::delMin()
{
	if (length() == 0) return -1;

	int deletedValue = array[1];
	array[1] = array[length()];
	array[0]--;
	int new_Index = 1;
	int leftChild_Index = 2;
	int rightChild_Index = 3;

	while (leftChild_Index <= length()) {
		if (rightChild_Index <= length() && array[rightChild_Index] < array[leftChild_Index]) {
			leftChild_Index = rightChild_Index;
		}

		if (array[new_Index] > array[leftChild_Index]) {
			int tmp = array[new_Index];
			array[new_Index] = array[leftChild_Index];
			array[leftChild_Index] = tmp;

			new_Index = leftChild_Index;
		} else {
			break;
		}

		leftChild_Index = new_Index * 2;
		rightChild_Index = new_Index * 2 + 1;
	}
	return deletedValue;
}

void Heap::print()
{
	std::cout << "\nHeap: ";
	for (int i = 1; i <= this->length(); i++)
	{
		if (i != 1) std::cout << ", ";
		std::cout << this->array[i];
	}
}
