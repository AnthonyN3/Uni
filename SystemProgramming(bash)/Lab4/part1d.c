#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	if( fork() == 0 )
		fork();
	else
	{
		fork();
		fork();
		exit(0);
	}
	printf("%d\n", getpid());

}
