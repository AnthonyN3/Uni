#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//time_t t;

//

int main (void)
{
	int x,k,n,rk,y;
	char letters;
	//srand((time(&t)));
	srand(time(NULL));
	
	printf("Enter a number from 2 to 35: ");
	scanf("%d", &n);
	
	x = 0;
	k = n;
	letters = n + 87;
	
	while( x < n)
	{
		rk = rand() % 8 + 2;
		y = 0;
		printf("%d:", rk);
		
			
		if( rk < 5)
		{
			while( rk-1 > y)
			{	
				if(k <= 9)
				{
					printf("%d", k);
				}
				else 
				{
					printf("%c", letters);
				}
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
				if (k <= 9)
				{
					printf("%d",k);
				}
				else
				{
					printf("%c", letters);
				}
				y++;
			}
		}
		
		printf("\n");
		letters--;
		k--;
		x++;
	}
	
	return 0;
}