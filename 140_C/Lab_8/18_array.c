#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define size 61

// Functions
void InputRange();
void PrintSpaces();
void PrintCharacters();
void PrintStats();


// Variables
int rk, k, w, h, x, y, diff;
float wCounter = 0;
char convert2Letters;
int a[size];

//Complex program working with arrays and functions

// Main
int main(void)
{
    // Randomizer
    srand(time(NULL));
	
	//Use to intialize all the values for the arrray a[size]
	for( int i = 0; i <= 60 ; ++i)
	{
		a[i] = i+1; 
	}
	
    // Input Range
    InputRange();

    // Print lines
    for( k = 1; k <= h; ++k )
    {
        rk = (rand()%(w-2))+2;
		
		if( rk == (w/2) )
		{
			wCounter += 1; 
		}
		
		if(rk <= 9)
		{
        printf("0%d:", rk);
        }
		else 
		{
			printf("%d:",rk);
		}
		
		diff = w-rk;
		
        // Prints
        PrintSpaces();
        PrintCharacters();
        printf("\n");
    }

    // Print stats
    PrintStats(); 
	
}

// Input Function
void InputRange()
{
    // Loop
    do
    {
        // Get w
        printf("Enter a value for w (10 <= w <= 20): ");
        scanf("%d", &w);

        // Get h
        printf("Enter a value for h (3 <= h <= 61): ");
        scanf("%d", &h);

    }while( w < 10 || w > 20 || h < 3 || h > 61 );
}

// Spaces
void PrintSpaces()
{
    if(diff <= (w/2))
    {
        for( x = 0 ; x < rk ; ++x)
        {      
            printf(" ");
        }
    }
}

// Characters
void PrintCharacters()
{
    if(diff <= (w/2))
    {        
        for( x = 0 ; diff > x ; ++x)
        {
            if(k > 9 && k <= 35)
            {
				convert2Letters = a[k -1] + 87;
                printf("%c", convert2Letters);
            }
			else if( k >= 36)
			{
				convert2Letters = a[k -1] + 29;
				printf("%c", convert2Letters);
			}
            else
            {
                printf("%d", k);
            }
        }
    }
    else
    {
        for(x = 0; x < rk-1 ; ++x)
        {
            if(k > 9 && k <= 35)
            {
               convert2Letters = a[k -1] + 87;
                printf("%c", convert2Letters);
            }
			else if( k >= 36)
			{
				convert2Letters = a[k -1] + 29;
				printf("%c", convert2Letters);
			}
            else
            {
                printf("%d", k);
            }
        }
    }
}

// Statistics
void PrintStats()
{	
    float percent = (float) (wCounter/ h) * 100;
    printf("Among %d numbers, the percentage of %d is %0.2f%%", h, (w/2), percent);
}