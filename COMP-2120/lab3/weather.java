package com.anthony;

/**
 * A weather class that takes the weather. it will get the temperature, wind speed and using these two will calculate
 * the severity and windchill of the weather....
 * 
 * @author Anthony Nguyen (104792283)
 * @version 1.8
 */

public class weather {
	
	/**
	 * tempF - temperature in fahrenheit (must be between -50 and 150)
	 */
	private int tempF;
	
	/**
	 * windSpeed -in mph and must be greater than 0
	 */
	private int windSpeed;
	
	/**
	 * windChill - in fahrenheit, will be calculated based off of the temperature and wind speed using a formula
	 */
	private double windChill;
	
	
	/**
	 * Default constructor 
	 */
	public weather()
	{
		tempF = 0;
		windSpeed = 1;
		windChill = -0.01;
	}
	
	/**
	 * Overloaded constructor
	 * @param temp - the temperature in fahrenheit
	 * @param speed - the windspeed in mph
	 */
	public weather(int temp, int speed)
	{
		this();	//invokes the default constructor
		setTempF(temp);	//sets the tempF (because its private)
		setWindSpeed(speed);	//sets the windspeed (private)
		updateWindChill();	//calculates the windChill based off the entered temp and speed
		//just noticed, the updatewindCHill call in this overloaded constuctor is useless since the setTemp and setWind has it
	}
	
	/**
	 * the access method to set tempF 
	 * @param temp - a fahrenheit 
	 */
	public void setTempF(int temp)
	{
		//follows through only if temperature is between -50 and 150
		if (temp > -50 && temp <150)
		{
			//Sets the local temp to the private tempF of this instance of this class
			tempF = temp;
			updateWindChill();	//updates the windChill because temperature was changed
			
		}
	}
	
	/**
	 * the access method to set the windSpeed 
	 * @param speed - in mph
	 */
	public void setWindSpeed(int speed)
	{
		//follows through if speed is greater than 0
		if (speed > 0)
		{
			windSpeed = speed;	//sets the local winspeed to the windSpeed of this instance
			updateWindChill();	//updates windChill because windSpeed was changed
			
		}
	}
	
	/**
	 * A private method that calculates the windChill based off of the current tempF and windSpeed 
	 */
	private void updateWindChill()
	{
		windChill = 35.74 + 0.6215*tempF-35.75*Math.pow(windSpeed, 0.16) + 0.4275*tempF*Math.pow(windSpeed, 0.16);
	}
	
	/**
	 * access method to get the windChill
	 * @return the windChill in fahrenheit
	 */
	public double getWindChill()
	{
		return windChill;
	}
	
	/**
	 * boolean method that will check if the weather is severe or not 
	 * @return true if weather is severe, and false otherwise
	 */
	boolean isSevere()
	{
		//if the windChill is below -15, then the weather is classified as severe
		if(windChill < -15)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	/**
	 * the toString of this class prints out the information of the weather
	 */
	public String toString()
	{
		return "Current Temperature is "+ tempF +"'F. Feels like " + String.format("%.2f", windChill) +"'F and Wind Speed is " + windSpeed + "mph";
	}
	
}