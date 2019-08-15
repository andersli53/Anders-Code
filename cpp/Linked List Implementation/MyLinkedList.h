/**

Homework 6
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#pragma once
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
#include <string>
#include <cassert>

class List;
class Iterator;

class Node {
public:
	/** Constructor of Node
			@param num - int argument for the number
	*/
	Node(int num);
private:
	int num;
	Node* previous;
	Node* next;
	friend class List;
	friend class Iterator;
};

class List {
public:
	/** Default Constructor of List*/
	List();
	/** Destructor of List*/
	~List();
	/** Mutator function of List to push back inputed numbers
			@param num - int argument of number to push back
	*/
	void push_back(int num);
	/** Mutator function of List to push front inputed numbers
			@param num - int argument of number to push back
	*/
	void push_front(int num);
	/** Mutator function of List insert numbers into the list
			@param pos - Iterator class for position to insert
			@param num - number to insert
	*/
	void insert(Iterator pos, int num);
	/** Mutator function of List to print out elements of list*/
	void print();
	/** Mutator function of List
			@param pos - Iterator class for position to insert
			@return - return an interator
	*/
	Iterator erase(const Iterator& pos);
	/** Mutator function of List for sorting*/
	void sort();
	/** Mutator function of List to alternatively merge two list together*/
	void merge(List& a);
	/** Mutator function to reverse order of sorted list*/
	void reverse();
	/** Accessor function of list to get the beginning of list
			@return - iterator of the first element of list
	*/
	Iterator begin();
	/** Accessor function of list to get the end of list
			@return - iterator of the last element of list
	*/
	Iterator end();
private:
	Node* first;
	Node* last;
	friend class Iterator;
};

class Iterator {
public:
	/** Default Constructor of Iterator*/
	Iterator();
	/** Overloading *() for dereferencing
			@return - element of list, int argument
	*/
	int operator*() const;
	/** Overloading operator++
			@return - dereferenced iterator to get the element
	*/
	Iterator& operator++();
	/** Overloading operator--
			@return - dereferenced iterator to get the element
	*/
	Iterator& operator--();
	/** Overloading operator+
			@return - dereferenced iterator to get the element
	*/
	Iterator operator+(int x);
	/** Overloading operator--
			@return - derefferenced iterator to get the element
	*/
	Iterator operator-(int x);
	/** Overloading operator==
			@param a - const Iterator class passed by reference
			@param b - const Iterator class passed by reference
			@return - a's iterator = b's iterator
	*/
	friend bool operator==(const Iterator& a, const Iterator& b);
	/** Overloading operator!=
			@param a - const Iterator class passed by reference
			@param b - const Iterator class passed by reference
			@return - a's iterator != b's iterator
	*/
	friend bool operator!=(const Iterator& a, const Iterator& b);
private:
	Node * position;
	const List* container; //const List& container;
	friend class List;
};


#endif // !MYLINKEDLIST_H
