#include <stdio.h>
#include <math.h>

/*
	Takes a 3 digit number from user and reverses the numbe (ei 123 -> 321)
*/

int main (void)
{
	int x,n,reverse=0; 
	
	printf("Enter a number: ");
	scanf("%d", &x);
	n = x;
	
	if( x > 10)
	{
		do{
			reverse *= 10;
			reverse += x%10;
			x = floor(x/10);
		}while(x > 0);
			
		printf("\nInput number: %d\n", n);
		printf("The reverse : %d\n", reverse);
	}
	
	else if( x > 0)
	{
		printf("\nInput number: %d\n", n);
		printf("No need to reverse the number.\n");
	}
	else
	{
	printf("\nInput number: %d\n", n);
	printf("Invalid input\n");
	}
	
	printf("Thank you for using the software");
	
	return 0;
}