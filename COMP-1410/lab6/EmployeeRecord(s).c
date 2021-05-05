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


/* Input the employee data interactively from the keyboard */
//  Input: Struct array of Employee
//  Output: void, stores the records into the struct array
void InputEmployeeRecord(Employee *ptrEmp);

/* Display the contents of a given Employee record*/
//  Input: a sningle struct
//  Ouput: displays the single employee record , return void
void PrintEmployeeRecord(const Employee e);

/* Save the contents of the employee record list to the newly created text file specified by FileName */
//  Input: takes the struct array, and the file pointer
//  Ouput: void, saves employee record into a .dat file
void SaveEmployeeRecord(const Employee e[], const char *FileName);


int main()
{
    //Delcartions & Varialbes
    FILE *fptr;
    Employee employeeList[MAX];     //List of employee's records using struct array
    int i, j;       //variables used for looping

    //Calls function for input
    InputEmployeeRecord(employeeList);
    printf("\nEmployee Record:");

    //Loops the employee record to print each record on screen
    for(i = 0; i < MAX; ++i)
    {
        PrintEmployeeRecord(employeeList[i]);
    }

    //Calls save function and saves the employee records into employee.dat
    SaveEmployeeRecord(employeeList, "employee.dat");

    return 0;

}

void InputEmployeeRecord(Employee *ptrEmp)
{
    //Variables
    int i = 0;  //For loop

    //Loop for promting and scanning usiner input
    for(i = 0; i < MAX; ++i)
    {
        printf("Enter Employee %d record in form \"ID FIRSTNAME LASTNAME\"\n", i+1);    //promt for record input from user
        scanf("%d %s %s", &ptrEmp[i].id, ptrEmp[i].firstname, ptrEmp[i].lastname);      //scans input
    }
}

void PrintEmployeeRecord(const Employee e)
{
    printf("\n%d %s %s", e.id, e.firstname, e.lastname);    //Prints the employee record
}

void SaveEmployeeRecord(const Employee e[], const char *FileName)
{
    //Variables & delcations
    int i = 0;
    FILE *fp;

    fp = fopen(FileName, "w");     //Opens file "fileName" that the user inputs and points to that file for writing (if DNE, then creates the file)

    fprintf(fp,"ID FIRSTNAME LASTNAME");
    //Loops for the amount of tweets there are
    for(int i = 0; i < MAX; ++i)
    {
        fprintf(fp ,"\n%d %s %s",  e[i].id, e[i].firstname, e[i].lastname);//prints the tweets and properties into pointed file
    }

    fclose(fp);     //Closes fp
}


