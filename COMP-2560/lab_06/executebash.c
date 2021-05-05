#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
	int status;
	
	if( fork() == 0)
	{
		execl("./mybash" , "mybash" , "EXAM!" , (char *) 0  );
		//Since we call execl, we never reach anything under this
	}
	
	wait(&status);
	printf("STUDY!STUDY!STUDY!\n");

	return 0;
}
