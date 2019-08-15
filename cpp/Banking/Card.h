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
#include <time.h>
#include <algorithm>
#ifndef CARD_H
#define CARD_H



class Card {
protected:
	std::string institution;
	std::string name;
	std::string expiration;

public:
	/** Default Constructor*/
	Card();

	/** Destructor */
	~Card();

	/** Constructor to store institution, name, expiration, account, code
			@param institution - a string argument for the name of institution
			@param name - a string argument for the name of card holder
			@param expiration - a string argument for the expiration date
	*/
	Card(std::string institution, std::string name, std::string expiration);

	/** Accessor function to get the name of institution*/
	std::string getInstitution() const;

	/** Accessor function to get the name of card holder*/
	std::string getName() const;

	/** Accessor function to get the expiration date*/
	std::string getDate() const;

	/** Mutator function to convert date format*/
	virtual void convert();

	/** Mutator function to convert date into lexical order*/
	void lexical();

	/** Mutator function to set info of card*/
	virtual void setInfo();

	/** Mutator function to print info of card*/
	virtual void print() const;
};





#endif // !CARD_H
