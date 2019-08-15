/**

Homework 7
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "MyBinaryTree.h"

/** Default Constructor for BinarySearchTreee*/
BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

/** Destructor for BinarySearchTree*/
BinarySearchTree::~BinarySearchTree()
{
	/** If statement to check if root exists*/
	if (root) {
		cleanup(root);
	}
}

/** Mutator function to get the smallest number
		@return - object of TreeIterator
*/
TreeIterator BinarySearchTree::begin()
{
	if (!root) {
		return TreeIterator();
	}
	else {
		TreeNode* current = root;

		while (current->left != nullptr) {
			current = current->left;
		}


		return TreeIterator(current);
	}

}

/** Mutator function to go one past the largest number
		@return - object of TreeIterator
*/
TreeIterator BinarySearchTree::end()
{
	return TreeIterator(nullptr);
}

/** Mutator function to insert number into BST
		@param num - an int argument
*/
void BinarySearchTree::insert(int num)
{
	TreeNode* new_node = new TreeNode;
	new_node->num = num;
	new_node->left = nullptr;
	new_node->right = nullptr;
	new_node->parent = root;
	/** If-else statement to check if root is a nullptr*/
	if (root == nullptr) {
		root = new_node;
	}
	/** If-else statement for the action if root != nullptr*/
	else {
		root->insert(new_node);
	}
}


/** Mutator function to erase a number from the BST
		@param num - an int argument
*/
void BinarySearchTree::erase(int num)
{
	TreeNode* remove = root;
	bool found = false;
	/** While loop to check if the input number exists in BST*/
	while (!found && remove != nullptr) {
		/** If-else statement to check if number is greater than current node's number*/
		if (remove->num < num) {
			remove = remove->right;
		}
		/** If-else statement to check if number is less than current node's number*/
		else if (num < remove->num) {
			remove = remove->left;
		}
		/** If-else statement to check if number is the current node's number*/
		else {
			found = true;
		}
	}

	/** If statement to check if not found*/
	if (!found) {
		return;
	}

	/** If-else statement for one child*/
	if (remove->left == nullptr || remove->right == nullptr) {
		TreeNode* new_child;
		/** If statement for left child = nullptr*/
		if (remove->left == nullptr) {
			new_child = remove->right;
		}
		/** If statement for right child = nullptr*/
		else {
			new_child = remove->left;
		}

		/** If-esle statement for paranet = nullptr*/
		if (remove->parent == nullptr) {
			root = new_child;
		}
		/** If-else statement to check the node is the left child*/
		else if (remove->parent->left == remove) {
			remove->parent->left = new_child;
			/** If statment to set parent*/
			if (new_child != nullptr) {
				new_child->parent = remove->parent;
			}
		}
		/** If-else statement to check the ndoe is the right child*/
		else {
			remove->parent->right = new_child;
			/** If statement to set parent*/
			if (new_child != nullptr) {
				new_child->parent = remove->parent;
			}
		}
		return;
	}


	TreeNode* replace = remove->left;
	/** While loop for two existing children*/
	while (replace->right != nullptr) {
		replace = replace->right;
	}
	remove->num = replace->num;
	/** If-else statement to move content and unlink child*/
	if (replace->parent == remove) {
		replace->parent->left = replace->left;
	}
	else {
		replace->parent->right = replace->left;
	}

}

/** Mutator function to search for the num
		@param num - int argument
		@return - object of TreeIterator
*/
TreeIterator BinarySearchTree::find(int num) const
{
	if (!root) {
		return TreeIterator(nullptr,this);
	}
	else {
		return root->find(num);
	}
}

/** Mutator function to print the tree*/
void BinarySearchTree::print() const
{
	/** If statement to check if the root exists*/
	if (root) {
		root->print();
	}
}

/** Mutator function to delete nodes*/
void BinarySearchTree::cleanup(TreeNode * p)
{
	if (p->left) {
		cleanup(p->left);
	}
	if (p->right) {
		cleanup(p->right);
	}
	delete p;
}

/** Default Constructor for TreeNode*/
TreeNode::TreeNode() : num(-1), left(nullptr), right(nullptr), parent(nullptr)
{
}


/** Mutator function to insert node
		@param new_node - pointer to TreeNode object
*/
void TreeNode::insert(TreeNode * new_node)
{
	/** If else statement to check if the number of node is greater or less than the current number*/
	if (new_node->num < num) {
		/** If else statement to check if the left child is a nullptr*/
		if (left == nullptr) {
			new_node->parent = this;
			left = new_node;
		}
		else {
			left->insert(new_node);
		}
	}
	else if (num < new_node->num) {
		/** If else statement to check if the right child is a nullptr*/
		if (right == nullptr) {
			new_node->parent = this;
			right = new_node;
		}
		else {
			right->insert(new_node);
		}
	}
}

