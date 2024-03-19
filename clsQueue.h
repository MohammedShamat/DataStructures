#pragma once
#include <iostream>

using namespace std;
template <class T>

class clsQueue
{
private:
	int _size = 0;
public:
	class Node
	{
	public:
		T data;
		Node* nextNode;
	};

	Node* front;
	Node* back;

	clsQueue()
	{
		front = NULL;
		back = NULL;
	}

	bool IsEmpty()
	{
		return (front == NULL && back == NULL);
	}

	void Push(T newItem)
	{
		Node* newNode = new Node();
		newNode->data = newItem;

		if (IsEmpty())
		{

			newNode->nextNode = NULL;
			front = newNode;
			back = newNode;
			_size++;
			return;
		}

		back->nextNode = newNode;
		back = newNode;
		_size++;
	}

	void Print()
	{
		if (IsEmpty())
		{

			return;
		}

		Node* temp = front;

		while (temp != NULL)
		{
			cout << temp->data << "-";
			temp = temp->nextNode;
		}

		delete temp;

	}

	void Pop()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty\n";
			return;
		}

		else if (front == back)
		{
			front = NULL;
			back = NULL;
			_size--;
		}

		else
		{
			Node* temp = front;
			front = temp->nextNode;
			_size--;
			delete temp;
		}

	}

	T Front()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty\n";
			return NULL;
		}
		return front->data;
	}

	T Back()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty\n";
			return NULL;
		}
		return back->data;
	}


	short Size()
	{
		return _size;
	}
};


