package com.anthony;

import java.util.*;

/**
 * @author Anthony Nguyen (104792283) 
 * @version 1.9
 * @category Math
 */

public class MyClass 
{
	
	public static void main(String[] args)
	{
		//Variables
		int x,y;
		int choice;
		int flag;
		String word, wordTwo;
		
		//creates an instance of a scanner for input use form user
		Scanner sc = new Scanner(System.in);
		
		//Prompts which program you'd like to run
		System.out.print("Enter from 1-3 which part of the lab you'd like to run: ");
		choice = sc.nextInt();	
		sc.nextLine();			//this consumes the \n, so whenever we use a nextLine() after it wont get an error
		System.out.println();
		
		//Switch used to choose which program the user wants to run when they input a number
		switch(choice) 
		{
		
		//First case is the math program
		case 1:
			System.out.print("Enter two integers: ");
			x = sc.nextInt();
			y = sc.nextInt();
			System.out.printf("The calculation is: %.2f ", calc(x,y));
			break;
			
		//second case is the capitalized word  
		case 2:
			System.out.print("Enter a word: ");
			word = sc.next(); 
			System.out.println("The capalized form is: " +wordCap(word));
			break;
			
		//third case checks if a keyword was found in a sentence, both which are user inputed
		case 3:
			System.out.print("Enter a word or sentence: ");
			word = sc.nextLine();
			
			
			System.out.print("Enter a keyword: ");
			wordTwo = sc.next();
			
			System.out.print("Enter (0) if you'd like the search to be case sensitive and (1) if not: ");
			flag = sc.nextInt();
			
			if(findKeyWord(word,wordTwo, flag))
			{
				System.out.printf("\"%s\" contains \"%s\"", word,wordTwo);
			}
			else
			{
				System.out.printf("\"%s\" does not contains \"%s\"", word,wordTwo);
			}
			
			break;
			
		default: 
			System.out.println("Value inputed is out of range");
		
		
		}
		
		sc.close();	//close the Scanner sc
		
	}
	
	
	/**
	 * 
	 * @param x - a value
	 * @param y - a value
	 * @return the mathematical calculation of sqrt( pi * y^2) / 2x
	 */
	public static double calc(int x, int y)
	{
		return (double)(Math.sqrt(Math.PI*(y*y))) / (2*x);  //don't need the cast (double) since there is Math.pi
															//which is not an integer, so even though x and y are integers, it gives a double
	}
	
	/**
	 * 
	 * @param argument - a word
	 * @return The capitalized form of a word. 
	 * Example: aSuS --> Asus
	 */
	public static String wordCap(String argument)
	{	
		argument = argument.toLowerCase();	//changes the string to where all it's characters are lower cased
		argument = argument.substring(0, 1).toUpperCase() + argument.substring(1);	//changes the first character to an upper case and adds the rest 
	
		return argument; //returns the newly capitalized form 
	}
	/**
	 * 
	 * @param str - A sentence or word
	 * @param kw - a keyword to search for inside str
	 * @parem flag - an into that chooses between either if the method will be case sensitive or case insensitive
	 * @return true if the keyword was found in the str string and false if not
	 */
	public static boolean findKeyWord(String str, String kw, int flag)
	{
		//If statement to choose if either the search is case sensitive or not
		if(flag == 0)
		{
			return str.contains(kw);	//returns true if kw is found in str and false if not
		}								//This is case sensitive
		else
		{
			return str.toLowerCase().contains(kw.toLowerCase()); //returns true if kw is found in str and false if not
		}														//Is not case sensitive
		
	}
	

}
