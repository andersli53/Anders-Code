/**

Homework 7
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/

#include <iostream>
#include <string>
#include "MyBinaryTree.h"


int main()
{
	BinarySearchTree bst;
	bst.insert(3); bst.insert(2); bst.insert(11);
	bst.insert(13); bst.insert(5); bst.insert(17); bst.insert(17);
	std::cout << "Your tree consists of : ";
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;

	bst.erase(6);
	bst.erase(11);
	std::cout << "Tree now  consists of : ";
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;

	TreeIterator start = bst.begin();
	TreeIterator stop = bst.end();
	std::cout << "Checking initial value: ";
	if (start != stop) std::cout << *start++ << std::endl;
	return 0;
}

