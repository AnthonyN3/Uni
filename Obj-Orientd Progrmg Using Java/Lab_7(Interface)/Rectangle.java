package com.shapes.inferface;

/**
 * A rectangle class that extends the class shape and creates a rectangle with attributes width and length of rectangle
 * @author Anthony
 *
 */

public class Rectangle extends Shape{

	//Attributes of a rectangle in order to calculate the area
	private double width;
	private double length;
	
	/**
	 * Default constructor, defaults the width and height to 1, and sets the id and label of the shape
	 */
	public Rectangle()
	{
		width = 1;
		length = 1;
		
		id = ++counter;
		label = "Rectangle";
	}
	
	/**
	 * Overloaded constructor that takes in width and length as a double of the rectangle
	 * @param width
	 * @param length
	 */
	public Rectangle(double width, double length)
	{
		this();		//invokes default constructor 
		setWidth(width);
		setLength(length);
	}
	
	/**
	 * Calculates the area of the rectangle
	 */
	public double CalculateArea()
	{
		return width*length;
	}
	
	/**
	 * Sets the width of the rectangle (must be greater than 0)
	 * @param width
	 */
	public void setWidth(double width)
	{
		if( width > 0 )
			this.width = width;
	}
	
	/**
	 * sets the length of the recntagle (must be greater than 0)
	 * @param length
	 */
	public void setLength(double length)
	{
		if( length > 0 )
			this.length = length;
	}
	
	/**
	 * access method that returns the width of the rectangle
	 * @return
	 */
	public double getWidth()
	{
		return width;
	}
	
	/**
	 * access method that returns the length of the rectangle
	 * @return
	 */
	public double getLength()
	{
		return length;
	}
}
