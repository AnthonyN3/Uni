/*
Nguyen, Anthony
id: 104792283
Assignment 1
*/

#include <stdio.h>

/*  Takes the reverse of an integer
    Input: Any positive integer
    Output: returns the reverse of the integer, eg: 123 -> 321
*/
unsigned int reverseInteger (unsigned int num);

/*  Takes any positive integer and calculates the magnic number: (Magic Number: is the reverse of the absolute difference between an integer and its reverse)
    Input: Any positive integer
    Output: returns the reverse of the absolute difference between an integer and its reverse
*/
unsigned int generateMagicNumber (unsigned int num);

int main (void)
{
    //Variables
    unsigned int input,n, hold = 0;

    //Takes the input and stores it into n (This input is the number the user inputs to show how many integers they are going to
    scanf("%u", &n);

    //Loops as many times as the user inputed for n
    for(int i = 0 ; i < n; ++i )
    {
        //Stores intger input into "input"
        scanf("%u", &input);

        //stores the highest absolute difference encountered
        if ( hold < reverseInteger(generateMagicNumber(input)))
        {
            hold = reverseInteger(generateMagicNumber(input));
        }

        //Prints the magicnumber
        printf("%u ",generateMagicNumber(input));
    }

    //prints the largest absolute difference it encountered
    printf("\n%u", hold);

    return 0;
}

unsigned int reverseInteger (unsigned int num)
{
    //Variables
    unsigned int reverse=0;

    /*If statements check if the number is one digit or multiple
    if it was one digit, then the reverse is itsself*/
	if( num > 10)
	{
	    //Loop to calculate the reverse of the integer
		do{
			reverse *= 10;
			reverse += num%10;
			num = num/10;
		}while(num > 0);

		return reverse;
	}

	//If the number that the user wants to reverse is less than 0 (1 digit) then the reverse is the number itself
	//No need for another if statement since the other one checks if its more than 10 and returns the reverse (Aka it exits the function)
	return num;
	
}

unsigned int generateMagicNumber (unsigned int num)
{
    //Variables
    int reverse, difference;

    //Get the reverse of the input integer
    reverse = reverseInteger(num);

    //Calculates the absoulte difference between the input and its reverse
    //uses if statements to check if the reverse or orginal is higher so it can subtract accordingly to get a positive/absolute difference
    if (num > reverse)
    {
        difference = num - reverse;
    }
    else
    {
        difference = reverse - num;
    }

    //Returns the magic number of the input
    return reverseInteger(difference);

}
