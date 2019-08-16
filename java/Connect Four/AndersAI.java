package hw4;

public class AndersAI implements CFPlayer{
	// public method, CFGame parameter, return int
	// generates AI's next move (column)
	@Override
	public int nextMove(CFGame g){
		int[][] stateCopy = new int[7][6];
		int winningMove = 0;
		int temp = 0;
		boolean winningChance = false;
		// for loop
		// copy current game's state
		for(int i=0; i<7; i++){
			for(int j=0; j<6; j++){
				stateCopy[i][j] = g.getState()[i][j];
			}
		}
		CFGameCopy gc = new CFGameCopy(stateCopy, g.isRedTurn());

		// double for loop
		// check if there's a winning move in vertical, horizontal, or diagonal
		// if yes, either block or play the move to win
		outerloop:
		for(int i=0; i<7; i++){
			for(int j=0; j<6; j++){
				if(gc.vertical(i,j,1)||gc.vertical(i,j,-1)){
					if(!gc.columnFull(gc.getTempCol())){
						winningChance = true;
						temp = gc.getTempCol();
						break outerloop;
					}else{
						winningChance = false;
					}
				}else if(gc.horizontal(i,j,1)||gc.horizontal(i,j,-1)||gc.diagonal(i,j,1)||gc.diagonal(i,j,-1)){
					if(!gc.columnFull(gc.getTempCol())){
						winningChance = true;
						temp = gc.getTempCol();
						break outerloop;
					}else{
						winningChance = false;
					}
				}
			}
		}

		// if else statement
		// if there's a winning chance in either one of the three directions, return the column, else play randomly
		if(winningChance){
			winningMove = temp+1;
		}else{
			RandomAI randomAI = new RandomAI();
			winningMove = randomAI.nextMove(g);
		}

		return winningMove;
	} 

	// public method, return String
	// returns Anders' AI
	@Override
	public String getName(){
		return "Anders' AI";
	}

	// private inner class for the copy of the game's state
	private class CFGameCopy{
		private int[][] copy = new int[7][6];
		private boolean isRedTurn;
		private boolean played;
		private int tempRow = 0;
		private int tempCol = 0;

		// Constructor, int[][] parameter, boolean parameter
		public CFGameCopy(int[][] copy, boolean isRedTurn){
			this.copy = copy;
			this.isRedTurn = isRedTurn;
		}

		// private method, return int[][]
		// copies the game's current state
		private int[][] getStateCopy(){
			int[][] ret_arr = new int[7][6];
    		for (int i=0; i<7; i++)
      		for (int j=0; j<6; j++)
        		ret_arr[i][j] = copy[i][j];
    		return ret_arr;
		}

		// private method, return boolean
		// returns true if red's turn, false if black's turn
		private boolean isRedTurn(){
			return isRedTurn;
		}

		// private method, return int
		// returns the temporary stored row
		private int getTempRow(){
			return tempRow;
		}

		// private method, int parameter, return boolean
		// returns true if column is full, false otherwise
		private boolean columnFull(int column){
			if(getStateCopy()[column][0]==0){
				return false;
			}
			return true;
		}

		// private method, return int
		// returns the temporary stored column
		private int getTempCol(){
			return tempCol;
		}

