/**

Homework 4
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "IDCard.h"

/** Default Constructor*/
IDCard::IDCard() : Card()
{
}

/** Destructor*/
IDCard::~IDCard()
{
}

/** Constructor to store institution, name, expiration, account, code
		@param institution - a string argument for the name of institution
		@param name - a string argument for the name of card holder
		@param expiration - a string argument for the expiration date
		@param id - a string argument for the ID number
		@param dob - an string argument for the date of birth
*/
IDCard::IDCard(std::string institution, std::string name, std::string expiration, std::string id, std::string dob) :
	Card(institution, name, expiration), id(id), dob(dob)
{
}

/** Mutator function to set info of cards*/
void IDCard::setInfo()
{

	Card::setInfo();
	std::cout << "ID number : ";
	std::cin >> id;
	std::cout << "DOB mmddyyyy (0 if not listed) : ";
	std::cin >> dob;
	std::cout << std::endl;
}

/** Mutator function to convert date format*/
void IDCard::convert()
{
	/** If-esle statement to turn "no date of birth" to N/A.*/
	if (dob == "0") {
		dob = "N/A.";
	}
	Card::convert();
}


/** Mutator function to print the card info*/
void IDCard::print() const
{
	Card::print();
	std::cout << "|       ID# : " << id << std::endl;
	std::cout << "|       DOB : " << dob << std::endl;
	std::cout << "|" << std::endl;
}

/** Accessor function to get id*/
std::string IDCard::getID() const
{
	return id;
}

/** Accessor function to get date of birth*/
std::string IDCard::getDOB() const
{
	return dob;
}

