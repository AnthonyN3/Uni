#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
	Author: Anthony Nguyen

	C program to create a binary ppm file with 1000 by 1000 pixels. It uses five input
	colors to draw a picture. See sample runs. The input colors can be: red, green, blue, yellow,
	orange, cyan, magenta, ocean, violet. The corners of the central part should use the 250th and
	750th row/column.
*/

int main(int argc, char *argv[])
{	
	//Checks if there are enough arguments in the command line
	if(argc != 7)
	{
		printf("ERROR: Invalid number of arguments");	//Or use write(1, "text here", # of characters)
		return 0;	//Or use Exit(1) 
	}
	

	//We create a new file in which we are going to name whatever the 3rd argument user entered as
	int f1 = creat(argv[1], 0722);
	int status, id;

	//Write a generic header
	char headerDefault[] = "P6\n1000 1000\n255\n";
	write(f1, headerDefault, strlen(headerDefault));	

	int black = 0;
	int white = 255;

	for(int i = 0 ; i < 10 ; i++)
	{	
		if(fork() == 0)
		{
			if(i <= 4)
			{
				for(int x = 0 ; x < 1000*3*100 ; x++)
				{
					write(f1, &white, 1);
				}
			} 
			else 
			{
				for(int y = 0 ; y < 1000*3*100 ; y++)
				{
					write(f1, &black, 1);
				}
			}

			exit(1);
		}

		wait(&status);
	}

	close(f1);

    return 0;
}

