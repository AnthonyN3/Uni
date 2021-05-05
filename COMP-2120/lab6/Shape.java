package com.shapes;

/**
 * 
 * @author Anthony Nguyen 
 *
 */


public abstract class Shape {

	/**
	 * Attribute id that applies a unique id to every new shape
	 */
	protected int id;
	/**
	 * Attribute label that gives a name to each shape
	 */
	protected String label;
	
	/**
	 * Counter used to give a unique integer to each id of a new shape
	 */
	protected static int counter = 0;
	
	protected abstract double CalculateArea();
	
	/**
	 * gets the label of the shape (the shapes name)
	 * @return The name of the shape (ex: Circle)
	 */
	public String getLabel()
	{
		return label;
	}
	
}
