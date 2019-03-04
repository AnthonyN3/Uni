#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define TWEET_AMOUNT 5  //Max amount of tweets

//struct for a tweet
struct tweet
{
    int id;                 //uniquely identifies the simple tweet
    char created_at[51];    //store the UTC time and date
    char text[141];         //text of the tweet, allows max of 140 characters
    char user[21];          //User name of the person who posted the tweet

    struct tweet * ptrNext;
};

//alias
typedef struct tweet Tweet;

//  This option will search all tweets’ text for occurrences of a certain keyword string entered form the user.
//  It will search the text of each tweet, then display all the tweets that contained this keyword.
//  Input: the struct array, and the number of tweets
//  Output: void, returns nothing, but does print all the tweets and its properties that include the key word
void SearchTweet(Tweet quantity[TWEET_AMOUNT] , int numberOfTweets);

//  This option will display to the console screen all the tweets
//  Input: the struct array, and the number of tweets
//  Output: void. However, it displays all the tweets onto console and its properties
void DisplayTweets();

//  This option will save all the tweets to a file. The user is promoted for the filename. A simple status is
//  generated accounting to the number of records saved. Use a sequential text file
//  Input: the struct array, file pointer, and number of tweets
//  Ouput: void. Saves tweets inside a text file
void SaveTweet(Tweet quantity[TWEET_AMOUNT] , FILE *fp ,int numberOfTweets);

//  This option will retrieve all the tweets stored in the file. The filename is provided by the user. The loaded
//  records will replace all existing records. Note that any new record added at this point will have to have
//  the next available id as per the new records (i.e. the next max value).
//  Input: the struct array and file pointer
//  Ouput: returns the number of tweets in a file
int LoadTweet(Tweet quantity[TWEET_AMOUNT] , FILE *fp);

//  This option will automatically generate the next highest value for an id, the locate date/time for the created_at in UTC, and prompt the user for the tweet’s text
//  Input: the struct pointer , and the id value
//  output: returns the new struct pointer
Tweet * CreateNewTweet (Tweet firstTweet, int i);

void ClearList();

Tweet * ptrFirst = NULL;
Tweet * ptrLast = NULL;

int main()
{
    //Variable(s)
    Tweet quantity[TWEET_AMOUNT];    //creates the amount of tweets that are capable to be made(5 is max)
    int choose;     //Used for the user input when choosing the functions
    int i = 0;      //Used to change the id number, also represents the number of tweets there are

    //Define struct tweet as "Tweet"
    Tweet firstTweet;

    //Define file pointer
    FILE *fpointer;

    //Promt menu
    printf("Welcome to Simple Twitter\n-------------------------\n");
    printf("Please enter your user name: ");            //Promt to enter user name
    scanf("%[^\n]s",firstTweet.user );
    printf("Welcome %s, let's start tweeting...\n", firstTweet.user);

    //Loops the choosing of a function so that the user is able to use more than one function after termination of one of the functionality
    do{
        //displays the menu functionality's (6 in total)
        printf("\n1. Create a new tweet\n");
        printf("2. Serach tweets\n");
        printf("3. Display tweets\n");
        printf("4. save tweets to file\n");
        printf("5. Load tweets from file\n");
        printf("6. Exit\n");
        printf("\n>> ");
        scanf("%d", &choose);

            // Switch statement is used to choose the function the user wanted to use correspond to its given number
            switch (choose)
            {
                case 1:                                             /*Case 1: Create Tweet*/
                    CreateNewTweet(firstTweet, i);  //Calls CreateTweet function
                    i++;

                    break;

                case 2:                                                    /*Case 2: Keyword search through all the tweets*/

                    printf("Please enter the search keyword: ");    //Prompts user to enter a keyword
                    SearchTweet(quantity , i);  //calls SearchTweet function

                    break;

                case 3:                                                 /*Case 3: Displays the tweets*/

                    printf("Displaying all %d tweet(s):", i);    //promts user the amount of tweets displayed
                    DisplayTweets();    //calls display function

                    break;

                case 4:                                     /*Case 4: save's tweet into a file that the user creates the file name for*/

                    printf("Please enter a filename: ");    //promts user
                    SaveTweet(quantity , fpointer ,i);          //calls save function

                    break;

                case 5:                                         /*Case 5: Leads tweet from a previously saved tweet (via file) */

                    printf("Please enter a filename: ");    //promts user for a file name they'd like to open to load tweet
                    i = LoadTweet(quantity ,fpointer);          //calls load tweets and also asigns the  int i(number of tweets) variable to it

                    break;

                case 6:

                    printf("Good bye!\n");      //displays "Good bye!"

                    break;

                default:

                    printf("Invalid input\n");  //If invalid input, it states it.
                    break;
            }
        }while(choose != 6);    //Program will keep looping until user inputs a 6 to exit*/

    ClearList();

    return 0;
}


