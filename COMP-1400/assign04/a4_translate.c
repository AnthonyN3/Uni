#include <stdio.h>
#define letters 10
#define elements ( (int) (sizeof(phoneNumber) / sizeof(phoneNumber[0])))	//in order to get the amount of elements

/*
	this program takes a sequance of 10 letters (In uppercase ONLY) and prints out its dedicated number value (like on a phone)
	This implmentation only takes the first 10 letters
*/

int main (void)
{
	char phoneNumber[letters];
	
	printf("Enter a sequance of letters (10 letters = phone number): ");
	scanf("%s", phoneNumber);
	printf("\nthe translation of ");
		
	
	/*using a loop so if more than 10 letters are inputed,
	it will take the first 10*/
	for( int i = 0; i < elements; ++i)
	{
		printf("%c", phoneNumber[i]);
	}
	printf(" is: ");
	
	for( int i = 0; i < elements; i++)
	{
		switch (phoneNumber[i])
		{
			case 'A': case 'B': case 'C':
			phoneNumber[i] = '2';
			break;
			
			case 'D': case 'E': case 'F':
			phoneNumber[i] = '3';
			break;
				
			case 'G': case 'H': case 'I':
			phoneNumber[i] = '4';
			break;
			
			case 'J': case 'K': case 'L':
			phoneNumber[i] = '5';
			break;
			
			case 'M': case 'N': case 'O':
			phoneNumber[i] = '6';
			break;
			
			case 'P': case 'R': case 'S': case 'Q':
			phoneNumber[i] = '7';
			break;
			
			case 'T': case 'U': case 'V':
			phoneNumber[i] = '8';
			break;
			
			case 'W': case 'X': case 'Y': case 'Z':
			phoneNumber[i] = '9';
			break;
		}
	}
	
	for( int i = 0; i < elements; ++i)
	{
		printf("%c", phoneNumber[i]);	
	}	
	
	return 0;
}