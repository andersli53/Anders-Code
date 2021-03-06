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
#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Person.h"


int main()
{
	int num_games;
	std::string name1, name2;
	std::string repeat;
	bool valid = false;

	/** do-while loop to continue the game if players want to play again
	*/
	do{
		/** while loop to check if players do not input integer
		*/
	while (!valid) {
		valid = true;
		std::cout << "Number of games: ";
		std::cin >> num_games;
		/** if statement to ask players to input a valid number
		*/
		if (std::cin.fail()) {													
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Enter a valid number." << std::endl;
			valid = false;
		}
	}
	std::cout << "Player 1 Name = ";
	std::cin >> name1;
	
	std::cout << "Player 2 Name = ";
	std::cin >> name2;


	Person player1(name1);
	Person player2(name2);

	Game TicTacToe(player1, player2, num_games);


	TicTacToe.play();

	std::cout << "Do you want to play again (y/n)? ";
	std::cin >> repeat;
	} while (repeat == "y" || repeat == "yes");


	return 0;
}

