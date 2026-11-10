#pragma once

class Heap {
public:
	Heap(int size) {
        array = new int[size + 1];
		this->size = size;
        array[0] = 0;
    }
	
	~Heap() {
		delete[] array;
	}

	void insert(int value);
	int delMin();
	void print();
	int length() { return array[0]; }

private:
	int* array;
	int size;
};