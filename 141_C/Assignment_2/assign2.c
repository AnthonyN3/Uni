/*
Nguyen, Anthony
id: 104792283
Assignment 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 20
#define ROW 20

//ROWSIZE and COLSIZE is user inputed to make it easier to change from size to size when testing
#define ROWSIZE 1
#define COLSIZE 1

/*  Populates the 2D Array of sizes rowsize x colsize with random integers ranging between min and max inclusive
    Input: A 2D array, the rowsize and columnsize of that array, and a min and maximum
    Ouput: Void (populates the array with min-max)
*/
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);

/*  Display the contents of a 2D array of size rowsize x colsize in a table format that is each line will display one row where the numbers are separated by a single space character.
    Input: A 2D array, the rowsize and columnsize of that array
    Ouput: Void (it prints the array in a table form)
*/
void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize);

/*  Given a 2D array A of size rowsize x colsize, return the largest integer number it contains.
    Input: A 2D array, the rowsize and columnsize of that array
    Ouput: type int, outputs/returns the largest integer found in the array
*/
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);

/*  Calculate the sum of a given column col of a 2D array of size rowsize x colsize. Return the sum of that column.
    Input: A 2D array, the rowsize and columnsize of that array, and the column that you'd like to find the sum of
    Ouput: type int, returns sum of the given column that was inputed to find the sum of
*/
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);

/*  Sort a 2D array of size rowsize x colsize in ascending order
    Input: A 2D array, the rowsize and columnsize of that array
    Ouput: returns 0 when succesfuly run, -1 when fail run. (Sorts the array)
*/
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize);

/*  Copy the contents of array A into array B of the same size such that the contents of B would be exactly the contents of A
    Input: A 2D array, the rowsize and columnsize of that array
    Ouput: returns 0 when succesfuly run, -1 when fail run.(Copies A[][] --> B[][])
*/
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);

/*  Copy the contents of array A into array B of the same size such that the contents of B would be exactly the contents of A except they will be in a clockwise spiral sorted order
    Input: A 2D array, the rowsize and columnsize of that array
    Ouput: returns 0 when succesfuly run, -1 when fail run.(Copies A[][] --> B[][] in a spiral manner)
*/
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);


int main()
{
    //randomize seed
    srand(time(NULL));

    //Arrays A,B
    int A[ROW][COL], B[ROW][COL];
    unsigned int row,col;

    //promts input of the size of array
    printf("Testing an array of size: ");
    scanf("%d x %d", &row, &col );
    printf("Populate Array with unique random integers between 1 and 99...\n");

    //Populates array
    PopulateArray2DUnique(A, row, col, 1,99);

    //prnts the populated array
    printf("DisplayArray2D:\n");
    DisplayArray2D( A, row, col);

    //Prints the largest value found in array
    printf("FindLargest: %d\n", FindLargest(A, row, col));

    //Prints the column sum of column 0
    printf("FindColSum of col 0: %d\n", FindColSum(A,row,col, 0));

    //Sorts 2D array then prints
    printf("Sort2DArray followed by DisplayArray2D:\n");
    Sort2DArray( A, row, col);
    DisplayArray2D( A, row, col);

    //Copies array from A to B then displays B
    printf("CopyArray2D from A to B, then Display B:\n");
    CopyArray2D(A,B, row, col);
    DisplayArray2D( B, row, col);

    //Copy's array A onto B in spiral form and prints B
    printf("CopyArray2DSpiral from A to B, then Display B:\n");
    CopyArray2DSpiral( A, B, row, col);
    DisplayArray2D( B, row, col);

    return 0;
}

void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max)
{
    //Variables
    int digitSeen[max - min + 1];   //Digit seen is a 1d array used to check if the digit was used in the populate arraay before
    int hold; //used to hold digits

    //If statement states that if there are more spaces than unique values it will just exit the function
    if(rowsize*colsize > max-min+1)
    {
        return;
    }

    //intializing each spot in the 1d array to 0 (to conpensate for boolean value false)
    for(int j = 0; j < max-min+1 ; ++j)
    {
        digitSeen[j] = 0;
    }

    //2 For loops to get into each spot of the array..
    for ( unsigned int i = 0; i < rowsize; ++i)
    {
        for (unsigned int x = 0; x < colsize; ++x)
        {
            //This loop is used to check if that random digit was already used in the array
            do{
                hold = rand() % (max + 1 - min) + min; //generates random rumber between min-max inclusive

                //If the spot in the array of that digit is 0(false) it will set it to true and use that digit in the array
                if(digitSeen[hold] == 0)
                {
                    digitSeen[hold] = 1; //Sets the spot of that digit to true ( 1 = true)
                    break; //Breaks the do while
                }

            //loops while the position of the array is 1(true)
            }while( digitSeen[hold] == 1 );

            A[i][x] = hold;
        }
    }

}

