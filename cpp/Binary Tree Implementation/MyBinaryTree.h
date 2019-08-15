/**

Homework 7
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#pragma once
#ifndef MYBINARYTREE_H
#define MYBINARYTREE_H
#include <iostream>
#include <string>
#include <cassert>

class TreeNode;
class TreeIterator;

class BinarySearchTree {
public:
	/** Default constructor for BST*/
	BinarySearchTree();
	/** Destructor for BST*/
	~BinarySearchTree();
	/** Mutator function for the smallest number
			@return - TreeIterator object
	*/
	TreeIterator begin();
	/** Mutator function for one past the largest number
			@return - TreeIterator obejct
	*/
	TreeIterator end();
	/** Mutator function to insert number
			@param num - int argument
	*/
	void insert(int num);
	/** Mutator function to erase nubmer
			@param num - int argument
	*/
	void erase(int num);
	/** Mutator function to search for a number
			@param num - int argument
			@return - TreeIterator object
	*/
	TreeIterator find(int num) const;
	/** Mutator function to print out the numbers*/
	void print() const;

private:
	/** Mutator function to delete node*/
	void cleanup(TreeNode* p);
	TreeNode * root;
};

class TreeNode {
public:
	/** Default constructor for TreeNode*/
	TreeNode();
	/** Mutator function to insert new node
			@param new_node - pointer to TreeNode object
	*/
	void insert(TreeNode* new_node);
	/** Mutator function to search for a number
			@param num - int argument
			@return - TreeIterator obejct
	*/
	TreeIterator find(int num);
	/** Mutator functiont o print out the nodes*/
	void print() const;

private:
	int num;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	friend class BinarySearchTree;
	friend class TreeIterator;
};

class TreeIterator {
public:
	/** Constructor and Default Constructor for TreeIterator*/
	TreeIterator(TreeNode* iterator = nullptr, const BinarySearchTree* bst = nullptr);
	/** Overloading Operator*
			@return - int number of the iterator
	*/
	int operator*() const;
	/** Overloading prefix operator++
			@return - TreeIterator object
	*/
	TreeIterator& operator++();
	/** Overloading postfix operator++
			@param unused - int argument
			@return - TreeIterator object
	*/
	TreeIterator operator++(int unused);
	/** Overloading prefix operator--
			@return - TreeITerator object
	*/
	TreeIterator& operator--();
	/** Overaloading postfix operator--
			@param unused - int argument
			@return - TreeIterator object
	*/
	TreeIterator operator--(int unused);
	/** Overloading operator !=
			@param rhs - TreeIterator object passing by reference
			@return - bool argument if the iterator doesn't equal
	*/
	bool operator!=(const TreeIterator& rhs) const;
	/** Overloading operator ==
			@param rhs - TreeIterator object passing by reference
			@return - bool argument if the iterator equals
	*/
	bool operator==(const TreeIterator& rhs) const;



private:
	TreeNode * iterator;
	const BinarySearchTree * container;
	friend class BinarySearchTree;
	friend class TreeNode;
};

#endif // !MYBINARYTREE_H

