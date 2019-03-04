package com.anthony.tictactoe;

import java.util.Scanner;

/**
 * Concrete class HumanPlayer that extends the abstract class Player creates a class in which a human player can play tictactoe
 * @author Anthony
 *
 */

public class HumanPlayer extends player implements global{

	/**
	 * Overloaded constructor takes the inputs and stores them in the variables of the its parent class "Player"
	 * @param gameBoard - The game board
	 * @param playerSymbol - The players symbol ( X or O)
	 * @param playerName - The players name
	 */
	public HumanPlayer(board gameBoard, int playerSymbol, String playerName)
	{	
		//Stores the objects and variables into the parent class
		super(gameBoard, playerSymbol, playerName);
	}
	
	/**
	 * A method that creates a nicely made play instruction for the user to play a move on the board.
	 * It will display the board and ask the user to input a move and then move their symbol onto the table
	 */
	public void play(board gameBoard)
	{	
		//create an instance of a scanner
		Scanner sca = new Scanner(System.in);
		
		//Prompts the selected board so the user can see which spots are free in the board
		System.out.println("\n");
		gameBoard.displayPlayerSelectionBoard();
		
		//Prints the player that is suppose to be moving and which place he/she wants to move
		System.out.printf("%s%s%s\n", "PLAYER[", super.playerSymbol == X ? "X]: " : "O]: " , super.playerName );
		System.out.print("Enter a move: ");
		
		//Loops until the user inputs a free or correct position in the board
		while( !gameBoard.makeMove(sca.nextInt(), super.playerSymbol) )
		{
			System.out.print("Invalid move, try again: ");
		}
		

	}
	
	/**
	 * To string just prints the parent class which just prints the player's name
	 */
	public String toString()
	{
		return super.toString();
	}
}
