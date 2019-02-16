#include <stdio.h> 
#include <math.h> 

#define M_PI 3.14159265358979323846

int main (void)
{
	float radius,height,volume;
	
	printf("\n");
	printf("Enter radius and height (r,h): ");
	scanf("%f,%f", &radius,&height);
	volume = M_PI * pow(radius,2) * height;
	
	printf("\n");
	printf("Enter radius: %0.2f \n", radius);
	printf("Enter height: %0.2f \n", height);
	
	if(radius >= 2)
	{
		if(height > radius)
		{
			printf("The volume is %0.2f.\n", volume);
		}
		else
			printf("The height has to be bigger than the radius\n");
	}
	
	else if(height < radius)
	{
		printf("The radius cannot be smaller than 2\n");
		printf("The height has to be bigger than the radius\n");
	}
	
	else
		printf("The radius cannot be smaller than 2\n");
	
	return 0;
}