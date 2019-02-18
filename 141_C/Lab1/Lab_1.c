#include <stdio.h>

/*  Adds all the positive integers under and including the given integer
    Input: A positive integer
    Output: The sum of the positive integers under and including the input integer
*/
void sum ();

/*  Adds all the positive integers under and including the given integer in the form (n + 1)^2 where n is the integer being consecutively decreased
    input: A positive integer
    Output: The sum of the positive integers under and including the input integer in the form (n+1)^2
*/
void squareSum ();

/*  Gives you the fibbonacci number
    Input: Any positive integer
    Output: The fivonacci number, eg; 4 -> 3
*/
void fibonacci ();

/*  Finds the lowest common divisor between two integers
    Input: Any two integers
    Output: the lowest common divisor, eg: (2,4) -> 2
*/
void gcd ();

/*  Calculates the answer to a power function when inputing a base and exponent
    Input: A integer for the base and an integer for the exponent (Its assumed that the integer for the exponent is positive)
    Output: The answer to the power function, eg: power(2,3) -> 8
*/
void powerFunction ();

/*  Prints out all the positive integers below a given integer in consecutive order
    Input: Any positive integer
    Output: a sequance of decreasing order of consecutive integers from the given input, eg: print(5) = 5 4 3 2 1
*/
void print ();

/*  Prints an inverted right triangle with stars
    Input: A positive integer for the dimension
    Output: An inverted right triangle made with stars
       eg: draw(3)  ***
                    **
                    *
*/
void drawTriangle ();

/*  Prints an upright right triangle with stars
    Input: A positive integer for the dimension
    Output: An inverted right triangle made with stars
       eg: draw(3)  *
                    **ger
    Output: The sum of the positive integers under and including the input integer
*/
int rsum (int n);

/*  Adds all the positive integers under and including the given integer in the form (n + 1)^2 where n is the integer being consecutively decreased
    input: A positive integer
    Output: The sum of the positive integers under and including the input integer in the form (n+1)^2
*/
int rsquareSum (int n);

/*  Gives you the fibbonacci number
    Input: Any positive integer
    Output: The fivonacci number, eg; 4 -> 3
*/
int rfibonacci (int n);

/*  Finds the lowest common divisor between two integers
    Input: Any two integers
    Output: the lowest common divisor, eg: (2,4) -> 2
*/
int rgcd (int x, int y);

/*  Calculates the answer to a power function when inputing a base and exponent
    Input: A integer for the base and an integer for the exponent (Its assumed that the integer for the exponent is positive)
    Output: The answer to the power function, eg: power(2,3) -> 8
*/
int rpowerFunction (int base, int power);

/*  Prints out all the positive integers below a given integer in consecutive order
    Input: Any positive integer
    Output: a sequance of decreasing order of consecutive integers from the given input, eg: print(5) = 5 4 3 2 1
*/
void rprint (int n);

/*  Prints an inverted right triangle with stars
    Input: A positive integer for the dimension
    Output: An inverted right triangle made with stars
       eg: draw(3)  ***
                    **
                    *
*/
void rdrawTriangle (int n);

/*  Adds all the positive integers under and including the given integer
    Input: A positive integer
    Output: The sum of the positive integers under and including the input integer
*/
void rdrawTriangle2 (int n);


                    ***
*/
void drawTriangle2 ();

/*  Adds all the positive integers under and including the given integer
    Input: A positive integer
    Output: The sum of the positive integers under and including the input integer
*/
int rsum (int n);

/*  Adds all the positive integers under and including the given integer in the form (n + 1)^2 where n is the integer being consecutively decreased
    input: A positive integer
    Output: The sum of the positive integers under and including the input integer in the form (n+1)^2
*/
int rsquareSum (int n);

/*  Gives you the fibbonacci number
    Input: Any positive integer
    Output: The fivonacci number, eg; 4 -> 3
*/
int rfibonacci (int n);

/*  Finds the lowest common divisor between two integers
    Input: Any two integers
    Output: the lowest common divisor, eg: (2,4) -> 2
*/
int rgcd (int x, int y);

/*  Calculates the answer to a power function when inputing a base and exponent
    Input: A integer for the base and an integer for the exponent (Its assumed that the integer for the exponent is positive)
    Output: The answer to the power function, eg: power(2,3) -> 8
*/
int rpowerFunction (int base, int power);

/*  Prints out all the positive integers below a given integer in consecutive order
    Input: Any positive integer
    Output: a sequance of decreasing order of consecutive integers from the given input, eg: print(5) = 5 4 3 2 1
*/
void rprint (int n);

/*  Prints an inverted right triangle with stars
    Input: A positive integer for the dimension
    Output: An inverted right triangle made with stars
       eg: draw(3)  ***
                    **
                    *
*/
void rdrawTriangle (int n);

/*  Adds all the positive integers under and including the given integer
    Input: A positive integer
    Output: The sum of the positive integers under and including the input integer
*/
void rdrawTriangle2 (int n);

