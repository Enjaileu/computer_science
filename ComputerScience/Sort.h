#pragma once
#include "LinkedList.h"
class Sort
{
public:
	static void bubbleSort(LinkedList& list);
	static void selectionSort(LinkedList& list);
	static void quickSort(LinkedList& list);
	static void mergeSort(LinkedList& list);
	static void mixValues(LinkedList& list, int it);

private:
	static void swapValues(Node* a, Node* b);
	static int quickPass(LinkedList& list, int startIndex, int endIndex);
	static void divideThenMerge(LinkedList& list);
};

