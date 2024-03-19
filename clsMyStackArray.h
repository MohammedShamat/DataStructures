#pragma once
#include <iostream>
#include "clsMyQueueArray.h"

template <class T>

class clsMyStackArray :public clsMyQueueArray <T>
{

public:

	void push(T Item)
	{
		clsMyQueueArray <T>::_MyList.InsertAtBeginning(Item);
	}

	T Top()
	{
		return clsMyQueueArray <T>::front();

	}

	T Bottom()
	{
		return clsMyQueueArray <T>::back();

	}

};


