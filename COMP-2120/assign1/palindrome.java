package com.anthony;

/**
 * Creates an object that stores a string into it, and determines if that string is a palindrome string, mirrored
 * string, both, or neither when called on one of the objects methods
 * 
 * NOTE: this class/blueprint  is made so that it is needed for the string in this class to be set in order
 * to calculate its palindrome! (hence no parameters on the methods like "isPalindrome"
 * 
 * ASSUMPTIONS: Even though we can assume that the input values will be valid, I created the program to check for
 * the validation of the input.....If a lower cased string is inputed, it will automatically be translated to its
 * upper case form
 * 
 * @author Anthony Nguyen (104792283)
 * @date October 05, 2018
 * @version 1.8
 *
 */

public class palindrome {
	
	/**
	 * theString: is a string that you'd like to apply methods to find if its palindrome or mirrored
	 * Note: when the user inputs a lower case string, it will automatically translate it to its upper case version
	 * this is seen in the method "setSomeString()"
	 */
	 private String someString;
	
	
	/**
	 * default constructor
	 * sets someString to NULL
	 */
	public palindrome()
	{
		someString = "NULL";
	}
	
	/**
	 * overloaded constructor
	 * @param str - the string the inputed into the parameter when this class is instantiated 
	 */
	public palindrome(String str)
	{
		this();
		setSomeString(str);
	}
	
	/**
	 * Access method to set the string, any lowercased string will be translated to its uppercase form
	 * @param str - a string
	 */
	public void setSomeString(String str)
	{	
		//If str is not empty, does not exceed 20 characters, and contains valid characters
		//than it will go through this if statement
		if( !str.isEmpty() && str.length() <= 20 && str.matches("[a-zA-Z1-9 ]*"))
		{
			str = str.toUpperCase();//I assumed that if a lower cased string is inputed, it will change to upper case
			someString = str;	//sets the string variable in this class to str
		}
	}
	
	/**
	 * Access method to get the string
	 * Note: this string is not necessarily used or needed, but it is a good habit to keep when making classes
	 * @return the "theString" string of the object
	 */
	public String getSomeString()
	{
		return someString;
	}
	
	/**
	 * Method that reverses the string variable in this object
	 * Note: this method is private because it really only is used inside the class and shouldn't be used outside the class
	 * @return the reverse of "theString" variable
	 */
	private String Reverse()
	{
		//instantiate StringBuilder
		StringBuilder s = new StringBuilder(someString);
		
		//returns the reverse version of the string (someString)
		return s.reverse().toString();
	}
	
	/**
	 * Method that checks if the theString is a Palindrome
	 * @return - true if the string is palindrome, false otherwise
	 */
	public boolean isPalindrome()	//NOTE: no parameters are used due to the fact that this method only calculates 
	{								//if the string in this class is a palindrome ( I assumed we did not need parameters)
	
		//if statement checks if the reverse of theString is equal to theString (definition of palindrome)
		//if so, then return true (IT IS A PALINDOME!!!)
		if( someString.equals(Reverse()))
		{
			return true;	//if true, returns true
		}
		else	//returns false because it is not a palindrome
		{
			return false;
		}
	}
	
