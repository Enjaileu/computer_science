#include "Sort.h"
#include <iostream>
using std::cout;
using std::endl;

void Sort::bubbleSort(LinkedList& list) {
	const int listSize = list.GetSize();
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
	const int listSize = list.GetSize();
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
