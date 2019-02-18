#include <stdio.h>
#include <ctype.h>
#include <string.h>

//  Takes a sentence and it extracts its words and prints them in alphebeticall order
//  Input:  A char array string that containts an english sentence
//  Returns void, but it prints the order of each word alphebetiacally
void ParseSentence (char s[100]);

int main()
{
    //Variable
    char string[50];

    //Prompt
    printf("Enter a sentence: ");
    //scans the input sentence the user inputed into char array string
    scanf("%[^\n]s", string);

    //Calls ParseSentence function on string
    ParseSentence(string);

    return 0;
}

void ParseSentence (char s[100])
{
    //Variables
    char *token;    //Creates a pointer named token
    char wordList[15][20];  //Creates a word list
    char temp[10];  //Used to move a word from a 1d array into a 2d array row
    int wordCount =0;   //Counts the amount of words in a sentence

    //assigns the token pointer to the first word
    token = strtok(s, ",:. ");

    //Loop that extracts each word from the sentence and inserts it into the word list
    while( token != NULL )
    {
        strcpy(wordList[wordCount],token);
        token = strtok(NULL, ",:. ");
        wordCount++;    //Used to count number of words
    }

    //Sort words alphebetically
    for(int i = 1; i < wordCount;++i)
    {
        for (int j = 0; j < wordCount - 1; j++)
        {
            if (strcmp(wordList[j], wordList[j+1]) > 0)
            {
                //Swap
                strcpy(temp, wordList[j]);
                strcpy(wordList[j], wordList[j+1]);
                strcpy(wordList[j+1], temp);
            }
        }
    }

    //Display the words
    for (int i = 0; i < wordCount; ++i)
    {
        printf("\n%s\n", wordList[i]);
    }

}
