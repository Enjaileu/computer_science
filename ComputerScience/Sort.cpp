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

void Sort::swapValues(Node* a, Node* b) {
	int valueTemp = a->value;
	a->value = b->value;
	b->value = valueTemp;
}

void Sort::quickSort(LinkedList& list){
	mixValues(list);
	const int listSize = list.getSize();
	quickPass(list, 0, listSize - 1);
	cout << "fini" << endl;
}

int Sort::quickPass(LinkedList& list, int startIndex, int endIndex){
	cout << "it" << endl;
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

void Sort::mixValues(LinkedList& list) {
	srand(time(NULL));
	const int listSize = list.getSize();
	for (int i = 0; i < 10; i++) {
		int index = rand() % listSize - 2;
		swapValues(list.at(index), list.at(index + 1));
	}
}