#include "LinkedList.h"
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

LinkedList::LinkedList(){}

LinkedList::LinkedList(vector<int> values){
	for (int value : values) {
		add(value);
	}
}

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
	if (listSize > 0) {
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
	else {
		cout << "The list is empty, you can't remove item" << endl;
	}
}

void LinkedList::display() {
	cout << "Node list :" << endl;
	if (listSize > 0) {
		Node* tempNode = firstNode;
		int index = 0;
		while (tempNode != nullptr) {
			cout << index << " || " << tempNode->value << " - " << tempNode->nextPtr << endl;
			tempNode = tempNode->nextPtr;
			index++;
		}
		cout << "List size = " << listSize << endl;
	}
	else {
		cout << "The list is empty." << endl;
	}
}

void LinkedList::clear() {
	const int size = listSize;
	for (int i = 0; i < size; i++) {
		remove();
	}
}