void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
    //Uses 2 for loops to get into each spot in the array
    for ( unsigned int i = 0; i < rowsize; ++i)
    {
        for ( unsigned int x = 0; x < colsize; ++x)
        {
            //Prints that spot of the array (a space between each integer printed)
            printf("%3d", A[i][x]);
        }
        //used to print a newline to make a table like display of the array
        printf("\n");
    }
}

int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
    //Varialbe
    //Used to find largest integer
    int largestInt = 0;

    for(int i = 0; i < rowsize ; ++i) //This loop is for the rows
    {
        for ( int x = 0; x < colsize ; ++x)   //Loop for column
        {
            //If statment to check if the spot infront of the array is bigger than the current spot, if so it will swap spots.
            if(A[i][x] > largestInt)
            {
                largestInt = A[i][x];
            }
        }
    }
    //Returns the largest input found in the array
    return largestInt;
}


int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum)
{
    //Varialbe
    //Sum is used to calculate the sum of the given column
    int sum = 0;

    //For loop used to sum a column
    for (int x = 0; x < rowsize; ++x)
    {
        //Suming the column
        sum += A[x][col_to_sum];
    }
    //returns the sum
    return sum;
}

int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
    //Variable
    unsigned int hold;

    /*
        USES BUBBLE SORT
    */

    //Uses 3 loops to bubble sort the array from lowest to greatest
  	for(unsigned int k =0 ; k < rowsize*colsize-1; ++k)    //This loop is for the passes
	{
		for(unsigned int i = 0; i < rowsize ; ++i) //This loop is for the rows
		{
            for (unsigned int g = 0; g < colsize ; ++g)   //Loop for column
            {

                //If statement checks if its at the last spot of the array, it wont run the code inside the if statement
                if( (i != rowsize-1) || (g != colsize-1))
                {
                    //Checks if you are at the last column, if so it will compare the last column spot with the row first column of the row underneath it
                    if (g == colsize-1)
                    {
                        //if statment to check if the spot is larger than the first spot of the row underneath it
                        if(A[i][g] > A[i+1][0])
                        {
                            hold = A[i][g];
                            A[i][g] = A[i+1][0];    /* SWAPPING */
                            A[i+1][0] = hold;
                        }
                    }
                    //If statment to check if the spot infront of the array is bigger than the current spot, if so it will swap spots.
                    else if(A[i][g] > A[i][g+1])
                    {
                        hold = A[i][g];
                        A[i][g] = A[i][g+1];    /* SWAPPING */
                        A[i][g+1] = hold;
                    }
               }
            }
        }
	}

	//returns 0 if the riwsize,colsize is in the restricted domain. -1 if it isnt (fails)
	return rowsize <= ROW && rowsize > 0 && colsize <= COL && colsize > 0 ? 0 : -1;

}

int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
    //2 for loops to copy A onto B
    for ( int i = 0; i < rowsize; ++i)
    {
        for (int x = 0; x < colsize; ++x)
        {
            //Copying A onto B
            B[i][x] = A[i][x];
        }
    }

    //returns 0 if the riwsize,colsize is in the restricted domain. -1 if it isnt (fails)
    return rowsize <= ROW && rowsize > 0 && colsize <= COL && colsize > 0 ? 0 : -1;
}

int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
    //direction = 0 means right(->)
    //Direction = 1 means down(v)
    //direction = 2 means left(<-)
    //Direction = 3 means up(^)

    //Varialbes
    int top = 0, bottom = rowsize-1, left = 0, right = colsize - 1;
    int direction = 0;
    int hold[rowsize*colsize];  //This 1D array is just to hold all of the values in A in a 1D array
    int x = 0; //Used for incrementing

    //This proccess is just to copy the 2D array A into a 1D array named hold
    for ( unsigned int i = 0; i < rowsize; ++i)
    {
        for (unsigned int y = 0; y < colsize; ++y)
        {
            hold[x] = A[i][y];
            x++;
        }
    }

    //This whole algorithm is taking the 1D array that held the components of A[][] and storing it into B[][] in a spiral manner
    //the while loop will move in a spiral manner for the 2D array B. and since hold[] is a 1D array of the component A[][] stored in it, it just needs to be incremented everytime we move spirally
    x =0;
    while(left <= right && top <= bottom)
    {
        if (direction == 0)
        {
           for (int i = left; i <= right; ++i)
           {
                B[top][i] = hold[x];
                x++;
           }
           top++;
        }

        else if (direction == 1)
        {
            for (int i = top; i <= bottom; ++i)
            {
                B[i][right] = hold[x];
                x++;
            }
            right--;
        }

        else if (direction == 2)
        {
            for (int i = right; i >= left; --i)
            {
                B[bottom][i]= hold[x];
                x++;
            }
            bottom--;
        }

        else if (direction == 3)
        {
            for (int i = bottom; i>=top; --i)
            {
                B[i][left] = hold[x];
                x++;
            }
            left++;
        }
        direction = (direction+1)%4;
    }

    //returns 0 if the riwsize,colsize is in the restricted domain. -1 if it isnt (fails)
    return rowsize <= ROW && rowsize > 0 && colsize <= COL && colsize > 0 ? 0 : -1;

}





