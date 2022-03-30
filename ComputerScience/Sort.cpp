#include "Sort.h"
#include <iostream>
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
	if (listSize == 0) {
		cout << "There is no item to sort" << endl;
	}
	else {
		int indexPivot = quickPass(list);
		LinkedList list01;
		LinkedList list02;
		for (int i = 0; i < indexPivot; i++) {
			list01.add(list.at(i)->value);
		}
		for (int i = indexPivot; i < listSize; i++) {
			list02.add(list.at(i)->value);
		}
		list01.display();
		quickPass(list01);
		list01.display();
		//quickPass(list02);
	}
	
		

}

void Sort::swapValues(Node* a, Node* b) {
	int valueTemp = a->value;
	a->value = b->value;
	b->value = valueTemp;
}

int Sort::quickPass(LinkedList& list) {
	const int listSize = list.getSize();
	int pivotValue = list.at(listSize - 1)->value;
	int indexPivot = listSize - 1;
	int indexCheck = 0;
	while (indexCheck != indexPivot) {
		if (list.at(indexCheck)->value > pivotValue) {
			Node* higherValue = list.at(indexCheck);
			Node* prevNode = list.at(indexPivot - 1);
			Node* pivot = list.at(indexPivot);
			swapValues(higherValue, pivot);
			swapValues(higherValue, prevNode);
			indexPivot--;
		}
		else { indexCheck++; }
	}
	return indexPivot;
}