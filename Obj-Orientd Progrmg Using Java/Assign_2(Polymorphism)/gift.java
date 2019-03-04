package com.anthony.assignment2;

/**
 * lass gift that extends the class abstract item
 * this gift class adds attributes to the abstract item like the gift label and manufacturer
 * @author Anthony Nguyen (104792283)
 *
 */

public class gift extends item  {
	
	
	/**
	 * the label of the gift, must not be empty
	 */
	private String label;
	
	/**
	 * the manufacturer of the gift, must not be empty
	 */
	private String manufacturer;
	
	
	/**
	 * default constructor for the gift class
	 * default Strings are set to "void"
	 */
	public gift()
	{
		label = "void";
		manufacturer = "void";
		super.id = ++item.counter;	//adds a unique id to the gift that is an item
	}
	
	/**
	 * Overloaded constructor that takes the (label, manufacturer, quantity, price) for gift
	 * @param label	-	String of the label of the gift
	 * @param manufacturer	-	String of the manufacturer of the gift
	 * @param quantity	-	quantity of gift in a int
	 * @param price	-	price of gift in a double
	 */
	public gift(String label, String manufacturer, int quantity, double price)
	{	
		this();	//invokes default constructor
		
		//Uses setters to set variables so they do not contain illegal inputs
		setLabel(label);	//sets the label
		setManufacturer(manufacturer);		//sets the manufacturer
		
		//the "super." is not needed, but it helps to clarify where this method comes from
		super.setQuantity(quantity);	//sets the quantity in the parent abstract class item
		super.setPrice(price);	//sets the price of the parent abstract class item
	}
	
	
	/**
	 * Method that zero's out the quantity of an gift
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
		System.out.printf("\n%-5d%-11.2f%-15d%s", super.id, super.price , super.quantity, "[GIFT] " + label + " made by " + manufacturer );
	}
	
	/**
	 * Access method that sets the label of the gift iff entered input is not empty
	 * @param label	- the string of the label
	 */
	public void setLabel(String label)
	{
		if(!label.isEmpty())
			this.label = label;
	}
	
	/**
	 * Access method that sets the manufacturer of the gift iff entered input is not empty
	 * @param manufacturer	-	the string of the manufacturer
	 */
	public void setManufacturer(String manufacturer)
	{	
		if(!manufacturer.isEmpty())
			this.manufacturer = manufacturer;
	}
	

	
	/**
	 * Access method that gets the label
	 * @return the label of the gift (String)
	 */
	public String getLabel()
	{
		return label;
	}
	
	/**
	 * Access method that gets the manufacturer of the gift
	 * @return	the manufacturer of the gift (String)
	 */
	public String getManufacturer()
	{
		return manufacturer;
	}
}
