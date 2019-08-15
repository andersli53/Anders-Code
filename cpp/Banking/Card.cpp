/**

Homework 4
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "Card.h"
/** Default Constructor*/
Card::Card()
{
}

/** Destructor */
Card::~Card()
{
}

/** Constructor to store institution, name, expiration, account, code
		@param institution - a string argument for the name of institution
		@param name - a string argument for the name of card holder
		@param expiration - a string argument for the expiration date
*/
Card::Card(std::string institution, std::string name, std::string expiration) :
	institution(institution), name(name), expiration(expiration)
{
}

/** Accessor function to get the name of institution*/
std::string Card::getInstitution() const
{
	return institution;
}

/** Accessor function to get the name of card holder*/
std::string Card::getName() const
{
	return name;
}

/** Accessor function to get the expiration date*/
std::string Card::getDate() const
{
	return expiration;
}

/** Mutator function to convert date format*/
void Card::convert()
{
	/** If-else statement to turn "no expiration date" to N/A.*/
	if (expiration == "~~~~~~~~") {
		expiration = "N/A.";
	}
	/** If-else statement to convert date to mm/dd/yyyy*/
	else if (expiration.size() == 8){
		expiration.insert(expiration.begin() + 2, '/');
		expiration.insert(expiration.begin() + 5, '/');
	}
}

/** Mutator function to convert date into lexical order*/
void Card::lexical()
{
	/** If-else statement to convert date to lexical order*/
	if (expiration.size() == 8) {
		expiration = expiration.substr(4, 4) + expiration.substr(0, 4);
	}
	/** If-else statement to convert "no expiration date" to "~~~~~~~~" for comparison*/
	else if (expiration == "0") {
		expiration = "~~~~~~~~";
	}

}

/** Mutator function to set info of card*/
void Card::setInfo()
{
	std::cout << "Institution name : ";
	std::cin >> std::ws;
	getline(std::cin, institution);
	std::cout << "Card holder name : ";
	getline(std::cin, name);
	std::cout << "Expiration date mmddyyyy (0 if none) : ";
	std::cin >> expiration;
}

/** Mutator function to print info of card*/
void Card::print() const
{
	std::cout << " ----------------------------------------------" << std::endl;
	std::cout << "|" << std::endl;
	std::cout << "| " << institution << std::endl;
	std::cout << "|      name : " << name << std::endl;
	std::cout << "|       exp : " << expiration << std::endl;
	std::cout << "|" << std::endl;
}
