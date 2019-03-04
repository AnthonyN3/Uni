#include <stdio.h>

/*
	Calculates commision given input of the price share and the amount of the shares sold...
	
*/

int main (void)
{
	float originalCommission, rivalCommission, pricePerShare, value;
	int sharesSold;
	
	printf("\nEnter the price per share: ");
	scanf("%f", &pricePerShare);
	printf("Enter the amount of shares sold: ");
	scanf("%d", &sharesSold); 
	
	value = pricePerShare*sharesSold;
	
	if(value < 2500.00f)
		originalCommission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		originalCommission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		originalCommission = 76.00f + .0034f *value;
	else if (value < 50000.00f)
		originalCommission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		originalCommission = 155.00f + .0011f * value;
	else
		originalCommission = 255.00f + .0009f * value;
	
	originalCommission = originalCommission < 39 ? 39 : originalCommission;
	
	rivalCommission = sharesSold >= 2000 ? 33+0.02*sharesSold : 33+0.03*sharesSold;
	
	printf("\nOrginal broker's commission: $%.2f\n", originalCommission);
	printf("Rival broker's commission: $%.2f\n", rivalCommission);
	
	return 0;
}