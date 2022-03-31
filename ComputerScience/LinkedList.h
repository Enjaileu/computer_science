#pragma once
#include <iostream>
#include <vector>

struct Node {
	int value;
	Node* nextPtr;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(std::vector<int> values);

	//add node à la fin
	void add(int value);
	//insert node à index n
	void insert(int value, int index);
	//remove node à la fin
	void remove();
	//remove node à index n
	void remove(int n);
	//return ptr node à index n;
	Node* at(int n);
	//display ce que contient la liste
	void display();
	//clear all item in list
	void clear();

	//return listSize
	int getSize() { return listSize; }

private:
	Node* firstNode{ nullptr };
	Node* lastNode{nullptr};
	int listSize{0};
};