int main (void)
{
    //Variables
    int choose;
    int input1,input2;
    char cunt[100];

    // Prints the Table/list of functions that the user is able to select to use
    printf("Non-Recursive\t\t\tRecursive");
    printf("\n----------------------------------------------");
    printf("\n[1]Sums\t\t\t\t[9]Sums");
    printf("\n[2]SquareSum\t\t\t[10]SquareSum");
    printf("\n[3]Fibonacci\t\t\t[11]Fibonacci");
    printf("\n[4]GCD\t\t\t\t[12]GCD");
    printf("\n[5]Power\t\t\t[13]Power");
    printf("\n[6]Print\t\t\t[14]Print");
    printf("\n[7]TriangleOne\t\t\t[15]TriangleOne");
    printf("\n[8]TriangleTwo\t\t\t[16]TriangleTwo\n");

    //Loops the choosing of a function so that the user is able to use more than one function after termination of the program
    do{
        printf("\n\nEnter a number coresponding to the function you'd like to run (0 to exit): ");
        scanf("%d", &choose);
        printf("\n");

        // Switch statement is used to choose the function the user wanted to use correspond to its given number in the list/table
        switch (choose){
            case 0:
                break;
            case 1:
                sum();
                break;
            case 2:
                squareSum();
                break;
            case 3:
                fibonacci();
                break;
            case 4:
                gcd();
                break;
            case 5:
                powerFunction();
                break;
            case 6:
                print();
                break;
            case 7:
                drawTriangle();
                break;
            case 8:
                drawTriangle2();
                break;

            case 9:
                printf("\tEnter a positive integer: ");
                scanf("%d", &input1);
                printf("\tThe sum of all the integers under and including %d is %d\n", input1 ,rsum(input1) );
                break;
            case 10:
                printf("\tEnter a positive integer: ");
                scanf("%d", &input1);
                printf("\tThe total sum of the squares from %d to %d is %d", input1-(input1-2) , input1+1 ,rsquareSum(input1) );
                break;
            case 11:
                printf("\tEnter a natural number to find the fibonacci number: ");
                scanf("%d", &input1);
                printf("\tFibonacci(%d) = %d", input1, rfibonacci(input1));
                break;
            case 12:
                printf("\tEnter two integers that you'd like to find the gcd to in the format [x,y]: " );
                scanf("%d,%d", &input1,&input2);
                printf("\tThe gcd of %d and %d is %d", input1,input2,rgcd(input1,input2));
                break;
            case 13:
                printf("\tInput an integer base and a positive power in the form [base,power]: ");
                scanf("%d,%d", &input1,&input2);
                printf("\tPower(%d,%d) = %d", input1, input2, rpowerFunction(input1,input2));
                break;
            case 14:
                printf("\tEnter an positive integer: ");
                scanf("%d", &input1);
                printf("\tPrint(%d) = ",input1);
                rprint(input1);
                break;
            case 15:
                printf("\tEnter a positive integer Triangle Dimension) : ");
                scanf("%d", &input1);
                rdrawTriangle(input1);
                break;
            case 16:
                printf("\tEnter a positive integer Triangle Dimension) : ");
                scanf("%d", &input1);
                rdrawTriangle2(input1);
                break;

            default :
                printf("\tInvalid input");
                break;

        }

    }while(choose != 0);    //If the ussr inputs a 0, the loop will end and the program will terminate

    printf("\nProgram Terminated\n");

    return 0;
}

void sum ()
{
    //Variables
    int input;
    int total = 0;

    //User input
    printf("\tEnter a positive integer: ");
    scanf("%d", &input);

    //calculate summation using a loop
    for ( int i = 1; i <= input; ++i )
    {
        total += i;
    }
    //Prints the sum
    printf("\tThe sum of all the integers under and including %d is %d", input ,total );

}

void squareSum ()
{
    //Variables
    int input;
    int total = 0;

    //User input
    printf("\tInput a positive integer: ");
    scanf("%d", &input);

    //Loops "input" times
    for (int i = 1; i <= input; ++i)
    {
        total = (i+1)*(i+1) + total; //adds the form (i+1)^2 to total over and over untill loop is over
    }

    //Outputs the answer to the square sum
    printf("\tThe total sum of the squares from %d to %d is %d", input-(input-2) , input+1 ,total );
}


void fibonacci ()
{
    //Variables
    int input;
    int total;
    int term1 = 0, term2 = 1, hold;

    //User input
    printf("\tEnter a natural number to find the fibonacci number: ");
    scanf("%d", &input);

    // cehcks if the input is o,1 or greater than one
    if (input > 1)
    {
        //Loops to solve for the fibonacci number
        for (int i = 1; i < input; ++i)
        {
            hold = term1 + term2;
            term1 = term2;
            term2 = hold;
        }
        printf("\tFibonacci(%d) = %d", input, hold);
    }
    else if (input == 0)
        printf("\tFibonacci(0) = 0");
    else if (input == 1)
        printf("\tFibonacci(1) = 1");
}

