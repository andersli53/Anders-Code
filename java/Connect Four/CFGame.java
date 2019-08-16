package hw4;

public class CFGame {
  //state[i][j]= 0 means the i,j slot is empty
  //state[i][j]= 1 means the i,j slot has red
  //state[i][j]=-1 means the i,j slot has black
  private final int[][] state;
  private boolean isRedTurn;
  private boolean played;
  
  {
    state = new int[7][6];
    for (int i=0; i<7; i++)
      for (int j=0; j<6; j++)
        state[i][j] = 0;
    isRedTurn = true; //red goes first
  }
  
  // public method, return int[][]
  // returns current state of the game
  public int[][] getState() {
    int[][] ret_arr = new int[7][6];
    for (int i=0; i<7; i++)
      for (int j=0; j<6; j++)
        ret_arr[i][j] = state[i][j];
    return ret_arr;
  }
  
  // public method, return boolean
  // return turn, true if it's red's turn, false if it's black's turn
  public boolean isRedTurn() {
    return isRedTurn;
  }
  
  // public method, int parameter, return boolean
  // return true if column can be played
  public boolean play(int column) {
    played = false;
    // for loop
    // loop around the column to find valid slot to play
    for(int i=0; i<6; i++){
      if(state[column-1][i]==0){
        played = true;
      }
    }
    // if else statement
    // play the column according to the validity of slot
    if(column>=1&&column<=7&&played){
      int i = 5;
      while(state[column-1][i]!=0){
        i = i - 1;
      }
      if(columnFull(column-1)){
        if(isRedTurn){
          state[column-1][i] = 1;
          isRedTurn = false;
        }else{
          state[column-1][i] = -1;
          isRedTurn = true;
        }
        return true;
      }
    }
    return false;
  }
  
  // private method, int parameter, return boolean
  // returns true if column if full, false if not
  private boolean columnFull(int column){
    for(int i=0; i<6; i++){
      if(state[column][i]==0){
        return true;
      }
    }
    return false;
  }

  // public method, return boolean
  // return true if game is over, false otherwise
  public boolean isGameOver() {
    if(winner()==1||winner()==-1||boardFull()){
      return true;
    }
    return false;
  }
  
  // public method, return int
  // returns 1 if red wins, returns -1 if black wins, returns 0 if draw
  public int winner() {
    int winner = 0;
    for(int i=0; i<7; i++){
      for(int j=0; j<6; j++){
        if(horizontal(i,j)||vertical(i,j)||diagonal(i,j)){
          winner = state[i][j];
        }
      }
    }
    return winner;
  }

  // public method, return boolean
  // return true if board is full, false otherwise
  public boolean boardFull(){
    // for loop
    // check if every slot is filled up with 1 and -1
    for(int i=0; i<7; i++){
      for(int j=0; j<6; j++){
        if(state[i][j]==0){
          return false;
        }
      }
    }
    return true;
  }

  // private method, int paramster, int parameter, return boolean
  // returns true if there's a winning situation in diagonal direction, false otherwise
  private boolean diagonal(int c, int r){
    boolean connected = false;
    // if else statement
    // check every possibilities in different slots
    if(state[c][r]!=0){
      int slot = state[c][r];
      if(c<=3&&r<3){
        if(state[c+1][r+1]==slot&&state[c+2][r+2]==slot&&state[c+3][r+3]==slot){
          connected = true;
        }
      }else if(c>=3&&r<3){
        if(state[c-1][r+1]==slot&&state[c-2][r+2]==slot&&state[c-3][r+3]==slot){
          connected = true;
        }
      }else if(c<=3&&r>=3){
        if(state[c+1][r-1]==slot&&state[c+2][r-2]==slot&&state[c+3][r-3]==slot){
          connected = true;
        }
      }else if(c>=3&&r>=3){
        if(state[c-1][r-1]==slot&&state[c-2][r-2]==slot&&state[c-3][r-2]==slot){
          connected = true;
        }
      }else if(c==3&&r==3){
        if((state[c-1][r-1]==slot&&state[c-2][r-2]==slot&&state[c-3][r-2]==slot)||(state[c+1][r-1]==slot&&state[c+2][r-2]==slot&&state[c+3][r-3]==slot)){
          connected = true;
        }
      }
    }
    return connected;
  }

  // private method, int parameter, int parameter, return boolean
  // returns true if there's a winning situation in the horizontal direction, false otherwise
  private boolean horizontal(int c, int r){
    boolean connected = false;
    // if else statement to check every possibilities in different slots
    if(state[c][r]!=0){
      int slot = state[c][r];
      if(c<3){
        if(state[c+1][r]==slot&&state[c+2][r]==slot&&state[c+3][r]==slot){
          connected = true;
        }
      }else{
        if(state[c-1][r]==slot&&state[c-2][r]==slot&&state[c-3][r]==slot){
          connected = true;
        }
      }
    }
    return connected;  
  }

  // private method, int parameter, int parameter, return boolean
  // returns true if there's a winning situation in the vertical direction, false otherwise
  private boolean vertical(int c, int r){
    boolean connected = false;
    // if else statement to check every possibilities in different slots
    if(state[c][r]!=0){
      int slot = state[c][r];
      if(r<3){
        if(state[c][r+1]==slot&&state[c][r+2]==slot&&state[c][r+3]==slot){
          connected = true;
        }
      }else{
        if(state[c][r-1]==slot&&state[c][r-2]==slot&&state[c][r-3]==slot){
          connected = true;
        }
      }
    }
    return connected;
  }
}
