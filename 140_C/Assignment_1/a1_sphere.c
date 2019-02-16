/*Libaries*/
#include <stdio.h> 
/*math.h is a library in which allows certain math operations to be used*/
#include <math.h>
#define Pi 3.1415926535897932384626433832795028841971693993751

/*
	Takes input from user for a sphere (radius) and calculaes the volume of a sphere
*/

int main (void)
{
	float volume, radius;
	printf("Enter the radius (meters): ");
	scanf("%f", &radius);
	/*pow(radius,3) is the power operation in the math.h library*/
	volume = 4.0f/3.0f*Pi*pow(radius,3);
	printf("A volume of sphere with %0.2f-meter radius is %0.4f.", radius, volume);	
	
	return 0;
}