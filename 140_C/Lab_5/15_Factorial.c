#include <stdio.h> 

int main (void)
{
	int x,product = 1;
		
	while( x >= 0){
		
		printf("\nEnter a positive integer (Or (-) integer to exit): ");
		scanf("%d", &x);
		
		product = 1;
		
		for(int n = x; n >= 1; n--)
		{
			product *= n;
		}

		printf("The factorial of %d: %d\n", x,product);
	}
	
	printf("Thank you for using my software :)-");
	return 0;
}