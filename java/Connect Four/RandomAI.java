package hw4;

import java.util.Random;

public class RandomAI implements CFPlayer{
	// public method, CFGame parameter, return int
	// returns randomly generated column
	@Override
	public int nextMove(CFGame g){
		boolean full = true;
		Random rand = new Random();
		int randomColumn = rand.nextInt(7);
		// while loop
		// generate new random column if the previous is full
		while(full){
			randomColumn = rand.nextInt(7);
			if(g.getState()[randomColumn][0]==0){
				full = false;
			}
		}
		return randomColumn+1;
	}

	// public method, return String
	// returns Random Player
	@Override
	public String getName(){
		return "Random Player";
	}
}