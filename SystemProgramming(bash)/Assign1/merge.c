#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
        int f1,f2;
        int temp = 0;	//temporary holder to hold the integer of each dimension 
        int digit = 0;	//used to read each digits of the dimension of each image
        char buffer;	//used to read characters in file
        int dimen[4];   //spots 0-1 correspond to the first images dimensions, and spots 2-3 are the second image's dimensions.
	
	if(argv[1] == NULL )
	{
		printf("\nERROR: missing image one and image two\n\n");
		return 0;
	} else if (argv[2] == NULL){
		printf("\nERROR: missing image two\n\n");
		return 0;
	} else if (argv[3] == NULL){
		printf("\nERROR: missing the file name of the merged images (third argument)\n\n");
		return 0;
	}

	printf("IMAGES:\n%s\n%s\n\n", argv[1], argv[2] );
	
	//Open the 2 images for reading ONLY	
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[2], O_RDONLY);
	
	if(f1 == -1 || f2 == -1)
	{	
		if(f1 == -1 && f2 == -1)
			printf("ERROR: \"%s\" and \"%s\" cannot be found\n\n", argv[1], argv[2] );
		else if ( f1 == -1) 
			printf("ERROR: \"%s\" cannot be found\n\n", argv[1]);
		else 
			printf("ERROR: \"%s\" cannot be found\n\n", argv[2]);

		close(f1);
		close(f2);
		return 0;
		
	}
			
	//offset pass the "P6\n" in order to get to the line that reads the size of the image
	lseek(f1, 3, SEEK_SET);
	lseek(f2, 3, SEEK_SET);
	
	//this will grab all of the dimensions of both of the images and store them in the array dimen[];
	//[0] -> width of image 1	[1] -> height of image 1
	//[2] -> width of image 2	[3] -> height of image 2
	for (int i = 0 ; i < 4 ; i++)
	{
		digit = 0;

		if( i <= 1)
		{
	        	read(f1, &buffer, 1);
	                temp = buffer - '0';
			
			while( read(f1, &buffer,1) > 0 &&  buffer != ' ' &&  buffer != '\n'  )
			{
				digit = buffer - '0';
				temp = temp*10 + digit;
			}
		}
		else if( i >= 2)
                {
			read(f2, &buffer, 1);
			temp = buffer - '0';

                        while( read(f2, &buffer,1) > 0 &&  buffer != ' ' &&  buffer != '\n'  )
                        {
                                digit = buffer - '0';
                                temp = temp*10 + digit;
                        }
                }

		dimen[i] = temp; 				
	}
	
	//if the dimensions are not compatible, then an error will be prompted and the program will end
	if(dimen[0] < dimen[2] || dimen[1] < dimen[3])
	{
		printf("ERROR:\"%s\" dimensions are to small to merge with \"%s\"\n\n", argv[1] , argv[2]);
		close(f1);
		close(f2);
		return 0;		

	}else
	{
		printf("COMPATIBLE IMAGE DIMENSIONS\n\n");
	}	
	
	//Reset the position of the read back to the beggining for both images
	lseek(f1, 0, SEEK_SET);
	lseek(f2, 0, SEEK_SET);		
	
	//Calculates the length in bytes of the header of image1 and image2
	int header1=0,header2=0;
	while( read(f1, &buffer, 1) > 0 && (buffer > 47 || buffer == 10 || buffer == 32)  )		// 32 - Space , 10 - \n , 47 - acci value before the last digit 0
		header1++;

	while( read(f2, &buffer, 1) > 0 && (buffer > 47 || buffer == 10 || buffer == 32)  ) 	
		header2++;

	//Create a new file called "merged.ppm" where we will merge both images
	int f3 = creat(argv[3], 0722);
	
	//Since we are printing image2 onto the cornor of image1, we start at the beggining of image1 (for the header) and offset image2 (so we can exclude its header)
	lseek(f1, 0, SEEK_SET);
	lseek(f2, header2, SEEK_SET);
	
	//write the header of image1 (P6)
	int count = 0;
	while (count++ < header1 && read(f1, &buffer , 1) > 0)
		write(f3, &buffer, 1);
	
	//write contents of image1 and image2 into new image3
	char empty;
	int check = 0;
	count = 0;
	while(count++ < dimen[0]*dimen[1]*3)
	{	
		check++;
		if( check % (dimen[0]*3-dimen[2]*3+1) == 0 && count <  3*dimen[0]*dimen[3]   ) 		//checks if we are at the top right cornor if so, we write contents of image 2
		{	
			int i = 0;
			while(i++ < dimen[2]*3)
			{
				read(f1, &empty, 1);
				read(f2, &buffer, 1);
				write(f3, &buffer, 1);
				count++;
			}
			count--;	//the count will be off by +1, therefore we subtract 1 to the count
		}else{											//if not in the top right cornor, we write contents of image1 
			read(f1, &buffer, 1);
			write(f3, &buffer, 1);
		}

	}

	printf("....Saved as \"%s\"\n", argv[3]);

	close(f1);
	close(f2);	
	close(f3);
	

        return 0;
}

