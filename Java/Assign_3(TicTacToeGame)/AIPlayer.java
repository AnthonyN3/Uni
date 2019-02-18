package com.anthony.tictactoe;

import java.util.Random;

/**
 * Extends player, a type of player that implements a simple computer player.
 * The strategy is to play a valid random move. 
 * @author Anthony Nguyen
 */

public class AIPlayer extends player implements global{
	
	/**
	 * overloaded constructor used to input the AI players name, symbol and the board in which it will play on
	 * @param gameBoard
	 * @param playerSymbol
	 * @param playerName
	 */
	public AIPlayer(board gameBoard, int playerSymbol, String playerName)
	{
		super(gameBoard, playerSymbol, playerName);
	}
	
	/**
	 * Method that simply lets the bot "play" a move on the board
	 */
	public void play(board gameBoard)
	{	
		//randomly chooses a move that is legal/free on the board
		int move = randomLegalMove();
	
		//displays that the bot has moved
		System.out.println( "\n" + playerName +" MOVES TO " + move);
		
		//Makes the randomized move
		gameBoard.makeMove(move, super.playerSymbol);
		
		//Displays the board to show where the bot moved
		gameBoard.displayBoard();
		
	}
	
	/**
	 * A simply method that returns a random valid position on the game board
	 * @return A free and valid position on the game board
	 */
	private int randomLegalMove()
	{
		//Variables
		int freeSpace = 0;	//Counts the amount of free spaces in the board
		int i = 1;	//This is used to reference how the indexes are named on the board to be stored in the array
		int [] spots = new int[9];	//An array of size 9 to hold all the free spaces in the board
		
		//loops through the 2d board array to check for empty spaces
		for(int rows = 0 ; rows < 3; rows++)
		{
			for(int cols = 0 ; cols < 3 ; cols++)
			{
				//If empty space is found it will input its index from the board to the spots arrays
				if(super.gameBoard.blocks[rows][cols].getState() == EMPTY)
				{
					spots[freeSpace] = i;
					freeSpace++;
				}
				i++;	
			}
		}
		
		//Creates an instance of random used to randomize the spots choosen in spots
		Random rnd = new Random();
		
		//used to choose  a random spot in the array spot
		int randomMove = rnd.nextInt(freeSpace);
	
		return spots[randomMove];	//returns a random free spot in the board
	}
}
