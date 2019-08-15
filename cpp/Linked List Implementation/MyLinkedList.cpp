/**

Homework 6
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "MyLinkedList.h"

/** Constructor of Node
		@param num - int argument for the number
*/
Node::Node(int num) : num(num), previous(nullptr), next(nullptr)
{
}

/** Default Constructor of List*/
List::List() : first(nullptr), last(nullptr)
{
}

/** Destructor of List*/
List::~List()
{
	Node* current = first;
	Node* temp = first;
	/** While loop to traverse the list and delete each node*/
	while (current != nullptr) {
		temp = current->next;
		delete current;
		current = temp;
	}

	first = nullptr;
	last = nullptr;
}

/** Mutator function of List to push back inputed numbers
		@param num - int argument of number to push back
*/
void List::push_back(int num)
{
	Node* new_node = new Node(num);
	/** If-else statement to check for empty list*/
	if (last == nullptr) {
		first = new_node;
		last = new_node;
	}
	else {
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
}

/** Mutator function of List to push front inputed numbers
		@param num - int argument of number to push back
*/
void List::push_front(int num)
{
	Node* new_node = new Node(num);
	/** If-else statement to check for empty list*/
	if (last == nullptr) {
		first = new_node;
		last = new_node;
	}
	else {
		new_node->next = first;
		first->previous = new_node;
		first = new_node;
	}
}

/** Mutator function of List insert numbers into the list
		@param pos - Iterator class for position to insert
		@param num - number to insert
*/
void List::insert(Iterator pos, int num)
{
	/** If-else statement to check for empty list*/
	if (pos.position == nullptr) {
		push_back(num);
		return;
	}
	Node* after = pos.position;
	Node* before = after->previous;
	Node* new_node = new Node(num);
	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;
	/** If-else statement to check for first node*/
	if (before == nullptr) {
		first = new_node;
	}
	else {
		before->next = new_node;
	}
}

/** Mutator function of List to print out elements of list*/
void List::print()
{
	std::cout << "(";
	/** For loop to travers the list*/
	for (auto iter = begin(); iter != end(); ++iter) {
		/** If-else statement to format output*/
		if (iter.position != last) {
			std::cout << *iter << ",";
		}
		else if (iter.position == last) {
			std::cout << *iter << ")";
		}
	}

}

/** Mutator function of List
		@param pos - Iterator class for position to insert
		@return - return an interator
*/
Iterator List::erase(const Iterator& pos)
{
	assert(pos.position != nullptr);
	Node* remove = pos.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	/** If-else statment to modify list*/
	if (remove == first) {
		first = after;
	}
	else {
		before->next = after;
	}
	/** If-else statment to modify list*/
	if (remove == last) {
		last = before;
	}
	else {
		after->previous = before;
	}
	delete remove;
	Iterator rm;
	rm.position = after;
	rm.container = this;
	return rm;
}

/** Mutator function of List for sorting*/
void List::sort()
{
	/** If-else statment to check for empty list*/
	if (first == nullptr) {
		return;
	}
	bool sorted;
	/** Do-while loop to keep sorting*/
	do {
		sorted = false;
		Node* current = first;
		Node* temp = nullptr;
		/** While loop to travers the list*/
		while (current != nullptr) {
			temp = current;
			current = current->next;
			/** If-else statement to check condition for sorting (a's num < b's num)*/
			if (current != nullptr && current->num < temp->num) {
				sorted = true;
				std::swap(current->num, temp->num);
				
			}
		}
	} while (sorted);
}

/** Mutator function of List to alternatively merge two list together 
	and print out the augmented list*/
void List::merge(List& a)
{
	List mergedList;
	Node* current = first;
	Iterator iter = a.begin();
	/** While loop to continue merging if traversing is valid*/
	while (current != nullptr && iter.position != nullptr) {
		mergedList.push_back(current->num);
		mergedList.push_back(*iter);
		current = current->next;
		++iter;
	}
	/** While loop to continue merging if traversing is valid only for original list*/
	while (current != nullptr && iter.position == nullptr) {
		mergedList.push_back(current->num);
		current = current->next;
	}
	/** While loop to continue merging if traversing is valid only for list to be merged*/
	while (current == nullptr && iter.position != nullptr) {
		mergedList.push_back(*iter);
		++iter;
	}
	mergedList.print();
}

/** Mutator function to reverse order of sorted list*/
void List::reverse()
{
	/** If-else statement to check for empty list*/
	if (first == nullptr) {
		return;
	}
	bool sorted;
	/** Do-while loop to keep sorting descending*/
	do {
		sorted = false;
		Node* current = first;
		Node* temp = nullptr;
		/** While loop to check if traversing is valid*/
		while (current != nullptr) {
			temp = current;
			current = current->next;
			if (current != nullptr && current->num > temp->num) {
				sorted = true;
				std::swap(current->num, temp->num);
			}
		}
	} while (sorted);

}

/** Accessor function of list to get the beginning of list
		@return - iterator of the first element of list
*/
Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

/** Accessor function of list to get the end of list
		@return - iterator of the last element of list
*/
Iterator List::end()
{
	Iterator iter;
	iter.position = nullptr;
	iter.container = this;
	return iter;
}

/** Default Constructor of Iterator*/
Iterator::Iterator() : position(nullptr), container(nullptr)
{
}

/** Overloading *() for dereferencing
		@return - element of list, int argument
*/
int Iterator::operator*() const
{
	assert(position != nullptr);
	return position->num;
}

/** Overloading operator++
		@return - dereferenced iterator to get the element
*/
Iterator& Iterator::operator++()
{
	assert(position != nullptr);
	position = position->next;
	return *this;
}

/** Overloading operator--
		@return - dereferenced iterator to get the element
*/
Iterator & Iterator::operator--()
{
	assert(position != nullptr);
	position = position->previous;
	return *this;
}

/** Overloading operator+
		@return - dereferenced iterator to get the element
*/
Iterator Iterator::operator+(int x)
{
	assert(position != nullptr);
	/** For loop to add x*/
	for (auto i = 0; i < x; i++) {
		position = position->next;
	}
	return *this;
}

/** Overloading operator-
		@return - derefferenced iterator to get the element
*/
Iterator Iterator::operator-(int x)
{
	assert(position != nullptr);
	/** For loop to minus x*/
	for (auto i = 0; i < x; i++) {
		position = position->previous;
	}
	return *this;
}

/** Overloading operator==
		@param a - const Iterator class passed by reference
		@param b - const Iterator class passed by reference
		@return - a's iterator = b's iterator
*/
bool operator==(const Iterator & a, const Iterator & b)
{
	return a.position == b.position;
}

/** Overloading operator!=
		@param a - const Iterator class passed by reference
		@param b - const Iterator class passed by reference
		@return - a's iterator != b's iterator
*/
bool operator!=(const Iterator & a, const Iterator & b)
{
	return a.position != b.position;
}

