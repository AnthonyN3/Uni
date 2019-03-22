#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) 
{
        int fd1, fd2;
        pid_t pid;
        char ch;
        char blanks[55]="                                 |  ";
        int writeblanks = 1;

        chmod("/tmp/Anthony0", 0777);
        chmod("/tmp/Anthony1", 0777);

        while (1)
        {                 
		printf("\nConnected...\n");

		fd1 = open("/tmp/Anthony0", O_WRONLY); 
		fd2 = open("/tmp/Anthony1", O_RDONLY);
		
                printf("\n my messages (client)\t\treceived messages (server) \n");

                
printf("-------------------------------------------------------------------------------\n");
                
                if ( (pid = fork()) == -1 )
                {
                        perror("fork");
                        exit(1);
                }

                //child will be the writing end of the pipe Anthony0
                if ( pid == 0 )
                        while (1)
                        {
                                while( (ch=getchar()) != -1)    //takes users input and writes into pipe so the server will see it
                                        write(fd1, &ch, 1);
                        }

                //parent runs this
                while ( read(fd2, &ch, 1) == 1 )        //parent will read the input from the pipe Anthony1 (which is written by server)
                {//NOTE: while loop will only exit when pipe Anthony1's writing is closed
                        if ( writeblanks == 1 )
                                write(1, blanks, sizeof(blanks));
                        write(1, &ch, 1);

			if( ch == '\n')      //checks when the "Enter" key is pressed to activate if a writeblank is needed
				writeblanks = 1;
			else
				writeblanks = 0;                        
                }

                close(fd1);
                close(fd2);
                printf("\nClient left.\n\n\n");

		exit(1);               //client MUST exit in order to kill all procceses 
        }
}

