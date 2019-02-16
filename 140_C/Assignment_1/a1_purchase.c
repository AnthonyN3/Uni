#include <stdio.h>

/*
This is only a basic immplentation

Create a C program that will prompt for a item number, price and date of purchase...
With the input that the user has inputed, it will display it in a table like manner (with headers)...
HOWEVER: this is not a sophisticated code, it doesonly checks if the price entered is higher than 999.99 and if so, it will round down to 999.99
there is no implmentation to check if values inputed are legal (ei, legal date, number, or even unit price)
*/

int main (void) 
{
		int day, month, year, itemNumber; 
		float unitPrice;
		
		printf("Enter the item number: ");
		scanf("%d", &itemNumber);
		printf("Enter the unit price: ");
		scanf("%f", &unitPrice);
		printf("Enter the purchase date (mm/dd/yyyy): ");
		scanf("%d/%d/%d", &month, &day, &year);
		printf("\n");
		printf("\n");
		
		if(unitPrice > 999.99)
		{
			unitPrice = 999.99;
		}
			
		
		printf("item\tUnit\tPurchase\n");
		printf("\tPrice\tDate\n");
		printf("%d\t$%6.2f\t%d/%d/%d", itemNumber, unitPrice, month, day, year);

		return 0;	
	
}