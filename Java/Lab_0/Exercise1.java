/**
 * 
 * @author Anthony Nguyen
 * @Task  Write and document (Javadoc!) a java 
 * program that can prompt the user for 3 integers and display the largest, smallest, and average values. 
 * 
 */

package com.anthony;
import java.util.*;

public class Exercise1 {

	public static void main(String[] arg) 
	{	
		/** num1 to num3 for storing input*/
		int num1, num2, num3;
		
		//prompt for 3 integers
		System.out.println("Enter 3 integers: ");
		Scanner sc = new Scanner(System.in);
		num1 = sc.nextInt();
		num2 = sc.nextInt();
		num3 = sc.nextInt();
		
		//display largest, smallest and average values
		System.out.println("Largest: " + Math.max(num1, Math.max(num2,num3)));
		System.out.println("Smallest: " + Math.min(num1, Math.min(num2,num3)));
		System.out.println("Average: " + (num1 + num2 + num3)/3 );
		
		sc.close();
		
	}
}