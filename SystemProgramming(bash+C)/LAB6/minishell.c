#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc , char *argv[])
{	
	int status;		
	
	for(int x = 1 ; x < argc ; x = x+2)
	{	
		if(fork() == 0)
		{	
			char str[ 5+strlen(argv[x]) ];
			strcpy(str, "/bin/");
			strcat(str, argv[x]);	
		
			printf("This child process is %d\n", getpid() );			
			
			if( x == argc - 2 && argv[x+1] == NULL )
			{				
				execl(str, argv[x], (char *) 0);
			}		
			execl( str , argv[x] , argv[x+1] , (char *) 0);
		}	
		
	}

	while(wait(&status) > 0);
	
	return 0;
}
