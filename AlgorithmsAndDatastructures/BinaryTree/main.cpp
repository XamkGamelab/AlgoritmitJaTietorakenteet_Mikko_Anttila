#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include "binarytree.h"
#include <windows.h>


int main()
{
	SetConsoleOutputCP(CP_UTF8); // Makes the fancy printing work


	std::cout << "Making a tree.\n";
	BinaryTree tree;
	tree.Insert(5);
	tree.Insert(10);
	tree.Insert(2);
	tree.Insert(7);
	tree.Insert(6);
	tree.Insert(8);
	tree.Insert(15);
	tree.Insert(12);
	tree.Insert(11);
	tree.Insert(14);
	tree.Print();
	std::cout << "Number of nodes: " << tree.CountNodes() << "\n";
	std::cout << "Number of leaves: " << tree.CountLeaves() << "\n";
	std::cout << "7 Exists in tree?: " << (tree.Find(7) ? "Yes" : "No") << "\n";
	std::cout << "\n\n";

	std::cout << "Deleting 5.\n";
	tree.Delete(5);
	tree.Print();
	std::cout << "\n\n";

	std::cout << "Deleting 7.\n";
	tree.Delete(7);
	tree.Print();
	std::cout << "\n\n";

	std::cout << "7 Exists in tree?: " << (tree.Find(7) ? "Yes" : "No") << "\n";
	std::cout << "Deleting 14.\n";
	tree.Delete(14);
	tree.Print();
	std::cout << "Number of nodes: " << tree.CountNodes() << "\n";
	std::cout << "Number of leaves: " << tree.CountLeaves() << "\n";
	return 0;
}