#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){}

void LinkedList::add(int value) {
	Node* tempNode = new Node{value, nullptr};
	if (listSize == 0) {
		firstNode = tempNode;
	}
	else {
		lastNode->nextPtr = tempNode;
	}
	lastNode = tempNode;
	listSize++;
}

Node LinkedList::at(int n){
	if (n > listSize - 1) {
		cout << "There is no item at index " << n << endl;
		cout << "Use at function with indew between 0 & " << listSize - 1 << endl;
	}
	else {

	}
}

void LinkedList::insert(){}

void LinkedList::remove(){}

void LinkedList::remove(int n){}

void LinkedList::display() {
	cout << "Node list :" << endl;
	Node* tempNode = firstNode;
	while (tempNode != nullptr) {
		cout << tempNode->value << " - " << tempNode->nextPtr << endl;
		tempNode = tempNode->nextPtr;
	}
}
