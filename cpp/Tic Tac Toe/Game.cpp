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
#include "Game.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>

/** Default Constructor
*/
Game::Game()
{
}

/** Constructor for Game
	@param p1 - add the first player's info to the class Person
	@param p2 - add the second player's info to the class Person
	@param num_games - an int argument for the number of games in Game
*/
Game::Game(Person &p1, Person &p2, int num_games) :player1(&p1), player2(&p2), num_games(num_games) {}

/** Mutator member function for playing the game
*/
void Game::play()
{
	int row, col;
	int remainder;
	std::string repeat;

	

		player1->resetScore();
		player2->resetScore();

		/**	do-while loop to continue the game for a number of times that the players input
		*/
		do {

			clearBoard();
			displayBoard();


			/**	for loop to alternate player 1's and player 2's turn
			*/
			for (int turn = 0; turn < 9; turn++) {
				remainder = turn % 2;
				/**	if statement if it's player 1's turn
				*/
				if (remainder == 0) {
					std::cout << player1->getName() << " (X) Mark Location: ";
					std::cin >> row >> col;

					/**	if statement for player 1 to mark location
					*/
					if (((row > 0 && row < 4) && (col > 0 && col < 4)) && (board[row - 1][col - 1] == " ")) {

						board[row - 1][col - 1] = "X";
						displayBoard();
					}

					/** else if statement to check whether the location is occupied
					*/
					else  if (((row > 0 && row < 4) && (col > 0 && col < 4)) && (board[row - 1][col - 1] == "X" || board[row - 1][col - 1] == "O"))
					{
						/** while loop if players keep inputting wrong info
						*/
						while (board[row - 1][col - 1] == "X" || board[row - 1][col - 1] == "O" || row >= 4 || col >= 4 || std::cin.fail()) {
							std::cout << "[" << row << " " << col << "]" << " is occupied. Please select another location: ";
							std::cin >> row >> col;
						}
						board[row - 1][col - 1] = "X";
						displayBoard();
					}

					/** else if statement to check whether the location is out of the board
					*/
					else if (row >= 4 || col >= 4 || std::cin.fail()) {
						/** while loop if players keep inputting wrong info
						*/
						while (row >= 4 || col >= 4 || std::cin.fail() || board[row - 1][col - 1] == "X" || board[row - 1][col - 1] == "O") {
							std::cout << "Please enter a valid location: ";
							std::cin >> row >> col;
						} 
						board[row - 1][col - 1] = "X";
						displayBoard();
					}

				}
				/** if-else statement if it's player 2's turn
				*/
				else {

					std::cout << player2->getName() << " (O) Mark Location: ";
					std::cin >> row >> col;

					/**	if statement for player 2 to mark location
					*/
					if (row > 0 && row < 4 && col > 0 && col < 4 && board[row - 1][col - 1] == " ") {
						board[row - 1][col - 1] = "O";
						displayBoard();
					}
					/** else if statement to check whether the location is occupied
					*/
					else if (((row > 0 && row < 4) && (col > 0 && col < 4)) && (board[row - 1][col - 1] == "X" || board[row - 1][col - 1] == "O"))
					{
						/** while loop if players keep inputting wrong info
						*/
						while (board[row - 1][col - 1] == "X" || board[row - 1][col - 1] == "O" || std::cin.fail() || row >= 4 || col >= 4 || std::cin.fail()) {
							std::cout << "[" << row << " " << col << "]" << " is occupied. Please select another location: ";
							std::cin >> row >> col;

						}
						board[row - 1][col - 1] = "O";
						displayBoard();
					}
					/** else if statement to check whether the location is out of the board
					*/
					else if (row >= 4 || col >= 4 || std::cin.fail()) {
						/** while loop if players keep inputting wrong info
						*/
						while (row >= 4 || col >= 4 || std::cin.fail() || board[row - 1][col - 1] == "X" || board[row - 1][col - 1] == "O") {
							std::cout << "Please enter a valid location: ";
							std::cin >> row >> col;
						}
						board[row - 1][col - 1] = "O";
						displayBoard();
					}

				}

				checkX();
				checkO();
				/** if statement if X wins, update player 1's score and display the score
				*/
				if (checkX() == true) {
					player1->updateScore();
					std::cout << player1->getName() << " has won this round!" << std::endl
						<< player1->getName() << " " << player1->getScore()
						<< " : " << player2->getScore() << " " << player2->getName() << std::endl;

					break;
				}
				/** else if statement if O wins, update player 2's score and display the score
				*/
				else if (checkO() == true) {
					player2->updateScore();

					std::cout << player2->getName() << " has won this round!" << std::endl
						<< player1->getName() << " " << player1->getScore()
						<< " : " << player2->getScore() << " " << player2->getName() << std::endl;

					break;

				}
				/** else if statement if draw, display the score
				*/
				else if (turn == 8) {
					std::cout << "Tie!" << std::endl
						<< player1->getName() << " " << player1->getScore()
						<< " : " << player2->getScore() << " " << player2->getName() << std::endl;

					break;
				}

			}


			num_games--;

		} while (num_games != 0);

		std::cout << std::endl;
		announceWinner();

		std::cout << std::endl;



}