Tweet * CreateNewTweet (Tweet firstTweet, int i)
{
    Tweet * ptrNew = (Tweet *) malloc(sizeof(Tweet));
    if (ptrNew != NULL)
    {
        struct tm *newtime;
        time_t ltime;

        strcpy(ptrNew->user, firstTweet.user);   //Copies the user from Tweet, into the array user

        //Prompts "tweet text"
        printf("tweet text: ");
        scanf(" %[^\n]s",ptrNew->text);     //scans the text from the user

        //Used to get the time/date
        time(&ltime);
        newtime = localtime(&ltime);
        strcpy(ptrNew->created_at,asctime(newtime));    //Stores the date of the creation of the tweet into created_at of quantity[i]
        ptrNew->created_at[strlen(ptrNew->created_at)-1] = '\0';  //Since when storing the date, it also stores the '\n' inside the char array, this overwrite the '\n' and replace it with '\0'

        ptrNew->id = 1000 + i;              //Id of the tweet, starts at 1000 and increments by i each time

        ptrNew->ptrNext = NULL;
        //Prints the tweet and its properties
        printf("New Tweet Created:\nid: %d\tCreated at: %s by %s\n%s\n",ptrNew->id, ptrNew->created_at, ptrNew->user,ptrNew->text);
    }

    if(ptrFirst == NULL)
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        ptrLast -> ptrNext = ptrNew;
        ptrLast = ptrNew;
    }

    return ptrNew;
}

void ClearList()
{
    Tweet * ptrDelete;         //used to point the record to delete

    while(ptrFirst != NULL)
    {
        ptrDelete = ptrFirst;
        ptrFirst = ptrFirst -> ptrNext;
        free(ptrDelete);
    }
    ptrLast = NULL;
}


void DisplayTweets()
{
    //Loops the number of tweets and prints all tweets and its members
    Tweet * ptrCurrent = ptrFirst;

    while (ptrCurrent != NULL)
    {
        printf("\nid: %d\tCreated at: %s by %s\n%s\n",ptrCurrent->id, ptrCurrent->created_at, ptrCurrent->user,ptrCurrent->text);
        ptrCurrent = ptrCurrent -> ptrNext;
    }

}

void SaveTweet(Tweet quantity[TWEET_AMOUNT] , FILE *fp ,int numberOfTweets)
{
    //Variables
    char fileName[15];  //char fileName used to get the file name the user inputs

    scanf(" %[^\n]s",fileName); //scans for the file name


    fp = fopen(fileName, "w");     //Opens file "fileName" that the user inputs and points to that file for writing (if DNE, then creates the file)

    //Loops for the amount of tweets there are
    for(int i = 0; i < numberOfTweets; ++i)
    {
        fprintf(fp ,"%d\n%s\n%s\n%s\n",quantity[i].id, quantity[i].created_at, quantity[i].user,quantity[i].text);  //prints the tweets and properties into pointed file
    }

    fclose(fp);     //Closes fp

    printf("%d tweet(s) saved in file \"%s\".",numberOfTweets ,fileName);
}

int LoadTweet(Tweet quantity[TWEET_AMOUNT], FILE *fp)
{
    //Variable
    char fileName[15];  //used to get file name from user

    scanf(" %[^\n]s",fileName); //scans the file name user wants to input

    fp = fopen(fileName, "r");  //Opens existing file and points for reading

    //While loop reads until end of the file is reached
    int i = 0;
	while(!feof(fp))
	{
		fscanf(fp ,"%d\n%[^\n]s",&quantity[i].id, quantity[i].created_at);
		fscanf(fp, "\n%[^\n]s",  quantity[i].user);                             /*reads all the tweets and its properties and stores it into the struct array*/
		fscanf(fp,"\n%[^\n]s", quantity[i].text);
		fscanf(fp,"\n");
		i++;        //increments i so that all tweets can be read and stored/loaded, NOTE: it also is ued for the number of tweets in the file
	}

    fclose(fp); //close file pointer

    //prints the number of tweets saved in a file
    printf("%d tweet(s) loaded from file \"%s\".",i ,fileName);

    return i;   //returns the number of tweets
}

void SearchTweet(Tweet quantity[TWEET_AMOUNT] , int numberOfTweets)
{
    //Variables
    char keyword[20];   //keyword that the user inputs
    int tweetWithKeyword = 0; //keeps track of the number tweets that contain the keyword


    scanf(" %[^\n]s", keyword);  //scanf to scan for the users keyword

    int i;  //Int i used to cycle through each tweet/struct
    for(i = 0; i < numberOfTweets; ++i)      //This loop will cycle through each tweet
    {
        if (strstr(quantity[i].text, keyword)!= NULL)   //compares the keyword with the each text, and if it containts it, the strstr should return a address and not a NULL
        {
            printf("Found match: ");
            printf("\nid: %d\tCreated at: %s by %s\n%s\n\n",quantity[i].id, quantity[i].created_at, quantity[i].user,quantity[i].text); //Prints tweet that containts the keyword
            tweetWithKeyword++; //counts the amount of tweets containt the keyword
        }
    }

    printf("Found %d tweet(s) matching the criteria!\n", tweetWithKeyword);

}
