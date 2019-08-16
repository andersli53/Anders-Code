package hw4;

import java.util.Random;
import java.util.Scanner;

public class ConsoleCF extends CFGame{
	private CFPlayer[] order = new CFPlayer[2];

	// Constructor for human vs ai game
	public ConsoleCF(CFPlayer ai){
		Random rand = new Random();
		boolean aiRed = rand.nextBoolean();
		HumanPlayer human = new HumanPlayer();
		// if else statement
		// Randomizing order
		if(aiRed){
			order[0] = ai;
			order[1] = human;
		}else{
			order[0] = human;
			order[1] = ai;
		}
	}

	// Constructor for ai vs ai game
	public ConsoleCF(CFPlayer ai1, CFPlayer ai2){
		Random rand = new Random();
		boolean ai1Red = rand.nextBoolean();
		// if else statement
		// Randomizing order
		if(ai1Red){
			order[0] = ai1;
			order[1] = ai2;
		}else{
			order[0] = ai2;
			order[1] = ai1;
		}
	}

	// public method
	// continue playing until game is over
	public void playOut(){
		while(!isGameOver()){
			// alternating red and black
			if(isRedTurn()){
				play(order[0].nextMove(this));
			}else{
				play(order[1].nextMove(this));
			}
		}

	}

	// public method, return String
	// returns name of the winner
	public String getWinner(){
		String winner = "";
		if(winner()==0){
			winner = "draw";
		}else if(winner()==1){
			winner = order[0].getName();
		}else if(winner()==-1){
			winner = order[1].getName();
		}
		return winner;
	}

	// private inner class for human player
	private class HumanPlayer implements CFPlayer{
		// public method, CFGame parameter, return int
		// returns human player's (user's) move
		@Override
		public int nextMove(CFGame g){
			for(int j=0; j<6; j++){
				for(int i=0; i<7; i++){
					System.out.print(g.getState()[i][j]+" ");
				}
				System.out.print("\n");
			}
			Scanner scanner = new Scanner(System.in);
			System.out.print("Next Move? ");
			int col = scanner.nextInt();
			return col;
		}

		// public method, return String
		// return "human player"
		@Override
		public String getName(){
			return "Human Player";
		}
	}

}