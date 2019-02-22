#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	
	int f = creat("data", 0722);
	
	int x;
	int temp = 0;
	char c[2];
	char buffer;
	
	printf("Enter number between 1-15[inclusive]: ");
	scanf("%d", &x);

	if( x > 15 || x < 1)
	{
		printf("\nERROR\n");
		close(f);
		return 0;
	}
	
	
	int isprime(int n){

		int i;
		if (n <= 1) return 0;
		for( i = 2; i*i <= n; i++)
			if(n%i == 0) return 0;
		return 1;		
	}

	sprintf(c, "%d", x );
	
	write(f, &c, strlen(c));	
	close(f);

	if(fork() == 0)
	{
		sleep(2);
		int f2 = open("data", O_RDONLY, 0700);
		x = 0;
		temp = 0;

		read(f2,&buffer,1);
		x = buffer - '0';
		printf("%d", buffer);	
		while( read(f2,&buffer,1) > 0 )
		{
			temp = buffer - '0';
			x = x*10 + temp;		
		} 
		
		printf("   %d  ", x);		

		if( isprime(x) )
		{
			printf("ITS A PRIME\n");
		}
		else
			printf("NOT PRIME\n");
	}
	
	sleep(3);
	close(f);
}

