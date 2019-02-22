#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
	if (fork() == 0)
	{
	 	fork();
		//printf("TEST");
	}
	else {
	 	fork();
		fork();
		printf("%d\n", getpid());
	}
}
