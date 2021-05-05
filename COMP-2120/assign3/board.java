package com.anthony.tictactoe;

/**
 * the board consists of a block 2d array (3 by 3) where the board acts like a tic tac toe board.
 * Includes assisting features that help with playing the game, (ei. making moves, checking for wins, etc)
 * @author Anthony Nguyen
 *
 */


public class board implements global{
	
	/**
	 *  state is the state of the board and is defaulted to EMPTY, if X then means X won and if O means O has won
	 */
	private int state = EMPTY;
						//ROW by Column
	
	/**
	 * This is a 3 by 3 block array, basically it is the board of the gamew
	 */
	block [][] blocks = new block[3][3];	
	
	/**
	 * Default constructor, it instantiates all its 9 (3x3) spaces to block
	 */
	public board()
	{
		//creates the instance for each spot in the array to block
		for(int i = 0 ; i < 3; i++)
		{
			for(int j = 0 ; j < 3; j++)
				blocks[i][j] = new block();
		}
	}
	
	/**
	 * A method that makes a move on the board depending on the parameters 
	 * @param moveTo - (int) index on the board (from 1-9)
	 * @param player - The player's symbol either X or O
	 * @return true if a move was made and false if not
	 */
	public boolean makeMove(int moveTo, int player)
	{
		//If a illegal move was made (out of bounds) or player symbol is incorrect then it will return a false and will not make a move
		if(moveTo > 9 || moveTo < 0 || (player != O && player != X)  )
			return false;
		
		//if the player's symbol is equal to X then it will run and check which spot was used
		if(player == X)
		{
			//If statements used to put the player's symbol in that position based off of the board index (1-9)
			if(moveTo >= 1 && moveTo <= 3)
			{
				if(blocks[0][moveTo-1].getState() != EMPTY)	//if that spot is taken then it will exit the method and return false
					return false;
				blocks[0][moveTo-1].setState(X);
			}
			else if(moveTo >= 4 && moveTo <= 6)
			{
				if(blocks[1][moveTo-4].getState() != EMPTY)	//if that spot is taken then it will exit the method and return false
					return false;
				blocks[1][moveTo-4].setState(X);
			}
			else if(moveTo >= 7 && moveTo <= 9)
			{
				if(blocks[2][moveTo-7].getState() != EMPTY)	//if that spot is taken then it will exit the method and return false
					return false;
				blocks[2][moveTo-7].setState(X);
			}
		}
		//if the player's symbol is equal to O then it will run and check which spot was used
		else if(player == O)
		{
			//If statements used to put the player's symbol in that position based off of the board index (1-9)
			if(moveTo >= 1 && moveTo <= 3)
			{
				if(blocks[0][moveTo-1].getState() != EMPTY)	//if that spot is taken then it will exit the method and return false
					return false;
				blocks[0][moveTo-1].setState(O);
			}
			else if(moveTo >= 4 && moveTo <= 6)
			{
				if(blocks[1][moveTo-4].getState() != EMPTY)	//if that spot is taken then it will exit the method and return false
					return false;
				blocks[1][moveTo-4].setState(O);
			}
			else if(moveTo >= 7 && moveTo <= 9)
			{
				if(blocks[2][moveTo-7].getState() != EMPTY)	//if that spot is taken then it will exit the method and return false
					return false;
				blocks[2][moveTo-7].setState(O);
			}
		}
		
		//If we get to this point that means a move has been made and then it calls the updateState() function to check the boards state
		updateState();
		return true;	
	}
	
	/**
	 * Checks the column of the board based on the column number (1-3) in the parameter to see if there is a winner
	 * @param columnNum - number from 1-3 corresponding to which column you'd like to check
	 * @return X if X won or O if O won, else it returns 100
	 */
	public int checkCol(int columnNum)
	{
		columnNum--; //used to change the index because arrays start at 0 not 1
		
		//Checks the column if X is on all columns
		if(blocks[0][columnNum].getState() == X && blocks[1][columnNum].getState() == X && blocks[2][columnNum].getState() == X )
		{
			return X;	//means X won
		}
		//Checks the column if O is on all columns
		else if (blocks[0][columnNum].getState() == O && blocks[1][columnNum].getState() == O && blocks[2][columnNum].getState() == O)
		{
			return O;
		}

		return 100;		//means no one has won or loss in that column
	}
	
	/**
	 * Checks the row of the board based on the row number (1-3) in the parameter to see if there is a winner
	 * @param rowNum - the index of the row intended to check
	 * @return X if X won or O if O won, else it returns 100
	 */
	public int checkRow(int rowNum)
	{
		rowNum--;
		if(blocks[rowNum][0].getState() == X && blocks[rowNum][1].getState() == X && blocks[rowNum][2].getState() == X )
		{
			return X;	//means X won
		}
		else if (blocks[rowNum][0].getState() == O && blocks[rowNum][1].getState() == O && blocks[rowNum][2].getState() == O)
		{
			return O;	//means O won
		}
		
		return 100; //means no one won or lost in that row
	}
	