		// private method, int parameter, in parameter, int parameter, return boolean
		// returns true if there's a winning or losing chance in diagonal directions
		private boolean diagonal(int c, int r, int slot){
			boolean connected = false;
			// if else statement to check if there's a winning/losing chance in the diagonal directions for different slots
		    if(copy[c][r]==slot){
		     	if(c<=3&&r<3){
		        	if(copy[c+1][r+1]==slot){
		          		connected = true;
		          		tempCol = c+2;
		          		tempRow = r+2;
		        	}else if(copy[c+1][r+1]==slot&&copy[c+2][r+2]==slot){
		        		connected = true;
		        		tempCol = c+3;
		        		tempRow = r+3;
		        	}else if(copy[c+2][r+2]==slot&&copy[c+3][r+3]==slot){
		        		connected = true;
		        		tempCol = c+1;
		        		tempRow = r+1;
		        	}else if(copy[c+1][r+1]==slot&&copy[c+3][r+3]==slot){
		        		connected = true;
		        		tempCol = c+2;
		        		tempRow = r+2;
		        	}
		      	}else if(c>=3&&r<3){
		        	if(copy[c-1][r+1]==slot){
		          		connected = true;
		          		tempCol = c-2;
		          		tempRow = r+2;
		        	}else if(copy[c-1][r+1]==slot&&copy[c-2][r+2]==slot){
		        		connected = true;
		        		tempCol = c-3;
		        		tempRow = r+3;
		        	}else if(copy[c-2][r+2]==slot&&copy[c-3][r+3]==slot){
		        		connected = true;
		        		tempCol = c-1;
		        		tempRow = r+1;
		        	}else if(copy[c-1][r+1]==slot&&copy[c-3][r+3]==slot){
		        		connected = true;
		        		tempCol = c-2;
		        		tempRow = r+2;
		        	}
		      	}else if(c<=3&&r>=3){
		        	if(copy[c+1][r-1]==slot){
		          		connected = true;
		          		tempCol = c+2;
		          		tempRow = r-2;
		        	}else if(copy[c+1][r-1]==slot&&copy[c+2][r-2]==slot){
		        		connected = true;
		        		tempCol = c+3;
		        		tempRow = r-3;
		        	}else if(copy[c+2][r-2]==slot&&copy[c+3][r-3]==slot){
		        		connected = true;
		        		tempCol = c+1;
		        		tempRow = r-1;
		        	}else if(copy[c+1][r-1]==slot&&copy[c+3][r-3]==slot){
		        		connected = true;
		        		tempCol = c+2;
		        		tempRow = r-2;
		        	}
		      	}else if(c>=3&&r>=3){
		        	if(copy[c-1][r-1]==slot){
		          		connected = true;
		          		tempCol = c-2;
		          		tempRow = r-2;
		        	}else if(copy[c-1][r-1]==slot&&copy[c-2][r-2]==slot){
		        		connected = true;
		        		tempCol = c-3;
		        		tempRow = r-3;
		        	}else if(copy[c-2][r-2]==slot&&copy[c-3][r-3]==slot){
		        		connected = true;
		        		tempCol = c-1;
		        		tempRow = r-1;
		        	}else if(copy[c-1][r-1]==slot&&copy[c-3][r-3]==slot){
		        		connected = true;
		        		tempCol = c-2;
		        		tempRow = r-2;
		        	}
		      	}else if(c==3&&r==3){
		        	if(copy[c-1][r-1]==slot){
		          		connected = true;
		          		tempCol = c-2;
		          		tempRow = r-2;
		        	}else if(copy[c+1][r+1]==slot){
		        		connected = true;
		        		tempCol = c+2;
		        		tempRow = r+2;
		        	}else if(copy[c-1][r-1]==slot&&copy[c-2][r-2]==slot){
		        		connected = true;
		        		tempCol = c-3;
		        		tempRow = r-3;
		        	}else if(copy[c+1][r+1]==slot&&copy[c+2][r+2]==slot){
		        		connected = true;
		        		tempCol = c+3;
		        		tempRow = r+3;
		        	}else if(copy[c-2][r-2]==slot&&copy[c-3][r-3]==slot){
		        		connected = true;
		        		tempCol = c-1;
		        		tempRow = r-1;
		        	}else if(copy[c+2][r+2]==slot&&copy[c+3][r+3]==slot){
		        		connected = true;
		        		tempCol = c+1;
		        		tempRow = r+1;
		        	}else if(copy[c-1][r-1]==slot&&copy[c-3][r-3]==slot){
		        		connected = true;
		        		tempCol = c+2;
		        		tempRow = r+2;
		        	}else if(copy[c+1][r+1]==slot&&copy[c+3][r+3]==slot){
		        		connected = true;
		        		tempCol = c-2;
		        		tempRow = r-2;
		        	}
		      	}
		    }
		    return connected;
		}

		// private method, int parameter, int parameter, int parameter, return boolean
		// returns true if there's a winning or losing chance in the horizontal directions
		private boolean horizontal(int c, int r, int slot){
		    boolean connected = false;
		    // if else statement
		    // checkes whether there's a winning/losing chance in the horizontal directions for different slots
		    if(copy[c][r]==slot){
		    	if(c<3){
		        	if(copy[c+1][r]==slot){
		        		connected = true;
		        		tempCol = c+2;
		        		tempRow = r;
		        	}else if(copy[c+1][r]==slot&&copy[c+2][r]==slot){
		        		connected = true;
		        		tempCol = c+3;
		        		tempRow = r;
		        	}else if(copy[c+2][r]==slot&&copy[c+3][r]==slot){
		        		connected = true;
		        		tempCol = c+1;
		        		tempRow = r;
		        	}else if(copy[c+1][r]==slot&&copy[c+3][r]==slot){
		        		connected = true;
		        		tempCol = c+2;
		        		tempRow = r;
		        	}
		      	}else{
		      		if(copy[c-1][r]==slot){
		      			connected = true;
		      			tempCol = c-2;
		      			tempRow = r;
		      		}else if(copy[c-1][r]==slot&&copy[c-2][r]==slot){
		      			connected = true;
		      			tempCol = c-3;
		      			tempRow = r;
		      		}else if(copy[c-2][r]==slot&&copy[c-3][r]==slot){
		      			connected = true;
		      			tempCol = c-1;
		      			tempRow = r;
		      		}else if(copy[c-1][r]==slot&&copy[c-3][r]==slot){
		      			connected = true;
		      			tempCol = c-2;
		      			tempRow = r;
		      		}
		      	}
		    }
		    return connected;  
		}

		// private method, int parameter, int parameter, int parameter, return boolean
		// returns true if there's a winning or losing chance in the vertical directions
		private boolean vertical(int c, int r, int slot){
			boolean connected = false;
			// if else statement
			// checks whether there's a winning/losing chance in the vertical directions for different slots
		    if(copy[c][r]==slot){
		    	if(r<3){
		        	if(copy[c][r+1]==slot){
		          		connected = true;
		          		tempCol = c;
		          		tempRow = r+2;
		        	}else if(copy[c][r+1]==slot&&copy[c][r+2]==slot){
		        		connected = true;
		        		tempCol = c;
		        		tempRow = r+3;
		        	}
		      	}else{
		        	if(copy[c][r-1]==slot){
		          		connected = true;
		          		tempCol = c;
		          		tempRow = r-2;
		        	}else if(copy[c][r-1]==slot&&copy[c][r-2]==slot){
		        		connected = true;
		        		tempCol = c;
		        		tempRow = r-3;
		        	}
		      	}
		    }
		    return connected;
		} 
	}	
}