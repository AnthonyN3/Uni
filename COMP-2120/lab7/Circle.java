package com.shapes.inferface;

/**
 * A rectangle class that extends the class shape and creates a circle with attributes radius of the circle
 * @author Anthony
 *
 */


public class Circle extends Shape{

	//variable radius corresponds to the radius of the circle ( must be greater than 0)
	private double radius;
	
	/**
	 * Default constructor, sets the radius to 1 and sets the id and label of the shape (Circle)
	 */
	public Circle()
	{
		radius = 1;
		
		id = ++counter;
		label = "Circle";
	}
	
	/**
	 * overloaded constructor takes one parameter the radius as a double of the circle
	 * @param radius
	 */
	public Circle(double radius)
	{
		this();		//invokes default constructor 
		setRadius(radius);
	}
	
	/**
	 * Calculates the area of the circle
	 */
	public double CalculateArea()
	{
		return Math.PI*Math.pow(radius, 2);
	}
	
	/**
	 * Sets the radius of the circle (must be greater than 0 ,if not, nothing gets set)
	 * @param radius
	 */
	public void setRadius(double radius)
	{
		if( radius > 0 )
			this.radius = radius;
	}
	
	/**
	 * returns the length of the circle
	 * @return
	 */
	public double getLength()
	{
		return radius;
	}
	
	
}
