package com.anthony.inheritance;

import java.text.DecimalFormat;

/**
 * 
 * @author Anthony
 *
 */

public class hourlyWorker extends employee {
	
	/**
	 * attributes
	 */
	private int num_hours;	//positive integer indicating number of hours an employee worked in a given week
	private double hourly_rate;	//positive double indicating the amount paid per hour
	
	/**
	 * default constructor, sets number hours and hourly rate to 0 by default
	 */
	public hourlyWorker()
	{
		num_hours = 0;
		hourly_rate = 0;
	}
	
	/**
	 * overloaded constructor
	 * @param name	-	name of employee
	 * @param age	-	age of employee (positive)
	 * @param year_hired	-	the year of hire of employee ( 1900 < year_hired < 2999)
	 * @param num_hours	-	number of hours employee worked this week (positive)
	 * @param hourly_rate	-	hourly rate of employee (positive double)
	 */
	public hourlyWorker(String name, int age, int year_hired, int num_hours, double hourly_rate)
	{
		this();	//invokes default constructor
		super.setName(name);
		super.setAge(age);
		super.setYearHired(year_hired);
		setNumHours(num_hours);
		setHourlyRate(hourly_rate);
	}
	
	public void payWorker()	//overrides the payWorker method in employee
	{	
		//if the employee has hours greater than 0, he/she will be paid 
		if ( num_hours > 0 )
		{	
			DecimalFormat dc = new DecimalFormat("#.00");	//used to format the amount of pay
			
			super.payWorker();	//prints the payWorker method from the parent class employee
			System.out.println(super.name + " is an hourly worker and is paid $" + dc.format(num_hours*hourly_rate));
			num_hours = 0;
		}
		else	//if the employee has 0 hours then will prompt that this employee has already been paid
		{
			System.out.println(super.name + " has already been paid and needs to work more hours this week.");
		}
	}

	
	/**
	 * Access method to set the number of hours worked in a week from an employee (must be an integer > 0)
	 * @param num_hours
	 */
	public void setNumHours(int num_hours)
	{
		if(num_hours > 0)
			this.num_hours = num_hours;
	}
	
	/**
	 * Access method to set the hourly rate an employee makes ( must be greater than 0)
	 * @param hourly_rate
	 */
	public void setHourlyRate(double hourly_rate)
	{
		if(hourly_rate > 0)
			this.hourly_rate = hourly_rate;
	}	
	
	/*
	 * 
	 * @see com.anthony.inheritance.employee#toString()
	 */
	public String toString()
	{
		return super.toString();
	}
	
}