void gcd ()
{
    //Variables
    int x,y,z;
    int termOne,termTwo;

    //User input
    printf("\tEnter two integers that you'd like to find the gcd to in the format [x,y]: " );
    scanf("%d,%d", &x,&y);

    //Holds the valus the user inputs into variables "termOne" and "termTwo" because x and y are going to change
    termOne = x;
    termTwo = y;

    //checks if any of the inputed variables were 0
    if ( termOne != 0 && termTwo != 0)
    {
        //Loop to find the greatest common divisor
        while ( x != 0 )
        {
            z = x;
            x = y%x;
            y = z;
        }
        printf("\tThe gcd of %d and %d is %d", termOne,termTwo,y);
    }
    //If one of the input is 0, the gcd is the other input
    else if ( termOne == 0 && termTwo != 0)
        printf("\tThe gcd of %d and %d is %d", termOne,termTwo,termTwo);
    //If one of the input is 0, the gcd is the other input
    else if ( termTwo == 0 && termOne != 0)
        printf("\tThe gcd of %d and %d is %d", termOne,termTwo,termOne);

}

void powerFunction()
{
    //Variables
    int input;
    int power;
    int product;

    printf("\tInput an integer base and a positive power in the form [base,power]: ");
    scanf("%d,%d", &input,&power);
    product = input;

    //If statements to check if the exponent inputed is zero,one, or greater than 1
    if (power > 1)
    {
        for ( int i = 1; i < power; ++i)
        {
            product *= input;
        }
        printf("\tPower(%d,%d) = %d", input, power, product);
    }
    else if (power == 1)
        printf("\tPower(%d,1) = %d", input,input );
    else if (power ==0)
        printf("\tPower(%d,0) = 1", input);

}

void print()
{
    //Variables
    int input;

    //User input
    printf("\tEnter an positive integer: ");
    scanf("%d", &input);

    printf("\tPrint(%d) = ", input);

    //loops input time
    for (int i = 0; i < input; ++i)
    {
        printf("%d ", input - i);
    }
}

void drawTriangle()
{
    //Variables
    int input;

    //usser input
    printf("\tEnter a positive integer (Triangle Dimension) : ");
    scanf("%d", &input);

    printf("\tDrawTriangle(%d):\n", input);

    //loops "input" times
    for( int i = 0; i < input; ++i)
    {
        //Loops input-i times
        for( int x = 0; x < (input - i); ++x)
        {
            printf("*");
        }
        printf("\n");
    }
}

void drawTriangle2()
{
    //Variables
    int input;

    //User input
    printf("\tEnter a positive integer Triangle Dimension) : ");
    scanf("%d", &input);

    printf("\tDrawTriangle2(%d):\n", input);

    //Loops the input times
    for( int i = 1; i <= input; ++i)
    {
        //loops i times
        for( int x = 0; x < i; ++x)
        {
            printf("*");
        }
        printf("\n");
    }
}

int rsum(int n)
{
    //Base Case
    if(n==0)
    {
        return 0;
    }
    //If base doesnt work it will call rsum again while adding n
    else
    {
        return n + rsum(n-1);
    }

}

int rsquareSum(int n)
{
    //Base case returns 0 if n == 0
    if (n == 0)
    {
        return 0;
    }
    //Recursive used to find the squaresum
    else
    {
        return (n+1)*(n+1) + rsquareSum(n-1);
    }

}

int rfibonacci(int n)
{
    //Base case
    if ( n == 1)
    {
        return 1;
    }
    //Base case
    else if (n == 0)
    {
        return 0;
    }
    //Fubonacci formula (recursive)
    else
    {
        return rfibonacci(n-1) + rfibonacci(n-2);
    }

}

int rgcd(int x,int y)
{
    //Base case
    if (x == 0)
    {
        return y;
    }
    //Base case
    else if (y == 0)
    {
        return x;
    }
    //recursion
    else
    {
        return rgcd(y,x%y);
    }
}

int rpowerFunction(int base, int power)
{
    //Base case
    if (power == 0)
    {
        return 1;
    }
    //recursion
    else
    {
        return (base*rpowerFunction(base,power-1));
    }
}


void rprint(int n)
{
    //prints the consecutive number
   printf("%d ", n);
   if (n > 1)
   {
       rprint(n-1);
   }

}


void rdrawTriangle(int n)
{
    //base case when n<= 0 returns nothing
    if (n <= 0)
    {
        return;
    }
    //Loops through and performs the (algorithm)
    for (int i= 0; i<n; ++i)
    {
        printf("*");
    }
    printf("\n");
    //recursion
    rdrawTriangle(n-1);
}

void rdrawTriangle2(int n)
{
    //base case returns nothing when n <= 0
    if (n <= 0)
    {
        return;
    }
    //recursion
    rdrawTriangle2(n-1);
    ////Loops through and performs the (algorithm)
    for (int i= 0; i<n; ++i)
    {
        printf("*");
    }
    printf("\n");
}








