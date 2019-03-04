#include <stdio.h>

int main()
{

    int a = 7;  //Definig a variable a with type int, and intialzing it with a value of 7
    int *aPtr;  //declaring a pointer called aPtr as a type int

    aPtr = &a; //Returns the address of the variable a. So now aptr will have the address of variable a and will now "point" to it

    printf("%p", &a); //prints the address of variable a
    //OUTPUT:0060FF0C

    printf("%p", aPtr); //Prints the adress of where the pointer points to
    //OUTPUT:0060FF0C

    printf("%p", &aPtr);   //Prints the adress of the pointer
    //OUTPUT:0060FF08

    printf("%d", a);    //Prints the value inside the address
    //OUTPUT:7

    printf("%d", *aPtr);    //prints the value inside the adress a (via pointing)
    //OUTPUT:7

    printf("%p", *&aPtr);   //Takes the address of the Pointer itsself and takes what its holding
    //OUTPUT:0060FF0C

    printf("%p", &*aPtr); //Takes what the pointer is holding and takes its address
    //OUTPUT:0060FF0C

    printf("%d\t", *&a); // Takes the adress of the variable a and takes the value it holds in that adress
    //OUTPUT:7

    printf("%d", &*a);
    // ERROR Invalid type of unary "*"

    return 0;

}
