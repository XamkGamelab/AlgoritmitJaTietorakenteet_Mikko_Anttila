#include <iostream>
#include <chrono>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <random>

void PrintArray(int* array, int size, int limit = -1)
{
    std::cout << "[";
    int count = (limit < 0 || limit > size) ? size : limit;
    for (int i = 0; i < count; i++) {
        std::cout << array[i];
        if (i < count - 1) std::cout << ", ";
    }

    if (count < size) std::cout << "...";
    std::cout << "]\n";
}

void ShellSort(int* array, int size)
{
    for (int gap = size / 2; gap > 0; gap = gap/2) {
        for (int i = gap; i < size; i += 1) {
            int temp = array[i];

            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void Merge(int* array, int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = array[middle + 1 + i];
    }

    int leftCount = 0;
    int rightCount = 0;
    int totalCount = left;
    
    while (leftCount < leftSize && rightCount < rightSize) {
        if (leftArray[leftCount] <= rightArray[rightCount]) {
            array[totalCount] = leftArray[leftCount];
            leftCount++;
        }
        else {
            array[totalCount] = rightArray[rightCount];
            rightCount++;
        }
        totalCount++;
    }
    while (leftCount < leftSize) {
        array[totalCount] = leftArray[leftCount];
        leftCount++;
        totalCount++;
    }

    while (rightCount < rightSize) {
        array[totalCount] = rightArray[rightCount];
        rightCount++;
        totalCount++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void MergeSort(int* array, int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;

        MergeSort(array, left, middle);
        MergeSort(array, middle + 1, right);
        Merge(array, left, middle, right);
    }
}

//Easier to use function using same parameters as ShellSort.
void MergeSorting(int* array, int size) { MergeSort(array, 0, size - 1); }

int* CreateRandomArray(int size)
{
    int* array = new int[size];
    std::unordered_set<int> usedNumbers;
    usedNumbers.reserve(size);

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, size * 10 - 1); //Generating a bigger range to not have it just be 1,2,3,4 for the end result. Better shows its truly random.

    for (int i = 0; i < size; i++) {
        int number = dist(rng);

        while (usedNumbers.count(number)) {
            number = dist(rng);
        }

        array[i] = number;
        usedNumbers.insert(number);
    }

    return array;
}

int* CreateOrderedArray(int size)
{
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}

int* CreateReversedArray(int size)
{
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = size - 1 - i;
    }
    return array;
}

int* CopyArray(int* array, int size)
{
    int* newArray = new int[size];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    return newArray;
}

void DoTest(int* array, int size, int displayNumbers)
{
    int* mergeArray = CopyArray(array, size);
    int* shellArray = CopyArray(array, size);
    int* stdsortArray = CopyArray(array, size);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //Ordered array

    std::cout << "\nShell sorting... ";
    begin = std::chrono::steady_clock::now();
    ShellSort(shellArray, size);
    end = std::chrono::steady_clock::now();
    std::cout << "Done!\n";
    std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds\n";
    std::cout << "Time per data item: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / size << " nanoseconds\n";

    std::cout << "\nMerge sorting... ";
    begin = std::chrono::steady_clock::now();
    MergeSorting(mergeArray, size);
    end = std::chrono::steady_clock::now();
    std::cout << "Done!\n";
    std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds\n";
    std::cout << "Time per data item: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / size << " nanoseconds\n";

    std::cout << "\nstd::sort sorting... ";
    begin = std::chrono::steady_clock::now();
    std::sort(stdsortArray, stdsortArray + size);
    end = std::chrono::steady_clock::now();
    std::cout << "Done!\n";
    std::cout << "Time Elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds\n";
    std::cout << "Time per data item: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / size << " nanoseconds\n";

    std::cout << "\nResults in order (only " << displayNumbers << " first numbers):\n";
    PrintArray(shellArray, size, displayNumbers);
    PrintArray(mergeArray, size, displayNumbers);
    PrintArray(stdsortArray, size, displayNumbers);
}

void TimedTest(int size, int displayNumbers)
{
    std::cout << "\n###########################################################\n";
    std::cout << "Generating ORDERED array with " << size << " elements... ";
    int* array = CreateOrderedArray(size);
    std::cout << "Done!\n";
    DoTest(array, size, displayNumbers);
    std::cout << "\n###########################################################\n";
    std::cout << "Generating REVERSED array with " << size << " elements... ";
    array = CreateReversedArray(size);
    std::cout << "Done!\n";
    DoTest(array, size, displayNumbers);
    std::cout << "\n###########################################################\n";
    std::cout << "Generating RANDOM array with " << size << " elements... ";
    array = CreateRandomArray(size);
	std::cout << "Done!\n";
    DoTest(array, size, displayNumbers);
}

int main()
{
    TimedTest(100, 10);
    TimedTest(10000, 10);
    TimedTest(1000000, 10);
    return 0;
}