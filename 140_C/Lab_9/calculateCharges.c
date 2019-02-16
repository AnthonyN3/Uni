#include <stdio.h> 
#include <math.h>

float calculateCharges(float hours);

//Calculate the charge per car that is parked in a parking space depending on the users input of how long 3 cars are parked for

int main (void)
{
	float hours[3];
	float totalHours=0;
	float totalCharge=0;
	
	printf("Enter the hours parked for 3 cars: ");
	scanf("%f %f %f", &hours[0], &hours[1], &hours[2]);
	
	printf("\tCar\tHours\tCharge\n");
	for( int i = 0 ; i < 3; ++i)
	{
		printf("\t%d\t%0.1f\t%0.2f\n", i+1 ,hours[i],calculateCharges(hours[i]));
		totalHours += hours[i];
		totalCharge += calculateCharges(hours[i]);
	}
	
printf("\tTOTAL\t%0.1f\t%0.2f", totalHours, totalCharge);
	
}


float calculateCharges(float hours)
{
	if(hours > 16)
	{
		return 10;
	}
		
	return hours <= 3 ? 2 : 2 + 0.5*ceil(hours-3);
}