package com.anthony;

/**
 * Items is a class that abstracts a single item in the invoice
 * each item has a name, quantity, and price
 * @author Anthony Nguyen
 *@version 1.8
 */
public class Item {
	
	/**
	 * name: A descriptive name for the item, must not be empty and space are permitted
	 */
	private String name;
	
	/**
	 * quantity: Amount of the item, must be positive (greater than 0)
	 */
	private int quantity;
	
	/**
	 * price: the price of the item, must be in ($) and formatted to two decimal places (must be positive)
	 */
	private double price;
	
	
	/**
	 * Default constructor used to initialize the Items
	 */
	public Item()
	{
		name = "Null";
		quantity = 1;
		price = 0.01;
	}
	
	/**
	 * Overloaded constructor used to initialize but with some given values by the instantiating object
	 * @param String name - the name of the item
	 * @param int quantity - the amount of the item
	 * @param double price - the price of the item
	 */
	public Item(String name, int quantity, double price)
	{
		this();	//invoke the default constructor first
		setName(name);
		setQuantity(quantity);
		setPrice(price);
	}
	
	/**
	 * Overloaded copy constructor used to initialize an item using another existing item
	 * @param itm - an existing item object that was previously initialize
	 */
	public Item(Item itm)
	{
		name = itm.getName();
		quantity = itm.getQuantity();
		price = itm.getPrice();
	}
	
	/**
	 * access method to set the name of the item
	 * @param String name - the name of the item
	 */
	public void setName(String name)
	{
		//checks if the input of the name was not just a bunch of spaces
		if(name.trim().length() > 0)
		{
			name = name.trim();
			this.name = name;
		}
	}
	
	/**
	 * access method to set the amount of the item
	 * @param int quantity - the quantity of the item
	 */
	public void setQuantity(int quantity)
	{
		//checks if the quantity of the item is more than 0, if so, then it proceeds
		if(quantity > 0)
		{
			this.quantity = quantity;
		}
	}
	
	/**
	 * access method to set the price of the item
	 * @param double price - the price of the item
	 */
	public void setPrice(double price)
	{
		//If prices are greater than 0 it will proceed
		if( (price > 0) && (String.valueOf(price).split("\\.")[1].length() <= 2) )	//the second part checks if the price 
		{																	//has at max 2 decimal places
			this.price = price; 
		}
	}
	
	/**
	 * access method to get the name of the item
	 * @return the name (string)
	 */
	public String getName()
	{
		return name;
	}
	
	/**
	 * access method to get the quantity of the item
	 * @return the quantity (int)
	 */
	public int getQuantity()
	{
		return quantity;
	}
	
	/**
	 * access method to get the price of the item
	 * @return the price of the item (in dollars)
	 */
	public double getPrice()
	{
		return price;
	}
	
	/**
	 * Allows the conversion of items class to a string of choice.
	 * in my case, it will return the name,quantity,price and total in the format like the lab output(a chart)
	 */
	public String toString()
	{
		if(name == "Null")
		{
			return "Missing item";
		}
		else
		{	
			String bundle = String.format("%-30s%10d%10.2f%10.2f", name, quantity,price,price*quantity );
			return bundle;
		}
	}

}

