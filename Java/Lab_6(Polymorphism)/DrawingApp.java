package com.shapes;

import java.util.Random;
import java.text.DecimalFormat;

public class DrawingApp {

	public DrawingApp()
	{
		
		//Variables 
		int shapeSelector;	//used to select which shape
		int shapeAmount = 10;	//amount of shapes you'd like to be randomly generated
		int maxDimension = 50;	//the max dimension of the shape
		double totalArea = 0;	//total area of all shapes added together
		
		Random rnd = new Random();
		
		Shape [] shapes = new Shape[shapeAmount];
		
		//For loop, loops through and randomly generated shapes and stored them into the shape array
		for(int i = 0; i < shapeAmount; ++i)
		{
			shapeSelector = rnd.nextInt(3);	//random number from 0-2 inclusive (0,1, or 2)
			
			//Switch statement used to chose the shape corresponding to the randomly generated number 0-2 (inclusive)
			switch(shapeSelector)
			{
				//Case 0 generates a rectangle with random width and length from 1-50
				case 0:
					double width = rnd.nextInt(maxDimension) + 1;  	// 1 - 50 inclusive
					double length = rnd.nextInt(maxDimension) + 1;
					
					shapes[i] = new Rectangle(width, length);
					break;
				
				//Case 1 generated a circle with a random radius from 1-50
				case 1:
					double radius = rnd.nextInt(maxDimension) + 1;
					
					shapes[i] = new Circle(radius);
					break;
					
				//Case 2 generates a triangle with a random base and height from 1-50
				case 2:
					double base = rnd.nextInt(maxDimension) + 1;
					double height = rnd.nextInt(maxDimension) + 1;
					
					shapes[i] = new Triangle(base, height);
					break;
				default:
					System.out.println("ERROR");
			}
		}
		
		//This for loop adds up the total area of all shapes
		for( int i = 0 ; i < shapeAmount; i++)
		{
			totalArea = totalArea + shapes[i].CalculateArea();
		}
		
		//This prints out all the shapes in the array (its label and id)
		for( int i = 0 ; i < shapeAmount; i++)
		{
			System.out.println((i+1) + ". " + shapes[i].getLabel());
		}
		
		
		
		DecimalFormat dc = new DecimalFormat("#.00");
		
		System.out.println("\nThe total area of the " + shapeAmount + " randomly generated shapes are " + dc.format(totalArea));
	
	}
	
	public static void main(String [] args)
	{
		DrawingApp da = new DrawingApp();
	}
	
	
}
