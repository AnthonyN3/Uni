#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    char label[21];
    struct point *ptrNext;  //self referential pointer
    struct point *ptrPrevious;
};

struct point *CreateRecord();

struct point *InputRecord(struct point *ptrNew);

struct point *AddAtEnd(struct point *ptrNew);

struct point *AddAtBeginning(struct point *ptrNew);

//  checks if the list is empty, if so, it returns 1. And 0 If it isnt
//  Input: the pointer of the struct
//  Output: 1 - Empty,  0 - Not Empty
int isEmptyList();

//  Prints the list
//  Input: the struct pointer for the first element in the list
//  Output: void
void PrintList(struct point *ptrF);

//  Resets the list, (clears)
//  Input: the struct pointer for the first element in the list, and the last
//  Output: void
void ResetList(struct point *ptrF);

//  Adds an element to the beggining of the list
//  Input: the struct pointer for the first element in the list and the last
//  Output: Void
//void AddToBeginning(struct point * preF, struct point *PtrL);


//  Adds an element to the end of the list
//  Input: the struct pointer for the first element in the list and the last
//  Output: void
void AddToEnd(struct point *ptrF, struct point *ptrL);



void DisplayMenu();

struct point *ptrFirst = NULL;
struct point *ptrLast = NULL;

int main ()
{

    int choice;

    DisplayMenu();

    do{

        printf("\n>> ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                printf("Program Terminated");
                break;

            case 1:                                     //Add a point at the end of the list


                break;

            case 2:                                     //Add a point at the beggining of the list
                break;

            case 3:
                if (isEmptyList())         //Checks if the function "isEmptyList" returns 1 when passing ptrFirst, if it does, then the list is empty
                {                                       //If not, then it is not empty
                    printf("The list is empty\n");
                }
                else
                {
                    printf("The list is not empty\n");
                }
                break;

            case 4:
                ResetList(ptrFirst);                   //Resets the list, or in other words, clears it.
                break;

            case 5:                                    //Display the list
                PrintList(ptrFirst);
                break;

            case 6:                                     //Save the list into file
                break;

            case 7:                                        //Load list from file
                break;

            default:
                printf("INVALID INPUT\n");
                break;
        }

    }while(choice != 0 );

    ResetList(ptrFirst);

}

void DisplayMenu()
{
    printf("1. Add a point at the END pf the list.\n");
    printf("2. Add a point at the BEGINNING of the list.\n");
    printf("3. Is the list empty?\n");
    printf("4. Erase all points from the list (reset).\n");
    printf("5. Display the list.\n");
    printf("6. Save the list to a sequential file (reset/replace file contents)\n");
    printf("7. Read the list back from a sequential file (reset/replace current memory content)\n");
    printf("0. Exit\n");
}

int isEmptyList()
{
    if(ptrFirst == NULL)
    {
        return 1;   //its empty
    }
    else
    {
        return 0;
    }
}

void PrintList(struct point *ptrF)
{

    if(ptrF == NULL)
    {
        return;
    }
    else
    {
        printf("%d %s\n", ptrF->x, ptrF->label);
        PrintList(ptrF->ptrNext);
    }

}

void ResetList(struct point* ptrF)
{
    if (ptrF == NULL)
    {
        return;
    }
    else
    {
        ResetList(ptrF->ptrNext);
        free(ptrF);
    }
}


struct point *CreateRecord()
{
    struct point* ptrNew;
	ptrNew = (struct point *) (malloc(sizeof(struct point)));

	// initialize pointers here
	ptrNew->ptrNext = NULL;
    ptrNew->ptrPrevious = NULL;

	return ptrNew;
}

struct point *InputRecord(struct point *ptrNew)
{
    printf ("Enter a number and a word label: ");
	scanf("%d%s", &ptrNew->x, ptrNew->label);

	return ptrNew;
}

struct point *AddAtEnd(struct point *ptrNew)
{
    if(isEmptyList())
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        ptrLast->ptrNext = ptrNew;
        ptrNew->ptrPrevious = ptrLast;
        ptrLast = ptrNew;
    }
}

struct point *AddAtBeginning(struct point *ptrNew)
{
    if(isEmptyList())
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        ptrFirst->ptrPrevious = ptrNew;
        ptrNew->ptrNext = ptrFirst;
        ptrFirst = ptrNew;
    }

}
