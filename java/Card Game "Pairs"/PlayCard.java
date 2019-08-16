package hw2;

public class PlayCard {
  // fields
  private static boolean faceUp[];
  private static char knownCard[];
  private static int[] posKnown = new int[2];

  // methods
  // private static method
  // randomly flip two unknown cards
  // no return type
  private static void randomChoice(MatchCardGame g){
    java.util.Random rand = new java.util.Random();

    int rand1 = rand.nextInt(g.n);
    int rand2 = rand.nextInt(g.n);
    // while loop
    // continuously get two random numbers within the range of the size of gameboard until
    // two distinct cards are unknown and 
    while(faceUp[rand1] || faceUp[rand2] || (rand1 == rand2)){
      rand1 = rand.nextInt(g.n);
      rand2 = rand.nextInt(g.n);
    }
    g.flip(rand1);
    g.flip(rand2);
    // if else statement
    // check if the previous two flips were a match, change face-up state for each card if true
    // otherwise flip back the cards
    if(g.wasMatch()){
      faceUp[rand1] = true;
      faceUp[rand2] = true;
    }else{
      g.flipMismatch();
    }
  }

  // private static method
  // return true if there are known pairs in knownCard array
  // return type: boolean
  private static boolean duplicate(){
    // for loops
    // loop through the knownCard array to check if two cards are identical
    for(int i = 0; i < knownCard.length; i++){
      for(int j = i + 1; j < knownCard.length; j++){
        // if else statement
        // store position of the two identical cards if they are identical, not face-up, and not null
        if((knownCard[i]==knownCard[j])&&!faceUp[i]&&!faceUp[j]&&knownCard[i]!=(char) 0 &&knownCard[j]!=(char) 0){
          posKnown[0] = i;
          posKnown[1] = j;
          return true;
        }
      }
    }
    return false;
  }

  // private static method
  // return true if there is a known card that can make a match
  // return type: boolean
  private static boolean dupSingle(char letter){
    boolean dup = false;
    // for loop
    // loop over the knownCard array to check if such card exists
    for(int i = 0; i < knownCard.length; i++){
      // if else statement
      // store the position of this particular card if it is the same as the previously flipped card, not face-up, and doesn't have the same position
      if((knownCard[i] == letter) && (!faceUp[i]) && (i!=posKnown[0])){
        dup = true;
        posKnown[1] = i;
      }
    }
    return dup;
  }

  // private static method
  // return true if game is finished, i.e. all cards are face-up
  // return type: boolean
  private static boolean finish(){
    // for loop
    // loop through the faceUp array to check if all cards are face-up
    for(int i = 0; i < faceUp.length; i++){
      // if else statement
      // check if every element is true
      if(!faceUp[i]){
        return false;
      }
    }
    return true;
  }

  // public static method
  // return the number of flips when AI plays randomly
  // return type: int
  public static int playRandom(MatchCardGame g) {
    faceUp = new boolean[g.n];
    // for loop
    // initialize all cards' face-up state to false 
    for(int i = 0; i < faceUp.length; i++){
      faceUp[i] = false;
    }
    // while loop
    // continue playing until game is over
    while(!g.gameOver()){
      randomChoice(g);
    }
    return g.getFlips();
  }

