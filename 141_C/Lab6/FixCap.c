#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 3

//  struct for the memberos of employee record
struct employee {

    char firstname[40];     //stores the first name of the employee
    char lastname[40];      //stores the last name of the employee
    int id;                 //stores the id of the emplouee

}; typedef struct employee Employee;     //shortform of "struct employee" as Employee

//  Puts caps on the first letter of the first and last name of an employee from a struct array
//  Input:  struct array, and # of employee's
//  OUput: void
void WordCap(Employee *e, int numberOfEmployee);

int main()
{
    //Delcarions & Variables
    FILE *fp;
    Employee EmployeeList[MAX]; //Employee list

    fp = fopen("employee.dat", "r");    //Opens file for reading

    fscanf(fp,"ID FIRSTNAME LASTNAME"); //print into file

    int i = 0;
	while(!feof(fp))        //Loops the file until the end of the file is reached
	{
        fscanf(fp,"\n%d %s %s", &EmployeeList[i].id, EmployeeList[i].firstname, EmployeeList[i].lastname);  //scans the file and stores in into the array struct
		i++;
	}

    fclose(fp);     //closes fpointer

    WordCap(EmployeeList, i);   //calls the word cap

    fp = fopen("employee.dat", "w");    //P[ems the "emplyee.dat" file for writing
    fprintf(fp,"ID FIRSTNAME LASTNAME");    //prints into file

    int x;
    for(x = 0; x < i; ++x)
	{
        fprintf(fp,"\n%d %s %s", EmployeeList[x].id, EmployeeList[x].firstname, EmployeeList[x].lastname);      //Prints the new record into file with uppercase names
	}

    fclose(fp);

    return 0;
}

void WordCap(Employee *e,int numberOfEmployee)
{
    int i;  //Variable
    for (i = 0; i < numberOfEmployee ; ++i)  //Loops the number of records there are
    {
        e[i].firstname[0] = toupper(e[i].firstname[0]);     //Upercases the first letter of frist name
        e[i].lastname[0] = toupper(e[i].lastname[0]);       //Upercases the first letter last name
    }

}
