package com.anthony.tictactoe;

/**
 *  simply block class that represents a block in the board of a tic tac toe game.....each block has a state and assiting methods
 * @author Anthony Nguyen
 *
 */

public class block implements global {
	
	/**
	 *  state is the state of the block and is defaulted to EMPTY
	 */
	private int state = EMPTY;
	
	
	/**
	 * A method that states if the state of this block/object is a valid state
	 * @param state
	 * @return True if the state of this block is valid and false otherwise
	 */
	public boolean isValidState(int state)
	{
		//if the block is either EMPTY X or O then it will return true for the valid state
		if(state == EMPTY || state == X || state == O)
			return true;
		else
			return false;
	}
	
	/**
	 * Access method that sets the state of the block
	 * @param state
	 */
	public void setState(int state)
	{
		if(isValidState(state))
			this.state = state;
	}
	
	/**
	 * Access method that gets the state of the block
	 * @return
	 */
	public int getState()
	{
		return state;
	}
	
	/**
	 * To string that prints out the state (in int) of the block
	 */
	public String toString()
	{
		if(state == X)
			return "X";
		else if(state == O)
			return "O";
		else if ( state == EMPTY )
			return " ";
		return "";
	}
}
