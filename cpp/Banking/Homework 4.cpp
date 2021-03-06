/**

Homework 4
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include "Card.h"
#include "IDCard.h"
#include "BankCard.h"

/** Function object for sorting vector of Cards according to the expiration date
		@param card1 - a const pointer to Card class
		@param card2 - a const pointer to Card class
		@return - bool argument that card1's expiration date is earlier than that of card2
*/
struct compare {
	inline bool operator() (const Card* card1, const Card* card2) const{
		return (card1->getDate() < card2->getDate());
	}
};

int main()
{
	int type;
	IDCard id;
	BankCard bc;
	Card basic_card;
	Card *id_card = &id;
	Card *bank_card = &bc;
	bool wrongInput;


	std::vector<Card*> newCard;

	std::cout << "*********************" << std::endl;
	std::cout << "*  Wallet Printer!  *" << std::endl;
	std::cout << "*********************" << std::endl;
	
	std::cout << "Print Cards by selecting the type (0 when done) : " << std::endl << std::endl;

	std::cout << "1. Basic Card" << std::endl << "2. ID Card" << std::endl << "3. Bank Card" << std::endl;

	/** Do-while loop to prompt the user for the type of cards */
	do {

		std::cout << std::endl << "Card Type : ";
		std::cin >> type;
		if (std::cin.fail()) {
			wrongInput = 1;
		}
		std::cout << std::endl;
			/** If-else statement to test if user wants to input data of basic card*/
			if (type == 1) {
				basic_card.setInfo();
				newCard.push_back(new Card(basic_card.getInstitution(), basic_card.getName(), basic_card.getDate()));
			}
			/** If-else statement to test if user wants to input data of ID card*/
			else if (type == 2) {
				id_card->setInfo();
				newCard.push_back(new IDCard(id.getInstitution(), id.getName(), id.getDate(), id.getID(), id.getDOB()));

			}
			/** If-else statement to test if user wants to input data of Bank card*/
			else if (type == 3) {
				bank_card->setInfo();
				newCard.push_back(new BankCard(bc.getInstitution(), bc.getName(), bc.getDate(), bc.getAccount(), bc.getCode()));
			}
			

	} while (type != 0 || wrongInput == 1);

	/** for loop to change every expiration date to lexical order (yyyymmdd)*/
	for (size_t i = 0; i < newCard.size(); ++i) {
		newCard[i]->lexical();
	}
	
	/** Sorting the vector of Cards based on the expiration dates*/
	std::sort(newCard.begin(), newCard.end(), compare());

	/** for loop to reverse the expiration date to mmddyyyy*/
	for (size_t i = 0; i < newCard.size(); ++i) {
		newCard[i]->lexical();
	}

	/** for loop to convert expiration date to mm/dd/yyyy and print the sorted vector*/
	for (size_t i = 0; i < newCard.size(); ++i) {
		newCard[i]->convert();
		newCard[i]->print();
	}
	
	/** for loop to deallocate the vector of object*/
	for (std::vector<Card*>::iterator it = newCard.begin(); it != newCard.end(); it++) {
		delete (*it);
	}

	id_card = nullptr;
	bank_card = nullptr;

	return 0;
}

