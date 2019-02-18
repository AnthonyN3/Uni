package com.shapes.inferface;

import java.util.Arrays;
import java.util.Random;
import java.lang.reflect.Array;
import java.text.DecimalFormat;

public class DrawingApp {

	public DrawingApp()
	{
		//Variables
		int shapeSelector;
		int shapeAmount = 10;
		int maxDimension = 50;
		double totalArea = 0;
		
		//used to randomly generated shape
		Random rnd = new Random();
		
		//array of shapes
		Shape [] shapes = new Shape[shapeAmount];
		
		//for loop loops through the shapes
		for(int i = 0; i < shapeAmount; ++i)
		{
			shapeSelector = rnd.nextInt(3);	//random number from 0-2 inclusive (0,1, or 2)
			
			switch(shapeSelector)
			{
				case 0:
					double width = rnd.nextInt(maxDimension) + 1;  	// 1 - 50 inclusive
					double length = rnd.nextInt(maxDimension) + 1;
					
					shapes[i] = new Rectangle(width, length);
					break;
				
				case 1:
					double radius = rnd.nextInt(maxDimension) + 1;
					
					shapes[i] = new Circle(radius);
					break;
					
				case 2:
					double base = rnd.nextInt(maxDimension) + 1;
					double height = rnd.nextInt(maxDimension) + 1;
					
					shapes[i] = new Triangle(base, height);
					break;
				default:
					System.out.println("ERROR");
			}
		}
		
		
		//Calculates the total area of all shapes
		for( int i = 0 ; i < shapeAmount; i++)
		{
			totalArea = totalArea + shapes[i].CalculateArea();
		}
		
		//Sorts the shape array by area size 
		Arrays.sort(shapes);
		
		DecimalFormat dc = new DecimalFormat("#.00");
		
		//For loop, loops and display the sorted array
		for( int i = 0 ; i < shapeAmount; i++)
		{
			System.out.println((i+1) + ": " + shapes[i].getLabel() + " - " + dc.format(shapes[i].CalculateArea()) + "          ID: " + shapes[i].id  );
		}
		
		
		System.out.println("\nThe total area of the " + shapeAmount + " randomly generated shapes are " + dc.format(totalArea));
	
	}
	
	public static void main(String [] args)
	{
		DrawingApp da = new DrawingApp();
	}
	
	
}