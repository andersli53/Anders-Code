/**

Homework 4
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "BankCard.h"

/** Default Constructor*/
BankCard::BankCard() : Card()
{
}

/** Destructor */
BankCard::~BankCard()
{
}

/** Constructor to store institution, name, expiration, account, code
		@param institution - a string argument for the name of institution
		@param name - a string argument for the name of card holder
		@param expiration - a string argument for the expiration date
		@param account - a string argument for the account number
		@param code - an int argument for the card security code
*/
BankCard::BankCard(std::string institution, std::string name, std::string expiration, std::string account, int code) :
	Card(institution, name, expiration), account(account), code(code)
{
}

/** Mutator function to set info of cards*/
void BankCard::setInfo()
{

	Card::setInfo();
	std::cout << "Account number : ";
	std::cin >> account;
	std::cout << "Card Security Code: ";
	std::cin >> code;
	std::cout << std::endl;
}

/** Mutator function to print the card info*/
void BankCard::print() const
{
	Card::print();
	std::cout << "|  Account# : " << account << std::endl;
	std::cout << "|       CSC : " << code << std::endl;
	std::cout << "|" << std::endl;
}

/** Accessor function to get the account number*/
std::string BankCard::getAccount() const
{
	return account;
}

/** Accessor function to ge the card security code*/
int BankCard::getCode() const
{
	return code;
}
