void SearchTweet(struct tweet quantity[TWEET_AMOUNT] , int numberOfTweets)
{
    //Variables
    char keyword[20];   //keyword that the user inputs
    char wordList[80][20];  //Creates a word list
    char temp[141];  //Used to move a word from a 1d array into a 2d array row
    int wordCount = 0;  //keeps track of the number of words in each text of a tweet
    int tweetWithKeyword = 0; //keeps track of the number tweets that contain the keyword
    char *tokenPtr;        //declare pointer


    scanf(" %s", keyword);  //scanf to scan for the users keyword

    int i;  //Int i used to cycle through each tweet/struct
    for(i = 0; i < numberOfTweets; ++i)      //This loop will cycle through each tweet
    {
        wordCount = 0;  //word count = 0 to reset the number of word count for each text in a tweet every time a new tweet is checked

        strcpy(temp, quantity[i].text);     //copies the text from the tweet onto a char array named "temp"

        tokenPtr = strtok(temp,",:;!?. ");  //tokenizes the sentence into its first word

        //loops intil tokenptr reaches NULL (when it reaches the end of the sentence)
        while( tokenPtr != NULL )
        {
            strcpy(wordList[wordCount],tokenPtr);
            tokenPtr = strtok(NULL, ",:;!?. ");     /* LOOPS EACH WORD AND STORES EACH WORD INTO A 2D WORD LIST*/
            wordCount++;    //increments the wordCount to keep track of # of words being stored
        }

        //This beauty is to check if any of the words in the wordlist match the keyword the user inputs, if so it will print the tweet and its properties
        int j;
        for(j = 0; j < wordCount; ++j)  //Loops the amount of words in the sentence/2D word list
        {
            if (strcmp(keyword, wordList[j]) == 0)  //Compares each individual word to the keyword, if it matches, it will run the contents of the if statement
            {
                printf("Found match: ");
                printf("\nid: %d\tCreated at: %s by %s\n%s\n\n",quantity[i].id, quantity[i].created_at, quantity[i].user,quantity[i].text); //Prints tweet that containts the keyword
                tweetWithKeyword++; //keeps track of # of tweets with teh keyword
                break;              //Used so that once it finds a word that matches in that tweet, it wont print multiple if theres multiple keywords in one sentence
            }
        }
    }

    printf("Found %d tweet(s) matching the criteria!\n", tweetWithKeyword);

}
