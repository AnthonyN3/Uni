#include <stdio.h>
#include <math.h>

//function prototype
int num_digits(int n);

/*
	User inputs a positive integer, and this program will calculate the number of digits that integer contains
*/

int main (void)
{
	int value;
	printf("Input a positive integer: ");
	scanf("%d", &value);
	
	printf("\nThe number of digits in %d is %d", value, num_digits(value));
	return 0;
}

int num_digits(int n)
{
	int digits = 0;
	do
	{
		n = n/10; 
		digits++;
	}while(n > 0);
	
	return digits;
}