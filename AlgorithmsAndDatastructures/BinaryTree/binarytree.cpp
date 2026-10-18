#include "binarytree.h"
#include <iostream>

bool BinaryTree::IsEmpty()
{
    return this->pRoot == nullptr;
}

bool BinaryTree::Insert(int value)
{
    Node* newNode = new Node(value);
    
    if (IsEmpty())
    {
        pRoot = newNode;
        return true;
    }
    else
    {
        Node* current = pRoot;
        while (current != nullptr)
        {
            if (value < current->data)
            {
                if (current->pLeft == nullptr)
                {
                    current->pLeft = newNode;
                    return true;
                }
                current = current->pLeft;
            }
            else
            {
                if (current->pRight == nullptr)
                {
                    current->pRight = newNode;
                    return true;
                }
                current = current->pRight;
            }
        }
    }
    return false;
}

//Originally split these two, thinking I could use FindNode to help in Delete. At this point might as well just leave it here.
Node* FindNode(int value, Node* root) {
    Node* current = root;

    while (current != nullptr) {
        if (value == current->data) {
            return current;
        }
        else if (value < current->data) {
            current = current->pLeft;
        }
        else {
            current = current->pRight;
        }
    }
    return nullptr;
}

bool BinaryTree::Find(int value) {
	Node* Node = FindNode(value, this->pRoot);
    return Node ? true : false;
}


bool BinaryTree::Delete(int value) {
    Node* parent = nullptr;
    Node* current = pRoot;

    while (current && current->data != value) {
        parent = current;
        if (value < current->data) current = current->pLeft;
        else current = current->pRight;
    }
    if (!current) return false; //Can't find value to delete

    // No children (Good for them)
    if (current->pLeft == nullptr && current->pRight == nullptr) {
        if (parent == nullptr)
        {
            delete pRoot;
            pRoot = nullptr;
        }
        else {
            if (parent->pLeft == current) parent->pLeft = nullptr; //Have to delete references to the node since they don't automatically return null
            else parent->pRight = nullptr; //Have to delete references to the node since they don't automatically return null
            delete current;
        }
    }

    // One child
    else if (current->pLeft == nullptr || current->pRight == nullptr) {
        Node* child = current->pLeft ? current->pLeft : current->pRight;
        if (parent == nullptr) {
            pRoot = child;
        }
        else if (parent->pLeft == current) {
            parent->pLeft = child;
        }
        else {
            parent->pRight = child;
        }
        delete current;
    }

    // Two children
    // To not struggle with regenerating the entire tree,
    // we get the values closest child to "current" and delete that, replacing current's value with it
    else {
        Node* parent = current;
        Node* child = current->pRight;
        while (child->pLeft) {
            parent = child;
            child = child->pLeft;
        }
        current->data = child->data;
        if (parent->pLeft == child) parent->pLeft = child->pRight;
        else parent->pRight = child->pRight;
        delete child;
    }

    return true;
}

//Could be 1 function but then we'd always have to provide root. I dont want to do that so two functions
int CountNonRootNodes(Node* node) {
    if (node == nullptr) return 0;
    return 1 + CountNonRootNodes(node->pLeft) + CountNonRootNodes(node->pRight);
}
int BinaryTree::CountNodes() {
    if (this->pRoot == nullptr)
        return 0;

    return 1 + CountNonRootNodes(this->pRoot->pLeft) + CountNonRootNodes(this->pRoot->pRight);
}

int CountNonRootLeaves(Node* node) {
    if (node == nullptr) return 0;
    if (node->pLeft == nullptr && node->pRight == nullptr) return 1;
    return CountNonRootLeaves(node->pLeft) + CountNonRootLeaves(node->pRight);
}
int BinaryTree::CountLeaves() {
    if (this->pRoot == nullptr)
        return 0;
    return CountNonRootLeaves(this->pRoot);
}

// Source - https://stackoverflow.com/a/51730733
// Posted by Adrian Schneider, modified by community. See post 'Timeline' for change history
// Retrieved 2026-10-15, License - CC BY-SA 4.0
// Modified slightly for this implementation.

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");

        std::cout << node->data << std::endl;
        printBT(prefix + (isLeft ? "│  " : "   "), node->pLeft, true);
        printBT(prefix + (isLeft ? "│  " : "   "), node->pRight, false);
    }
}

void BinaryTree::Print()
{
    printBT("", this->pRoot, false);
}