/** Mutator function to search for a nubmer
		@param num - int argument
		@return - object of TreeIterator
*/
TreeIterator TreeNode::find(int num)
{
	/** If else statement to check if the number is the current number*/
	if (num == num) {
		return TreeIterator(this);
	}
	else if (num < num) {
		/** If else statement to check if the left child exists*/
		if (left) {
			return left->find(num);
		}
		else {
			return TreeIterator(nullptr);
		}
	}
	else {
		/** If else statement to check if the right child exists*/
		if (right) {
			return right->find(num);
		}
		else {
			return TreeIterator(nullptr);
		}
	}

}

/** Mutator function to print out node*/
void TreeNode::print() const
{
	/** If statement to check if left child exists*/
	if (left) {
		left->print();
	}
	std::cout << num << " ";
	/** If statement to check if right child exists*/
	if (right) {
		right->print();
	}
}

/** Default constructor for TreeIterator*/
TreeIterator::TreeIterator(TreeNode * iterator, const BinarySearchTree* bst) : iterator(iterator), container(bst)
{
}

/** Overloading operator* 
		@return - int number of the iterator
*/
int TreeIterator::operator*() const
{
	assert(iterator != nullptr);
	return iterator->num;
}

/** Overloading prefix operator++
		@return - TreeIterator object
*/
TreeIterator & TreeIterator::operator++()
{	
	assert(iterator != nullptr);

	TreeNode* p;
	/** If else statement to check if the parent is a nullptr*/
	if (iterator->parent == nullptr) {
		/** If statement to check if the right child is not a nullptr*/
		if (iterator->right != nullptr) {
			iterator = iterator->right;
			/** While loop to go to the left-most child*/
			while (iterator->left != nullptr) {
				iterator = iterator->left;
			}
		}
	}
	else {
		/** If-else statement to check if the right child is not a nullptr*/
		if (iterator->right != nullptr) {
			iterator = iterator->right;
			/** While loop to go to the left-most child*/
			while (iterator->left != nullptr) {
				iterator = iterator->left;
			}
		}
		/** If right child is nullptr*/
		else if (iterator->right == nullptr) {
			p = iterator->parent;
			/** While loop to go to the parent until getting the next greater number*/
			while (iterator->parent != nullptr && iterator == iterator->parent->right) {
				iterator = p;
				p = p->parent;

			}
			iterator = p;
		}
		/** If the current iterator is left child of the parent*/
		else if (iterator->parent->left == iterator) {
			iterator = iterator->parent;
		}
		
	}
	
	return *this;
}

/** Overloading postfix operator++
		@param unused - int argument
		@return - TreeIterator object
*/
TreeIterator TreeIterator::operator++(int unused)
{
	assert(iterator != nullptr);
	TreeIterator clone(this->iterator);
	++(*this);
	return clone;
}

/** Overloading prefix operator++
		@return - TreeIterator object
*/
TreeIterator & TreeIterator::operator--()
{
	assert(iterator != nullptr);

	TreeNode* p;
	/** If else statement to check if the parent is a nullptr*/
	if (iterator->parent == nullptr) {
		/** If statement to check if the left child is not a nullptr*/
		if (iterator->left != nullptr) {
			iterator = iterator->left;
			/** While loop to go to the right-most child*/
			while (iterator->right != nullptr) {
				iterator = iterator->right;
			}
		}
	}
	else {
		/** If-else statement to check if the left child is not a nullptr*/
		if (iterator->left != nullptr) {
			iterator = iterator->left;
			/** While loop to go to the right-most child*/
			while (iterator->right != nullptr) {
				iterator = iterator->right;
			}
		}
		/** If right child is nullptr*/
		else if (iterator->left == nullptr) {
			p = iterator->parent;
			/** While loop to go to the parent until getting the next greater number*/
			while (iterator->parent != nullptr && iterator == iterator->parent->left) {
				iterator = p;
				p = p->parent;

			}
			iterator = p;
		}
		/** If the current iterator is right child of the parent*/
		else if (iterator->parent->right == iterator) {
			iterator = iterator->parent;
		}
		
	}

	return *this;
}

/** Overloading postfix operator--
		@param unused - int argument
		@return - TreeIterator object
*/
TreeIterator TreeIterator::operator--(int unused)
{
	assert(iterator != nullptr);
	TreeIterator clone(this->iterator);
	--(*this);
	return clone;
}

/** Overloading operator !=
		@param rhs - TreeIterator passing by reference
		@return - bool if this->iterator != rhs.iterator
*/
bool TreeIterator::operator!=(const TreeIterator & rhs) const
{
	return this->iterator != rhs.iterator;
}

/** Overloading operator ==
		@param rhs - TreeIterator passing by reference
		@return - bool if this->iterator == rhs.iterator
*/
bool TreeIterator::operator==(const TreeIterator & rhs) const
{
	return this->iterator == rhs.iterator;
}


