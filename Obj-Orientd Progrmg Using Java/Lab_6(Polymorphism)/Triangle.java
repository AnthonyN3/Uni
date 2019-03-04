package com.shapes;

/**
 * A rectangle class that extends the class shape and creates a triangle with attributes base and height of rectangle
 * @author Anthony
 *
 */

public class Triangle extends Shape {

	//Attributes of a triangle, must be greater than 0
	private double base;
	private double height;
	
	/**
	 * Default constructor, sets the base and height to 1 and adds the id and label of the shape (triangle)
	 */
	public Triangle()
	{
		base = 1;
		height = 1;
		
		id = ++counter;
		label = "Triangle";
	}
	
	/**
	 * Overloaded constructor, takes parameters base and height for the triangle and sets it accordingly
	 * @param base
	 * @param height
	 */
	public Triangle(double base, double height)
	{
		this();		//invokes default constructor 
		setBase(base);
		setHeight(height);
	}
	
	/**
	 * Calculates the area of the triangle
	 */
	public double CalculateArea()
	{
		return (base*height)/2;
	}
	
	/**
	 * Sets the base of the triangle
	 * @param base
	 */
	public void setBase(double base)
	{
		if( base > 0 )
			this.base = base;
	}
	
	/**
	 * sets the height of the triangle
	 * @param height
	 */
	public void setHeight(double height)
	{
		if( height > 0 )
			this.height = height;
	}
	
	/**
	 * gets the base of the triangle
	 * @return base of triangle
	 */
	public double getbase()
	{
		return base;
	}
	
	/**
	 * gets the height of the triangle
	 * @return	height of triangle
	 */
	public double getHeight()
	{
		return height;
	}
}	

