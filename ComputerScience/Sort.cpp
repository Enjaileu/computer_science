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
					switchValues(list.at(i), list.at(i + 1));
				}
				else {
					good++;
				}
			}
		}
	}

}

void Sort::switchValues(Node* a, Node* b) {
	int valueTemp = a->value;
	a->value = b->value;
	b->value = valueTemp;
}
