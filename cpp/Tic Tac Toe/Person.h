/**

Homework 1
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon

Collaborator: Wong, Chi Hin (Terence)

Honor pledge:
	I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#pragma once
#ifndef PERSONTEST_H
#define PERSONTEST_H
#include <iostream>
#include <string>
#include <vector>


class Person
{
public:
	/** Default constructor for Person
	*/
	Person();

	/** Constructor for Person
		@param name - a string argument for the name of the player
	*/
	Person(std::string name);

	/** Mutator member funtion to update player's score if he/she wins
	*/
	void updateScore();

	/** Mutator member function to reset player's score after the game
	*/
	void resetScore();

	/** Accessor member function for the name member variable
		@return a string for the name
	*/
	std::string getName() const;

	/** Accessor member function for the score number variable
		@return an int for the score
	*/
	int getScore() const;

private:
	std::string name;
	int score;
};


#endif // !Person

#pragma once
