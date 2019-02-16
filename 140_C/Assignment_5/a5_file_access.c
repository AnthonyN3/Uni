#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Prototypes
void PrepareData(int m, FILE *fp);
void MonthDay(FILE*fp);
int ObtainData(FILE *fp,int a1d[15], float a2d[4][15]);
void PrintData(int m, int a1d[15], float a2d[4][15]);
void sort_item_numbers(int m,int a1d[15],float a2d[4][15]);

/*
	More complex program... (WORKING WITH FILES, READING/WRITING)
	This program will write to a file called "test.dat"
	and this file will prepare data information in the form of: 
	"12 171.26 6 27 2008" where each number is "item# UnitPrice PurchaseDate(MM/DD/YYYY)" respectively..Where there is no newline, and
	its written with a space between each number only (the numbers will be randomly generated)
	

	It will then read back the information and store them into arrays
	and take the information read and order them from item # from least->greatest and print (up to down) the matching item# and its corresponding 
	UnitPrice and PurchaseDate 
*/

int main (void){
	
	srand(time(NULL));
	int mx = 15;
	int a1d[mx];
	float a2d[4][mx]; 
	int m;
	
	FILE *fpointer;
	
	fpointer = fopen("test.dat", "w");
	PrepareData(mx,fpointer);
	fclose(fpointer);
	
	fpointer = fopen("test.dat", "r");
	m = ObtainData(fpointer, a1d, a2d);	
	fclose(fpointer);
	
	PrintData(m, a1d, a2d);
	
	return 0;
}

//Generate the text file with random numbers
void PrepareData(int m, FILE *fp)
{
	
	int num = rand() % (m-10) + 10;
	
	for(int i = 0; i < num; ++i)
	{
		fprintf(fp,"%d ", (rand() % 15 + 5));
		fprintf(fp,"%0.2f ", ((float)rand()/RAND_MAX) * 200.0f);
		MonthDay(fp);
		fprintf(fp,"%d ", rand()%17 + 2000);
	}
}

//In order to generate legal month and day (taking in consideration of leap years/months with different day lenths)
void MonthDay(FILE*fx)
{	
	int day;
	int mon = rand()% 12 + 1;
	fprintf(fx,"%d ", mon);
	
	if(mon == 2)
	{
		day = 28;	
	}
	
	else
	{
		if( mon < 8)
		{
			if(mon%2 != 0)
			{				
				day = 31;
			}
			
			else
			{
			day = 30;
			}
		}
		else
		{
			if(mon%2 != 0)
			{
				day = 30;
			}
			else
			{
				day = 31;
			}	
			
		}
	}
	
	fprintf(fx,"%d ", rand()%day + 1 );	
}

//Read from the data we previously written in
int ObtainData(FILE *fp, int a1d[15], float a2d[4][15])
{
	int i = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%d %f %g %g %g", &a1d[i], &a2d[0][i], &a2d[1][i], &a2d[2][i], &a2d[3][i]); 
		i++;	
	}
	
	return i-1;
}

//Print the data
void PrintData(int m, int a1d[15], float a2d[4][15])
{
	sort_item_numbers(m,a1d,a2d);
	
	printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");
	
	for(int i = 0; i < m; ++i)
	{
		printf("%2d\t\t$%6.2f\t\t%02g/%g/%g\n", a1d[i], a2d[0][i], a2d[1][i], a2d[2][i], a2d[3][i]);		
	}
	
	
}

//Sort by item number
void sort_item_numbers(int m,int a1d[15],float a2d[4][15])
{
	for(int q =0 ; q <= m; ++q)
	{
		for(int i = 0; i < m - 1; ++i)
		{
			if(a1d[i] > a1d[i+1])
			{
				int hold = a1d[i];
				a1d[i] = a1d[i+1];
				a1d[i+1] = hold;
			
				
				for(int x = 0; x < 4; ++x)
				{
					float hold = a2d[x][i];
					a2d[x][i] = a2d[x][i+1];
					a2d[x][i+1] = hold;
				}
			
			}
			
			
		}
	}
}





















