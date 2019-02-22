#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int status;

	if(fork() == 0)
	{
		sleep(3);
		exit(1);
	}

	printf("HELLO\n");

	wait(&status);

	printf("WORLD");

	return 0;
}