#include <iostream>
#include "linkedlist.h"

int main()
{
    //Task 5.2
    std::cout << "Creating a list of 1-99 with Insert...";
    LinkedList list;
    for (int i = 1; i < 100; i++)
    {
        //InsertEnd to make it ordered because it bothers me if it isnt.
        list.InsertEnd(i);
    }
    std::cout << " Done!\n";
    list.Print();
    std::cout << "\n\n";

    std::cout << "Finding 99... " << (list.Find(99) ? "Found!\n" : "Not found.\n");
    std::cout << "Finding 66... " << (list.Find(66) ? "Found!\n" : "Not found.\n");
    std::cout << "Finding 100... " << (list.Find(100) ? "Found!\n" : "Not found.\n");

    std::cout << "Deleting 77... " << (list.Delete(77) ? "Success!\n" : "Failure.\n");
    std::cout << "Deleting 21... " << (list.Delete(21) ? "Success!\n" : "Failure.\n");
    std::cout << "Deleting -1... " << (list.Delete(-1) ? "Success!\n" : "Failure.\n");

    std::cout << "\nCurrent list:\n";
    list.Print();
    std::cout << "\n\n";
    std::cout << "Deleting the whole list... ";

    int i = 0;
    while (!list.IsEmpty())
    {
		list.Delete(i);
        i++;
    }
    std::cout << (list.IsEmpty() ? "Success!\n" : "Failure.\n");
    return 0;
}