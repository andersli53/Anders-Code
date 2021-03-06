/**

Homework 6
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/

#include <iostream>
#include <string>
#include <sstream>
#include "MyLinkedList.h"

int main() {
	int num = 0;
	int count = 0;
	List linkedList;
	std::cout << "Please input a set of nonnegative numbers for a List" << std::endl;
	std::cout << "(Enter -1 when you are finished) : " << std::endl << std::endl;
	/** Do-while loop to ask for input of list of numbers*/
	do {
		std::cin >> num;
		/** If-else statement to check correct input*/
		if (num < -1 || std::cin.fail()) {
			std::cout << "All positive numbers are stored." << std::endl  
				<< "Enter a positive integer to correct the negative number" 
				<< "(-1 if finished): " << std::endl;
			std::cin >> num;
		}
		linkedList.push_back(num);
		++count;
	} while (num != -1);
	Iterator lastElement = linkedList.begin();
	lastElement = lastElement + (count - 1);
	linkedList.erase(lastElement);
	std::cout << "Your list is" << std::endl;
	linkedList.print();
	std::cout << std::endl;
	
	int index = 0;
	Iterator pos = linkedList.begin(); 
	int insertion = 0;
	std::cout << std::endl;
	/** Do-while loop to ask for input of index and number to insert*/
	do{
		std::cout << "Select an index for insertion (enter -1 when finished): ";
		std::cin >> index;
		while (index >= count) {
			std::cout << "Please enter a valid index (-1 when finished): ";
			std::cin >> index;
		}
		/** If-else statement to check if index = -1*/
		if (index != -1) {
			pos = pos + index;
			std::cout << "Select a value for insertion: ";
			std::cin >> insertion;
			linkedList.insert(pos, insertion);
			pos = linkedList.begin();
		}
		else{

		}
		
	} while (index != -1);
	

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "The augmented List is" << std::endl;
	linkedList.print();
	std::cout << std::endl << std::endl;

	std::cout << "When we sort the previous list we obtain" << std::endl;
	linkedList.sort();
	linkedList.print();
	std::cout << std::endl;

	std::cout << "And this sorted list in reverse order is" << std::endl;
	linkedList.reverse();
	linkedList.print();
	std::cout << std::endl;
	

	std::cout << "If we merge this list with the list (2,3,5,7,11) we obtain" << std::endl;
	List mergeList;
	mergeList.push_back(2);
	mergeList.push_back(3);
	mergeList.push_back(5);
	mergeList.push_back(7);
	mergeList.push_back(11);
	linkedList.merge(mergeList);
	std::cout << std::endl;



	return 0;
}