/** Mutator member function to display an empty board
*/
void Game::displayBoard()
{
	std::string emptyRow = "  ______|________|______";
	std::string colSeparator = "         |        |         ";
	std::string rowSeparator = "____________________";
	std::string rowSpace = "                    ";
	std::string row1 = "";
	std::string row2 = "";
	std::string row3 = "";

	const int COL = 3;
	const int ROW = 3;
	board.resize(COL, std::vector<std::string>(ROW));


	row1 = "1    " + board[0][0] + "   |   " + board[0][1] + "    |   " + board[0][2] + "   ";
	row2 = "2    " + board[1][0] + "   |   " + board[1][1] + "    |   " + board[1][2] + "   ";
	row3 = "3    " + board[2][0] + "   |   " + board[2][1] + "    |   " + board[2][2] + "   ";


	std::cout << "     Tic Tac Toe" << std::endl << player1->getName() << " (X) - " << player2->getName() << " (O)" << std::endl << std::endl;
	std::cout << "     1    " << "   2    " << "    3    " << std::endl;
	std::cout << colSeparator << std::endl;
	std::cout << row1 << std::endl;
	std::cout << " " << emptyRow << std::endl;
	std::cout << colSeparator << std::endl;
	std::cout << row2 << std::endl;
	std::cout << " " << emptyRow << std::endl;
	std::cout << colSeparator << std::endl;
	std::cout << row3 << std::endl;
	std::cout << colSeparator << std::endl;

}

/**	Mutator member function to clear the board
*/
void Game::clearBoard()
{
	const int COL = 3;
	const int ROW = 3;
	board.resize(COL, std::vector<std::string>(ROW));

	/** for loop to enter an empty string for each slot in the vectors
	*/
	for (size_t i = 0; i < board.size(); i++) {
		for (size_t j = 0; j < board.size(); j++) {
			board[i][j] = " ";
		}
	}
}

/** Mutator member function to check whether player 1 (X) fulfills the winning requirement
	@return - a bool argument whether X wins (True), X doesn't win (False)
*/
bool Game::checkX()
{
	/** if else statement to check whether X fulfills one of the winning conditions or not
	*/
	if ((board[0][0] == "X" && board[0][1] == "X" && board[0][1] == "X" && board[0][2] == "X") ||
		(board[1][0] == "X" && board[1][1] == "X" && board[1][1] == "X" && board[1][2] == "X") ||
		(board[2][0] == "X" && board[2][1] == "X" && board[2][1] == "X" && board[2][2] == "X") ||
		(board[0][0] == "X" && board[1][0] == "X" && board[1][0] == "X" && board[2][0] == "X") ||
		(board[0][1] == "X" && board[1][1] == "X" && board[1][1] == "X" && board[2][1] == "X") ||
		(board[0][2] == "X" && board[1][2] == "X" && board[1][2] == "X" && board[2][2] == "X") ||
		(board[0][0] == "X" && board[1][1] == "X" && board[1][1] == "X" && board[2][2] == "X") ||
		(board[0][2] == "X" && board[1][1] == "X" && board[1][1] == "X" && board[2][0] == "X")) {

		return true;

	}
	else {
		return false;
	}

}

/** Mutator member function to check whether player 2 (O) fulfills the winning requirement
	@return - a bool argument whether X wins (True), X doesn't win (False)
*/
bool Game::checkO()
{

	/** if else statement to check whether O fulfills one of the winning conditions or not
	*/
	if ((board[0][0] == "O" && board[0][1] == "O" && board[0][1] == "O" && board[0][2] == "O") ||
		(board[1][0] == "O" && board[1][1] == "O" && board[1][1] == "O" && board[1][2] == "O") ||
		(board[2][0] == "O" && board[2][1] == "O" && board[2][1] == "O" && board[2][2] == "O") ||
		(board[0][0] == "O" && board[1][0] == "O" && board[1][0] == "O" && board[2][0] == "O") ||
		(board[0][1] == "O" && board[1][1] == "O" && board[1][1] == "O" && board[2][1] == "O") ||
		(board[0][2] == "O" && board[1][2] == "O" && board[1][2] == "O" && board[2][2] == "O") ||
		(board[0][0] == "O" && board[1][1] == "O" && board[1][1] == "O" && board[2][2] == "O") ||
		(board[0][2] == "O" && board[1][1] == "O" && board[1][1] == "O" && board[2][0] == "O")) {

		return true;

	}
	else {

		return false;
	}
}


/**	Mutator member function to announce the winner
*/
void Game::announceWinner()
{
	/** if statement if player 1's score is greater than player 2's score, announce player 1 as winner and display scores and congratulations
	*/
	if (player1->getScore() > player2->getScore()) {
		std::cout << player1->getName() << " wins this round " << std::endl;
		std::cout << player1->getName() << " : " << player1->getScore() << std::endl;
		std::cout << player2->getName() << " : " << player2->getScore() << std::endl;
		std::cout << "Congratulations " << player1->getName() << ". You won!" << std::endl;
	}
	/** else if statement if player 2's score is greater than player 1's score, announce player 2 as winner and display scores and congratulations
	*/
	else if (player2->getScore() > player1->getScore()) {
		std::cout << player2->getName() << " wins this round " << std::endl;
		std::cout << player1->getName() << " : " << player1->getScore() << std::endl;
		std::cout << player2->getName() << " : " << player2->getScore() << std::endl;
		std::cout << "Congratulations " << player2->getName() << ". You won!" << std::endl;
	}
	/**	else if statement if player 1's score equals to player 2's score, announce no winner and display scores
	*/
	else if (player1->getScore() == player2->getScore()) {
		std::cout << "No winners this round " << std::endl;
		std::cout << player1->getName() << " : " << player1->getScore() << std::endl;
		std::cout << player2->getName() << " : " << player2->getScore() << std::endl;
		std::cout << "Draw! Play again to find out a winner!" << std::endl;
	}
}

