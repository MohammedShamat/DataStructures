#pragma once
#include<iostream>

using namespace std;
template<class T>

class clsLinkedList
{
private:
	int _size = 0;

public:

	class Node
	{

	public:
		T data = 0;
		Node* nextNode = NULL;
	};

	Node* _head;

	clsLinkedList()
	{
		_head = NULL;
	}

	bool IsEmpty()
	{
		return _head == NULL;
	}

	void InsertFirst(T newValue)
	{
		Node* newNode = new Node();
		newNode->data = newValue;

		if (IsEmpty())
		{
			newNode->nextNode = NULL;
			_head = newNode;
		}
		else
		{

			newNode->nextNode = _head;
			_head = newNode;
		}
		_size++;
	}

	void PrintList()
	{
		if (IsEmpty()) {
			cout << "List is Empty...";
			return;
		}
		Node* tempNode = _head;
		while (tempNode != NULL) {
			cout << tempNode->data << " ";
			tempNode = tempNode->nextNode;
		}
	}

	short Size()
	{
		return _size;
	}

	Node* Find(T value)
	{
		if (IsEmpty()) {
			cout << "List is Empty...";
			return NULL;
		}
		Node* tempNode = _head;
		while (tempNode != NULL) {
			if (tempNode->data == value)
			{
				return  tempNode;
			}
			tempNode = tempNode->nextNode;
		}

	}

	void InsertAfter(T newValue, T oldValue)
	{
		if (IsEmpty())
		{
			cout << "List is Empty...";
			return;
		}
		else if (Find(oldValue) == NULL)
		{
			cout << "\nThe Data not Found...\n";
			return;
		}
		Node* preNode = Find(oldValue);
		Node* newNode = new Node();
		newNode->data = newValue;
		newNode->nextNode = preNode->nextNode;
		preNode->nextNode = newNode;
		_size++;
	}

	void InsertAtEnd(T newValue)
	{
		if (IsEmpty()) {
			InsertFirst(newValue);
			return;
		}

		Node* newNode = new Node();
		newNode->data = newValue;
		newNode->nextNode = NULL;

		Node* tempNode = _head;
		while (tempNode->nextNode != NULL)
		{
			tempNode = tempNode->nextNode;
		}
		tempNode->nextNode = newNode;
		_size++;
		return;
	}

	void DeleteNode(T value)
	{
		if (IsEmpty()) {
			cout << "List is Empty...";
			return;
		}
		Node* current = _head;
		Node* prev = _head;

		if (current->data == value)
		{
			_head = current->nextNode;
			delete current;
			_size--;
			return;
		}

		while (current->data != value && current != NULL)
		{
			prev = current;
			current = current->nextNode;

		}

		prev->nextNode = current->nextNode;
		delete current;
		_size--;
	}

	void DeleteFirstNode()
	{
		if (IsEmpty()) {
			cout << "List is Empty...";
			return;
		}

		Node* current = _head;
		_head = current->nextNode;
		delete current;
		_size--;
		return;

	}

	void DeleteLastNode()
	{
		Node* current = _head;

		if (IsEmpty()) {
			cout << "List is Empty...";
			return;
		}

		if (current->nextNode == NULL)
		{
			_head = NULL;
			delete current;
			_size--;
			return;
		}

		Node* prev = _head;
		while (current->nextNode != NULL && current != NULL)
		{
			prev = current;
			current = current->nextNode;
		}
		prev->nextNode = NULL;
		delete current;
		_size--;
		return;
	}
};








