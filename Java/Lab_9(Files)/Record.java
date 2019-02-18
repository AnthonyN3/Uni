package com.iofile;


public class Record implements Comparable<Record> {
	
	//Variables 
	public String first_name;
	public String last_name;
	public String date;
	
	/**
	 * Default constructor, stores NULL in each variable in this object
	 */
	public Record()
	{
		first_name = "NULL";
		last_name = "NULL";
		date = "NULL";
	}
	
	/**
	 * Overloaded constructor, takes a line of the record and splits it and stores each part into the object
	 * @param s
	 */
	public Record(String s)
	{
		String [] token = s.split(",");
		first_name = token[0];
		last_name = token[1];
		date = token[2];	
	}
	
	/**
	 * Used for the comparable to compare in order to use Array.sort
	 * Compares last name and sorts it in decending order
	 */
	public int compareTo(Record a)
	{
		if(this.last_name.compareToIgnoreCase(a.last_name) > 0 )
		{
			return -1;
		}
		if(this.last_name.compareToIgnoreCase(a.last_name) == 0)
		{
			if(this.first_name.compareTo(a.first_name) > 0)
			{
				return -1;
			}
		}
		return 1;
	}
	
	/**
	 * toString prints out the record
	 */
	public String toString()
	{
		return first_name +"," + last_name + "," + date + "\n";
	}
}
