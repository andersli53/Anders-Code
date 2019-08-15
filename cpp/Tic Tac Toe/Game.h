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
#ifndef GAMETEST_H
#define GAMETEST_H
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"


class Game
{
public:
	/** Default Constructor
	*/
	Game();

	/** Constructor for Game
		@param p1 - add the first player's info to the class Person
		@param p2 - add the second player's info to the class Person
		@param num_games - an int argument for the number of games in Game
	*/
	Game(Person &p1, Person &p2, int num_games);

	/** Mutator member function for playing the game
	*/
	void play();

	/** Mutator member function to display an empty board
	*/
	void displayBoard();

	/**	Mutator member function to clear the board
	*/
	void clearBoard();

	/** Mutator member function to check whether player 1 (X) fulfills the winning requirement
		@return - a bool argument whether X wins (True), X doesn't win (False)
	*/
	bool checkX();

	/** Mutator member function to check whether player 2 (O) fulfills the winning requirement
		@return - a bool argument whether X wins (True), X doesn't win (False)
	*/
	bool checkO();

	/**	Mutator member function to announce the winner
	*/
	void announceWinner();



private:
	Person * player1;
	Person* player2;
	int num_games;
	std::vector<std::vector<std::string> > board;
};

#endif // !GAMETEST_H

