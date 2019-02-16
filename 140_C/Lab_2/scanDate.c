#include <stdio.h>

int main (void)
{
	int month, day, year;
	
	printf("Enter a date(dd-mm-yyyy): ");
	scanf("%d-%d-%d", &month, &day, &year);
	printf("This is the %dth day in the %dth month of %d", day, month, year);
		
	return 0;
}