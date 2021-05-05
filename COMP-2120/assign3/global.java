package com.anthony.tictactoe;

/**
 * interface called global that is a universal variable set used throughout the whole program.....
 * Acts like a global constant throughout all functions
 * @author Anthony Nguyen
 *
 */

public interface global {
	
	/**
	 * constant value X(player X) is defined by 1
	 */
	public static final int X = 1;
	
	/**
	 * constant value O(Player O) is defined by 0
	 */
	public static final int O = 0;
	
	/**
	 * Used for debugging the program
	 */
	public static final Boolean DEBUG = true;
	
	/**
	 * Constant value DRAW is defined by -1, used to imply a draw in the game has occured
	 */
	public static final int DRAW = -1;	
	
	/**
	 * Constant value EMPY is defined by 2, used to imply that something is empty (ex: block or board)
	 */
	public static final int EMPTY = 2;
}
