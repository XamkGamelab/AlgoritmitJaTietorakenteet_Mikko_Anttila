#include <iostream>
#include <chrono>
#include "heap.h"

int main()
{
	srand(time(0));

	Heap InitialHeap(15);
	InitialHeap.insert(17);
	InitialHeap.insert(11);
	InitialHeap.insert(6);
	InitialHeap.insert(14);
	InitialHeap.insert(22);
	InitialHeap.insert(8);
	InitialHeap.insert(1);
	InitialHeap.insert(16);
	InitialHeap.insert(10);
	InitialHeap.insert(19);
	InitialHeap.insert(12);
	InitialHeap.insert(3);
	InitialHeap.insert(5);
	InitialHeap.insert(15);
	InitialHeap.insert(13);

	InitialHeap.print();

	std::cout << "\n\nSorting heap... \n";
	int* result = new int[15];

	for (int i = 0; i < 15; i++) {
		result[i] = InitialHeap.delMin();
		if (i != 0) std::cout << ", "; 
		std::cout << result[i];
	}
	std::cout << "\nDone!\n";


	std::cout << "\nCreating and filling and sorting heap of 100 thousand... ";
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	Heap Heap100k(100000);
	delete[] result;
	result = new int[100000];
	for (int i = 0; i < 100000; i++) {
		Heap100k.insert(rand() % 1000000001);
	}
	for (int i = 0; i < 100000; i++) {
		result[i] = Heap100k.delMin();
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Done!\n" << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms\n";

	std::cout << "\nCreating and filling and sorting heap of 1000 thousand... ";
	begin = std::chrono::steady_clock::now();
	Heap Heap1000k(1000000);
	delete[] result;
	result = new int[1000000];
	for (int i = 0; i < 1000000; i++) {
		Heap1000k.insert(rand() % 1000000001);
	}
	for (int i = 0; i < 1000000; i++) {
		result[i] = Heap1000k.delMin();
	}
	end = std::chrono::steady_clock::now();
	std::cout << "Done!\n" << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms\n";

	std::cout << "\nCreating and filling and sorting heap of 10000 thousand... ";
	begin = std::chrono::steady_clock::now();
	Heap Heap10000k(10000000);
	delete[] result;
	result = new int[10000000];
	for (int i = 0; i < 10000000; i++) {
		Heap10000k.insert(rand() % 1000000001);
	}
	for (int i = 0; i < 10000000; i++) {
		result[i] = Heap10000k.delMin();
	}
	end = std::chrono::steady_clock::now();
	std::cout << "Done!\n" << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms\n";

	// Not sure where / how I was supposed to answer the question in the assignment, so I will answer it here.
	// The performance measure should be O = n*log(n).
	// Admittedly needed to look this one up, but to my understanding "n*" is of course because we have to insert all the values into the heap,
	// and "log(n)" because the heap's maximum searches doubles in size with each element added, so the time complexity is logarithmic?

	return 0;
}