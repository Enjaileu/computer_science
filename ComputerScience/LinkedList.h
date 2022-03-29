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

	//add node à la fin
	void add(int value);
	//insert node à index n
	void insert();
	//remove node à la fin
	void remove();
	//remove node à index n
	void remove(int n);
	//return node à index n;
	Node at(int n);
	//display ce que contient la liste
	void display();

private:
	Node* firstNode{ nullptr };
	Node* lastNode{nullptr};
	int listSize{0};
};