	/**
	 * Checks the diagonals to see if there is a winner (3 X's in a row or O's in a row)
	 * @return X if X won or O if O won, else it returns 100
	 */
	public int checkDiagonals()
	{
		//if statement checks if there is a winner on the diagonals 
		if(blocks[0][0].getState() == blocks[1][1].getState() && blocks[1][1].getState() == blocks[2][2].getState() && blocks[1][1].getState() != EMPTY)
			return blocks[1][1].getState();
		else 
			if(blocks[2][0].getState() == blocks[1][1].getState() && blocks[1][1].getState() == blocks[0][2].getState() && blocks[1][1].getState() != EMPTY)
				return blocks[1][1].getState();
		return 100; //means no one won based off the diagonals
	}
	
	/**
	 * Checks if the board contains a draw (all spots are filled)
	 * @return
	 */
	public boolean checkDraw()
	{
		//Counts the number of fullspots on the board
		int fullSpots = 0;
		
		//loops through the board
		for (int i = 0 ; i < 3 ; i ++)
		{
			for (int j = 0 ; j < 3; j++)
			{
				//If the block at that position is full, then add to the counter
				if(blocks[i][j].getState() == X || blocks[i][j].getState() == O)
					fullSpots++;
			}
		}
		
		//returns true if board is full. ei. equals 9
		return fullSpots == 9;
	}
	
	/**
	 * Displays the board with selection numbers (1-9) in each open spot in the board
	 */
	public void displayPlayerSelectionBoard()
	{
		//Index used to index the board
		int index = 1;
		//horizontalLine used to print between the first,middle row and the last,middle row
		int horizontalLine = 0;
		
		//loop through the board
		for(int row = 0 ; row < 3; row ++)
		{
			for (int col = 0 ; col < 3; col++)
			{
				if( (row == 0 && col == 1) || (row == 1 && col == 1) || (row == 2 && col == 1) )
				{
					System.out.print( blocks[row][col].getState() == EMPTY ? "| " + index + " |": "| " + blocks[row][col] + " |" );
				}
				else
					System.out.print( blocks[row][col].getState() == EMPTY ? " " + index + " " : " " + blocks[row][col] + " ");
				index++;
			}
			//prints newline for a new row
			System.out.println();
			
			//if statement to make sure only two horizontal lines are printed (like in a real tic tac toe board)
			if(horizontalLine < 2)
			{
				System.out.println("------------");
				horizontalLine++;
			}
		}
		
	}
	
	/**
	 * Simply displays the board without the selection indexes and only the player's in each spot
	 */
	public void displayBoard()
	{
		//used to print the 2 horizontal lines like in a real tic tac toe board
		int horizontalLine = 0;
		
		//loop through the 2d board array
		for(int row = 0 ; row < 3; row ++)
		{
			for (int col = 0 ; col < 3; col++)
			{
				if( (row == 0 && col == 1) || (row == 1 && col == 1) || (row == 2 && col == 1) )
				{
					System.out.print( "| " + blocks[row][col] + " |");
				}
				else
					System.out.print( " " + blocks[row][col] + " ");
				
			}
			
			System.out.println();
			
			if(horizontalLine < 2)
			{
				System.out.println("------------");
				horizontalLine++;
			}
		}
		
	}
	
	/**
	 * Access method that gets the state of the board
	 * @return
	 */
	public int getState()
	{
		return state;
	}
	
	/**
	 * method that checks the state of the board and if it has change it will update the boards state..
	 */
	public void updateState()
	{
		//checks if any winners in columns
		//This is a very slow and bad way of checking, but it basically checks EVERY row and column of the board 
		//A more efficient way would be checking the row and column in which the player has placed their symbol in, but this function plays it
		//safe and checks the whole board for any wins when it is called
		
		//for loop checks through each row and column of the board
		for(int i = 0 ; i < 3 ; i++)
		{
			if( checkCol(i+1) == X || checkCol(i+1) == O )
			{
				state = checkCol(i+1);
				return;
			}
			if( checkRow(i+1) == X || checkRow(i+1) == O )
			{
				state = checkRow(i+1);
				return;
			}
		}
		
		//checks to see if there is a winning diagonal 
		if (checkDiagonals() == X || checkDiagonals() == O)
		{
			state = checkDiagonals();
			return;
		}
		else if(checkDraw())	//checks to see if there is a draw
			state = DRAW;
		
	}
}
