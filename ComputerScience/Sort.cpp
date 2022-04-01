#include "Sort.h"
#include <iostream>
#include <time.h>  
using std::cout;
using std::endl;

void Sort::bubbleSort(LinkedList& list) {
	const int listSize = list.getSize();
	if (listSize == 0) {
		cout << "There is no item to sort" << endl;
	}
	else {
		int good = 0;
		while (good != listSize-1) {
			good = 0;
			for (int i = 0; i < listSize-1; i++) {
				if (list.at(i)->value > list.at(i + 1)->value) {
					swapValues(list.at(i), list.at(i + 1));
				}
				else {
					good++;
				}
			}
		}
	}
}

void Sort::selectionSort(LinkedList& list) {
	const int listSize = list.getSize();
	if (listSize == 0) {
		cout << "There is no item to sort" << endl;
	}
	else {
		for (int i = 0; i < listSize - 1; i++) {
			int minValue = list.at(i)->value;
			int indexSwap = i;
			for (int j = i; j < listSize; j++) {
				if (minValue > list.at(j)->value) {
					minValue = list.at(j)->value;
					indexSwap = j;
				}
			}
			if (list.at(i)->value != list.at(indexSwap)->value) {
				swapValues(list.at(i), list.at(indexSwap));
			}
		}
	}
}

void Sort::quickSort(LinkedList& list) {
	const int listSize = list.getSize();
	mixValues(list, listSize/2);
	quickPass(list, 0, listSize - 1);
}

void Sort::mergeSort(LinkedList& list) {
	divideThenMerge(list);
}

void Sort::swapValues(Node* a, Node* b) {
	int valueTemp = a->value;
	a->value = b->value;
	b->value = valueTemp;
}

int Sort::quickPass(LinkedList& list, int startIndex, int endIndex){
	const int listSize = list.getSize();
	int prevStartIndex = startIndex;
	int prevEndIndex = endIndex;
	int pivotValue = list.at(endIndex)->value;
	int indexCheck = 0;
	while (indexCheck != endIndex) {
		if (list.at(indexCheck)->value > pivotValue) {
			if (endIndex - indexCheck > 1) {
				Node* higherValue = list.at(indexCheck);
				Node* prevNode = list.at(endIndex - 1);
				Node* pivot = list.at(endIndex);
				swapValues(higherValue, pivot);
				swapValues(higherValue, prevNode);
			}
			else {
				Node* higherValue = list.at(indexCheck);
				Node* pivot = list.at(endIndex);
				swapValues(higherValue, pivot);
			}
			endIndex--;
		}
		else { indexCheck++; }
	}
	if (prevEndIndex != endIndex) {
		if (endIndex - prevStartIndex > 1) {
			quickPass(list, prevStartIndex, endIndex - 1);
		}
		if (prevEndIndex - endIndex > 1) {
			quickPass(list, endIndex + 1, prevEndIndex);
		}
	}

	return endIndex;
}

void Sort::mixValues(LinkedList& list, int it) {
	srand(time(NULL));
	const int listSize = list.getSize();
	for (int i = 0; i < it; i++) {
		int index01 = rand() % listSize;
		int index02 = rand() % listSize;
		swapValues(list.at(index01), list.at(index02));
	}
}

void Sort::divideThenMerge(LinkedList& list) {
	//divide
	const int listSize = list.getSize();
	const int indMedian = listSize / 2;
	LinkedList list01;
	for (int i = 0; i < indMedian; i++) {
		list01.add(list.at(i)->value);
	}
	LinkedList list02;
	for (int i = indMedian; i < listSize; i++) {
		list02.add(list.at(i)->value);
	}
	if (list01.getSize() > 1) {
		divideThenMerge(list01);
	}
	if (list02.getSize() > 1) {
		divideThenMerge(list02);
	}

	//merge
	int ind01 = 0;
	int ind02 = 0;
	int itemSort = 0;
	while (itemSort < listSize) {
		if (list01.getSize() != ind01 && list02.getSize() != ind02) {
			if (list01.at(ind01)->value < list02.at(ind02)->value) {
				list.at(itemSort)->value = list01.at(ind01)->value;
				ind01++;
			}
			else {
				list.at(itemSort)->value = list02.at(ind02)->value;
				ind02++;
			}
			itemSort++;
		}
		else if (list01.getSize() == ind01){
			for (int i = ind02; i < list02.getSize(); i++) {
				list.at(itemSort)->value = list02.at(i)->value;
				itemSort++;
			}

		}
		else {
			for (int i = ind01; i < list01.getSize(); i++) {
				list.at(itemSort)->value = list01.at(i)->value;
				itemSort++;
			}
		}
	}

	//delete items in lists
	list01.clear();
	list02.clear();
}