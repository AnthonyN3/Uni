#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


//struct for a tweet
struct tweet
{
    int id;                 //uniquely identifies the simple tweet
    char created_at[51];    //store the UTC time and date
    char text[141];         //text of the tweet, allows max of 140 characters
    char user[21];          //User name of the person who posted the tweet

    struct tweet * ptrNext; //self-reference pointer
};

//alias
typedef struct tweet Tweet;

//  This option will retrieve all the tweets stored in the file. The filename is provided by the user. The loaded
//  records will replace all existing records. Note that any new record added at this point will have to have
//  the next available id as per the new records (i.e. the next max value).
//  Input: a file pointer
//  Ouput: returns the number of tweets in a file
int LoadTweet(FILE *fp);

//  Resets the list, (clears)
//  Input: the struct pointer for the first element in the list, and the last
//  Output: void
void ClearList();


//  Prints the list
//  Input: the amount of tweets
//  Output: void
void SortTweet(int amountOfTweets);

//  Saves all the newly sorted list into the file
//  Input: the struct array, file pointer, and number of tweets
//  Ouput: void. Saves tweets inside a text file
void SaveToFile(Tweet *ptrF, FILE *fp);


//GLobal pointers
Tweet * ptrFirst = NULL;
Tweet * ptrLast = NULL;


int main()
{

    //Variable
    char fileName[15];  //used to get file name from user
    FILE *fpointer;


    printf("Please enter a filename: ");        //promts file name
    scanf(" %[^\n]s",fileName); //scans the file name user wants to input

    fpointer = fopen(fileName, "r");    //open file pointer for reading
    SortTweet(LoadTweet(fpointer));
    fclose(fpointer);           //closes file pointer

    fpointer = fopen(fileName, "w");             //open file pointer for writing
    SaveToFile(ptrFirst,fpointer);
    fclose(fpointer);                   //close file pointer

    ClearList();            //clears the list/ frees all allocated memory

    return 0;
}

void SaveToFile(Tweet *ptrF, FILE *fp)
{

    if(ptrF == NULL)                //Base case, if ptrF is NULL it ends
    {
        return;
    }
    else
    {
        fprintf(fp ,"%d\n%s\n%s\n%s\n",ptrF->id, ptrF->created_at, ptrF->user,ptrF->text);        //prints the list into a file via allocated memory
        SaveToFile(ptrF->ptrNext, fp);                      //Recursive call
    }
}

int LoadTweet(FILE *fp)
{
    int tweetCounter = 0;

    //While loop reads until end of the file is reached
	while(!feof(fp))
    {

        Tweet * ptrNew = (Tweet *) malloc(sizeof(Tweet));       //allocates memory

        if (ptrNew != NULL)
        {
            fscanf(fp ,"%d\n%[^\n]s",&ptrNew->id, ptrNew->created_at);
            fscanf(fp, "\n%[^\n]s",  ptrNew->user);                             /*reads all the tweets and its properties and stores it into the struct array*/
            fscanf(fp,"\n%[^\n]s", ptrNew->text);
            fscanf(fp,"\n");

            ptrNew->ptrNext = NULL;

            if(ptrFirst == NULL)            //if ptrFirst == NULL means the list is empty and it will add the first newptr into the list
            {
                ptrFirst = ptrNew;
                ptrLast = ptrNew;
            }
            else                            //else, the list is not empty and adds it to the end
            {
                ptrLast -> ptrNext = ptrNew;
                ptrLast = ptrNew;
            }

            tweetCounter++;         //counter for number of tweets
        }
    }

    return tweetCounter;           //returns number of tweets counted
}

void SortTweet(int amountOfTweets)
{
    //Variable pointers
    Tweet * ptrTempOne = NULL;  //temps are used swap
    Tweet * ptrTempTwo = NULL;

    char temp[141];     //string temp used to swap string elemens between nodes
    int idTemp;         //int temp used to swap int elemens between nodes

    int i,x;
    for(i = 0; i < (amountOfTweets-1); ++i)             //USES bubble sort to loop !!!!
    {
        ptrTempTwo = ptrFirst;

        for(x = 0; x < (amountOfTweets-1-i) ; ++x)
        {
            ptrTempOne = ptrTempTwo;            //sets ptrTempOne to the first part of the list
            ptrTempTwo = ptrTempTwo->ptrNext;   //sets ptrTempTwo to the second, and after it comes back ptrTempOne and ptrTempTwo both move one list over

            if (strcmp(ptrTempOne->user , ptrTempTwo->user) > 0)        //checks if the user in 2nd node temp is greater in aphebetical order than the 1st node temp
            {
               strcpy(temp, ptrTempOne->text);
               strcpy(ptrTempOne->text, ptrTempTwo->text);      //Swaps the tweet texts between nodes
               strcpy(ptrTempTwo->text, temp);

               strcpy(temp, ptrTempOne->user);
               strcpy(ptrTempOne->user, ptrTempTwo->user);  //Swaps the user between nodes
               strcpy(ptrTempTwo->user, temp);

               strcpy(temp, ptrTempOne->created_at);
               strcpy(ptrTempOne->created_at, ptrTempTwo->created_at);  //Swaps the created_at between nodes
               strcpy(ptrTempTwo->created_at, temp);

               idTemp = ptrTempOne->id;
               ptrTempOne->id = ptrTempTwo->id;         //Swaps the id between nodes
               ptrTempTwo->id = idTemp;
            }

        }
    }
}


void ClearList()
{
    Tweet * ptrDelete;         //used to point the record to delete

    while(ptrFirst != NULL)     //loops until ptrFirst == NULL
    {
        ptrDelete = ptrFirst;           //ptrDelete is set to ptrFirst
        ptrFirst = ptrFirst -> ptrNext; //ptrFirst is set to the node next to it
        free(ptrDelete);                //Deletes ptrDelete
    }
    ptrLast = NULL; //sets ptrLast to NULL
}





