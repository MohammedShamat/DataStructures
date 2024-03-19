#pragma once
#include<iostream>

using namespace std;
template<class T>

class clsDblLinkedList
{

protected:

	int _size = 0;

public:
	class Node {

	public:
		T data;
		Node* nextNode = NULL;
		Node* prevNode = NULL;
	};

	Node* head;

	clsDblLinkedList()
	{
		head = NULL;
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void InsertAtBeginning(T newValue)
	{
		Node* newNode = new Node();
		newNode->data = newValue;
		newNode->nextNode = head;
		newNode->prevNode = NULL;
		if (!IsEmpty())
		{
			head->prevNode = newNode;

		}
		head = newNode;
		_size++;
	}

	void PrintNodeDetails(Node* head)
	{

		if (head->prevNode != NULL)
			cout << head->prevNode->data;
		else
			cout << "NULL";

		cout << " <--> " << head->data << " <--> ";

		if (head->nextNode != NULL)
			cout << head->nextNode->data << "\n";
		else
			cout << "NULL";

	}

	void PrintList()
	{
		Node* current = head;

		while (current != NULL) {
			cout << current->data<< " ";
			current = current->nextNode;
		}
		cout << "\n";
		delete current;
	}

	void PrintListWithDetails()
	{
		if (IsEmpty()) {
			cout << "List is Empty...\n\n";
			return;
		}

		Node* tempNode = head;
		while (tempNode != NULL) {
			PrintNodeDetails(tempNode);
			tempNode = tempNode->nextNode;

		}
	}

	Node* Find(T value)
	{
		if (IsEmpty()) {
			return NULL;
		}
		Node* tempNode = head;
		while (tempNode != NULL) {
			if (tempNode->data == value)
			{
				return  tempNode;
			}
			tempNode = tempNode->nextNode;
		}

	}

	void InsertAfter(Node*& node, T newValue)
	{
		if (IsEmpty())
		{
			cout << "List is Empty...\n\n";
			return;
		}

		else if (node == NULL)
		{
			cout << "\nThe Data not Found...\n";
			return;
		}
		Node* preNode = node;
		Node* newNode = new Node();
		newNode->nextNode = preNode->nextNode;
		newNode->prevNode = preNode;
		newNode->data = newValue;
		if (preNode->nextNode != NULL)
		{
			preNode->nextNode->prevNode = newNode;
		}

		preNode->nextNode = newNode;
		_size++;
	}

	void InsertAtEnd(T newValue)
	{
		if (IsEmpty()) {
			InsertAtBeginning(newValue);
			return;
		}

		Node* newNode = new Node();
		newNode->data = newValue;
		newNode->nextNode = NULL;

		Node* tempNode = head;
		while (tempNode->nextNode != NULL)
		{
			tempNode = tempNode->nextNode;
		}
		tempNode->nextNode = newNode;
		newNode->prevNode = tempNode;
		_size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (IsEmpty()) {
			cout << "List is Empty...\n\n";
			return;
		}

		if (head == NodeToDelete) {
			head = NodeToDelete->nextNode;
		}
		if (NodeToDelete->nextNode != NULL) {
			NodeToDelete->nextNode->prevNode = NodeToDelete->prevNode;
		}
		if (NodeToDelete->prevNode != NULL) {
			NodeToDelete->prevNode->nextNode = NodeToDelete->nextNode;
		}
		_size--;
		delete NodeToDelete;
	}

	void DeleteFirstNode()
	{
		if (IsEmpty()) {
			cout << "List is Empty...\n\n";
			return;
		}

		Node* current = head;
		head = current->nextNode;
		if (head != NULL)
		{
			head->prevNode = NULL;

		}
		delete current;
		_size--;
		return;
	}

	void DeleteLastNode()
	{
		Node* current = head;

		if (IsEmpty()) {
			cout << "List is Empty...";
			return;
		}
		if (current->nextNode == NULL)
		{
			head = NULL;
			delete current;
			_size--;
			return;

		}
		while (current->nextNode->nextNode != NULL)
		{
			current = current->nextNode;
		}
		Node* temp = current->nextNode;

		current->nextNode = NULL;
		_size--;
		delete temp;

	}

	short Size()
	{
		return _size;
	}

	void Clear()
	{
		while (_size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->prevNode;
			current->prevNode = current->nextNode;
			current->nextNode = temp;
			current = current->prevNode;
		}

		if (temp != nullptr) {
			head = temp->prevNode;
		}
	}

	Node* GetNode(short index)
	{
		short counter = 0;

		if (IsEmpty() || (index > _size - 1 || index < 0)) {
			return NULL;
		}

		Node* current = head;
		while ((current != NULL) && (current->nextNode != NULL)) {

			if (counter == index)
				break;

			current = current->nextNode;
			counter++;

		}

		return current;
	}

	T GetItem(short index)
	{
		Node* item = GetNode(index);

		if (item == NULL)
		{
			return NULL;
		}
		else
		{
			return item->data;
		}

	}

	bool UpdateItem(short index, T newValue)
	{
		Node* item = GetNode(index);
		if (item != NULL)
		{
			item->data = newValue;
			return true;
		}
		else
		{
			return false;
		}

	}

	bool InsertAfter(short index, T newValue)
	{
		Node* item = GetNode(index);
		if (item != NULL)
		{
			InsertAfter(item, newValue);
			return true;
		}
		else {
			return false;
		}
	}

};

