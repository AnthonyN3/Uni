package com.anthony.inheritance;

/**
 * 
 * @author Anthony
 *
 */


public class person {
	
	//String name
	protected String name;

	
	//int age
	protected int age;
	
	public int asd;
	
	/**
	 * default constructor
	 */
	public person()
	{
		name = "private contractor";
		age = 18;
	}
	
	/**
	 * overloaded constructor
	 * @param name
	 * @param age
	 */
	public person(String name , int age)
	{
		this();
		setName(name);
		setAge(age);
	}
	
	/**
	 * access method to set name
	 * @param name
	 */
	protected void setName(String name)
	{
		if(!name.isEmpty())
		{
			this.name = name;
		}
	}
	
	/**
	 * acces method to set age
	 * @param age
	 */
	protected void setAge(int age)
	{
		if(age < 150 && age >= 0)
		{
			this.age = age;
		}
	}
	
	
	/**
	 * TO string 
	 */
	public String toString()
	{
		return name + " is " + age;
	}

}
