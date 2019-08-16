package hw4;

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class GUICF extends CFGame{
	private GameBoard this_board;
	private JButton[] button = new JButton[7];
	private JButton startButton = new JButton("Play");
	private CFPlayer[] order = new CFPlayer[2];
	private JLabel winner;

	// private HumanPlayer class implments ActionListener and CFPlayer
	private class HumanPlayer implements ActionListener, CFPlayer{
		// public method
		// do nothing
		@Override
		public int nextMove(CFGame g){
			return 0;
		}

		// public method, return String
		// returns Human Player
		@Override
		public String getName(){
			return "Human Player";
		}

		// public method, ActionEvent parameter
		// play the column when button is pushed
		@Override
		public void actionPerformed(ActionEvent event){
			// if else statement
			// only play the column if (it is red turn & human player is red) or (it is black turn & human player is black)
			if(((isRedTurn()&&order[0]==this)||(!isRedTurn()&&order[1]==this))&&!isGameOver()){
				for(int i=0; i<7; i++){
					if(event.getSource()==button[i]){
						playGUI(i+1);
					}
				}
			}
		}
	}

	// private inner class implements ActionListener
	private class playButton implements ActionListener{
		// public method, ActionEvent parameter
		// generate two AI's moves for that turn
		@Override
		public void actionPerformed(ActionEvent event){
			// if else statement
			// generates moves if game is not over, otherwise prints winner's name
			if(!isGameOver()){
				playGUI(order[0].nextMove(GUICF.this));
				playGUI(order[1].nextMove(GUICF.this));
			}else{
				winner.setText("Winner: "+getWinner());
			}
		}
	}

	// Constructor for human vs ai game
	public GUICF(CFPlayer ai){
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
		JFrame frame = new JFrame("Connect Four");
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));

		JPanel buttonPanel = new JPanel(new GridLayout(1,7,5,5));
		// initializing array of buttons and add action listener
		for(int i=0; i<7; i++){
			button[i] = new JButton("\u2193");
			button[i].addActionListener(human);
			buttonPanel.add(button[i]);
		}

		JPanel labelPanel = new JPanel();
		JLabel winner = new JLabel("Human vs AI");
		labelPanel.add(winner);
		
		this_board = new GameBoard();
		mainPanel.add(buttonPanel);
		mainPanel.add(this_board);
		mainPanel.add(labelPanel);

		frame.getContentPane().add(mainPanel);

		frame.setSize(650,650);
		frame.setVisible(true);

		// while loop
		// continue playing until game is over
		while(!isGameOver()){
			// if else statement
			// ai only plays is (it is red's turn and ai is red) or (it is black's turn and ai is black)
			if((isRedTurn()&&order[0]==ai)||(!isRedTurn()&&order[1]==ai)){
				playGUI(ai.nextMove(this));
			}
		}

		winner.setText("Winner: "+getWinner());
	}

	// Constructor for ai vs ai game
	public GUICF(CFPlayer ai1, CFPlayer ai2){
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
		JFrame frame = new JFrame("Connect Four");
		frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));

		JPanel buttonPanel = new JPanel();
		startButton.addActionListener(new playButton());
		buttonPanel.add(startButton);

		JPanel labelPanel = new JPanel();
		winner = new JLabel("AI vs AI");
		labelPanel.add(winner);

		this_board = new GameBoard();
		mainPanel.add(buttonPanel);
		mainPanel.add(this_board);
		mainPanel.add(labelPanel);

		frame.getContentPane().add(mainPanel);

		frame.setSize(650,650);
		frame.setVisible(true);
	}

	// private method, int parameter, return boolean
	// returns true and play the column if it can be played, false otherwise
	private boolean playGUI(int c){
		boolean played = false;
		for(int i=0; i<6; i++){
			if(getState()[c-1][i]==0){
				played = true;
			}
		}
		if(played){
			int i = 5;
			while(getState()[c-1][i]!=0){
				i = i - 1;
			}
			if(isRedTurn()){
				this_board.paint(i,c-1,1);
				play(c);
				this_board.revalidate();
				this_board.repaint();
			}else{
				this_board.paint(i,c-1,-1);
				play(c);
				this_board.revalidate();
				this_board.repaint();
			}
			return true;
		}
		return false;
	}

	// private method, return String
	// returns winner's name
	private String getWinner(){
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

	// private inner class inherits JPanel
	private class GameBoard extends JPanel{
		private JLabel[][] grid = new JLabel[6][7];
		private JButton[] button = new JButton[7];
		// Constructor
		private GameBoard(){
			this.setLayout(new GridLayout(6,7,5,5));
			// for loop
			// initializing array of labels in a 6*7 grid
			for(int i=0; i<6; i++){
				for(int j=0; j<7; j++){
					grid[i][j] = new JLabel();
					grid[i][j].setOpaque(true);
					grid[i][j].setBackground(Color.white);
					grid[i][j].setBorder(new LineBorder(Color.black));
					this.add(grid[i][j]);
				}
			}
			this.setVisible(true);
		}

		// private method, int parameter, int parameter, int parameter
		// paints slots (x,y) in red or black
		private void paint(int x, int y, int color){
			if(color==1){
				grid[x][y].setBackground(Color.red);
			}else if(color==-1){
				grid[x][y].setBackground(Color.black);
			}
		}
	}
}