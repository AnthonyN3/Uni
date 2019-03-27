#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

//Author: Anthony Nguyen

int main(void)
{
	//Variables
	int f1, toInt, charWritten;
	char num[2];
	char newNum[2];	
	char newline = '\n';

	f1 = open("storage", O_RDWR);
	read(f1, num, 2);	
		
	toInt = atoi(num);
	toInt = toInt - 3;
			
	charWritten = sprintf(newNum, "%d", toInt);	//NOTE:sprintf redirects the printf into the char array newNum and  returns # of characters written

	lseek( f1, 0 , SEEK_SET);	
	
	//Check if the integer is 1 or 2 digits..
	//If 1, we must write a "\n" at the end	
	if(charWritten == 1)
	{
		write(f1, newNum, strlen(newNum));
		write(f1, &newline, 1);
	}	
	else
		write(f1, newNum, strlen(newNum));
	
	printf("from consumer: current total is %d\n", toInt);

	close(f1);	//Must close before execl in order to write to file
	execl("./producer", "producer", (char *) 0); 	//Redirect into the bash script
	

	//This return is almost useless because it never actually ever gets reached
	//since we keep redirecting to the bashscipt from exec1 above
	return 0;
}
