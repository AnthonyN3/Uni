package com.anthony;

import java.util.Scanner;

/**
 * This program will read strings and state if they are either a; regular palindrome, mirrored string,
 * mirrored palindrome or neither
 * 
 * ASSUMPTIONS: Even though we can assume that the input values will be valid, I created the program to check for
 * the validation of the input
 * 
 * @author Anthony Nguyen (104792283)
 * @date October 05, 2018
 * @version 1.8
 */


public class palindromeTester {
	
	public static void main(String[] arg)
	{
		//line is a string that will be used to take the string input
		String str;
		
		//instantiate an object scanner sc
		Scanner sc = new Scanner(System.in);
		
		//loops as long as there is something next in the scanner
		while(sc.hasNext()) 
		{ 	
			str = sc.next(); //assigns the str string to the next word/string (scanner) 
			
			//instantiate an object palindrome to pl and uses the overloaded constructor. 
			//inserts the user input string "str" into its parameters
			palindrome pl = new palindrome(str);
			
			//outputs if the string inputed was mirrored,palindrome,both, neither, or invalid
			System.out.println(pl);
			
			//Resets the str string (so if an invalid string is inputed next it will not re-use the previous entered string
			str = "";
		}
		
		//closes scanner
		sc.close(); 
	}
}

