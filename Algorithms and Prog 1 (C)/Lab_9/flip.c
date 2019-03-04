#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

//Calculate the total numbers of heads and tails, when flipping a coin 100 times randomly (using srand)

int main (void)
{
	int toss, totalHeads, totalTails;	
	srand(time(NULL));
	for(int i = 0; i < 100; ++i)
	{
		toss = flip();
		printf("%s ", toss == 0 ? "Heads" : "Tails"); 
		toss == 0 ? totalHeads++ : totalTails++;
	}
	printf("\nThe total number of Heads was %d", totalHeads);
	printf("\nThe total number of Tails was %d", totalTails);
}


int flip()
{
	return rand() % 2;
}