/**
 * @author Anthony Nguyen
 */

package com.anthony;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class Exercise2 {
	
	public static void main(String[] args){

		int quote;
		Random quoteChooser = new Random();
		quote = quoteChooser.nextInt(5);
		
		
		//a bunch of if statements or cases
		switch(quote) {
		
		
			case 0: System.out.println("When you know how to think, it empowers you far beyond those who know only what to think.");
				break; 
			case 1: System.out.println("The only time success becomes before work, is in the dicitionary");
				break;
			case 2: System.out.println("I know that I am intelligent, because I know that I know nothing");
				break;
			case 3: System.out.println("Everyone is a genius, but if you judge a fish on its ability to climb a tree, it will live its whole life believing it is stupod");
				break;
			case 4: System.out.println("Life is not fair; get used to it.");
				break;
		}
		
		//Displays the current date and time
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Date date = new Date();
		System.out.println(dateFormat.format(date)); 
				
		
	}
	
}
