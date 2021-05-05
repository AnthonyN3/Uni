package com.anthony;

/**
 * Invoice is a class that abstracts a single invoice that contains some items
 * each invoice has a list of item done using an array and a item count
 * @author Anthony Nguyen
 *@version 1.8
 */

public class Invoice {
	
	/**
	 * lust of items
	 */
	private Item itemList[];
	
	/*
	 * A counter to keep track of how many ingredients we have in the list
	 */
	private int itemCount = 0;
	
	/*
	 * a constant defining the maximum number of items in an invoice
	 */
	private final int MAX_ITEMS = 3;

	
	/**
	 * Default constructor used to initialize the invoice
	 */
	public Invoice()
	{
		itemCount = 0;	//don't need this since we've already had a default value for it
		itemList = new Item[MAX_ITEMS];	//max items are 3 items
	}
	
	
	/**
	 * Adds an item in the invoice
	 * @param itm - the item object to add to the item list
	 * @return	returns true if added, and false if the max was reached
	 */
	public boolean addItem(Item itm)
	{
		if(itemCount < MAX_ITEMS)
		{
			itemList[itemCount++] = new Item(itm);
			return true;
		}
		else
		{
			System.err.println("Maximum number of items reached");
			return false;
		}
	}
	
	/**
	 * calculates the sub total of the invoice my adding the total off all the items in the invoice 
	 * @return a double of the sub total
	 */
	public double subTotal()
	{
		double sTotal = 0;
		//loops depending on how many items are in the invoice
		for(int i = 0; i < itemCount; i++)
		{
			sTotal += (itemList[i].getPrice() * itemList[i].getQuantity());	//adds the total of each item 
		}
		
		return sTotal;
		
	}
	
	/**
	 * Calculates the sales tax (by taking the tax percent of the sub total)
	 * @return a double of the tax on the sub total
	 */
	public double salesTax()
	{
		return Math.round( (subTotal()*0.0625)*100.0)/100.0 ;	
		//the Math.round( num * 100.0) / 100.0 rounds it to the nearest 2nd decimal place
		//or instead of the 100.0, leave it as 100's and do (double)
	}
	
	
	/**
	 * calculates the total of the invoice my adding the total off all the items in the invoice then adding the tax
	 * @return a double of the total calculated 
	 */
	public double Total()
	{
		return subTotal() + salesTax();		//uses the subTotal() and salesTax() method and adds them together
	}
	
	
	/**
	 * Note: this is a default method, so just calling "myInvoice" will return this string...
	 * This method returns a string of the invoice in the format of a table (like shown in the lab)
	 * Allows the conversion of invoice class to a string of choice.
	 * in my case, it will return the name,quantity,price and total in the format like the lab output(a chart)
	 *  @return A string of the invoice
	 */
	public String toString()
	{
		if(itemCount > 0)
		{
			int i;
			
			//adds the header of the invoice to fullInvoice
			String fullInvoice = String.format( "Your bill:\n\n%-30s%10s%10s%10s", "Item", "Quantity","Price","Total" );
			fullInvoice += "\n";	//starts a new line on the string
			
			//loops to add each item in the invoice and its corresponding parts
			for(i=0; i < itemCount; i++)
			{
				fullInvoice += itemList[i].toString();
				fullInvoice += "\n";
			}
			
			fullInvoice += "\n";
			
			//these adds the sub total, sales tax and total to the string
			fullInvoice += String.format("%-30s%30.2f\n","Subtotal" ,subTotal());
			fullInvoice += String.format("%-30s%30.2f\n", "6.25% sales tax",salesTax());
			fullInvoice += String.format("%-30s%30.2f\n", "Total",Total());
			
			//returns the FULL invoice chart as a string
			return fullInvoice;
		}
		else
		{
			return "Invoice is empty";
		}
	}	
}
