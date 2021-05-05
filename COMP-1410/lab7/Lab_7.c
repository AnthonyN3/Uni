#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    char label[21];
    struct point *ptrNext;  //self referential pointer
    struct point *ptrPrevious;
};

//Creates the record
struct point *CreateRecord();

//Input for the created record
struct point *InputRecord(struct point *ptrNew);

//struct point *AddAtEnd(struct point *ptrNew);

//struct point *AddAtBeginning(struct point *ptrNew);

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
void AddAtBeginning(struct point *ptrNew);

//  Saves the elements/list into a file
//  Input: takes the struct pointer and a file pointer
//  Ouput: Void
void SaveToFile(struct point *ptrF ,FILE *fp);

//  load the elements/list from a file
//  Input: takes the struct pointer and a file pointer
//  Ouput: Void
void LoadFromFile(struct point *ptrF ,FILE *fp);

//  Adds an element to the end of the list
//  Input: the struct pointer for the first element in the list and the last
//  Output: void
void AddToEnd(struct point *ptrNew);


//
void DisplayMenu();

//The pointers for the first and last points
struct point *ptrFirst = NULL;
struct point *ptrLast = NULL;

int main ()
{

    //Variables/File pointer
    int choice;         //For choosing
    FILE *fpointer;     //for opening file

    DisplayMenu();      //Displays menu

    do{

        printf("\n>> ");        //prompt
        scanf("%d", &choice);   //Scanfs for choice

        switch (choice)
        {
            case 0:
                printf("Program Terminated");
                break;

            case 1:                                     //Add a point at the end of the list
                AddToEnd(InputRecord(CreateRecord()));
                break;

            case 2:                                     //Add a point at the beggining of the list
                AddAtBeginning(InputRecord(CreateRecord()));
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
                ptrFirst = NULL;
                ptrLast = NULL;
                break;

            case 5:                                    //Display the list
                PrintList(ptrFirst);
                break;

            case 6:
                fpointer = fopen("List.txt", "w");             //Save the list into file
                SaveToFile(ptrFirst,fpointer);
                fclose(fpointer);
                break;

            case 7:                                        //Load list from file
                fpointer = fopen("List.txt", "r");
                LoadFromFile(ptrFirst,fpointer);
                fclose(fpointer);
                break;

            default:
                printf("INVALID INPUT\n");
                break;
        }

    }while(choice != 0 );

    ResetList(ptrFirst);
    ptrFirst = NULL;
    ptrLast = NULL;

}

void DisplayMenu()
{
    //Prompts the menu
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
    if(ptrFirst == NULL)        //Base case
    {
        return 1;   //its empty
    }
    else
    {
        return 0;   //is not empty
    }
}

void PrintList(struct point *ptrF)
{

    if(ptrF == NULL)    //base case
    {
        return;
    }
    else
    {
        printf("%d %s\n", ptrF->x, ptrF->label);//prints
        PrintList(ptrF->ptrNext);               //Reucsive call
    }

}

void ResetList(struct point* ptrF)
{
    if (ptrF == NULL)       //base case
    {
        return;
    }
    else
    {
        ResetList(ptrF->ptrNext);   //recursive call
        free(ptrF);         //free's the allocated memory
    }
}


struct point *CreateRecord()
{
    struct point* ptrNew;       //Creates pointer of struct
	ptrNew = (struct point *) (malloc(sizeof(struct point)));   //creates allocated memory for ptrNew

	// initialize pointers here
	ptrNew->ptrNext = NULL;
    ptrNew->ptrPrevious = NULL;

	return ptrNew;  //returns the pinter ptrNew
}

struct point *InputRecord(struct point *ptrNew)
{
    printf ("Enter a number and a word label: ");       //prompts for input
	scanf("%d %s", &ptrNew->x, ptrNew->label);          //scans the variable x and label in the struct

	return ptrNew;
}

void AddToEnd(struct point *ptrNew)
{
    if(isEmptyList())           //Checks if ptrFirst is empty, if so it makes the ptrNew the First and Last pointer of struct
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        ptrLast->ptrNext = ptrNew;          //If it isn't empty it will put the pointers of the last struct of the ptrNext as it address so its linked
        ptrNew->ptrPrevious = ptrLast;
        ptrLast = ptrNew;
    }
}

void AddAtBeginning(struct point *ptrNew)
{
    if(isEmptyList())               //Checks if ptrFirst is empty, if so it makes the ptrNew the First and Last pointer of struct
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        ptrFirst->ptrPrevious = ptrNew;     //If it isn't empty it will put the pointers of the First struct of the ptrNext as it address so its linked
        ptrNew->ptrNext = ptrFirst;
        ptrFirst = ptrNew;
    }
}

void SaveToFile(struct point *ptrF, FILE *fp)
{

    if(ptrF == NULL)                //Base case, if ptrF is NULL it ends
    {
        return;
    }
    else
    {
        fprintf(fp,"%d %s\n", ptrF->x, ptrF->label);        //prints the list into a file via allocated memory
        SaveToFile(ptrF->ptrNext, fp);                      //Recursive call
    }
}

void LoadFromFile(struct point *ptrF ,FILE *fp)
{
    //Resets the list just in case there is already some allocaated memory
    ResetList(ptrFirst);
    ptrFirst = NULL;
    ptrLast = NULL;

    //Temporary strut point
    struct point *current;

    //Loops until the file ends
	while(!feof(fp))
	{
	    current = malloc(sizeof(struct point)); //Creates allocated memory for current

        //Intizle the ptrNExt, and prevous int he current struct as NULL
	    current->ptrNext = NULL;
        current->ptrPrevious = NULL;

	    fscanf(fp,"%d %s\n", &current->x, current->label);  //scans the file

	    AddToEnd(current);  //Add to end
	}
}





