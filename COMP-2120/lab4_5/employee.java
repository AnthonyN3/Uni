package com.anthony.inheritance;

/**
 * 
 * @author Anthony
 *
 */
public class employee extends person{
	
	/**
	 * year_hired: needs to be between 1900 - 2999
	 */
	private int year_hired;
	
	/**
	 * id: a unique positive integer and it increments itself starting from 1
	 */
	private int id;
	
	//Counter used to keep track of number of employees to keep unique id
	private static int counter = 0;
	
	/**
	 * default constructor
	 */
	public employee()
	{
		year_hired = 2018;
		id = ++counter;
	}
	
	/**
	 * Overloaded constructor
	 * @param name	-	name of employee
	 * @param age	-	age of employee (positive)
	 * @param year_hired	-	the year the employee was hired ( valid iff between 1900 and 2999)
	 */
	public employee(String name, int age, int year_hired)
	{
		this();	//invokes default constructor 
		super.setAge(age);	//sets the age of the superclass person 
		super.setName(name);	//sets the name of the superclass name
		setYearHired(year_hired);	//sets year
	}
	
	/**
	 * Access method to set year
	 * @param year_hired
	 */
	public void setYearHired(int year_hired)
	{
		if (year_hired > 1900 && year_hired < 2999)
		{
			this.year_hired = year_hired;
		}
	}
	
	
	
	protected void payWorker()
	{
		System.out.println(super.name + " is an employee who needs to be paid");
	}

	/**
	 * toString/ default string printer
	 */
	public String toString()
	{
		return super.name +" was hired in " + year_hired + " and is " + super.age + " years old 	id:"+  id;
	}
	

}
