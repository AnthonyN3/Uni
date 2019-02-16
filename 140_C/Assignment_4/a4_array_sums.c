#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Used for easier maniulation
#define columns 5	
#define rows 5

/*
	Basic Program
	Working with 2d arrays in C (SIMPLE ADDITION USING 2d Array and there index's)
	-Populate the 2d array with randomly generated numbers from 0-23
	-Print out the sum of each of the individual rows and column....
*/

int main (void)
{	
	int array[rows][columns];
	int sum;
	
	//We need this in order to randomize the seed of the random values generated....
	//For example, if you exclude this, there will be numbers randomly generated, but ever time we re-run the program that 
	//same randomly generated number will be generated... (Ex: 1,5,2,32 (run 1) --> 1,5,2,32 (run 2))
	srand(time(NULL));
	

	//Simplistic loops to cycle through each position

	for( int x = 0; x < rows; x++)
	{	
		for( int i = 0; i < columns; i++)
		{
			array[x][i] = rand() % 24;
			
		}
	}	
	
	//Display 2d Array
	for(int x = 0; x < rows ; x++)
	{
		printf("row %d: ", x+1);
		for( int i = 0; i < columns ; i++)
		{
			printf("%2d ", array[x][i]); 	
		}	
		printf("\n");
	}
	

	printf("\nRow total:  ");	
	for(int x = 0; x < rows; x++)
	{
		sum = 0;
		for(int i = 0; i < columns; i++)
		{
			sum += array[x][i]; 		
		}
		printf(" %d", sum);
	}
	
	printf("\nColumn total:  ");
	for(int x = 0; x < rows; x++)
	{
		sum = 0;
		for(int i = 0; i < columns; i++)
		{
			sum += array[i][x];
		}
		printf(" %d", sum);
	}
	
	
	return 0;
}