#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <string.h>

//Author Anthony Nguyen

int main(int argc, char *argv[])
{
	char buffer[100];
	int sd, client;
	socklen_t len;
	pid_t pid;

	struct sockaddr_in servAdd;
	struct sockaddr_in cliAdd;
	
	sd = socket(AF_INET, SOCK_STREAM, 0);

	servAdd.sin_family = AF_INET;
	servAdd.sin_port = 55558;
	
	bind(sd, (struct sockaddr*)&servAdd, sizeof(servAdd));
	listen(sd,5);
	
	while(1)
	{
		printf("Waiting for connection...\n");
		
		len = sizeof(cliAdd);
		client = accept(sd,(struct sockaddr*)&cliAdd,&len);

		printf("Connected\n");
		
		memset(buffer, 0 , 100);

		while( read(client, buffer, 100) > 0) 
		{
			printf("received command: %s\n", buffer);
			
			if( (pid = fork()) == 0)
			{
				dup2(client, STDOUT_FILENO);
				execlp(buffer, buffer, (char*)0);
				memset(buffer, 0 , 100);
				return 0;
			} 
		}		

		close(client);
	}
	
	return 0;

}
