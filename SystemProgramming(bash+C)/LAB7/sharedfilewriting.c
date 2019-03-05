#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

//Author: Anthony Nguyen

void myAlarmHandler(int dummy){};


int main(int argc, char* argv[])
{
	//Check for missing argument in command line
	if( argv[1] == NULL)
	{
		printf("ERROR: Missing Argument (File Name)\n");
		return 0;
	}	
	
	//Variables
	int f1;					//descriptor for file opening
	pid_t childOne, childTwo;		//Hold childrens pid
	char* buf[3];				//Used for writing into file
	buf[0]="EXAM! EXAM! EXAM!\n";
	buf[1]="HELP! HELP! HELP!\n";
	buf[2]="STUDY! STUDY! STUDY!\n";
	
	//Opens file for writing, if file does not exist exit and prompt error
	if ( (f1 = open(argv[1], O_WRONLY)) == -1)
	{
		printf("ERROR: file \"%s\" does not exist\n", argv[1]);
		return 0;
	} 
	
	//Overwrite SIGALRM with myAlarmHandler
	signal(SIGALRM, myAlarmHandler);
	
	printf("parent opened file: %s\n", argv[1]);
	
	//child one will run the contents inside if statement (parent runs else statement)
	if( (childOne = fork()) == 0 )
	{
		printf("%d has written to file: %s", getpid(), buf[0]);
		write(f1, buf[0], strlen(buf[0]) );
		sleep(5);
		kill(getppid(), SIGALRM);	
	}
	else
	{
		printf("parent created child process: %d\n", childOne);
		
		//child two runs the inside of if statement (parent runs else statement)
		if( (childTwo = fork()) == 0 )
		{
			pause();
			
			printf("%d has written to file: %s", getpid(), buf[1]);
			write(f1, buf[1], strlen(buf[1]));
			sleep(5);
			kill(getppid(), SIGALRM);
		}
		else
		{
			printf("parent created child process: %d\n", childTwo);
			pause();
			kill(childTwo, SIGALRM);
			pause();

			printf("parent has written to file: %s", buf[2]);
			write(f1, buf[2], strlen(buf[2]));
			sleep(5);

			printf("parent closed the file\n");
		}
	}
	
	close(f1);
	return 0; 
}
