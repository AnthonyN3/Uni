#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	Author: Anthony Nguyen

	C program to create a binary ppm file with 1000 by 1000 pixels. It uses five input
	colors to draw a picture. See sample runs. The input colors can be: red, green, blue, yellow,
	orange, cyan, magenta, ocean, violet. The corners of the central part should use the 250th and
	750th row/column.
*/


//Function Prototype
int ColorToDecimal ( char colorName[] );


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
	int status, isCenter;

	//Write a generic header
	char headerDefault[] = "P6\n1000 1000\n255\n";
	write(f1, headerDefault, strlen(headerDefault));	

	int colors[5];
	
	for(int index = 0 ; index < 5 ; index++)
	{
		colors[index] = ColorToDecimal(argv[index+2]);

		if(colors[index] == -1)
		{
			printf("\nERROR: Invalid Color Entered\n");
			return 0;
		}

	}

	for(int childNum = 0 ; childNum < 10 ; childNum++)
	{	
		if(fork() == 0)
		{
			//If there are 10 childrens printing and the dimenions are 1000x1000
			//then each child needs to print a total of 100 rows (equivalent to 100*1000 = 100,000 pixels or 300,000 bytes) (NOTE: 1 pixel = 3 bytes [RGB])
			for(int rowNum = 0 ; rowNum < 100 ; rowNum++)
			{
				//First 5 childrens will write top half of the image
				if(childNum <= 4)
				{
					//each row consits of 1000 pixels, so we write 1000 pixels using this loop
					for(int x = 0 ; x < 1000 ; x ++)
					{
						//Since the color chhanges halfway through (500pixels) we switch the colors up when the iteration gets to 500
						if( x < 500 )
							write(f1, &colors[1] , 3);
						else
							write(f1, &colors[2] , 3);
					}
					
					//Used to calculate if we are at the center of the 1000 by 1000 image
					//NOTE: rowNum value is actually offset by 1.. so rowNum = 1 means you have just written the 2nd row of the image
					//we plan to start writing the center diamond top cornor in position 500x250..in order to implment this
					//you must take into account of the offseted rowNum...Therefore we must +1 to the rowNum in the equation
					isCenter = 2*(childNum*100 + (rowNum+1) - 250 );

					//If you are in range of the center diamond, start writing the center color
					if( isCenter > 0)
					{
						//Since we have alrady written the entire row out
						//We must lseek back to the correct position
						lseek(f1, (-3000) + (500*3) - ( (isCenter*3) /2 ) , SEEK_CUR);

						for(int w = 0 ; w < isCenter ; w++)
						{
							write(f1, &colors[0], 3);
						}

						lseek(f1, 500*3 - ( (isCenter*3)/2), SEEK_CUR );
					}

				}
				else	//other half prints the bottom of the image (everything is the same, but the equation for writing the center diamond)
				{
					//each row consits of 1000 pixels, so we write 1000 pixels using this loop
					for(int x = 0 ; x < 1000 ; x ++)
					{
						//Since the color chhanges halfway through (500pixels) we switch the colors up when the iteration gets to 500
						if( x < 500 )
							write(f1, &colors[3] , 3);
						else
							write(f1, &colors[4] , 3);
					}
					
					//Used to calculate if we are at the center of the 1000 by 1000 image
					//NOTE: rowNum value is actually offset by 1.. so rowNum = 1 means you have just written the 2nd row of the image
					//However, unlike the previous case, +1 will not be needed
					isCenter = 2*(750 - childNum*100 - (rowNum)) ;

					//If you are in range of the center diamond, start writing the center color
					if( isCenter > 0)
					{
						//Since we have alrady written the entire row out
						//We must lseek back to the correct position
						lseek(f1, (-3000) + (500*3) - ( (isCenter*3) /2 ) , SEEK_CUR);

						for(int w = 0 ; w < isCenter ; w++)
						{
							write(f1, &colors[0], 3);
						}

						lseek(f1, 500*3 - ( (isCenter*3)/2), SEEK_CUR );
					}
				}
			}

			exit(1);
		}

		wait(&status);
	}

	close(f1);

    return 0;
}


int ColorToDecimal ( char colorName[] )
{	
	int baseTenValue = -1;
	
	if(strcmp(colorName, "red") == 0)
	{
		baseTenValue = 255;	//good
	} 
	else if( strcmp(colorName, "green") == 0 )
	{
		baseTenValue = 65280;	//good
	}
	else if( strcmp(colorName, "blue") == 0 )
	{
		baseTenValue = 16750899;	//good
	}
	else if( strcmp(colorName, "yellow") == 0 )
	{
		baseTenValue = 3407871;	// good
	}
	else if( strcmp(colorName, "orange") == 0 )
	{
		baseTenValue = 6711039;
	}
	else if( strcmp(colorName, "cyan") == 0 )
	{
		baseTenValue = 16776960;	//good
	}
	else if( strcmp(colorName, "magenta") == 0 )
	{
		baseTenValue = 16711935;	//good
	}
	else if( strcmp(colorName, "ocean") == 0 )
	{
		baseTenValue = 16744448;	//good
	}
	else if( strcmp(colorName, "violet") == 0 )
	{
		baseTenValue = 3342387;	//good
	}

	return baseTenValue;

}