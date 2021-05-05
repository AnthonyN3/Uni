package com.anthony.tictactoe;

/**
 * Abstract class used for making a layout for the types of player to be made (human player or Ai player)
 * @author Anthony Nguyen
 *
 */

public abstract class player {

	/**
	 * the gameboard object, used so the player can see the gameboard
	 */
	protected board gameBoard;
	/**
	 * name of the player
	 */
	protected String playerName;
	/**
	 * the players symbol (ei: X or O)
	 */
	protected int playerSymbol;
	
	//Assumed that playerName can be any string the user wishes to input
	/**
	 * Overloaded constructor to take the gameBoard, playerSymbol and playerName
	 * @param gameBoard - (board) used so the player can see the board
	 * @param playerSymbol - (int) player symbol of either X or O, X = 1 and O = 0
	 * @param playerName - (String) players name taken as a string line
	 */
	protected player(board gameBoard, int playerSymbol, String playerName)
	{
		//stores the inputed value into the variables contained in this class
		this.gameBoard = gameBoard;
		this.playerSymbol = playerSymbol;
		this.playerName = playerName;
	}
	
	/**
	 * Abstract class called play in where the concrete class that extends this needs to make,
	 * it simply plays a move on the board
	 * @param gameBoard
	 */
	protected abstract void play(board gameBoard);
	
	/**
	 * Returns players name
	 */
	public String toString()
	{
		return playerName;
	}
}
