package com.anthony.tictactoe;

import java.util.Random;
import java.util.Scanner;

/**
 * the game class brings everything together (the board) and plays the game
 * @author Anthony Nguyen
 *
 */

public class game implements global {
	
	/**
	 * int used to decide the which players turn it is
	 */
	private int turn;
	
	/**
	 * type board, holds the game board (used to play the game)
	 */
	board gameBoard;
	
	/**
	 * a type abstract player is the PlayerO that will be used as the template for the concrete classes of player
	 */
	player playerO;
	
	/**
	 * a type abstract player is the PlayerX that will be used as the template for the concrete classes of player
	 */
	player playerX;
	
	
	/**
	 * method that starts the tic tac toe game
	 */
	public void start()
	{
		//Variables
		int input;	//input is used for the user selection
		String name1 = "";	//player 1's name
		String name2 = "";	//player 2's name
		
		//creates an instance of a board to play on
		gameBoard = new board();
		
		//creates a scanner for user input
		Scanner sc = new Scanner(System.in);
		//Creates a randomizer instance for a randomly coin toss to decide which player starts first
		Random rnd =  new Random();
		
		//Header
		System.out.println("TICTACTOE");
		System.out.println("[1] Human vs Human                 [2] Human vs AI                  [3] AI vs AI");
	
		//loop used for if the player enters an invalid selection not in the range 1-3 (inclusive)
		do {
			input = sc.nextInt();
			sc.nextLine();		//clears buffer of \n
			
			//if statements used to decide which game mode the player selects
			if(input == 1)
			{
				//player 1 enters name
				System.out.print("Enter human player X name: ");
				name1 = sc.nextLine();
				
				//player 2 enters name
				System.out.print("Enter human player O name: ");
				name2 = sc.nextLine();
				
				//creates the instance of the HumanPlayer for the abstract type player
				playerX = new HumanPlayer(gameBoard,X,name1);
				playerO = new HumanPlayer(gameBoard,O,name2);
			} 
			else if( input == 2)
			{
				//player 1 enters name
				System.out.print("Enter human player X name: ");
				name1 = sc.nextLine();	
				
				//bot's name is fixed to "BOT O"
				name2 = "BOT O";
				
				//creates an instance of HumanPlayer and AiPlayer
				playerX = new HumanPlayer(gameBoard,X,name1);
				playerO = new AIPlayer(gameBoard,O,name2);
			}
			else if( input == 3)
			{
				//BOT VS BOT
				name1 = "BOT X";
				name2 = "BOT O";
				
				//creates instance of AIPlayer for both players
				playerX = new AIPlayer(gameBoard,X,name1);
				playerO = new AIPlayer(gameBoard,O,name2);
			}
			else
				System.out.println("Invalid Command");		//promt if user enters invalid range
			
		} while(input != 1 && input != 2 && input != 3);	//loops if the user did not input the correct selection
		
		//randomly choose who starts first (1 or 2?)
		turn = rnd.nextInt(2) + 1;
		
		//prompts who gets to start first
		System.out.println(turn == 1? name1+" won the coin toss...X starts" : name2+" won the coin toss...O starts" );
		
		//plays the first turn depending on the randomly choosen turn
		if(turn == 1)
		{
			playerX.play(gameBoard);
		}
		else
			playerO.play(gameBoard);
		
		//loops the play method until the board's state is not EMPTY (when its either draw or a win)
		while(gameBoard.getState() == EMPTY)
		{
			//We increment turn every time we re-loop, when turn is a even number then playerO goes and odd PlayerX
			turn++;	//increments a turn
			if(turn % 2 == 0)		//Every even number is playerO's turn
			{
				playerO.play(gameBoard);
			}
			else					//Every odd number is playerX's turn
				playerX.play(gameBoard);
		}
		
		//prints the displayBoard to show the conclusion of the game
		System.out.println("\n");
		gameBoard.displayBoard();
		
		//States which player won or if there was a tie
		if(gameBoard.getState() == X)
			System.out.println("\n\n" + name1 + "[X] WON!!!");
		else if(gameBoard.getState() == O)
			System.out.println("\n\n" + name2 + "[O] WON!!!");
		else if(gameBoard.getState() == DRAW)
			System.out.println("\n\n DRAW");
		else
			System.out.println("ERROR");

			
	}
	
	
	
}
