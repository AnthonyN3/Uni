package com.anthony.assignment2;

import java.io.*;

/**
 * base abstract class that contains a unique id, price and quantity of the item
 * it also contains abstract functions that the sub/class need to make 
 * @author Anthony Nguyen (104792283)
 *
 */

public abstract class item implements Serializable {
	
	//Used for saving and loading object into a file
	private static final long serialVersionUID = 1L;
	
	/**
	 * Cointer used to create unique id's for each item that is created
	 */
	protected static int counter = 0;
	
	/**
	 * a unique integer id is given to each item
	 */
	protected int id = 0;
	
	/**
	 * a price is set on each item (positive double)
	 */
	protected double price = 0;
	
	/**
	 * A quantity of an item is also set (positive int)
	 */
	protected int quantity = 0;
	
	
	/**
	 * abstract method
	 * Displays the given item
	 */
	protected abstract void Displayed();
	
	/**
	 * abstract method
	 * purchases a certain amount of quantity of a given item
	 */
	protected abstract void Purchased();
	
	
	/**
	 * Access method to set the quantity of the book (positive int)
	 * @param quantity	-	quantity of the item must be positive int
	 */
	public void setQuantity(int quantity)
	{
		if(quantity > 0)
			this.quantity = quantity;
	}
	
	/**
	 * Access method to set the price of the gift (positive double)
	 * @param price - price of the item must be a positive double
	 */
	public void setPrice(double price)
	{
		if(quantity > 0)
			this.price = price;
	}
	
	public int getId()
	{
		return id;
	}
	public double getPrice()
	{
		return price;
	}
	public double getQuantity()
	{
		return quantity;
	}
	
	
	
	//SPECIAL ACCES METHOD (USED FOR THE BONUS QUESTION WHERE U SAVE AND LOAD FROM A FILE) (The statc int does not load from file)
	public void setCounter(int c)
	{
		if(c > 0)
			counter = c;
	}
	public int getCounter()
	{
		return counter;
	}
	
	
}
