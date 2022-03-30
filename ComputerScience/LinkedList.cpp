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

Node* LinkedList::at(int n){
	if (n > listSize - 1) {
		cout << "There is no item at index " << n << endl;
		cout << "Use at function with index between 0 & " << listSize - 1 << endl;
		Node node{ 0, nullptr };
		return &node;
	}
	else {
		Node* tempNode = firstNode;
		int i = 0;
		while (i < n) {
			tempNode = tempNode->nextPtr;
			i++;
		}
		return tempNode;
	}
}

void LinkedList::insert(int value, int index){
	if (index >= 0) {
		Node* prevNode;
		Node* node = new Node{ value, nullptr };
		Node* nextNode;
		if (index == 0) {
			nextNode = firstNode;
			node->nextPtr = nextNode;
			firstNode = node;
			listSize++;
		}
		else if (index > listSize) {
			for (int i = listSize; i < index; i++) {
				add(0);
			}
			add(value);
		}
		else if (index == listSize) {
			add(value);
		}
		else {
			prevNode = at(index - 1);
			nextNode = at(index);
			prevNode->nextPtr = node;
			node->nextPtr = nextNode;
			listSize++;
		}

	}
	else {
		cout << "Your index need to be positive" << endl;
	}
}

void LinkedList::remove(){
	if (listSize > 0) {
		Node* nodeToRemove = lastNode;
		lastNode = at(listSize - 2);
		delete(nodeToRemove);
		lastNode->nextPtr = nullptr;
		listSize--;
	}
	else {
		cout << "You can't remove item in linkedList because it is empty." << endl;
		cout << "Use function add(int value) to add an item in the list." << endl;
	}
}

void LinkedList::remove(int n){
	if (n < listSize) {
		Node* prevNode; 
		Node* nodeToRemove; 
		Node* nextNode; 
		if (n == 0) {
			nodeToRemove = firstNode;
			nextNode = nodeToRemove->nextPtr;
			delete(nodeToRemove);
			firstNode = nextNode;
		}
		else {
			prevNode = at(n - 1);
			nodeToRemove = prevNode->nextPtr;
			nextNode = nodeToRemove->nextPtr;
			delete(nodeToRemove);
			prevNode->nextPtr = nextNode;
		}
		listSize--;
	}
	else {
		cout << "There is no item at index " << n << endl;
		cout << "Use remove function with index between 0 & " << listSize - 1 << endl;
	}
}

void LinkedList::display() {
	cout << "Node list :" << endl;
	Node* tempNode = firstNode;
	while (tempNode != nullptr) {
		cout << tempNode->value << " - " << tempNode->nextPtr << endl;
		tempNode = tempNode->nextPtr;
	}
	cout << "List size = " << listSize << endl;
}
