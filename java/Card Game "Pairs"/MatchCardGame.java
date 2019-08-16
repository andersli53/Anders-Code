package hw2;

public class MatchCardGame {
	// fields
	public final int n;
	private int num_type;
	private char board[];
	private boolean faceUp[];
	private int[] previousPos = new int[2];
	private int num_flip = 0;
	private boolean alternate = false;
	private boolean match = false;

	// constructor
	// parameter: gameboard size in int
	public MatchCardGame(int n) {
		this.n = n;
		num_type = n/4;
		board = new char[n];
		faceUp = new boolean[n];
		int letter = 97;
		// for loop
		// initialize the gameboard with different letters without shuffling
		for(int i = 0; i < board.length; i++){
			// if else statement
			// initialize each letter 4 times
			if(i != 0 && i % 4 == 0){
				letter += 1;
				board[i] = (char) letter;
			}else{
				board[i] = (char) letter;
			}
		}
	}

	// methods
	// public method
	// print gameboard
	// return type: String 
	public String boardToString() {
		String gameboard = "";
		// for loop
		// loop over gameboard for printing
		for(int i = 0; i < board.length; i++){
			// if else statement
			// print letter if it is flipped, otherwise print |*i*|
			if(faceUp[i] == true){
				gameboard += "| "+board[i]+" |";
			}else{
				gameboard += "|*"+i+"*|";
			}
		}
		return gameboard;
	}

	// public method
	// record a flip
	// return type: boolean
	public boolean flip(int i) {
		// if else statement
		// return false if card is face-up and the number is within range
		if(faceUp[i] == true || i < 0 || i > n){
			return false;
		}else{
			// if else statement
			// store flipped card position and face-up state
			if(!alternate){
				previousPos[0] = i;
				faceUp[previousPos[0]] = true;
				alternate = true;
			}else{
				previousPos[1] = i;
				faceUp[previousPos[1]] = true;
				alternate = false;
			}
			num_flip = num_flip + 1;
			return true;

		}
	}

	// public method
	// check if previous 2 flips were a match
	// return type: boolean
	public boolean wasMatch() {
		// if else statement
		// change face-up state if after even number of flips and previous two flips were a match
		if((num_flip % 2 ==0) && (board[previousPos[0]] == board[previousPos[1]])){
			faceUp[previousPos[0]] = true;
			faceUp[previousPos[1]] = true;
			match = true;
		}else{
			match = false;
		}
		return match;
	}

	// public method
	// return previous flipped card
	// return type: char
	public char previousFlipIdentity() {
		char card = '*';
		// if else statement
		// return the face of the card based on whether it is an odd or even flip
		if(alternate){
			card = board[previousPos[0]];
		}else{
			card = board[previousPos[1]];
		}
		return card;
	}

	// public method
	// turn previous flipped card's face-up state to false
	// no return type
	public void flipMismatch(){
		faceUp[previousPos[0]] = false;
		faceUp[previousPos[1]] = false;
	}

	// public method
	// deteremines if the game is over
	// return type: boolean
	public boolean gameOver() {
		// for loop
		// loop over faceUp arrays, if all cards are face-up, then it is game over
		for(int i = 0; i < faceUp.length; i++){
			// if else statement
			// check if all cards are face-up
			if(!faceUp[i]){
				return false;
			}
		}
		return true;
	}

	// public method
	// returns number of flips
	// return type: int
	public int getFlips() {
		return num_flip;
	}

	// public method
	// shuffles card using Fisher-Yates shuffle
	// no return type
	public void shuffleCards() {
		java.util.Random rand = new java.util.Random();
		// for loop
		// loop over gameboard to shuffle cards
		for(int i = 0; i < board.length; i++){
			int randomValue = i + rand.nextInt(board.length - i);
			char randomLetter = board[randomValue];
			board[randomValue] = board[i];
			board[i] = randomLetter;
		}
	}
}