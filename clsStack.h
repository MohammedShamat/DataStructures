#include <iostream>
using namespace std;



template <class T>
class clsStack
{
private:
	short _size = 0;
public:

	class Node
	{
	public:
		T data;
		Node* nextNode = NULL;

	};


	Node* top;
	clsStack()
	{
		top = NULL;
	}

	bool IsEmpty()
	{
		return (top == NULL);
	}

	void Push(T newItem)
	{
		Node* newNode = new Node();
		newNode->data = newItem;
		if (IsEmpty())
		{
			newNode->nextNode = NULL;
		}
		else
		{
			newNode->nextNode = top;
		}
		top = newNode;
		_size++;
	}

	void Pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is Empty\n";
			return;
		}

		Node* temp = top;
		top = temp->nextNode;
		_size--;
		delete temp;
	}

	void Display()
	{
		if (IsEmpty())
		{
			cout << "Stack is Empty\n";
			return;
		}
		Node* temp = top;

		while (temp != NULL)
		{
			cout << temp->data << "-";
			temp = temp->nextNode;
		}

		delete temp;

	}


	int Top()
	{
		return top->data;
	}

	Node* Find(T value)
	{

		if (IsEmpty())
		{
			return NULL;
		}

		Node* tempNode = top;
		while (tempNode != NULL) {
			if (tempNode->data == value)
			{
				return tempNode;
			}
			tempNode = tempNode->nextNode;
		}

	}

	short Size()
	{
		return _size;
	}

};
