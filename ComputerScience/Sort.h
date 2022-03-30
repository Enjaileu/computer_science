#pragma once
#include "LinkedList.h"
class Sort
{
public:
	static void bubbleSort(LinkedList& list);

private:
	static void switchValues(Node* a, Node* b);
};

