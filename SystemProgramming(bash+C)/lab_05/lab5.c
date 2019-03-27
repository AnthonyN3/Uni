#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argsc , char *argv[])
{
	int status;

    if( fork() == 0)
	{
		if(fork() == 0)
		{
			sleep( atoi(argv[5]) );
			printf("process 5 terminated. pid=%d\n", getpid() );
		}
		else
		{
			if( fork() == 0)
			{
				sleep( atoi(argv[4]) );
				printf("process 4 terminated. pid=%d\n", getpid() );
			}
			else
			{
				sleep( atoi(argv[2]) );
				printf("process 2 terminated. pid=%d\n", getpid() );
			}			
		}
	
	}
	else
	{
		if(fork() == 0)
		{
			if(fork() == 0)
			{
				sleep( atoi( argv[7]) );
				printf("process 7 terminated. pid=%d\n", getpid() );
			}
			else
			{
				if(fork() == 0)
				{
					sleep( atoi(argv[6]) );
					printf("process 6 terminated. pid=%d\n", getpid() );
				}
				else
				{
					sleep( atoi(argv[3]) );
					printf("process 3 terminated, pid=%d\n", getpid() ); 
				}
			}			

        }
		else 
		{
			sleep( atoi(argv[1]) );
			printf("process 1 terminated. pid=%d\n", getpid() );
		}
	

	}

    while(wait(&status) > 0);
	
	exit(0);
}

