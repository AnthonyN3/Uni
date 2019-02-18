#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 5

/*  Initialize the array with 0's
    Input: A 2D array
    Ouput: Void (intilizses the array to 0's
*/
void InitializeArray2D(int array[M][N]);

/*  Populate the array with random numbers between 1 and 100.
    Input: A 2D array
    Ouput: Void (populates the array with numbers from 1-100)
*/
void PopulateRanomdValues2d(int array[M][N]);

/*  Prints a 2D array
    Input: A 2D array
    Ouput: Prints the 2D array
*/
void PrintArray2D(int array[M][N]);

/*  Sort the array in ascending order using Bubble Sort
    Input: A 2D array
    Ouput: Void (sorts the array)
*/
void Sort2D(int array[M][N]);

/*  Linear Search to find if a number n is found in the array, where n is an integer between 1 and 100 entered by the user.
    Input: A 2D array and the number the user is earching for in that array
    Ouput: returns the amount of times it saw the users input int he array
*/
int LinearSeach2D(int array[M][N] , int n);

/*  Apply a single LEFT shift operation to the array
    Input: A 2D array
    Ouput: void
*/
void LeftShift2D(int array[M][N]);

int main(void)
{
    /*Randomizses the the sequance  of the seed, so that
    a randomly generated sequance wont yield the same sequance*/
    srand(time(NULL));

    //Array variable
    int array[M][N];
    int n;
    int choose;

    //Creates the function menu so the user knows which functions correspond to what number
    printf("\n[1] Intialize Array With 0's\t\t\t[4] PrintArray2D");
    printf("\n[2] Populate Array with (1-100)\t\t\t[5] Sort Array");
    printf("\n[3] Linear Search\t\t\t\t[6] Left Shift\n\n");


    //Loops the choosing of a function so that the user is able to use more than one function after termination of the program
    do{
        printf("Enter a number coresponding to the function you'd like to run (0 to exit): ");
        scanf("%d", &choose);
       // printf("\n");

        // Switch statement is used to choose the function the user wanted to use correspond to its given number in the list/table
        switch (choose){
            case 0:
                break;
            case 1:
                InitializeArray2D(array);
                break;
            case 2:
                PopulateRanomdValues2d(array);
                break;
            case 3:
                printf("\n\tinput an integer from 1-100 to check if it is found in the array: ");
                scanf("%d", &n);
                printf("\t%d was found %d time(s) in the array\n\n", n, LinearSeach2D(array,n));
                break;
            case 4:
                PrintArray2D(array);
                break;
            case 5:
                Sort2D(array);
                break;
            case 6:
                LeftShift2D(array);
                break;
            default :
                printf("\tInvalid input\n");
                break;
        }

    }while(choose != 0);

    return 0;
}

void PrintArray2D(int array[M][N])
{
    //Uses two for loops to print the array
    for( int i = 0 ; i < M ; ++i )  //First loop corresponds to the rows
    {
        for( int x = 0 ; x < N ; ++x) //second loop corresponds to the amount of columns in the row of the array
        {
            printf("%4d", array[i][x]); //Prints the components of the array
        }
        printf("\n");
    }
}

void PopulateRanomdValues2d(int array[M][N])
{
    //Uses 2 for loops to randomly populate the array
    for( int i = 0 ; i < M ; ++i ) //First loop corresponds to the rows
    {
        for( int x = 0 ; x < N ; ++x)//second loop corresponds to the amount of columns in the row of the array
        {
            //Assigns each array spot with a value between 1 to 100
            array[i][x] = rand() % 100 + 1;
        }
    }
}

void InitializeArray2D(int array[M][N])
{
    //Uses 2 for loops to intialize the array with zeros
    for( int i = 0 ; i < M ; ++i ) //First loop corresponds to the rows
    {
        for( int x = 0 ; x < N ; ++x)//second loop corresponds to the amount of columns in the row of the array
        {
            //Assigns all spots in the array to zero
            array[i][x] = 0;
        }
    }
}

void Sort2D(int array[M][N])
{
    //Variable
    int hold;

    //Uses 3 loops to bubble sort the array from lowest to greatest
  	for(int k =0 ; k < M*N-1; ++k)    //This loop is for the passes
	{
		for(int i = 0; i < M ; ++i) //This loop is for the rows
		{
            for ( int g = 0; g < N ; ++g)   //Loop for column
            {
                //If statement checks if its at the last spot of the array, it wont run the code inside the if statement
                if( (i != M-1) || (g != N-1))
                {
                    //If statment to check if the spot infront of the array is bigger than the current spot, if so it will swap spots.
                    if(array[i][g] > array[i][g+1])
                    {
                    hold = array[i][g];
                    array[i][g] = array[i][g+1];    /* SWAPPING */
                    array[i][g+1] = hold;
                    }
                }
            }
        }
	}
}

int LinearSeach2D(int array[M][N] , int n)
{
    //Variables
    int count=0;

    //Two loops to check if the number the user input is seen inside the array
    for( int i = 0 ; i < M ; ++i )
    {
        for( int x = 0 ; x < N ; ++x)
        {
            //If the number the user entered is in the array it will add one to the variabe count
            if (array[i][x] == n)
            {
                count++;
            }
        }
    }
    //returns the number of times the the user's input is in the array
    return count;
}

void LeftShift2D(int array[M][N])
{
    //Variables
    int hold;

    //Uses 2 loops to go through the rows and column of the array
    for(int i = 0; i < M ; ++i)
    {
        for ( int g = 0; g < N ; g++)
        {
            if( (i != M-1) || (g != N-1))
            {
                hold = array[i][g];
                array[i][g] = array[i][g+1];        /*left shft*/
                array[i][g+1] = hold;
            }
        }
    }
}
