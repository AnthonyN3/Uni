#include <stdio.h>
int main(void)
{
    int x;
	int factorial; 
	short factorialShort; 
	unsigned short factorialUshort; 
	unsigned int factorialUint; 
	long factorialLong; 
	unsigned long factorialUlong; 
	long long factorialLongLong; 
	unsigned long long factorialUlongLong;  
	long double factorialLongDouble;
	
	
	
	do {
		
		printf("\nEnter a positive integer: ");
		scanf("%d", &x);
		
		if (x >= 0) 
		{
			
			factorial = 1; 
			factorialShort = 1;
			factorialUshort = 1; 
			factorialUint = 1;
			factorialLong = 1;
			factorialUlong = 1;
			factorialLongLong = 1;
			factorialUlongLong = 1;
			factorialLongDouble = 1;
			
			
			
			for (int n = x ; n >= 1 ; n--) 
			{
				factorial *= n;
				factorialShort *= n;
				factorialUshort *= n;
				factorialUint *= n;
				factorialLong *= n;
				factorialUlong *= n;
				factorialLongLong *= n;
				factorialUlongLong *= n;
				factorialLongDouble *= n;
				
			}
			
			printf("Factorial of %d:\n", x);   
			printf("%hi (short, size = %lu)\n", factorialShort, sizeof(factorialShort));
			printf("%hu (unsigned short, size = %lu)\n", factorialUshort, sizeof(factorialUshort)); 
			printf("%d (int, size = %lu)\n", factorial, sizeof(factorial));
			printf("%u (unsigned int, size = %lu)\n", factorialUint, sizeof(factorialUint));			
			printf("%li (long, size = %lu)\n", factorialLong, sizeof(factorialLong));  //!!!
			printf("%lu (unsigned long, size = %lu)\n", factorialUlong, sizeof(factorialUlong)); //!!!
			printf("%lld (long long, size = %lu)\n", factorialLongLong, sizeof(factorialLongLong));			
			printf("%llu (unsigned long long, size = %lu)\n", factorialUlongLong, sizeof(factorialUlongLong));			
			printf("%Lg (long double, size = %lu)\n", factorialLongDouble, sizeof(factorialLongDouble)); 	//Lf
		}
		
		
	} while (x >= 0);
	
	
	printf("Thank you for running my software :)-");
	
	return 0;
}

	
		  
	  
	
