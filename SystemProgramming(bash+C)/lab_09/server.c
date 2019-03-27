#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>


void myInteruptHandler()
{
	unlink("/tmp/Anthony0");
	unlink("/tmp/Anthony1");

	kill(getpid(), SIGKILL);
}


int main(int argc, char *argv[]) {
	int fd1, fd2;
	pid_t pid;
	char ch;
	char blanks[55]="                                 |  ";
	int writeblanks = 1;

	unlink("/tmp/name0");
 	unlink("/tmp/name1"); 	
	if ( mkfifo("/tmp/Anthony0", 0777) || mkfifo("/tmp/Anthony1", 0777)) 
	{
 		perror("fifo");
 		exit(1);
 	}
 
	chmod("/tmp/Anthony0", 0777);
 	chmod("/tmp/Anthony1", 0777);
	
	signal(SIGINT, myInteruptHandler); 	

	while (1) 
	{
 		printf("\nWaiting for connection...\n");
 		fd1 = open("/tmp/Anthony0", O_RDONLY);
 		fd2 = open("/tmp/Anthony1", O_WRONLY);
 		printf("\n my messages (server)\t\treceived messages (client) \n");
 
		printf("-------------------------------------------------------------------------------\n");
 		
		if ( (pid = fork()) == -1 ) 
		{
	 		perror("fork");
 			exit(1);
 		}
		
		//child will take care of pipe end write of Anthony1
		if ( pid == 0 )
 			while (1)
			{
				while( (ch=getchar()) != -1)
					write(fd2, &ch, 1);
			}
		
		
		

		//parent runs this
		while ( read(fd1, &ch, 1) == 1 ) 
		{//NOTE: while loop will only exit when pipe Anthony0's writing is closed
			if ( writeblanks == 1 )
				write(1, blanks, sizeof(blanks));
 			write(1, &ch, 1);

			if( ch == '\n')
				writeblanks = 1;
			else
				writeblanks = 0;
						
		}

		close(fd1);
		close(fd2);
 		printf("\nClient left.\n\n\n");
 		kill(pid, SIGTERM);	//Used to terminate the 
	}
}
