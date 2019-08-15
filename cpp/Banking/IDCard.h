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
#include <vector>
#include "Card.h"

#ifndef IDCARD_H
#define IDCARD_H

class IDCard : public Card {
private:
	std::string id;
	std::string dob;

public:
	/** Default Constructor*/
	IDCard();

	/** Destructor*/
	~IDCard();

	/** Constructor to store institution, name, expiration, account, code
			@param institution - a string argument for the name of institution
			@param name - a string argument for the name of card holder
			@param expiration - a string argument for the expiration date
			@param id - a string argument for the ID number
			@param dob - an string argument for the date of birth
	*/
	IDCard(std::string institution, std::string name, std::string expiration, std::string id, std::string dob);
	
	/** Mutator function to set info of cards*/
	 void setInfo();

	/** Mutator function to convert date format*/
	 void convert();

	/** Mutator function to print the card info*/
	 void print() const;

	/** Accessor function to get id*/
	std::string getID() const;

	/** Accessor function to get date of birth*/
	std::string getDOB() const;
};

#endif // !IDCARD_H
