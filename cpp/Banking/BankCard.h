/**

Homework 4
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Card.h"
#ifndef BANKCARD_H
#define BANKCARD_H

class BankCard : public Card{
private:
	std::string account;
	int code;

public:
	/** Default Constructor*/
	BankCard();
	
	/** Destructor */
	~BankCard();

	/** Constructor to store institution, name, expiration, account, code
			@param institution - a string argument for the name of institution
			@param name - a string argument for the name of card holder
			@param expiration - a string argument for the expiration date
			@param account - a string argument for the account number
			@param code - an int argument for the card security code
	*/
	BankCard(std::string institution, std::string name, std::string expiration, std::string account, int code);

	/** Mutator function to set info of cards*/
	 void setInfo();

	/** Mutator function to print the card info*/
	 void print() const;

	/** Accessor function to get the account number*/
	std::string getAccount() const;

	/** Accessor function to ge the card security code*/
	int getCode() const;
};
#endif // !BANKCARD_H

