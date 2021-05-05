#include <stdio.h>

//Taking users input for a date in (dd/mm/yyyy) and translating it into a sentance

int main (void)
{
	int month, day, year;
	
	printf("Enter a date(dd-mm-yyyy): ");
	scanf("%d-%d-%d", &month, &day, &year);
	printf("This is the %dth day in the %dth month of %d", day, month, year);
		
	return 0;
}