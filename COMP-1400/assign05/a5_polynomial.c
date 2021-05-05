#include <stdio.h>
#include <math.h>

//Function prototype, need to include this if the function definition is below the main...
float polynomial_calcuation(float x);

/*
	simple calculation for the equation "3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6" (where user inputs value for x)
	uses function calls.....
*/

int main (void)
{
	float x;
	printf("\n3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6\n\n");
	printf("Enter an integer for x: " );
	scanf("%f", &x);
	
	printf("The result is %f", polynomial_calcuation(x));
	
}

float polynomial_calcuation(float x)
{
	
	return 3*pow(x,5) + 2*pow(x,4) - 5*pow(x,3) - pow(x,2) + 7*x - 6;
	
}