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

	//add node � la fin
	void add(int value);
	//insert node � index n
	void insert();
	//remove node � la fin
	void remove();
	//remove node � index n
	void remove(int n);
	//return node � index n;
	Node at(int n);
	//display ce que contient la liste
	void display();

private:
	Node* firstNode{ nullptr };
	Node* lastNode{nullptr};
	int listSize{0};
};

