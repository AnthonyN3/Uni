#include <stdio.h>
#define MAX 20

/*  takes two integer pointers and exchanges the values of each
    Input: 2 type int pointers
    Ouput: Void
*/
void Swap( int *a , int *b );
/*  takes a single parameter of type pointer to an integer and triples its value.
    Input: 1 type int pointer
    Output: the tripled value of the int
*/
int Triple(int *d);
/*  accepts an integer array, its size, and sort order. (Use the function Swap that you designed in part II above.)(the Sort order is defined by a flag parameter in the function call
    Input: Passing the array via pointer, the size of array, and sort order
    Output: Void
*/
void BubbleSort(int *Array, int size, int sortOrder);
/*  Prints an array
    Input: Takes the array via pointer, and the size of the array
    Output: Its type void, but ouputs the Array inside the function
*/
void PrintArray(int *Array, int size);

int main()
{
    // Variables
    int NumList[MAX];
    int choice;
    int *ptrNumList = NumList; //Defining the Pointer and setting it to the array

    //Set the first spot of the array = 4 via pointer
    *ptrNumList = 4;

    //This is to populate the array with Even numbers
    for(int i = 1 ; i <= MAX-1; ++i)
    {
        *(ptrNumList+i) = *(ptrNumList +i -1) + 2;
    }

    //Prints the array
    printf("Array:\n");
    PrintArray(NumList,MAX);

    //Triples the value inside the array
    for(int i = 0 ; i <= MAX-1; ++i)
    {
         Triple(ptrNumList+i);
    }

    //Prints the tripled Array
    printf("\n\nTripled: \n");
    PrintArray(NumList,MAX);

    //Promt that ask which sort would you like
    printf("\n\nChoose which sort you'd like (1=Ascending, -1=descending):");
    scanf("%d", &choice);

    //IF statement that chooses either if the user inputed Ascending or Descending order
    if (choice == 1)
    {
        printf("Ascending Order:\n");
        BubbleSort(NumList, MAX, 1);
        PrintArray(NumList,MAX);
    }
    else if (choice == -1)
    {
        printf("Descending Order:\n");
        BubbleSort(NumList, MAX, -1);
        PrintArray(NumList,MAX);
    }


    //Prints the Ascending Order of the Array
    printf("\n\nAscending Order:\n");
    BubbleSort(NumList, MAX, 1);
    PrintArray(NumList,MAX);

    //Prints the Ascending Order of the Array
    printf("%\n\nDescending Order:\n");
    BubbleSort(NumList, MAX, -1);
    PrintArray(NumList,MAX);


}

void Swap( int *a , int *b )
{
    //Variables
    int hold;
    //Swap using hold
    hold = *b;
    *b = *a ;
    *a = hold;
}

int Triple(int *d)
{
    //Multiplies the value that the pointer points to by 3
    *d = *d * 3;
    return *d;
}

void BubbleSort(int *Array, int size, int sortOrder)
{
    //Variables
    int hold;

    // two Loops used, one for the pass and the other to check if the array spots should be swapped
    for (int i = 0; i < size - 1 ; ++i)
    {
        for (int x = 0; x < size - 1; ++x)
        {
            //If statement to check if its an ascending order sort
            if ( sortOrder == 1)
            {
                if(*(Array+x) > *(Array+x+1))
                {
                    Swap(Array+x,Array+x+1);
                }
            }

            //Checks if its an Descending order sort
            else if ( sortOrder == -1)
            {
                 if(*(Array+x) < *(Array+x+1))
                    {
                    Swap(Array+x,Array+x+1);
                    }
            }

        }

    }

}

void PrintArray(int *Array, int size)
{
    //Prints the array using pointers
    for(int i = 0 ; i < size; ++i)
    {
        printf("%5d", *(Array+i));
    }
}
