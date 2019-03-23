#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

// Author: Anthony Nguyen

int main(int argc, char *argv[])
{
	char buffer[50];
	char commandOut[10000];
	int server;
	socklen_t len;
	struct sockaddr_in servAdd;
	
	int checker = 0;
	
	server = socket(AF_INET, SOCK_STREAM,0);
	
	servAdd.sin_family = AF_INET;
	servAdd.sin_addr.s_addr = inet_addr(argv[1]);
	servAdd.sin_port = 55558;
	
	memset(commandOut, 0, 10000);
	memset(buffer, 0, 50);	
	
	char ch;
	
	if( fork() == 0)
	{
		while(1)
		{
			if( recv(server, &ch, 1, MSG_PEEK) == 0)
			{
				kill(getppid(), SIGINT);
				exit(1);
			}
		}
	} 
	else
	{
		while(1)
		{	
			connect(server,(struct sockaddr*)&servAdd,sizeof(servAdd));
		
			printf("\nenter shell command: ");
			scanf("%s", buffer);
		
			write(server, buffer, strlen(buffer)+1);		
			read(server,commandOut, 10000);
			printf("%s", commandOut);
		
			memset(commandOut,0 , 10000);
			memset(buffer,0,50);
		}	
	}

	return 0;
}
