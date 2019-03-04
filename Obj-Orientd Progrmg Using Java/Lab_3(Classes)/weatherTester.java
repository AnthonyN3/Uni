package com.anthony;

/**
 * A tester class used to test the weather class
 * 
 * @author Anthony Nguyen (104792283)
 * @version 1.8
 */


public class weatherTester {
	
	public static void main(String[] args)
	{
		//creating an instance of weather by the name w1 using a default constructor
		weather w1 = new weather();
		//creating an instance of weather by the name w2 using an overloaded constructor
		weather w2 = new weather(-25,7);
		
		//prints the weather of w1 and w2
		System.out.println(w1);
		System.out.println(w2);
		System.out.println();	//prints an empty new line
		
		//Sets the temperature of w1 to 60		
		w1.setTempF(60);
		
		//prints the w1 after changing its temperature to 60
		System.out.println(w1);
		System.out.println(w1.getWindChill());	//prints w1 wind chill
		System.out.println(w1.isSevere());	//prints if w1 weather is sever
		
	}
}
