package com.shapes.inferface;

/**
 * 
 * @author Anthony Nguyen 
 *
 */


public abstract class Shape implements Comparable<Shape> {

	/**
	 * Attribute id that applies a unique id to every new shape
	 */
	protected int id;
	/**
	 * Attribute label that gives a name to each shape
	 */
	protected String label;
	
	protected static int counter = 0;
	
	public int compareTo(Shape a)
	{
		if(this.CalculateArea() < a.CalculateArea())
		{
			return 1;
		}
		return -1;
	}
	
	protected abstract double CalculateArea();
	
	public String getLabel()
	{
		return label;
	}
	
}
