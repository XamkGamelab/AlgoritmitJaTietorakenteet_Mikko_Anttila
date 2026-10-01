#include "linkedlist.h"
#include <iostream>

bool LinkedList::IsEmpty()
{
    return this->pHead == nullptr;
}

bool LinkedList::Insert(int value)
{
    Node* newNode = new Node(value);
    newNode->pNext = this->pHead;
    this->pHead = newNode;
    return true;
}

bool LinkedList::InsertEnd(int value)
{
    if (IsEmpty()) {
        Node* newNode = new Node(value);
        this->pHead = newNode;
        return true;
    }
    else {
        Node* current = this->pHead;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        Node* newNode = new Node(value);
        current->pNext = newNode;
        return true;
    }
    return false;
}

bool LinkedList::Find(int value)
{
    Node* current = this->pHead;

    while (current != nullptr)
    {
        if (current->data == value)
            return true;

        current = current->pNext;
    }

    return false;
}

bool LinkedList::Delete(int value)
{
    Node* current = this->pHead;
    Node* previous = nullptr;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            if (previous == nullptr)
                this->pHead = current->pNext;
            else
                previous->pNext = current->pNext;

            delete current;
            return true;
        }

        previous = current;
        current = current->pNext;
    }

    return false;
}

void LinkedList::Print()
{
    Node* pTemp = this -> pHead;
    while (pTemp != nullptr)
    {
        std::cout << pTemp->data << " ";
        pTemp = pTemp->pNext;
    }
    std::cout << std::endl;
}

void LinkedList::Invert()
{

}
