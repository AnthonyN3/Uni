#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>


//Prototypes
void child(int fd[], char *argv[] );
void parent(int fd[], char *argv[]  );

int main(int argc, char *argv[])
{	
	//[0] = reader
	//[1] = writer

	int fd[2];
	
	pipe(fd);

	if(fork() == 0)//Child
		child(fd,argv);		
	else
		parent(fd, argv);		
	
	return 0;
}


void child(int fd[], char *argv[] )
{
	close(fd[0]);

	//Changing the standard output (screen) to fd[1] (pipe)
	dup2(fd[1], STDOUT_FILENO);

	//runs command in bash, but output is directed into the fd[1] (pipe) since we
	//redirected the Standard Output
	execlp(argv[1], argv[1], (char *)0);	
	close(fd[1]);
}

void parent(int fd[], char *argv[])
{
	char c;
	int byteCount = 0;	

	close(fd[1]);	//close writer

	int f  = open("result.txt", O_CREAT|O_TRUNC|O_WRONLY, 0755);
		
	while( read(fd[0], &c,1) != 0 )
	{
		write(f, &c, 1);	
		byteCount++;
	}
	
	printf("The result of %s is written into result.txt with total %d bytes\n", argv[1], byteCount);

	close(fd[0]);
	close(f);
}
