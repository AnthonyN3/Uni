#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main (void)
{
	int x,k,n,rk,y; 
	
	printf("Enter a number from 2 to 9: ");
	scanf("%d", &n);
	
	x = 0;
	k = n;
	
	while( x < n)
	{
	
		rk = rand() % 8 + 2;
		y = 0;
	
		printf("%d:", rk);
	
		if( rk < 5)
		{
			while( rk-1 > y)
			{
				printf("%d", k);
				y++;
			}
		}
		else
		{
			while(rk > y)
			{
				printf(" ");
				y++;
			}
			
			y = 0;
			
			while( 10-rk > y)
			{
				printf("%d",k);
				y++;
			}
		}
		printf("\n");
		k--;
		x++;
	}
}