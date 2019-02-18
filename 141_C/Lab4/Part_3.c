#include <stdio.h>
#include <string.h>

#define SIZE 80

/*  The function reverses the contents of the array (or string) being passed
    Input: Accepts a char array or char pointer
    Output: Void
*/
void Reverse(char *Array);

void RecursiveReverse(char *Array, int start, int end);

int main()
{
    //Variables
    char Array[SIZE];
    //Assignning the pointer to the array
    //char *PtrArray = Array;

    //Promts user input
    printf("Input a string: ");
    //Takes user input and stores it in an array (note [^\n] is used to specify that the string will stoptaking input when it reaches '\n'
    scanf("%[^\n]s", Array);

    //Prints out the input the user inputed
    printf("\nintput: %s", Array);

    //Reverse the string using functions
    Reverse(Array);
    printf("\nReverse (Non-recursive): %s", Array);
    Reverse(Array);

    printf("\n\nintput: %s", Array);
    RecursiveReverse(Array, 0, strlen(Array)-1);
    printf("\nReverse(recursive): %s", Array);
}


void Reverse(char *Array)
{
    int temp,start,end;
    start = 0;
    end = strlen(Array) - 1;

    while (start < end)
    {
        temp = *(Array+start);
        *(Array+start) = *(Array+end);
        *(Array+end) = temp;
        start++;
        end--;
    }
}

void RecursiveReverse(char *Array, int start, int end)
{
    if (start > end)
    {
        return;
    }
    int temp = *(Array+start);
    *(Array+start) = *(Array+end);
    *(Array+end) = temp;
    start++;
    end--;
    RecursiveReverse(Array,start,end);
}
