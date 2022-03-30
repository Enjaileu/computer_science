#pragma once
#include "LinkedList.h"
class Sort
{
public:
	static void bubbleSort(LinkedList& list);
	static void selectionSort(LinkedList& list);

private:
	static void swapValues(Node* a, Node* b);
};

