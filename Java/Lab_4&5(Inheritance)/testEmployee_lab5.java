package com.anthony.inheritance;

//import java.util.Random;

/**
 * Tester
 * @author Anthony
 *
 */

public class testEmployee_lab5 {
	
	public static void main(String[] args)
	{
		hourlyWorker hw1 = new hourlyWorker("Jim", 19,2017,10,15.75);
		
		System.out.println(hw1);
		
		hw1.payWorker();
		hw1.payWorker();
	}
}
