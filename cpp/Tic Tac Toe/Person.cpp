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
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>

/** Default constructor for Person
*/
Person::Person() : name(""), score(0)
{
}

/** Constructor for Person
	@param name - a string argument for the name of the player
*/
Person::Person(std::string name) : name(name), score(0)
{
}

/** Mutator member funtion to update player's score if he/she wins
*/
void Person::updateScore()
{
	score++;
}

/** Mutator member function to reset player's score after the game
*/
void Person::resetScore()
{
	score = 0;
}

/** Accessor member function for the name member variable
	@return a string for the name
*/
std::string Person::getName() const
{
	return name;
}

/** Accessor member function for the score number variable
	@return an int for the score
*/
int Person::getScore() const
{
	return score;
}