  // public static method
  // return the number of flips when AI plays with perfect memory
  // return type: int
  public static int playGood(MatchCardGame g) {
    faceUp = new boolean[g.n];
    knownCard = new char[g.n];
    // for loop
    // initialize all cards' face-up state to false and all known cards to be null
    for(int i = 0; i < faceUp.length; i++){
      faceUp[i] = false;
      knownCard[i] = (char) 0;
    }
    // while loop
    // keep playing until game is finished
    while(!finish()){
      // if else statement
      // AI plays differently on odd and even turns
      if(g.getFlips()%2==0){
        // if else statement
        // if there's a known pair after the even flip, flip the pair and store the faces in knownCard in according position
        if(duplicate()){
          g.flip(posKnown[0]);
          knownCard[posKnown[0]] = g.previousFlipIdentity();
          g.flip(posKnown[1]);
          knownCard[posKnown[1]] = g.previousFlipIdentity();
          // if else statement
          // change faceUp state if they are a match
          if(g.wasMatch()){
            faceUp[posKnown[0]] = true;
            faceUp[posKnown[1]] = true;
          }
        }else{
          java.util.Random rand = new java.util.Random();
          int rand1 = rand.nextInt(g.n);
          // while loop
          // keep generating random number until the card isn't face-up and not equal to null
          while(faceUp[rand1] || knownCard[rand1]!=(char) 0){
            rand1 = rand.nextInt(g.n);
          }
          g.flip(rand1);
          posKnown[0] = rand1;
          knownCard[posKnown[0]] = g.previousFlipIdentity();
        }
      }else{
        // if else statement
        // if there is a known card after the odd flip, flip that card and store the face in knownCard in according position
        if(dupSingle(knownCard[posKnown[0]])){
          g.flip(posKnown[1]);
          knownCard[posKnown[1]] = g.previousFlipIdentity();
        }else{
          java.util.Random rand = new java.util.Random();
          int rand2 = rand.nextInt(g.n);
          // while loop
          // keep generating random number until the card isn't face-up and not equal to null
          while(faceUp[rand2] || knownCard[rand2] != (char) 0){
            rand2 = rand.nextInt(g.n);
          }
          g.flip(rand2);
          posKnown[1] = rand2;
          knownCard[posKnown[1]] = g.previousFlipIdentity();
        }
        // if else statement
        // if the two previously flipped cards were a match, change their face-up state
        // otherwise flip back those cards
        if(g.wasMatch()){
          faceUp[posKnown[0]] = true;
          faceUp[posKnown[1]] = true;
        }else{
          g.flipMismatch();
        }
      }
    }
    return g.getFlips();
  }

  // public static method
  // lets AI to play randomly and record the average number of flips
  // return type: double
  public static double randomMC(int N) {
    int totalFlips = 0;
    // for loop
    // keep playing for N tiems
    for(int i = 0; i < N; i++){
      MatchCardGame g = new MatchCardGame(32);
      g.shuffleCards();
      totalFlips = totalFlips + playRandom(g);
    }
    double average = (double) totalFlips/N;
    return average;
  }

  // public static method
  // lets AI to play with perfect memory and record the average number of flips
  // return type: double
  public static double goodMC(int N) {
    int totalFlips = 0;
    // for loop
    // keep playing for N tiems
    for(int i = 0; i < N; i++){
      MatchCardGame g = new MatchCardGame(32);
      g.shuffleCards();
      totalFlips = totalFlips + playGood(g);
    }
    double average = (double) totalFlips/N;
    return average;
  }

  // public static main method
  public static void main(String[] args) {
    //set up reader to take inputs
    java.util.Scanner reader = new java.util.Scanner (System.in);
    
    int n = 16; //game size
    MatchCardGame g1 = new MatchCardGame(n);
    g1.shuffleCards();
    
    while(!g1.gameOver()) {
      //print board status
      System.out.println(g1.boardToString());

      //ask for a card to flip until we get a valid one
      System.out.println("Which card to play?");
      while(!g1.flip(reader.nextInt())) {}
      
      //print board status
      System.out.println(g1.boardToString());

      //ask for a card to flip until we get a valid one
      while(!g1.flip(reader.nextInt())) {}

      //say whether the 2 cards were a match
      if(g1.wasMatch()) {
        System.out.println("Was a match!");
      } else {
        //print board to show mismatched cards
        System.out.println(g1.boardToString());		
        System.out.println("Was not a match.");
        //flip back the mismatched cards
        g1.flipMismatch();
      }
    }
    
    //Report the score
    System.out.println("The game took " + g1.getFlips() + " flips.");
    
    //Using the AIs
    int count;
    MatchCardGame g2 = new MatchCardGame(n);
    g2.shuffleCards();
    count = playRandom(g2);
    System.out.println("The bad AI took " + count + " flips.");
    MatchCardGame g3 = new MatchCardGame(n);
    g3.shuffleCards();
    count = playGood(g3);
    System.out.println("The good AI took " + count + " flips.");
    
    // //Using MCs
    int N = 1000;
    System.out.println("The bad AI took " + randomMC(N) + " flips on average.");
    System.out.println("The good AI took " + goodMC(N) + " flips on average.");
  }
}