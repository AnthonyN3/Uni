#include <stdio.h>
#include <math.h>

/*
	Takes a 2 digit number from the users input, and reverse the number (ie 12 -> 21)
*/
int main (void) 
{
	int inputNum,firstNum,secondNum;
	
	printf("Enter a two digit number: ");
	scanf("%d", &inputNum);
	
	secondNum = inputNum % 10;
	firstNum = floor(inputNum / 10);
	
	printf("The reverse: %d%d", secondNum, firstNum);	
}