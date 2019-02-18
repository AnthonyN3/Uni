package com.anthony.inheritance;


public class testEmployee_lab4 {

	public static void main(String[] args)
	{
		//Creates new instances of employee three times (note: uses the overloaded constructor)
		employee e1 = new employee("jim", 19, 2017);
		employee e2 = new employee("Jenny smith", 23, 2014);
		employee e3 = new employee("", 185, 12777);
		
			
		//Prints out the employee info 
		System.out.println(e1);
		System.out.println(e2);
		System.out.println(e3);
		
	}
}
