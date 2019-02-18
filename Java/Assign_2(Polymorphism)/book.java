package com.anthony.assignment2;

/**
 * class book that extends the class abstract item
 * this book adds attributes to the item like the book author,title, and the year the book was made
 * @author Anthony Nguyen (104792283)
 *
 */

public class book extends item  {
	
	
	private String author;
	private String title;
	private int year;
	
	/**
	 * default constructor
	 */
	public book()
	{
		author = "void";
		title = "void";
		year = 0;
		super.id = ++item.counter;
	}
	
	/**
	 * overloaded constructor
	 * @param title
	 * @param author
	 * @param year
	 */
	public book(String title, String author, int year, int quantity, double price)
	{
		this();	//invokes default constructor
		
		//SETS ALL THE VARIABLES USING SETTERS
		setTitle(title);
		setAuthor(author);
		setYear(year);
		
		//the "super." is not needed, but it helps to clarify where this method comes from
		super.setQuantity(quantity);	//sets the quantity in the parent abstract class item
		super.setPrice(price);	//sets the price of the parent abstract class item
	}
	
	/**
	 * Method that zero's out the quantity of the book
	 */
	public void Purchased()
	{
		super.quantity = 0;
	}
	
	/**
	 * Method that displays the:
	 * [ID	($)PRICE	QTTY	ITEM+DESCRIPTION]
	 * of the item
	 */
	public void Displayed()
	{
		System.out.printf("\n%-5d%-11.2f%-15d%s", super.id, super.price , super.quantity, "[BOOK] " + title + " made by " + author + " in " + year);
	}
	
	
	/**
	 * Access method to set the author of the book iff input is not empty
	 * @param author - The author of the book must not be empty (STRING)
	 */
	public void setAuthor(String author)
	{
		if(!author.isEmpty())
		{
			this.author = author;
		}
	}
	
	/**
	 * Access method to set the title of the book iff input is not empty
	 * @param title	-	The title of the book must not be empty (STRING)
	 */
	public void setTitle(String title)
	{
		if(!title.isEmpty())
		{
			this.title = title;
		}
	}
	
	/**
	 * Access method to set the year the book was published/made iff input is greater than a 0
	 * @param year	-	year the book was published/made (must be a int greater than 0)
	 */
	public void setYear(int year)
	{
		if( year > 0)
		{
			this.year = year;
		}
	}
	
	/**
	 * Access method to get the author of the book
	 * @return	-	Author of the book (STRING)
	 */
	public String getAuthor()
	{
		return author;
	}
	
	/**
	 * Access method to get the title of the book
	 * @return	-	Title of the book (STRING)
	 */
	public String gettitle()
	{
		return title;
	}
	
	/**
	 * Access method to get the year the book was made/published
	 * @return	-	the year the book was released (INT)
	 */
	public int getYear()
	{
		return year;
	}
	
	
}