	/**
	 * Method that returns true if the theString is a mirror, false if not
	 * @return true or false depending if theString is mirrored or not
	 */
	public Boolean isMirrored()
	{	
		//breaks the string into a char array
		char[] letter = someString.toCharArray();
		
		//loops the start and end of the char array
		for(int i = 0, j = someString.length()-1 ; i <= j ; i++, j-- )
		{
			//calls upon my method called "isCharMirroed", and compares the two corresponding characters to be compared
			//and if they are not mirrors it will not run the if statement/
			// however, if it is false, it will pass the if statement and return false
			if( !isCharsMirrored(letter[i], letter[j]) )	
			{
				return false;	//this occurs if there exists any two characters that were compared and failed the mirror test in the string
			}
		}
		return true;	//all characters were mirrors of its corresponding character
	}
	
	
	/**
	 * Private method used to compare if two characters are mirrors of each other (based off of a table in the lab)
	 * example: if x = 3 and y = E, it will return true. 
	 * @param x - any character 
	 * @param y - any character
	 * @return true or false depending on if the two characters are mirrors
	 */
	private Boolean isCharsMirrored(char x, char y)
	{
		//THESE characters are KNOWN not to have any MIRRORS, so if x equal to these characters
		//then we know for a fact that the two characters are not mirrors no matter what y is
		if(x == 'B' || x == 'C' || x == 'D'|| x == 'F'|| x == 'G'|| x == 'K'|| x == 'N'|| x == 'P'||
				x == 'Q'|| x == 'R'|| x == '4'|| x == '6'|| x == '7'|| x =='0' )
		{
			return false;
		}
		//THESE characters are KNOWN not to have any MIRRORS, so if y equal to these characters
		//then we know for a fact that the two characters are not mirrors no matter what x is
		else if(y == 'B' || y == 'C' || y == 'D'|| y == 'F'|| y == 'G'|| y == 'K'|| y == 'N'|| y == 'P'||
				y == 'Q'|| y == 'R'|| y == '4'|| y == '6'|| y == '7'|| y =='0' )
		{
			return false;
		}
		
		//these are some known mirror pairs (where the pairs are of two different characters)
		//E - 3
		//J - L
		//S - 2
		//Z - 5
		
		//Known mirrors of different characters
		else if( x == 'E' && y == '3')
		{
			return true;
		}
		//Known mirrors of different characters
		else if( x == '3' && y == 'E')
		{
			return true;
		}
		//Known mirrors of different characters
		else if( x == 'J' && y == 'L')
		{
			return true;
		}
		//Known mirrors of different characters
		else if( x == 'L' && y == 'J')
		{
			return true;
		}
		//NOW we have must check vice versa of the known mirrors of different characters
		//Known mirrors of different characters
		else if( x == 'S' && y == '2')
		{
			return true;
		}
		//Known mirrors of different characters
		else if( x == '2' && y == 'S')
		{
			return true;
		}
		//Known mirrors of different characters
		else if( x == 'Z' && y == '5')
		{
			return true;
		}
		//Known mirrors of different characters
		else if( x == '5' && y == 'Z')
		{
			return true;
		}
		//Lastly, if x == y and they do not equal to any of the 8 characters that are known mirrors, then
		//the two characters are mirrors... Ex: H == H, A == A, etc
		//NOTE: we do not need to check if y != " " because if x == y then just checking the x's will be fine
		else if (x == y && x != 'E' && x != '3' && x != 'J' && x != 'L' && x != 'S' && x != '2' && x != 'Z' && x != '5' )
		{
			return true;
		}
		//When we've gotten to this part, that means we've reached a case where 
		// x == y and x,y equal to any of these characters E,3,L,J,S,2,Z,5 
		//OR
		//a case where the 4 pairs of known mirror characters of different characters are mixed (not paired with
		//its correct mirror character) ex: E and Z
		//in these two cases, the TWO characters are not MIRRORS so it returns false
		else 
		{
			return false;
		}
	}
	
	/**
	 * This will return if the setted string in this object is a palindrome, mirror, both or neither
	 */
	public String toString()
	{
		//if the input was either an invalid character or is empty or exceeds 20 characters, than 
		//an "invalid inpput" will be returned
		if(someString.equals("NULL"))	//NOTE: there is a flaw to this, if there was an input of the word NULL,
										//then this will assumed that n invalid input was inputed
		{
			return "invalid input or missing input";
		}
		//these statements return based on if the string inputed was a palindrome,mirror, both or neither
		else if(isPalindrome() && isMirrored() )
		{
			return someString + "--is a mirrored palindrome";
		}
		else if(isPalindrome())
		{
			return someString +  "--is a regular palindrome";
		}
		else if(isMirrored())
		{
			return someString + "--is a mirrored string";
		}
		else
		{
			return someString + "--is not a palindrome";
		}
		
	}
}
